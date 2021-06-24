/**
  UART5 Generated Driver File

  @Company
    Microchip Technology Inc.

  @File Name
    uart5.c

  @Summary
    This is the generated driver implementation file for the UART5 driver using PIC24 / dsPIC33 / PIC32MM MCUs

  @Description
    This header file provides implementations for driver APIs for UART5.
    Generation Information :
        Product Revision  :  PIC24 / dsPIC33 / PIC32MM MCUs - 1.170.0
        Device            :  PIC24FJ512GU410
    The generated drivers are tested against the following:
        Compiler          :  XC16 v1.61
        MPLAB             :  MPLAB X v5.45
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
#include <xc.h>
#include "uart5.h"

/**
  Section: UART5 APIs
*/

void UART5_Initialize(void)
{
/**    
     Set the UART5 module to the options selected in the user interface.
     Make sure to set LAT bit corresponding to TxPin as high before UART initialization
*/
    // STSEL 1; IREN disabled; PDSEL 8N; UARTEN enabled; RTSMD disabled; USIDL disabled; WAKE disabled; ABAUD disabled; LPBACK disabled; BRGH enabled; URXINV disabled; UEN TX_RX; 
    // Data Bits = 8; Parity = None; Stop Bits = 1;
    U5MODE = (0x8008 & ~(1<<15));  // disabling UARTEN bit
    // UTXISEL0 TX_ONE_CHAR; UTXINV disabled; URXEN disabled; OERR NO_ERROR_cleared; URXISEL RX_ONE_CHAR; UTXBRK COMPLETED; UTXEN disabled; ADDEN disabled; 
    U5STA = 0x00;
    // BaudRate = 9600; Frequency = 4000000 Hz; U5BRG 103; 
    U5BRG = 0x67;
    
    U5MODEbits.UARTEN = 1;   // enabling UART ON bit
    U5STAbits.UTXEN = 1;
}

uint8_t UART5_Read(void)
{
    while(!(U5STAbits.URXDA == 1))
    {
        
    }

    if ((U5STAbits.OERR == 1))
    {
        U5STAbits.OERR = 0;
    }
    
    return U5RXREG;
}

void UART5_Write(uint8_t txData)
{
    while(U5STAbits.UTXBF == 1)
    {
        
    }

    U5TXREG = txData;    // Write the data byte to the USART.
}

bool UART5_IsRxReady(void)
{
    return U5STAbits.URXDA;
}

bool UART5_IsTxReady(void)
{
    return ((!U5STAbits.UTXBF) && U5STAbits.UTXEN );
}

bool UART5_IsTxDone(void)
{
    return U5STAbits.TRMT;
}


/*******************************************************************************

  !!! Deprecated API !!!
  !!! These functions will not be supported in future releases !!!

*******************************************************************************/

uint16_t __attribute__((deprecated)) UART5_StatusGet (void)
{
    return U5STA;
}

void __attribute__((deprecated)) UART5_Enable(void)
{
    U5MODEbits.UARTEN = 1;
    U5STAbits.UTXEN = 1;
}

void __attribute__((deprecated)) UART5_Disable(void)
{
    U5MODEbits.UARTEN = 0;
    U5STAbits.UTXEN = 0;
}
