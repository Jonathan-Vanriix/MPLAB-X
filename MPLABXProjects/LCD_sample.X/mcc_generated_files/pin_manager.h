/**
  PIN MANAGER Generated Driver File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the generated manager file for the PIC24 / dsPIC33 / PIC32MM MCUs device.  This manager
    configures the pins direction, initial state, analog setting.
    The peripheral pin select, PPS, configuration is also handled by this manager.

  @Description:
    This source file provides implementations for PIN MANAGER.
    Generation Information :
        Product Revision  :  PIC24 / dsPIC33 / PIC32MM MCUs - 1.170.0
        Device            :  PIC24FJ512GU410
    The generated drivers are tested against the following:
        Compiler          :  XC16 v1.61
        MPLAB 	          :  MPLAB X v5.45
*/

/*
    (c) 2020 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/

#ifndef _PIN_MANAGER_H
#define _PIN_MANAGER_H
/**
    Section: Includes
*/
#include <xc.h>

/**
    Section: Device Pin Macros
*/
/**
  @Summary
    Sets the GPIO pin, RA10, high using LATA10.

  @Description
    Sets the GPIO pin, RA10, high using LATA10.

  @Preconditions
    The RA10 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RA10 high (1)
    Y2_SetHigh();
    </code>

*/
#define Y2_SetHigh()          (_LATA10 = 1)
/**
  @Summary
    Sets the GPIO pin, RA10, low using LATA10.

  @Description
    Sets the GPIO pin, RA10, low using LATA10.

  @Preconditions
    The RA10 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RA10 low (0)
    Y2_SetLow();
    </code>

*/
#define Y2_SetLow()           (_LATA10 = 0)
/**
  @Summary
    Toggles the GPIO pin, RA10, using LATA10.

  @Description
    Toggles the GPIO pin, RA10, using LATA10.

  @Preconditions
    The RA10 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RA10
    Y2_Toggle();
    </code>

*/
#define Y2_Toggle()           (_LATA10 ^= 1)
/**
  @Summary
    Reads the value of the GPIO pin, RA10.

  @Description
    Reads the value of the GPIO pin, RA10.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RA10
    postValue = Y2_GetValue();
    </code>

*/
#define Y2_GetValue()         _RA10
/**
  @Summary
    Configures the GPIO pin, RA10, as an input.

  @Description
    Configures the GPIO pin, RA10, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RA10 as an input
    Y2_SetDigitalInput();
    </code>

*/
#define Y2_SetDigitalInput()  (_TRISA10 = 1)
/**
  @Summary
    Configures the GPIO pin, RA10, as an output.

  @Description
    Configures the GPIO pin, RA10, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RA10 as an output
    Y2_SetDigitalOutput();
    </code>

*/
#define Y2_SetDigitalOutput() (_TRISA10 = 0)
/**
  @Summary
    Sets the GPIO pin, RA2, high using LATA2.

  @Description
    Sets the GPIO pin, RA2, high using LATA2.

  @Preconditions
    The RA2 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RA2 high (1)
    LCD_RW_SetHigh();
    </code>

*/
#define LCD_RW_SetHigh()          (_LATA2 = 1)
/**
  @Summary
    Sets the GPIO pin, RA2, low using LATA2.

  @Description
    Sets the GPIO pin, RA2, low using LATA2.

  @Preconditions
    The RA2 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RA2 low (0)
    LCD_RW_SetLow();
    </code>

*/
#define LCD_RW_SetLow()           (_LATA2 = 0)
/**
  @Summary
    Toggles the GPIO pin, RA2, using LATA2.

  @Description
    Toggles the GPIO pin, RA2, using LATA2.

  @Preconditions
    The RA2 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RA2
    LCD_RW_Toggle();
    </code>

*/
#define LCD_RW_Toggle()           (_LATA2 ^= 1)
/**
  @Summary
    Reads the value of the GPIO pin, RA2.

  @Description
    Reads the value of the GPIO pin, RA2.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RA2
    postValue = LCD_RW_GetValue();
    </code>

*/
#define LCD_RW_GetValue()         _RA2
/**
  @Summary
    Configures the GPIO pin, RA2, as an input.

  @Description
    Configures the GPIO pin, RA2, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RA2 as an input
    LCD_RW_SetDigitalInput();
    </code>

*/
#define LCD_RW_SetDigitalInput()  (_TRISA2 = 1)
/**
  @Summary
    Configures the GPIO pin, RA2, as an output.

  @Description
    Configures the GPIO pin, RA2, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RA2 as an output
    LCD_RW_SetDigitalOutput();
    </code>

*/
#define LCD_RW_SetDigitalOutput() (_TRISA2 = 0)
/**
  @Summary
    Sets the GPIO pin, RA4, high using LATA4.

  @Description
    Sets the GPIO pin, RA4, high using LATA4.

  @Preconditions
    The RA4 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RA4 high (1)
    LCD_E_SetHigh();
    </code>

*/
#define LCD_E_SetHigh()          (_LATA4 = 1)
/**
  @Summary
    Sets the GPIO pin, RA4, low using LATA4.

  @Description
    Sets the GPIO pin, RA4, low using LATA4.

  @Preconditions
    The RA4 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RA4 low (0)
    LCD_E_SetLow();
    </code>

*/
#define LCD_E_SetLow()           (_LATA4 = 0)
/**
  @Summary
    Toggles the GPIO pin, RA4, using LATA4.

  @Description
    Toggles the GPIO pin, RA4, using LATA4.

  @Preconditions
    The RA4 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RA4
    LCD_E_Toggle();
    </code>

*/
#define LCD_E_Toggle()           (_LATA4 ^= 1)
/**
  @Summary
    Reads the value of the GPIO pin, RA4.

  @Description
    Reads the value of the GPIO pin, RA4.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RA4
    postValue = LCD_E_GetValue();
    </code>

*/
#define LCD_E_GetValue()         _RA4
/**
  @Summary
    Configures the GPIO pin, RA4, as an input.

  @Description
    Configures the GPIO pin, RA4, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RA4 as an input
    LCD_E_SetDigitalInput();
    </code>

*/
#define LCD_E_SetDigitalInput()  (_TRISA4 = 1)
/**
  @Summary
    Configures the GPIO pin, RA4, as an output.

  @Description
    Configures the GPIO pin, RA4, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RA4 as an output
    LCD_E_SetDigitalOutput();
    </code>

*/
#define LCD_E_SetDigitalOutput() (_TRISA4 = 0)
/**
  @Summary
    Sets the GPIO pin, RA9, high using LATA9.

  @Description
    Sets the GPIO pin, RA9, high using LATA9.

  @Preconditions
    The RA9 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RA9 high (1)
    X2_SetHigh();
    </code>

*/
#define X2_SetHigh()          (_LATA9 = 1)
/**
  @Summary
    Sets the GPIO pin, RA9, low using LATA9.

  @Description
    Sets the GPIO pin, RA9, low using LATA9.

  @Preconditions
    The RA9 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RA9 low (0)
    X2_SetLow();
    </code>

*/
#define X2_SetLow()           (_LATA9 = 0)
/**
  @Summary
    Toggles the GPIO pin, RA9, using LATA9.

  @Description
    Toggles the GPIO pin, RA9, using LATA9.

  @Preconditions
    The RA9 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RA9
    X2_Toggle();
    </code>

*/
#define X2_Toggle()           (_LATA9 ^= 1)
/**
  @Summary
    Reads the value of the GPIO pin, RA9.

  @Description
    Reads the value of the GPIO pin, RA9.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RA9
    postValue = X2_GetValue();
    </code>

*/
#define X2_GetValue()         _RA9
/**
  @Summary
    Configures the GPIO pin, RA9, as an input.

  @Description
    Configures the GPIO pin, RA9, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RA9 as an input
    X2_SetDigitalInput();
    </code>

*/
#define X2_SetDigitalInput()  (_TRISA9 = 1)
/**
  @Summary
    Configures the GPIO pin, RA9, as an output.

  @Description
    Configures the GPIO pin, RA9, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RA9 as an output
    X2_SetDigitalOutput();
    </code>

*/
#define X2_SetDigitalOutput() (_TRISA9 = 0)
/**
  @Summary
    Sets the GPIO pin, RB10, high using LATB10.

  @Description
    Sets the GPIO pin, RB10, high using LATB10.

  @Preconditions
    The RB10 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB10 high (1)
    X4_SetHigh();
    </code>

*/
#define X4_SetHigh()          (_LATB10 = 1)
/**
  @Summary
    Sets the GPIO pin, RB10, low using LATB10.

  @Description
    Sets the GPIO pin, RB10, low using LATB10.

  @Preconditions
    The RB10 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB10 low (0)
    X4_SetLow();
    </code>

*/
#define X4_SetLow()           (_LATB10 = 0)
/**
  @Summary
    Toggles the GPIO pin, RB10, using LATB10.

  @Description
    Toggles the GPIO pin, RB10, using LATB10.

  @Preconditions
    The RB10 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RB10
    X4_Toggle();
    </code>

*/
#define X4_Toggle()           (_LATB10 ^= 1)
/**
  @Summary
    Reads the value of the GPIO pin, RB10.

  @Description
    Reads the value of the GPIO pin, RB10.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RB10
    postValue = X4_GetValue();
    </code>

*/
#define X4_GetValue()         _RB10
/**
  @Summary
    Configures the GPIO pin, RB10, as an input.

  @Description
    Configures the GPIO pin, RB10, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB10 as an input
    X4_SetDigitalInput();
    </code>

*/
#define X4_SetDigitalInput()  (_TRISB10 = 1)
/**
  @Summary
    Configures the GPIO pin, RB10, as an output.

  @Description
    Configures the GPIO pin, RB10, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB10 as an output
    X4_SetDigitalOutput();
    </code>

*/
#define X4_SetDigitalOutput() (_TRISB10 = 0)
/**
  @Summary
    Sets the GPIO pin, RB11, high using LATB11.

  @Description
    Sets the GPIO pin, RB11, high using LATB11.

  @Preconditions
    The RB11 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB11 high (1)
    Y4_SetHigh();
    </code>

*/
#define Y4_SetHigh()          (_LATB11 = 1)
/**
  @Summary
    Sets the GPIO pin, RB11, low using LATB11.

  @Description
    Sets the GPIO pin, RB11, low using LATB11.

  @Preconditions
    The RB11 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB11 low (0)
    Y4_SetLow();
    </code>

*/
#define Y4_SetLow()           (_LATB11 = 0)
/**
  @Summary
    Toggles the GPIO pin, RB11, using LATB11.

  @Description
    Toggles the GPIO pin, RB11, using LATB11.

  @Preconditions
    The RB11 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RB11
    Y4_Toggle();
    </code>

*/
#define Y4_Toggle()           (_LATB11 ^= 1)
/**
  @Summary
    Reads the value of the GPIO pin, RB11.

  @Description
    Reads the value of the GPIO pin, RB11.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RB11
    postValue = Y4_GetValue();
    </code>

*/
#define Y4_GetValue()         _RB11
/**
  @Summary
    Configures the GPIO pin, RB11, as an input.

  @Description
    Configures the GPIO pin, RB11, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB11 as an input
    Y4_SetDigitalInput();
    </code>

*/
#define Y4_SetDigitalInput()  (_TRISB11 = 1)
/**
  @Summary
    Configures the GPIO pin, RB11, as an output.

  @Description
    Configures the GPIO pin, RB11, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB11 as an output
    Y4_SetDigitalOutput();
    </code>

*/
#define Y4_SetDigitalOutput() (_TRISB11 = 0)
/**
  @Summary
    Sets the GPIO pin, RB3, high using LATB3.

  @Description
    Sets the GPIO pin, RB3, high using LATB3.

  @Preconditions
    The RB3 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB3 high (1)
    X1_SetHigh();
    </code>

*/
#define X1_SetHigh()          (_LATB3 = 1)
/**
  @Summary
    Sets the GPIO pin, RB3, low using LATB3.

  @Description
    Sets the GPIO pin, RB3, low using LATB3.

  @Preconditions
    The RB3 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB3 low (0)
    X1_SetLow();
    </code>

*/
#define X1_SetLow()           (_LATB3 = 0)
/**
  @Summary
    Toggles the GPIO pin, RB3, using LATB3.

  @Description
    Toggles the GPIO pin, RB3, using LATB3.

  @Preconditions
    The RB3 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RB3
    X1_Toggle();
    </code>

*/
#define X1_Toggle()           (_LATB3 ^= 1)
/**
  @Summary
    Reads the value of the GPIO pin, RB3.

  @Description
    Reads the value of the GPIO pin, RB3.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RB3
    postValue = X1_GetValue();
    </code>

*/
#define X1_GetValue()         _RB3
/**
  @Summary
    Configures the GPIO pin, RB3, as an input.

  @Description
    Configures the GPIO pin, RB3, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB3 as an input
    X1_SetDigitalInput();
    </code>

*/
#define X1_SetDigitalInput()  (_TRISB3 = 1)
/**
  @Summary
    Configures the GPIO pin, RB3, as an output.

  @Description
    Configures the GPIO pin, RB3, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB3 as an output
    X1_SetDigitalOutput();
    </code>

*/
#define X1_SetDigitalOutput() (_TRISB3 = 0)
/**
  @Summary
    Sets the GPIO pin, RB7, high using LATB7.

  @Description
    Sets the GPIO pin, RB7, high using LATB7.

  @Preconditions
    The RB7 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB7 high (1)
    Y1_SetHigh();
    </code>

*/
#define Y1_SetHigh()          (_LATB7 = 1)
/**
  @Summary
    Sets the GPIO pin, RB7, low using LATB7.

  @Description
    Sets the GPIO pin, RB7, low using LATB7.

  @Preconditions
    The RB7 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB7 low (0)
    Y1_SetLow();
    </code>

*/
#define Y1_SetLow()           (_LATB7 = 0)
/**
  @Summary
    Toggles the GPIO pin, RB7, using LATB7.

  @Description
    Toggles the GPIO pin, RB7, using LATB7.

  @Preconditions
    The RB7 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RB7
    Y1_Toggle();
    </code>

*/
#define Y1_Toggle()           (_LATB7 ^= 1)
/**
  @Summary
    Reads the value of the GPIO pin, RB7.

  @Description
    Reads the value of the GPIO pin, RB7.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RB7
    postValue = Y1_GetValue();
    </code>

*/
#define Y1_GetValue()         _RB7
/**
  @Summary
    Configures the GPIO pin, RB7, as an input.

  @Description
    Configures the GPIO pin, RB7, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB7 as an input
    Y1_SetDigitalInput();
    </code>

*/
#define Y1_SetDigitalInput()  (_TRISB7 = 1)
/**
  @Summary
    Configures the GPIO pin, RB7, as an output.

  @Description
    Configures the GPIO pin, RB7, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB7 as an output
    Y1_SetDigitalOutput();
    </code>

*/
#define Y1_SetDigitalOutput() (_TRISB7 = 0)
/**
  @Summary
    Sets the GPIO pin, RB8, high using LATB8.

  @Description
    Sets the GPIO pin, RB8, high using LATB8.

  @Preconditions
    The RB8 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB8 high (1)
    X3_SetHigh();
    </code>

*/
#define X3_SetHigh()          (_LATB8 = 1)
/**
  @Summary
    Sets the GPIO pin, RB8, low using LATB8.

  @Description
    Sets the GPIO pin, RB8, low using LATB8.

  @Preconditions
    The RB8 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB8 low (0)
    X3_SetLow();
    </code>

*/
#define X3_SetLow()           (_LATB8 = 0)
/**
  @Summary
    Toggles the GPIO pin, RB8, using LATB8.

  @Description
    Toggles the GPIO pin, RB8, using LATB8.

  @Preconditions
    The RB8 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RB8
    X3_Toggle();
    </code>

*/
#define X3_Toggle()           (_LATB8 ^= 1)
/**
  @Summary
    Reads the value of the GPIO pin, RB8.

  @Description
    Reads the value of the GPIO pin, RB8.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RB8
    postValue = X3_GetValue();
    </code>

*/
#define X3_GetValue()         _RB8
/**
  @Summary
    Configures the GPIO pin, RB8, as an input.

  @Description
    Configures the GPIO pin, RB8, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB8 as an input
    X3_SetDigitalInput();
    </code>

*/
#define X3_SetDigitalInput()  (_TRISB8 = 1)
/**
  @Summary
    Configures the GPIO pin, RB8, as an output.

  @Description
    Configures the GPIO pin, RB8, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB8 as an output
    X3_SetDigitalOutput();
    </code>

*/
#define X3_SetDigitalOutput() (_TRISB8 = 0)
/**
  @Summary
    Sets the GPIO pin, RB9, high using LATB9.

  @Description
    Sets the GPIO pin, RB9, high using LATB9.

  @Preconditions
    The RB9 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB9 high (1)
    Y3_SetHigh();
    </code>

*/
#define Y3_SetHigh()          (_LATB9 = 1)
/**
  @Summary
    Sets the GPIO pin, RB9, low using LATB9.

  @Description
    Sets the GPIO pin, RB9, low using LATB9.

  @Preconditions
    The RB9 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB9 low (0)
    Y3_SetLow();
    </code>

*/
#define Y3_SetLow()           (_LATB9 = 0)
/**
  @Summary
    Toggles the GPIO pin, RB9, using LATB9.

  @Description
    Toggles the GPIO pin, RB9, using LATB9.

  @Preconditions
    The RB9 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RB9
    Y3_Toggle();
    </code>

*/
#define Y3_Toggle()           (_LATB9 ^= 1)
/**
  @Summary
    Reads the value of the GPIO pin, RB9.

  @Description
    Reads the value of the GPIO pin, RB9.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RB9
    postValue = Y3_GetValue();
    </code>

*/
#define Y3_GetValue()         _RB9
/**
  @Summary
    Configures the GPIO pin, RB9, as an input.

  @Description
    Configures the GPIO pin, RB9, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB9 as an input
    Y3_SetDigitalInput();
    </code>

*/
#define Y3_SetDigitalInput()  (_TRISB9 = 1)
/**
  @Summary
    Configures the GPIO pin, RB9, as an output.

  @Description
    Configures the GPIO pin, RB9, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB9 as an output
    Y3_SetDigitalOutput();
    </code>

*/
#define Y3_SetDigitalOutput() (_TRISB9 = 0)
/**
  @Summary
    Sets the GPIO pin, RD15, high using LATD15.

  @Description
    Sets the GPIO pin, RD15, high using LATD15.

  @Preconditions
    The RD15 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RD15 high (1)
    LCD_D4_SetHigh();
    </code>

*/
#define LCD_D4_SetHigh()          (_LATD15 = 1)
/**
  @Summary
    Sets the GPIO pin, RD15, low using LATD15.

  @Description
    Sets the GPIO pin, RD15, low using LATD15.

  @Preconditions
    The RD15 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RD15 low (0)
    LCD_D4_SetLow();
    </code>

*/
#define LCD_D4_SetLow()           (_LATD15 = 0)
/**
  @Summary
    Toggles the GPIO pin, RD15, using LATD15.

  @Description
    Toggles the GPIO pin, RD15, using LATD15.

  @Preconditions
    The RD15 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RD15
    LCD_D4_Toggle();
    </code>

*/
#define LCD_D4_Toggle()           (_LATD15 ^= 1)
/**
  @Summary
    Reads the value of the GPIO pin, RD15.

  @Description
    Reads the value of the GPIO pin, RD15.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RD15
    postValue = LCD_D4_GetValue();
    </code>

*/
#define LCD_D4_GetValue()         _RD15
/**
  @Summary
    Configures the GPIO pin, RD15, as an input.

  @Description
    Configures the GPIO pin, RD15, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RD15 as an input
    LCD_D4_SetDigitalInput();
    </code>

*/
#define LCD_D4_SetDigitalInput()  (_TRISD15 = 1)
/**
  @Summary
    Configures the GPIO pin, RD15, as an output.

  @Description
    Configures the GPIO pin, RD15, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RD15 as an output
    LCD_D4_SetDigitalOutput();
    </code>

*/
#define LCD_D4_SetDigitalOutput() (_TRISD15 = 0)
/**
  @Summary
    Sets the GPIO pin, RF2, high using LATF2.

  @Description
    Sets the GPIO pin, RF2, high using LATF2.

  @Preconditions
    The RF2 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RF2 high (1)
    LCD_D6_SetHigh();
    </code>

*/
#define LCD_D6_SetHigh()          (_LATF2 = 1)
/**
  @Summary
    Sets the GPIO pin, RF2, low using LATF2.

  @Description
    Sets the GPIO pin, RF2, low using LATF2.

  @Preconditions
    The RF2 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RF2 low (0)
    LCD_D6_SetLow();
    </code>

*/
#define LCD_D6_SetLow()           (_LATF2 = 0)
/**
  @Summary
    Toggles the GPIO pin, RF2, using LATF2.

  @Description
    Toggles the GPIO pin, RF2, using LATF2.

  @Preconditions
    The RF2 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RF2
    LCD_D6_Toggle();
    </code>

*/
#define LCD_D6_Toggle()           (_LATF2 ^= 1)
/**
  @Summary
    Reads the value of the GPIO pin, RF2.

  @Description
    Reads the value of the GPIO pin, RF2.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RF2
    postValue = LCD_D6_GetValue();
    </code>

*/
#define LCD_D6_GetValue()         _RF2
/**
  @Summary
    Configures the GPIO pin, RF2, as an input.

  @Description
    Configures the GPIO pin, RF2, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RF2 as an input
    LCD_D6_SetDigitalInput();
    </code>

*/
#define LCD_D6_SetDigitalInput()  (_TRISF2 = 1)
/**
  @Summary
    Configures the GPIO pin, RF2, as an output.

  @Description
    Configures the GPIO pin, RF2, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RF2 as an output
    LCD_D6_SetDigitalOutput();
    </code>

*/
#define LCD_D6_SetDigitalOutput() (_TRISF2 = 0)
/**
  @Summary
    Sets the GPIO pin, RF5, high using LATF5.

  @Description
    Sets the GPIO pin, RF5, high using LATF5.

  @Preconditions
    The RF5 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RF5 high (1)
    LCD_D5_SetHigh();
    </code>

*/
#define LCD_D5_SetHigh()          (_LATF5 = 1)
/**
  @Summary
    Sets the GPIO pin, RF5, low using LATF5.

  @Description
    Sets the GPIO pin, RF5, low using LATF5.

  @Preconditions
    The RF5 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RF5 low (0)
    LCD_D5_SetLow();
    </code>

*/
#define LCD_D5_SetLow()           (_LATF5 = 0)
/**
  @Summary
    Toggles the GPIO pin, RF5, using LATF5.

  @Description
    Toggles the GPIO pin, RF5, using LATF5.

  @Preconditions
    The RF5 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RF5
    LCD_D5_Toggle();
    </code>

*/
#define LCD_D5_Toggle()           (_LATF5 ^= 1)
/**
  @Summary
    Reads the value of the GPIO pin, RF5.

  @Description
    Reads the value of the GPIO pin, RF5.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RF5
    postValue = LCD_D5_GetValue();
    </code>

*/
#define LCD_D5_GetValue()         _RF5
/**
  @Summary
    Configures the GPIO pin, RF5, as an input.

  @Description
    Configures the GPIO pin, RF5, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RF5 as an input
    LCD_D5_SetDigitalInput();
    </code>

*/
#define LCD_D5_SetDigitalInput()  (_TRISF5 = 1)
/**
  @Summary
    Configures the GPIO pin, RF5, as an output.

  @Description
    Configures the GPIO pin, RF5, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RF5 as an output
    LCD_D5_SetDigitalOutput();
    </code>

*/
#define LCD_D5_SetDigitalOutput() (_TRISF5 = 0)
/**
  @Summary
    Sets the GPIO pin, RF7, high using LATF7.

  @Description
    Sets the GPIO pin, RF7, high using LATF7.

  @Preconditions
    The RF7 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RF7 high (1)
    LCD_D7_SetHigh();
    </code>

*/
#define LCD_D7_SetHigh()          (_LATF7 = 1)
/**
  @Summary
    Sets the GPIO pin, RF7, low using LATF7.

  @Description
    Sets the GPIO pin, RF7, low using LATF7.

  @Preconditions
    The RF7 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RF7 low (0)
    LCD_D7_SetLow();
    </code>

*/
#define LCD_D7_SetLow()           (_LATF7 = 0)
/**
  @Summary
    Toggles the GPIO pin, RF7, using LATF7.

  @Description
    Toggles the GPIO pin, RF7, using LATF7.

  @Preconditions
    The RF7 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RF7
    LCD_D7_Toggle();
    </code>

*/
#define LCD_D7_Toggle()           (_LATF7 ^= 1)
/**
  @Summary
    Reads the value of the GPIO pin, RF7.

  @Description
    Reads the value of the GPIO pin, RF7.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RF7
    postValue = LCD_D7_GetValue();
    </code>

*/
#define LCD_D7_GetValue()         _RF7
/**
  @Summary
    Configures the GPIO pin, RF7, as an input.

  @Description
    Configures the GPIO pin, RF7, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RF7 as an input
    LCD_D7_SetDigitalInput();
    </code>

*/
#define LCD_D7_SetDigitalInput()  (_TRISF7 = 1)
/**
  @Summary
    Configures the GPIO pin, RF7, as an output.

  @Description
    Configures the GPIO pin, RF7, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RF7 as an output
    LCD_D7_SetDigitalOutput();
    </code>

*/
#define LCD_D7_SetDigitalOutput() (_TRISF7 = 0)
/**
  @Summary
    Sets the GPIO pin, RG3, high using LATG3.

  @Description
    Sets the GPIO pin, RG3, high using LATG3.

  @Preconditions
    The RG3 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RG3 high (1)
    LCD_RS_SetHigh();
    </code>

*/
#define LCD_RS_SetHigh()          (_LATG3 = 1)
/**
  @Summary
    Sets the GPIO pin, RG3, low using LATG3.

  @Description
    Sets the GPIO pin, RG3, low using LATG3.

  @Preconditions
    The RG3 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RG3 low (0)
    LCD_RS_SetLow();
    </code>

*/
#define LCD_RS_SetLow()           (_LATG3 = 0)
/**
  @Summary
    Toggles the GPIO pin, RG3, using LATG3.

  @Description
    Toggles the GPIO pin, RG3, using LATG3.

  @Preconditions
    The RG3 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RG3
    LCD_RS_Toggle();
    </code>

*/
#define LCD_RS_Toggle()           (_LATG3 ^= 1)
/**
  @Summary
    Reads the value of the GPIO pin, RG3.

  @Description
    Reads the value of the GPIO pin, RG3.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RG3
    postValue = LCD_RS_GetValue();
    </code>

*/
#define LCD_RS_GetValue()         _RG3
/**
  @Summary
    Configures the GPIO pin, RG3, as an input.

  @Description
    Configures the GPIO pin, RG3, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RG3 as an input
    LCD_RS_SetDigitalInput();
    </code>

*/
#define LCD_RS_SetDigitalInput()  (_TRISG3 = 1)
/**
  @Summary
    Configures the GPIO pin, RG3, as an output.

  @Description
    Configures the GPIO pin, RG3, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RG3 as an output
    LCD_RS_SetDigitalOutput();
    </code>

*/
#define LCD_RS_SetDigitalOutput() (_TRISG3 = 0)

/**
    Section: Function Prototypes
*/
/**
  @Summary
    Configures the pin settings of the PIC24FJ512GU410
    The peripheral pin select, PPS, configuration is also handled by this manager.

  @Description
    This is the generated manager file for the PIC24 / dsPIC33 / PIC32MM MCUs device.  This manager
    configures the pins direction, initial state, analog setting.
    The peripheral pin select, PPS, configuration is also handled by this manager.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    void SYSTEM_Initialize(void)
    {
        // Other initializers are called from this function
        PIN_MANAGER_Initialize();
    }
    </code>

*/
void PIN_MANAGER_Initialize (void);



#endif
