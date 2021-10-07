/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using MPLAB(c) Code Configurator

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  MPLAB(c) Code Configurator - 3.15.0
        Device            :  PIC18F4550
        Driver Version    :  2.00
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.35
        MPLAB             :  MPLAB X 3.20
*/

/*
    (c) 2016 Microchip Technology Inc. and its subsidiaries. You may use this
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

#include "mcc.h"
#include "stdio.h"
#include "stdlib.h"
#include <xlcd.h>

/*
                         Main application
 */

#define song_A  PORTBbits.RB7
#define song_B  PORTBbits.RB6
#define song_C  PORTBbits.RB5

#define A4      35
#define As4     33
#define B4      31
#define C4      59
#define Cs4     55
#define D4      52
#define Ds4     49
#define E4      46
#define F4      44
#define Fs4     41
#define G4      39
#define Gs4     37

void pause(void);
void tone(int valTMR2);
void melody1(void);

void pause(){
    __delay_ms(250);
    TMR2_StopTimer();
    __delay_ms(250);
}

void tone(int valTMR2){
    TMR2_StartTimer();
    PR2 = valTMR2; 
    pause();
}

void melody1(){
    tone(C4);
    tone(C4);
    tone(G4);
    tone(G4);
    tone(A4);
    tone(A4);
    tone(G4);
    pause();
    tone(F4);
    tone(F4);
    tone(E4);
    tone(E4);
    tone(D4);
    tone(D4);
    tone(C4);
    pause();
    tone(G4);
    tone(G4);
    tone(F4);
    tone(F4);
    tone(E4);
    tone(E4);
    tone(D4);
    pause();
    tone(G4);
    tone(G4);
    tone(F4);
    tone(F4);
    tone(E4);
    tone(E4);
    tone(D4);
    tone(C4);
    tone(C4);
    tone(G4);
    tone(G4);
    tone(A4);
    tone(A4);
    tone(G4);
    pause();
    tone(F4);
    tone(F4);
    tone(E4);
    tone(E4);
    tone(D4);
    tone(D4);
    tone(C4);
    pause();
}



void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();
    
    
    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();
    
    //period of 100 us and duty cycle of 50 us
    
    
    while (1)
    {
        //if(song_A) melody1();
        /*switch(Timer2_State){
            case State_1:   Timer2_State = State_2;
            PR2 = 149;
            __delay_ms(500);
            break;
            case State_2:   Timer2_State = State_1;
            PR2 = 238;
            __delay_ms(500);
            break;
            default:        Timer2_State = State_1;
        }*/
        
    }
}

/**
 End of File
*/