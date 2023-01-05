/*
 * File:   newavr-main.c
 * Author: Barret Klics / Nishi Solanki
 *
 * Created on April 5, 2022, 5:17 PM
 */

#include "twi_master.h"
#include "i2c_lcd.h"
#include <avr/io.h>
#include "menu.h"
#include "watch.h"
#include "bUtils.h"
#include "button.h"
#include "reoccurring.h"


unsigned short nSmp = 20; 
unsigned short wave[] = { 127, 166, 202, 230, 248, 255, 248, 230, 202, 166, 127, 88, 52, 24, 6, 0, 6, 24, 52, 88 }; //Makes up sinusoid signal.
//unsigned short zeros[] = {0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0};    //Essentially, 0V output to speaker when alarm is not ringing.

#define C 523.3     //Defined timer scaling value for each note with frequencies. `
#define D 587.3
#define E 659.3
#define F 698.5
#define G 784
#define A 880
#define B 987.8
int frequency[] = {C, C, G, G, A, A, G, F, F, E, E, D, D, C}; //Tune with varying frequencies.
int fchange = 1;    //Counter for frequency array.
int timer = 0;  //Internal timer keeps track of how long each frequency is played in tune.
int n = 0;



int main(void)
{

    i2c_lcd_init(); //initialize screen
    _delay_ms(1000);
    SREG = 0b10000000;//enable global interrupts
    
    
    PORTA.DIRCLR = 0b01110011; //Enable PA0-6
    PORTA.PIN0CTRL = 0x02;    //sets interrupts to trigger on pin X rising edge
    PORTA.PIN1CTRL = 0x02;
    PORTA.PIN4CTRL = 0x02;
    PORTA.PIN5CTRL = 0x02;
    PORTA.PIN6CTRL = 0x02;
    
    //PA0 - clock input
    //PA1 - Menu Shift Button
    //PA2/3 - reserved for the LCD
    //PA4 - right button
    //PA5 - middle button
    //PA 6 - left button
    
    //Speaker COnfiguration----------------------------------------------------
    // -- Clock Configuration --
    
    // Set internal clock frequency to 16 MHz.
    CCP = 0xd8;
    CLKCTRL.OSCHFCTRLA = 0b00011100;
    while( CLKCTRL.MCLKSTATUS & 0b00000001 ){
        ;
    }

    // -- DAC Configuration --
    DAC0.CTRLA = 0b01000001; // Set PD6 to be the DAC output and enable the DAC.
 
    VREF.DAC0REF = 0b10000101; //Set VDD to reference level
    
    TCA0.SINGLE.CTRLA = 0b00001001; // divide the 8MHz clock by 16
    

    TCA0.SINGLE.PER = 0xffff; //We are using a custom timer check so no need for
                              //this check, so we set it to its max value   
    //--------------------------------------------------------------
    
    
    while(1){
        
        if ((PORTA.INTFLAGS & 0b00000001) == 0b00000001){ //Clock 1Hz
            watchTick(0,0);
            if (wget('s') == 0)
            {
                checkEvents(); //Check events once the minute rolls WORKS
            }
            PORTA.INTFLAGS = 0b00000001;
            }
    
        
        if ((PORTA.INTFLAGS & 0b00000010) == 0b00000010){ //mode switch
            b_inc_mode();
           PORTA.INTFLAGS = 0b00000010;
        } 
        if ((PORTA.INTFLAGS & 0b01000000) == 0b01000000){ //Left Press
            button('l');
           PORTA.INTFLAGS = 0b01000000;
        }          
        if ((PORTA.INTFLAGS & 0b00100000) == 0b00100000){ //Middle Press
           button('m');
           PORTA.INTFLAGS = 0b00100000;
        }  
        if ((PORTA.INTFLAGS & 0b00010000) == 0b00010000){ //Right Press
           button('r');
           PORTA.INTFLAGS = 0b00010000;
        }        
      
        if (get_missed_events() > 0) b_set_mode(-1);    //Sets Alert mode if 
                                                        //there is one
        _delay_ms(10);      //10ms minimum delay within loops
        
        menu(b_get_mode()); // Calls the menu required for the certain mode
        
        
        
        
        //Code to play required sound
        if (b_get_mode() == -1){
            for (fchange = 0; fchange < 14; fchange++){
                int timerThreshold = 50000/frequency[fchange];
                for (timer = 0 ; timer < 5000; timer ++) {
                   //if (b_get_mode() != -1) break;
                    while( TCA0.SINGLE.CNT <= timerThreshold);
                     //Plays different tones in tune from frequency array.
                    TCA0.SINGLE.CNT = 0;
                    DAC0.DATAH = wave[n];
                    n = (n+1) % nSmp; 

                    //
                    if ((PORTA.INTFLAGS & 0b00000001) == 0b00000001){//timer
                        watchTick(0,0);
                        PORTA.INTFLAGS = 0b00000001;
                        //if (wget('s') == 0)
                        //{
                         //   checkEvents(); 
                        //}
                    }
                    if ((PORTA.INTFLAGS & 0b00100000) == 0b00100000){ //Middle Press
                        button('m');
                        PORTA.INTFLAGS = 0b00100000;
                        break;
                    }  
                }
            }
        }
    }   
}
//------------------------------------------------------------------------------