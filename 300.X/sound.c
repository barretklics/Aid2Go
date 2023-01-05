/*
 * File:   Speaker.c
 * Author: nishi22s
 *
 * Created on April 1, 2022, 7:23 PM
 */
/*

#include <avr/io.h>

unsigned short nSmp = 20; 
unsigned short wave[] = { 127, 166, 202, 230, 248, 255, 248, 230, 202, 166, 127, 88, 52, 24, 6, 0, 6, 24, 52, 88 }; //Makes up sinusoid signal.
unsigned short zeros[] = {0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0};    //Essentially, 0V output to speaker when alarm is not ringing.

#define C 523.3     //Defined timer scaling value for each note with frequencies. `
#define D 587.3
#define E 659.3
#define F 698.5
#define G 784
#define A 880
#define B 987.8


int frequency[] = {C, C, G, G, A, A, G, F, F, E, E, D, D, C}; //Tune with varying frequencies.
int fchange = 0;    //Counter for frequency array.
int counter = 0;    //Set a counter to count the number of times the MOM-switch has been pressed.
int timer = 0;  //Internal timer keeps track of how long each frequency is played in tune.
void initializeSpeaker(void) {

    // -- Clock Configuration --
    
    // Set internal clock frequency to 16 MHz.
    CCP = 0xd8;
    CLKCTRL.OSCHFCTRLA = 0b00011100;
    while( CLKCTRL.MCLKSTATUS & 0b00000001 ){
        ;
    }

    // -- DAC Configuration --
    
    // Set PD6 to be the DAC output and enable the DAC.
    DAC0.CTRLA = 0b01000001;
    
    // Enable PA6 as an input pin.
    //PORTA.DIRCLR = 0b01000000;
    
    // Configure to use VDD as the reference level.
    VREF.DAC0REF = 0b10000101;
    
    // Configure the timer to increment every 2us.
    // - Divide the 8MHz clock by 16.
    TCA0.SINGLE.CTRLA = 0b00001001;
    
    // We will manually check the timer and reset the timer
    // so set the period to its max value to avoid an automatic
    // reset.
    TCA0.SINGLE.PER = 0xffff;
    

    
}   
void playSound(int counter){ //send a counter

    unsigned short n = 0;
        
        if (counter == 0){   //Counter = 1, MOM switch has been pressed, alarm stops and waits for next alarm to ring.
            while( TCA0.SINGLE.CNT >= 20);
                TCA0.SINGLE.CNT = 0;
                DAC0.DATAH = zeros[n];}
        
        if(counter == 1) {   //Counter = 0, MOM switch has not been pressed, alarm continues.
            for (fchange = 0; fchange < 14; fchange++) {    //Jumps elements in frequency array (composed song).
                    int timerThreshold = 50000/frequency[fchange]; //Account for number of data points, and frequency in period.
                    for (timer = 0 ; timer < 5000; timer ++) {
                        if (timer < 5000){
                            while( TCA0.SINGLE.CNT <= timerThreshold);{ //Plays different tones in tune from frequency array.
                                TCA0.SINGLE.CNT = 0;
                                DAC0.DATAH = wave[n];
                                n = (n+1) % nSmp;}

                        if ( timer > 5000){     //Stops specific tone to jump to next frequency in array. 
                            while( TCA0.SINGLE.CNT >= 20);{
                                TCA0.SINGLE.CNT = 0;
                                DAC0.DATAH = zeros[n];}
                        }
                        }

                    }
                }
        }
    }

void incTimer(void){
    //timer++;
}

 working
void playSound2(int counter){ //send a counter
    int n = 0;
    
 
    for (fchange = 0; fchange < 14; fchange++){
        int timerThreshold = 50000/frequency[fchange];
        
        for (timer = 0 ; timer < 5000; timer ++) {
            while( TCA0.SINGLE.CNT <= timerThreshold);
            { //Plays different tones in tune from frequency array.
                TCA0.SINGLE.CNT = 0;
                DAC0.DATAH = wave[n];
                n = (n+1) % nSmp;}
            }
        }
     
}*/
        
