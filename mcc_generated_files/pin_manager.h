/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC16F18857
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.36 and above
        MPLAB 	          :  MPLAB X 6.00	
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set GPIO_SEG7_10 aliases
#define GPIO_SEG7_10_TRIS                 TRISAbits.TRISA0
#define GPIO_SEG7_10_LAT                  LATAbits.LATA0
#define GPIO_SEG7_10_PORT                 PORTAbits.RA0
#define GPIO_SEG7_10_WPU                  WPUAbits.WPUA0
#define GPIO_SEG7_10_OD                   ODCONAbits.ODCA0
#define GPIO_SEG7_10_ANS                  ANSELAbits.ANSA0
#define GPIO_SEG7_10_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define GPIO_SEG7_10_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define GPIO_SEG7_10_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define GPIO_SEG7_10_GetValue()           PORTAbits.RA0
#define GPIO_SEG7_10_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define GPIO_SEG7_10_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define GPIO_SEG7_10_SetPullup()          do { WPUAbits.WPUA0 = 1; } while(0)
#define GPIO_SEG7_10_ResetPullup()        do { WPUAbits.WPUA0 = 0; } while(0)
#define GPIO_SEG7_10_SetPushPull()        do { ODCONAbits.ODCA0 = 0; } while(0)
#define GPIO_SEG7_10_SetOpenDrain()       do { ODCONAbits.ODCA0 = 1; } while(0)
#define GPIO_SEG7_10_SetAnalogMode()      do { ANSELAbits.ANSA0 = 1; } while(0)
#define GPIO_SEG7_10_SetDigitalMode()     do { ANSELAbits.ANSA0 = 0; } while(0)

// get/set GPIO_SEG7_1 aliases
#define GPIO_SEG7_1_TRIS                 TRISAbits.TRISA1
#define GPIO_SEG7_1_LAT                  LATAbits.LATA1
#define GPIO_SEG7_1_PORT                 PORTAbits.RA1
#define GPIO_SEG7_1_WPU                  WPUAbits.WPUA1
#define GPIO_SEG7_1_OD                   ODCONAbits.ODCA1
#define GPIO_SEG7_1_ANS                  ANSELAbits.ANSA1
#define GPIO_SEG7_1_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define GPIO_SEG7_1_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define GPIO_SEG7_1_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define GPIO_SEG7_1_GetValue()           PORTAbits.RA1
#define GPIO_SEG7_1_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define GPIO_SEG7_1_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define GPIO_SEG7_1_SetPullup()          do { WPUAbits.WPUA1 = 1; } while(0)
#define GPIO_SEG7_1_ResetPullup()        do { WPUAbits.WPUA1 = 0; } while(0)
#define GPIO_SEG7_1_SetPushPull()        do { ODCONAbits.ODCA1 = 0; } while(0)
#define GPIO_SEG7_1_SetOpenDrain()       do { ODCONAbits.ODCA1 = 1; } while(0)
#define GPIO_SEG7_1_SetAnalogMode()      do { ANSELAbits.ANSA1 = 1; } while(0)
#define GPIO_SEG7_1_SetDigitalMode()     do { ANSELAbits.ANSA1 = 0; } while(0)

// get/set GPIO_DEAD_SW aliases
#define GPIO_DEAD_SW_TRIS                 TRISAbits.TRISA2
#define GPIO_DEAD_SW_LAT                  LATAbits.LATA2
#define GPIO_DEAD_SW_PORT                 PORTAbits.RA2
#define GPIO_DEAD_SW_WPU                  WPUAbits.WPUA2
#define GPIO_DEAD_SW_OD                   ODCONAbits.ODCA2
#define GPIO_DEAD_SW_ANS                  ANSELAbits.ANSA2
#define GPIO_DEAD_SW_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define GPIO_DEAD_SW_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define GPIO_DEAD_SW_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define GPIO_DEAD_SW_GetValue()           PORTAbits.RA2
#define GPIO_DEAD_SW_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define GPIO_DEAD_SW_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define GPIO_DEAD_SW_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define GPIO_DEAD_SW_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define GPIO_DEAD_SW_SetPushPull()        do { ODCONAbits.ODCA2 = 0; } while(0)
#define GPIO_DEAD_SW_SetOpenDrain()       do { ODCONAbits.ODCA2 = 1; } while(0)
#define GPIO_DEAD_SW_SetAnalogMode()      do { ANSELAbits.ANSA2 = 1; } while(0)
#define GPIO_DEAD_SW_SetDigitalMode()     do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set GPIO_SSR aliases
#define GPIO_SSR_TRIS                 TRISAbits.TRISA3
#define GPIO_SSR_LAT                  LATAbits.LATA3
#define GPIO_SSR_PORT                 PORTAbits.RA3
#define GPIO_SSR_WPU                  WPUAbits.WPUA3
#define GPIO_SSR_OD                   ODCONAbits.ODCA3
#define GPIO_SSR_ANS                  ANSELAbits.ANSA3
#define GPIO_SSR_SetHigh()            do { LATAbits.LATA3 = 1; } while(0)
#define GPIO_SSR_SetLow()             do { LATAbits.LATA3 = 0; } while(0)
#define GPIO_SSR_Toggle()             do { LATAbits.LATA3 = ~LATAbits.LATA3; } while(0)
#define GPIO_SSR_GetValue()           PORTAbits.RA3
#define GPIO_SSR_SetDigitalInput()    do { TRISAbits.TRISA3 = 1; } while(0)
#define GPIO_SSR_SetDigitalOutput()   do { TRISAbits.TRISA3 = 0; } while(0)
#define GPIO_SSR_SetPullup()          do { WPUAbits.WPUA3 = 1; } while(0)
#define GPIO_SSR_ResetPullup()        do { WPUAbits.WPUA3 = 0; } while(0)
#define GPIO_SSR_SetPushPull()        do { ODCONAbits.ODCA3 = 0; } while(0)
#define GPIO_SSR_SetOpenDrain()       do { ODCONAbits.ODCA3 = 1; } while(0)
#define GPIO_SSR_SetAnalogMode()      do { ANSELAbits.ANSA3 = 1; } while(0)
#define GPIO_SSR_SetDigitalMode()     do { ANSELAbits.ANSA3 = 0; } while(0)

// get/set GPIO_PIR aliases
#define GPIO_PIR_TRIS                 TRISAbits.TRISA4
#define GPIO_PIR_LAT                  LATAbits.LATA4
#define GPIO_PIR_PORT                 PORTAbits.RA4
#define GPIO_PIR_WPU                  WPUAbits.WPUA4
#define GPIO_PIR_OD                   ODCONAbits.ODCA4
#define GPIO_PIR_ANS                  ANSELAbits.ANSA4
#define GPIO_PIR_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define GPIO_PIR_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define GPIO_PIR_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define GPIO_PIR_GetValue()           PORTAbits.RA4
#define GPIO_PIR_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define GPIO_PIR_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define GPIO_PIR_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define GPIO_PIR_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define GPIO_PIR_SetPushPull()        do { ODCONAbits.ODCA4 = 0; } while(0)
#define GPIO_PIR_SetOpenDrain()       do { ODCONAbits.ODCA4 = 1; } while(0)
#define GPIO_PIR_SetAnalogMode()      do { ANSELAbits.ANSA4 = 1; } while(0)
#define GPIO_PIR_SetDigitalMode()     do { ANSELAbits.ANSA4 = 0; } while(0)

// get/set GPIO_LEDa aliases
#define GPIO_LEDa_TRIS                 TRISBbits.TRISB0
#define GPIO_LEDa_LAT                  LATBbits.LATB0
#define GPIO_LEDa_PORT                 PORTBbits.RB0
#define GPIO_LEDa_WPU                  WPUBbits.WPUB0
#define GPIO_LEDa_OD                   ODCONBbits.ODCB0
#define GPIO_LEDa_ANS                  ANSELBbits.ANSB0
#define GPIO_LEDa_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define GPIO_LEDa_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define GPIO_LEDa_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define GPIO_LEDa_GetValue()           PORTBbits.RB0
#define GPIO_LEDa_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define GPIO_LEDa_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define GPIO_LEDa_SetPullup()          do { WPUBbits.WPUB0 = 1; } while(0)
#define GPIO_LEDa_ResetPullup()        do { WPUBbits.WPUB0 = 0; } while(0)
#define GPIO_LEDa_SetPushPull()        do { ODCONBbits.ODCB0 = 0; } while(0)
#define GPIO_LEDa_SetOpenDrain()       do { ODCONBbits.ODCB0 = 1; } while(0)
#define GPIO_LEDa_SetAnalogMode()      do { ANSELBbits.ANSB0 = 1; } while(0)
#define GPIO_LEDa_SetDigitalMode()     do { ANSELBbits.ANSB0 = 0; } while(0)

// get/set GPIO_LEDb aliases
#define GPIO_LEDb_TRIS                 TRISBbits.TRISB1
#define GPIO_LEDb_LAT                  LATBbits.LATB1
#define GPIO_LEDb_PORT                 PORTBbits.RB1
#define GPIO_LEDb_WPU                  WPUBbits.WPUB1
#define GPIO_LEDb_OD                   ODCONBbits.ODCB1
#define GPIO_LEDb_ANS                  ANSELBbits.ANSB1
#define GPIO_LEDb_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define GPIO_LEDb_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define GPIO_LEDb_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define GPIO_LEDb_GetValue()           PORTBbits.RB1
#define GPIO_LEDb_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define GPIO_LEDb_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define GPIO_LEDb_SetPullup()          do { WPUBbits.WPUB1 = 1; } while(0)
#define GPIO_LEDb_ResetPullup()        do { WPUBbits.WPUB1 = 0; } while(0)
#define GPIO_LEDb_SetPushPull()        do { ODCONBbits.ODCB1 = 0; } while(0)
#define GPIO_LEDb_SetOpenDrain()       do { ODCONBbits.ODCB1 = 1; } while(0)
#define GPIO_LEDb_SetAnalogMode()      do { ANSELBbits.ANSB1 = 1; } while(0)
#define GPIO_LEDb_SetDigitalMode()     do { ANSELBbits.ANSB1 = 0; } while(0)

// get/set GPIO_LEDc aliases
#define GPIO_LEDc_TRIS                 TRISBbits.TRISB2
#define GPIO_LEDc_LAT                  LATBbits.LATB2
#define GPIO_LEDc_PORT                 PORTBbits.RB2
#define GPIO_LEDc_WPU                  WPUBbits.WPUB2
#define GPIO_LEDc_OD                   ODCONBbits.ODCB2
#define GPIO_LEDc_ANS                  ANSELBbits.ANSB2
#define GPIO_LEDc_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define GPIO_LEDc_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define GPIO_LEDc_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define GPIO_LEDc_GetValue()           PORTBbits.RB2
#define GPIO_LEDc_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define GPIO_LEDc_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define GPIO_LEDc_SetPullup()          do { WPUBbits.WPUB2 = 1; } while(0)
#define GPIO_LEDc_ResetPullup()        do { WPUBbits.WPUB2 = 0; } while(0)
#define GPIO_LEDc_SetPushPull()        do { ODCONBbits.ODCB2 = 0; } while(0)
#define GPIO_LEDc_SetOpenDrain()       do { ODCONBbits.ODCB2 = 1; } while(0)
#define GPIO_LEDc_SetAnalogMode()      do { ANSELBbits.ANSB2 = 1; } while(0)
#define GPIO_LEDc_SetDigitalMode()     do { ANSELBbits.ANSB2 = 0; } while(0)

// get/set GPIO_LEDd aliases
#define GPIO_LEDd_TRIS                 TRISBbits.TRISB3
#define GPIO_LEDd_LAT                  LATBbits.LATB3
#define GPIO_LEDd_PORT                 PORTBbits.RB3
#define GPIO_LEDd_WPU                  WPUBbits.WPUB3
#define GPIO_LEDd_OD                   ODCONBbits.ODCB3
#define GPIO_LEDd_ANS                  ANSELBbits.ANSB3
#define GPIO_LEDd_SetHigh()            do { LATBbits.LATB3 = 1; } while(0)
#define GPIO_LEDd_SetLow()             do { LATBbits.LATB3 = 0; } while(0)
#define GPIO_LEDd_Toggle()             do { LATBbits.LATB3 = ~LATBbits.LATB3; } while(0)
#define GPIO_LEDd_GetValue()           PORTBbits.RB3
#define GPIO_LEDd_SetDigitalInput()    do { TRISBbits.TRISB3 = 1; } while(0)
#define GPIO_LEDd_SetDigitalOutput()   do { TRISBbits.TRISB3 = 0; } while(0)
#define GPIO_LEDd_SetPullup()          do { WPUBbits.WPUB3 = 1; } while(0)
#define GPIO_LEDd_ResetPullup()        do { WPUBbits.WPUB3 = 0; } while(0)
#define GPIO_LEDd_SetPushPull()        do { ODCONBbits.ODCB3 = 0; } while(0)
#define GPIO_LEDd_SetOpenDrain()       do { ODCONBbits.ODCB3 = 1; } while(0)
#define GPIO_LEDd_SetAnalogMode()      do { ANSELBbits.ANSB3 = 1; } while(0)
#define GPIO_LEDd_SetDigitalMode()     do { ANSELBbits.ANSB3 = 0; } while(0)

// get/set GPIO_LEDe aliases
#define GPIO_LEDe_TRIS                 TRISBbits.TRISB4
#define GPIO_LEDe_LAT                  LATBbits.LATB4
#define GPIO_LEDe_PORT                 PORTBbits.RB4
#define GPIO_LEDe_WPU                  WPUBbits.WPUB4
#define GPIO_LEDe_OD                   ODCONBbits.ODCB4
#define GPIO_LEDe_ANS                  ANSELBbits.ANSB4
#define GPIO_LEDe_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define GPIO_LEDe_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define GPIO_LEDe_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define GPIO_LEDe_GetValue()           PORTBbits.RB4
#define GPIO_LEDe_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define GPIO_LEDe_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define GPIO_LEDe_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define GPIO_LEDe_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define GPIO_LEDe_SetPushPull()        do { ODCONBbits.ODCB4 = 0; } while(0)
#define GPIO_LEDe_SetOpenDrain()       do { ODCONBbits.ODCB4 = 1; } while(0)
#define GPIO_LEDe_SetAnalogMode()      do { ANSELBbits.ANSB4 = 1; } while(0)
#define GPIO_LEDe_SetDigitalMode()     do { ANSELBbits.ANSB4 = 0; } while(0)

// get/set GPIO_LEDf aliases
#define GPIO_LEDf_TRIS                 TRISBbits.TRISB5
#define GPIO_LEDf_LAT                  LATBbits.LATB5
#define GPIO_LEDf_PORT                 PORTBbits.RB5
#define GPIO_LEDf_WPU                  WPUBbits.WPUB5
#define GPIO_LEDf_OD                   ODCONBbits.ODCB5
#define GPIO_LEDf_ANS                  ANSELBbits.ANSB5
#define GPIO_LEDf_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define GPIO_LEDf_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define GPIO_LEDf_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define GPIO_LEDf_GetValue()           PORTBbits.RB5
#define GPIO_LEDf_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define GPIO_LEDf_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define GPIO_LEDf_SetPullup()          do { WPUBbits.WPUB5 = 1; } while(0)
#define GPIO_LEDf_ResetPullup()        do { WPUBbits.WPUB5 = 0; } while(0)
#define GPIO_LEDf_SetPushPull()        do { ODCONBbits.ODCB5 = 0; } while(0)
#define GPIO_LEDf_SetOpenDrain()       do { ODCONBbits.ODCB5 = 1; } while(0)
#define GPIO_LEDf_SetAnalogMode()      do { ANSELBbits.ANSB5 = 1; } while(0)
#define GPIO_LEDf_SetDigitalMode()     do { ANSELBbits.ANSB5 = 0; } while(0)

// get/set GPIO_LEDg aliases
#define GPIO_LEDg_TRIS                 TRISBbits.TRISB6
#define GPIO_LEDg_LAT                  LATBbits.LATB6
#define GPIO_LEDg_PORT                 PORTBbits.RB6
#define GPIO_LEDg_WPU                  WPUBbits.WPUB6
#define GPIO_LEDg_OD                   ODCONBbits.ODCB6
#define GPIO_LEDg_ANS                  ANSELBbits.ANSB6
#define GPIO_LEDg_SetHigh()            do { LATBbits.LATB6 = 1; } while(0)
#define GPIO_LEDg_SetLow()             do { LATBbits.LATB6 = 0; } while(0)
#define GPIO_LEDg_Toggle()             do { LATBbits.LATB6 = ~LATBbits.LATB6; } while(0)
#define GPIO_LEDg_GetValue()           PORTBbits.RB6
#define GPIO_LEDg_SetDigitalInput()    do { TRISBbits.TRISB6 = 1; } while(0)
#define GPIO_LEDg_SetDigitalOutput()   do { TRISBbits.TRISB6 = 0; } while(0)
#define GPIO_LEDg_SetPullup()          do { WPUBbits.WPUB6 = 1; } while(0)
#define GPIO_LEDg_ResetPullup()        do { WPUBbits.WPUB6 = 0; } while(0)
#define GPIO_LEDg_SetPushPull()        do { ODCONBbits.ODCB6 = 0; } while(0)
#define GPIO_LEDg_SetOpenDrain()       do { ODCONBbits.ODCB6 = 1; } while(0)
#define GPIO_LEDg_SetAnalogMode()      do { ANSELBbits.ANSB6 = 1; } while(0)
#define GPIO_LEDg_SetDigitalMode()     do { ANSELBbits.ANSB6 = 0; } while(0)

// get/set GPIO_LEDdp aliases
#define GPIO_LEDdp_TRIS                 TRISBbits.TRISB7
#define GPIO_LEDdp_LAT                  LATBbits.LATB7
#define GPIO_LEDdp_PORT                 PORTBbits.RB7
#define GPIO_LEDdp_WPU                  WPUBbits.WPUB7
#define GPIO_LEDdp_OD                   ODCONBbits.ODCB7
#define GPIO_LEDdp_ANS                  ANSELBbits.ANSB7
#define GPIO_LEDdp_SetHigh()            do { LATBbits.LATB7 = 1; } while(0)
#define GPIO_LEDdp_SetLow()             do { LATBbits.LATB7 = 0; } while(0)
#define GPIO_LEDdp_Toggle()             do { LATBbits.LATB7 = ~LATBbits.LATB7; } while(0)
#define GPIO_LEDdp_GetValue()           PORTBbits.RB7
#define GPIO_LEDdp_SetDigitalInput()    do { TRISBbits.TRISB7 = 1; } while(0)
#define GPIO_LEDdp_SetDigitalOutput()   do { TRISBbits.TRISB7 = 0; } while(0)
#define GPIO_LEDdp_SetPullup()          do { WPUBbits.WPUB7 = 1; } while(0)
#define GPIO_LEDdp_ResetPullup()        do { WPUBbits.WPUB7 = 0; } while(0)
#define GPIO_LEDdp_SetPushPull()        do { ODCONBbits.ODCB7 = 0; } while(0)
#define GPIO_LEDdp_SetOpenDrain()       do { ODCONBbits.ODCB7 = 1; } while(0)
#define GPIO_LEDdp_SetAnalogMode()      do { ANSELBbits.ANSB7 = 1; } while(0)
#define GPIO_LEDdp_SetDigitalMode()     do { ANSELBbits.ANSB7 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCAF2 pin functionality
 * @Example
    IOCAF2_ISR();
 */
void IOCAF2_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCAF2 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCAF2 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCAF2_SetInterruptHandler(MyInterruptHandler);

*/
void IOCAF2_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCAF2 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCAF2_SetInterruptHandler() method.
    This handler is called every time the IOCAF2 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCAF2_SetInterruptHandler(IOCAF2_InterruptHandler);

*/
extern void (*IOCAF2_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCAF2 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCAF2_SetInterruptHandler() method.
    This handler is called every time the IOCAF2 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCAF2_SetInterruptHandler(IOCAF2_DefaultInterruptHandler);

*/
void IOCAF2_DefaultInterruptHandler(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/