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

#define A4      70
#define As4     66
#define B4      62
#define C4      118
#define Cs4     112
#define D4      105
#define Ds4     99
#define E4      94
#define F4      88
#define Fs4     83
#define G4      79
#define Gs4     74

#define A5      17
#define As5     16
#define B5      15
#define C5      29
#define Cs5     27
#define D5      26
#define Ds5     24
#define E5      23
#define F5      21
#define Fs5     20
#define G5      19
#define Gs5     18
int baseTime;

void modulePause(int multiple);
void pause(void);
void tone(int valTMR2);
void tone_2Pressed(int valTMR2);
void tone_3Pressed(int valTMR2);
void tone(int valTMR2);
void melody1(void);
void melody2(void);
void melody3(void);


void modulePause(int multiple){
    baseTime = 300;
    TMR0_StartTimer();
    TMR0_Write8bitTimer(50);
    while(Timer0_Counter <= baseTime * 10){
        if(INTCONbits.TMR0IF == 1){
            TMR0_Write8bitTimer(50);
        } 
    }
    if(Timer0_Counter == 3000) Timer0_Counter = 0;
    TMR0_StopTimer();
}

void pause(){
    modulePause(1);
    TMR2_StopTimer();
    modulePause(1);
}

void tone(int valTMR2){
    TMR2_StartTimer();
    PR2 = valTMR2; 
    pause();
}

void tone_2Pressed(int valTMR2){
    TMR2_StartTimer();
    PR2 = valTMR2;
    __delay_ms(500);
    TMR2_StopTimer();
    __delay_ms(250);
}

void tone_3Pressed(int valTMR2){
    TMR2_StartTimer();
    PR2 = valTMR2;
    __delay_ms(750);
    TMR2_StopTimer();
    __delay_ms(250);
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

void melody2(){
    tone_2Pressed(G4);
    tone(A4);
    tone_2Pressed(G4);
    tone_3Pressed(E4);
    pause();
    tone_2Pressed(G4);
    tone(A4);
    tone_2Pressed(G4);
    tone_3Pressed(E4);
    pause();
    tone_2Pressed(D5);
    tone(D5);
    tone_3Pressed(B4);
    tone_2Pressed(C5);
    tone(C5);
    tone_3Pressed(G4);
    pause();
    tone_2Pressed(A4);
    tone(A4);
    tone_2Pressed(C5);
    tone(B4);
    tone(A4);
    tone_2Pressed(G4);
    tone(A4);
    tone_2Pressed(G4);
    tone_3Pressed(E4);
    tone_2Pressed(A4);
    tone(A4);
    tone_2Pressed(C5);
    tone(B4);
    tone(A4);
    tone_2Pressed(G4);
    tone(A4);
    tone_2Pressed(G4);
    tone_3Pressed(E4);
    pause();
    tone_2Pressed(D5);
    tone(D5);
    tone_2Pressed(F5);
    tone(D5);
    tone(B4);
    tone_3Pressed(C5);
    tone_3Pressed(E5);
    tone(C5);
    tone(G4);
    tone(E4);
    tone(G4);
    tone(F4);
    tone(D4);
    tone_3Pressed(C4);
    pause();
}

void melody3(){
    tone(D4);
    tone(D4);
    tone(E4);
    tone(D4);
    
    tone(G4);
    tone(Fs4);
    pause();
    
    tone(D4);
    tone(D4);
    tone(E4);
    tone(D4);
    
    tone(A4);
    tone(G4);
    pause();
    
    tone(D4);
    tone(D4);
    tone(D5);
    tone(B4);
    tone(G4);
    tone(Fs4);
    tone(E4);
    pause();
    
    tone(C5);
    tone(C5);
    tone(B4);
    tone(G4);
    tone(A4);
    tone(G4);
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
        if(song_A) melody1();
        if(song_B) melody2();
        if(song_C) melody3();
    }
}

/**
 End of File
*/