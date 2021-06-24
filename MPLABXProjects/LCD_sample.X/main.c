/**
  Generated main.c file from MPLAB Code Configurator

  @Company
    Microchip Technology Inc.

  @File Name
    main.c

  @Summary
    This is the generated main.c using PIC24 / dsPIC33 / PIC32MM MCUs.

  @Description
    This source file provides main entry point for system initialization and application code development.
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

/**
  Section: Included Files
*/
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
#include "mcc_generated_files/system.h"
#include "mcc_generated_files/pin_manager.h"
#include "mcc_generated_files/lcd.h"
#include "stdio.h"
#include <string.h>

/*
                         Main application
 */
//unsigned char keypad[4][4]= {'1','2','3','A'}, 
//                            {'4','5','6','B'},
//                            {'7','8','9','C'},
//                            {'#','0','*','D'};
//                            

void SetX1ToHigh(void)
{
    X1_SetHigh();
    X2_SetLow();
    X3_SetLow();
    X4_SetLow();
}

void SetX2ToHigh(void)
{
    X1_SetLow();
    X2_SetHigh();
    X3_SetLow();
    X4_SetLow();
}

void SetX3ToHigh(void)
{
    X1_SetLow();
    X2_SetLow();
    X3_SetHigh();
    X4_SetLow();
}

void SetX4ToHigh()
{
    X1_SetLow();
    X2_SetLow();
    X3_SetLow();
    X4_SetHigh();
}

void Display(char *i)
{
    char output[] =  "Press the Keypad\n";//    sprintf(output,"%s%s","Press the Keypad\n", i);
    strcat(output,i);
    LCD_ClearScreen();
    LCD_PutString(output,20);
}

char key[16][2] = {
                "1", "2", "3", "A",
                "4", "5", "6", "B",
                "7", "8", "9", "C",
                "*", "0", "#", "D"};
void KeypadScanner(void)  
{       
    SetX1ToHigh();
    if(Y1_GetValue() == 1) {  Display(key[0]); }
    if(Y2_GetValue() == 1) {  Display(key[1]); }
    if(Y3_GetValue() == 1) {  Display(key[2]); }
    if(Y4_GetValue() == 1) {  Display(key[3]); }
    
    SetX2ToHigh();
    if(Y1_GetValue() == 1) { Display(key[4]); }
    if(Y2_GetValue() == 1) { Display(key[5]); }
    if(Y3_GetValue() == 1) { Display(key[6]); }
    if(Y4_GetValue() == 1) { Display(key[7]); }
    
    SetX3ToHigh();
    if(Y1_GetValue() == 1) { Display(key[8]); }
    if(Y2_GetValue() == 1) { Display(key[9]); }
    if(Y3_GetValue() == 1) { Display(key[10]); }
    if(Y4_GetValue() == 1) { Display(key[11]); }
    
    SetX4ToHigh();
    if(Y1_GetValue() == 1) { Display(key[12]); }
    if(Y2_GetValue() == 1) { Display(key[13]); }
    if(Y3_GetValue() == 1) { Display(key[14]); }
    if(Y4_GetValue() == 1) { Display(key[15]); }
         
}

int main(void)
{
    
    char num[20];
    
    // initialize the device
    SYSTEM_Initialize();
    LCD_Initialize();

    LCD_ClearScreen();
    LCD_PutString("Press the Keypad",20);
    
    while (1)
    { 

        KeypadScanner();
        
    }

    return 1;
}



