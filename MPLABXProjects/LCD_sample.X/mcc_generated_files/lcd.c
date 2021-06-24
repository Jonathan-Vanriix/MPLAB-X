/*******************************************************************************
Copyright 2019 Microchip Technology Inc. (www.microchip.com)

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*******************************************************************************/

#include <stdint.h>
#include <stdbool.h>
#include <xc.h>
#include "lcd.h"

#ifndef SYSTEM_PERIPHERAL_CLOCK
#define SYSTEM_PERIPHERAL_CLOCK 16000000
#pragma message "This module requires a definition for the peripheral clock frequency.  Assuming 16MHz Fcy (32MHz Fosc).  Define value if this is not correct."
#endif

#ifndef FCY
    #if defined(XTAL_FREQ)
        #define FCY (XTAL_FREQ/2)
    #elif defined(SYSTEM_PERIPHERAL_CLOCK)
        #define FCY SYSTEM_PERIPHERAL_CLOCK
    #else
        #error This module requires the clock frequency to be defined.
    #endif
#endif

#include <libpic30.h>

/* Private Definitions ***********************************************/
#define FAST_INSTRUCTION_TIME_US    50
#define SLOW_INSTRUCTION_TIME_US    1600
#define STARTUP_TIME_MS             30
#define SIGNAL_TIMING_US            1

#define LCD_MAX_COLUMN                  16

enum COMMAND
{
    LCD_COMMAND_CLEAR_SCREEN        = 0x01,
    LCD_COMMAND_RETURN_HOME         = 0x02,
    LCD_COMMAND_ENTER_DATA_MODE     = 0x06,
    LCD_COMMAND_CURSOR_OFF          = 0x0C,
    LCD_COMMAND_CURSOR_ON           = 0x0F,
    LCD_COMMAND_MOVE_CURSOR_LEFT    = 0x10,
    LCD_COMMAND_MOVE_CURSOR_RIGHT   = 0x14,
    LCD_COMMAND_SET_MODE_4_BIT      = 0x28,
    LCD_COMMAND_SET_MODE_8_BIT      = 0x38,
    LCD_COMMAND_ROW_0_HOME          = 0x80,
    LCD_COMMAND_ROW_1_HOME          = 0xC0,
    LCD_COMMAND_START_UP_1          = 0x33,   
    LCD_COMMAND_START_UP_2          = 0x32 
};
   
/* Private Functions *************************************************/
static void LCD_CarriageReturn ( void ) ;
static void LCD_ShiftCursorLeft ( void ) ;
static void LCD_ShiftCursorRight ( void ) ;
static void LCD_ShiftCursorUp ( void ) ;
static void LCD_ShiftCursorDown ( void ) ;
static void LCD_SendData ( char ) ;
static void LCD_SendCommand ( unsigned int ) ;
static void LCD_DataNibbleWrite(uint8_t value);     

static inline void LCD_D4_Set(bool set)
{
    _TRISD15 = 0; 
    _LATD15 = set;
}

static inline void LCD_D5_Set(bool set)
{
    _TRISF5 = 0; 
    _LATF5 = set;
}

static inline void LCD_D6_Set(bool set)
{
    _TRISF2 = 0; 
    _LATF2 = set;
}

static inline void LCD_D7_Set(bool set)
{
    _TRISF7 = 0; 
    _LATF7 = set;
}

static inline void LCD_RS_Set(bool set)
{
    _TRISG3 = 0; 
    _LATG3 = set;
}

static inline void LCD_Enable_Set(bool set)
{
    _TRISA4 = 0; 
    _LATA4 = set;
}

static inline void LCD_RW_Set(bool set)
{
    _TRISA2 = 0; 
    _LATA2 = set;
}

/* Private variables ************************************************/
static uint8_t row ;
static uint8_t column ;

/*********************************************************************
 * Function: bool LCD_Initialize(void);
 *
 * Overview: Initializes the LCD screen.  Can take several hundred
 *           milliseconds.
 *
 * PreCondition: none
 *
 * Input: None
 *
 * Output: true if initialized, false otherwise
 *
 ********************************************************************/
bool LCD_Initialize ( void )
{            
    LCD_DataNibbleWrite(0);
    
    LCD_RW_Set(0); 
    LCD_RS_Set(0); 
    LCD_Enable_Set(0) ;     
    LCD_Enable_Set(1)  ;
    
    __delay_ms(STARTUP_TIME_MS);
	
    LCD_SendCommand ( LCD_COMMAND_START_UP_1 ) ;
    LCD_SendCommand ( LCD_COMMAND_START_UP_2 ) ;
    
    LCD_SendCommand ( LCD_COMMAND_SET_MODE_4_BIT ) ;
    LCD_SendCommand ( LCD_COMMAND_CURSOR_OFF ) ;
    LCD_SendCommand ( LCD_COMMAND_ENTER_DATA_MODE ) ;

    LCD_ClearScreen ( ) ;

    return true ;
}

/*********************************************************************
 * Function: void LCD_PutString(char* inputString, uint16_t length);
 *
 * Overview: Puts a string on the LCD screen.  Unsupported characters will be
 *           discarded.  May block or throw away characters is LCD is not ready
 *           or buffer space is not available.  Will terminate when either a
 *           null terminator character (0x00) is reached or the length number
 *           of characters is printed, which ever comes first.
 *
 * PreCondition: already initialized via LCD_Initialize()
 *
 * Input: char* - string to print
 *        uint16_t - length of string to print
 *
 * Output: None
 *
 ********************************************************************/
void LCD_PutString ( char* inputString , uint16_t length )
{
    while (length--)
    {
        switch (*inputString)
        {
            case 0x00:
                return ;

            default:
                LCD_PutChar ( *inputString++ ) ;
                break ;
        }
    }
}
/*********************************************************************
 * Function: void LCD_PutChar(char);
 *
 * Overview: Puts a character on the LCD screen.  Unsupported characters will be
 *           discarded.  May block or throw away characters is LCD is not ready
 *           or buffer space is not available.
 *
 * PreCondition: already initialized via LCD_Initialize()
 *
 * Input: char - character to print
 *
 * Output: None
 *
 ********************************************************************/
void LCD_PutChar ( char inputCharacter )
{
    static char lastCharacter = 0;
        
    switch (inputCharacter)
    {
        case '\r':
            if(lastCharacter != '\n')
            {
                LCD_CarriageReturn ( ) ;
            }
            break ;

        case '\n': 
            if(lastCharacter != '\r')
            {
                LCD_CarriageReturn ( ) ;
            }
            
            if (row == 0)
            {
                LCD_ShiftCursorDown ( ) ;
            }
            else
            {
                LCD_ShiftCursorUp ( ) ;
            }
            break ;

        case '\b':
            LCD_ShiftCursorLeft ( ) ;
            LCD_PutChar ( ' ' ) ;
            LCD_ShiftCursorLeft ( ) ;
            break ;
            
        case '\f':
            LCD_ClearScreen();
            break;

        default:
            if (column == LCD_MAX_COLUMN)
            {
                column = 0 ;
                if (row == 0)
                {
                    LCD_SendCommand ( LCD_COMMAND_ROW_1_HOME ) ;
                    row = 1 ;
                }
                else
                {
                    LCD_SendCommand ( LCD_COMMAND_ROW_0_HOME ) ;
                    row = 0 ;
                }
            }
            
            LCD_SendData ( inputCharacter ) ;
            column++ ;
            break ;
    }
    
    lastCharacter = inputCharacter;
}
/*********************************************************************
 * Function: void LCD_ClearScreen(void);
 *
 * Overview: Clears the screen, if possible.
 *
 * PreCondition: already initialized via LCD_Initialize()
 *
 * Input: None
 *
 * Output: None
 *
 ********************************************************************/
void LCD_ClearScreen ( void )
{
    LCD_SendCommand ( LCD_COMMAND_CLEAR_SCREEN ) ;
    LCD_SendCommand ( LCD_COMMAND_RETURN_HOME ) ;

    row = 0 ;
    column = 0 ;
}

/*********************************************************************
 * Function: void LCD_CursorEnable(bool enable)
 *
 * Overview: Enables/disables the cursor
 *
 * PreCondition: None
 *
 * Input: bool - specifies if the cursor should be on or off
 *
 * Output: None
 *
 ********************************************************************/
void LCD_CursorEnable ( bool enable )
{
    if (enable == true)
    {
        LCD_SendCommand ( LCD_COMMAND_CURSOR_ON ) ;
    }
    else
    {
        LCD_SendCommand ( LCD_COMMAND_CURSOR_OFF ) ;
    }
}

/*******************************************************************/
/*******************************************************************/
/* Private Functions ***********************************************/
/*******************************************************************/
/*******************************************************************/
/*********************************************************************
 * Function: static void LCD_CarriageReturn(void)
 *
 * Overview: Handles a carriage return
 *
 * PreCondition: already initialized via LCD_Initialize()
 *
 * Input: None
 *
 * Output: None
 *
 ********************************************************************/
static void LCD_CarriageReturn ( void )
{
    if (row == 0)
    {
        LCD_SendCommand ( LCD_COMMAND_ROW_0_HOME ) ;
    }
    else
    {
        LCD_SendCommand ( LCD_COMMAND_ROW_1_HOME ) ;
    }
    column = 0 ;
}
/*********************************************************************
 * Function: static void LCD_ShiftCursorLeft(void)
 *
 * Overview: Shifts cursor left one spot (wrapping if required)
 *
 * PreCondition: already initialized via LCD_Initialize()
 *
 * Input: None
 *
 * Output: None
 *
 ********************************************************************/
static void LCD_ShiftCursorLeft ( void )
{
    uint8_t i ;

    if (column == 0)
    {
        if (row == 0)
        {
            LCD_SendCommand ( LCD_COMMAND_ROW_1_HOME ) ;
            row = 1 ;
        }
        else
        {
            LCD_SendCommand ( LCD_COMMAND_ROW_0_HOME ) ;
            row = 0 ;
        }

        //Now shift to the end of the row
        for (i = 0 ; i < ( LCD_MAX_COLUMN - 1 ) ; i++)
        {
            LCD_ShiftCursorRight ( ) ;
        }
    }
    else
    {
        column-- ;
        LCD_SendCommand ( LCD_COMMAND_MOVE_CURSOR_LEFT ) ;
    }
}
/*********************************************************************
 * Function: static void LCD_ShiftCursorRight(void)
 *
 * Overview: Shifts cursor right one spot (wrapping if required)
 *
 * PreCondition: already initialized via LCD_Initialize()
 *
 * Input: None
 *
 * Output: None
 *
 ********************************************************************/
static void LCD_ShiftCursorRight ( void )
{
    LCD_SendCommand ( LCD_COMMAND_MOVE_CURSOR_RIGHT ) ;
    column++ ;

    if (column == LCD_MAX_COLUMN)
    {
        column = 0 ;
        if (row == 0)
        {
            LCD_SendCommand ( LCD_COMMAND_ROW_1_HOME ) ;
            row = 1 ;
        }
        else
        {
            LCD_SendCommand ( LCD_COMMAND_ROW_0_HOME ) ;
            row = 0 ;
        }
    }
}
/*********************************************************************
 * Function: static void LCD_ShiftCursorUp(void)
 *
 * Overview: Shifts cursor up one spot (wrapping if required)
 *
 * PreCondition: already initialized via LCD_Initialize()
 *
 * Input: None
 *
 * Output: None
 *
 ********************************************************************/
static void LCD_ShiftCursorUp ( void )
{
    uint8_t i ;

    for (i = 0 ; i < LCD_MAX_COLUMN ; i++)
    {
        LCD_ShiftCursorLeft ( ) ;
    }
}
/*********************************************************************
 * Function: static void LCD_ShiftCursorDown(void)
 *
 * Overview: Shifts cursor down one spot (wrapping if required)
 *
 * PreCondition: already initialized via LCD_Initialize()
 *
 * Input: None
 *
 * Output: None
 *
 ********************************************************************/
static void LCD_ShiftCursorDown ( void )
{
    uint8_t i ;

    for (i = 0 ; i < LCD_MAX_COLUMN ; i++)
    {
        LCD_ShiftCursorRight ( ) ;
    }
}

/*********************************************************************
 * Function: static void SendData(char data)
 *
 * Overview: Sends data to LCD
 *
 * PreCondition: None
 *
 * Input: char - contains the data to be sent to the LCD
 *
 * Output: None
 *
 ********************************************************************/
static void LCD_SendData ( char data )
{
  
    LCD_RW_Set(0) ;
    LCD_RS_Set(1) ;
    
    LCD_DataNibbleWrite(data>>4);
    __delay_us(SIGNAL_TIMING_US);
    LCD_Enable_Set(1) ;
    __delay_us(SIGNAL_TIMING_US);
    
    LCD_Enable_Set(0) ;
    
    LCD_DataNibbleWrite(data);
    __delay_us(SIGNAL_TIMING_US);
    LCD_Enable_Set (1) ;
    __delay_us(SIGNAL_TIMING_US);
    LCD_Enable_Set (0) ;
    
    LCD_RS_Set(0) ;
 
    __delay_us(FAST_INSTRUCTION_TIME_US);
}

/*********************************************************************
 * Function: static void SendCommand(char data)
 *
 * Overview: Sends command to LCD
 *
 * PreCondition: None
 *
 * Input: char - contains the command to be sent to the LCD
 *        unsigned int - has the specific delay for the command
 *
 * Output: None
 *
 ********************************************************************/
static void LCD_SendCommand ( enum COMMAND command )
{       
    LCD_RW_Set(0) ;
    LCD_RS_Set(0) ;
	
    LCD_DataNibbleWrite(command >> 4);
    LCD_Enable_Set(1) ;
    __delay_us(SIGNAL_TIMING_US);
    LCD_Enable_Set(0) ;
    
    LCD_RW_Set(0) ;
    LCD_RS_Set(0) ;
    LCD_DataNibbleWrite(command);
    LCD_Enable_Set(1) ;
    __delay_us(SIGNAL_TIMING_US);
    LCD_Enable_Set(0) ;  
    
    switch(command)
    {
        case LCD_COMMAND_MOVE_CURSOR_LEFT:
        case LCD_COMMAND_MOVE_CURSOR_RIGHT:
        case LCD_COMMAND_SET_MODE_8_BIT:
		case LCD_COMMAND_SET_MODE_4_BIT:
        case LCD_COMMAND_CURSOR_OFF:
            __delay_us(FAST_INSTRUCTION_TIME_US);
            break;
            
        case LCD_COMMAND_ENTER_DATA_MODE:
        case LCD_COMMAND_CLEAR_SCREEN:
        case LCD_COMMAND_RETURN_HOME:
        case LCD_COMMAND_CURSOR_ON:
        case LCD_COMMAND_ROW_0_HOME:
        case LCD_COMMAND_ROW_1_HOME:
        default:
            __delay_us(SLOW_INSTRUCTION_TIME_US);
            break;
    }
    
}

static void LCD_DataNibbleWrite(uint8_t value)
{   
    LCD_D4_Set(value & 0x01);      
    LCD_D5_Set((value >> 1) & 0x01);    
    LCD_D6_Set((value >> 2) & 0x01);
    LCD_D7_Set((value >> 3) & 0x01);
}
