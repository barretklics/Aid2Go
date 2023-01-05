//#include <util/delay.h>
#include "watch.h"
#include "bUtils.h"
#include <avr/io.h>
#include "reoccurring.h"
int seconds = 00;
int minutes = 0;
int hours = 0;
int days = 1;
int months = 1;
int years = 2000;





void watchTick(int arg, int val){
    if (arg == -1) years++; //Left for debug, not normally accessiblew
    
    if (arg == 0) seconds++;
    
    if (arg == 1) seconds = val;
    if (arg == 2) minutes = val;
    if (arg == 3) hours = val;
    if (arg == 4) days = val;
    
    if (arg == 5) months = val;
    if (arg == 6) years = val;
    
    if (seconds >= 60) {
        seconds = 00; 
        minutes++;
    }
    if (minutes < 0){
        minutes = 59;
    }
    
    if (minutes >= 60) {
        minutes = 0; 
        hours++;
    }  
    if (minutes < 0){
        minutes = 59;
    }
    
    
    
    if (hours >= 24) {
        hours = 0; 
        days++;
    }
    
    if (hours < 0){
        hours = 23;
    }
    
    
    
    //Now for days to roll over to months

    //31 day months
    int cday = days - 1; //we need to check the next day
    
    if (days < 1){
        days = 1; 
    }
    
    if (cday == 29) {    
        if (isLeapYear(years)){
            if (months == 2){
                days = 1;
                months ++;               
            } 
        }
    }
    if (cday == 28) {
        if (!(isLeapYear(years))){
            if (months == 2){
                days = 1;
                months ++;               
            } 
        }
    }
   
    if (cday == 30) {  //return if bad month   
        if (months == 1) return;
        if (months == 2) return;
        if (months == 3) return;
        if (months == 5) return;
        if (months == 7) return;
        if (months == 8) return;
        if (months == 10) return;
        if (months == 12) return;
        //now month is good and date is 30
        days = 1;
        months ++;
    }     
    
     if (cday == 31) {  //return if bad month   
        if (months == 2) return;
        if (months == 4) return;
        if (months == 6) return;
        if (months == 9) return;
        if (months == 12){
            months = 0;
            years++;
        }

        //now month is good and date is 30
        days = 1;
        months ++;
    }
    
    
    if (months > 12){
        months = 1;
    }
    if (months < 1){
        months = 12;
    }
    if (years < 2000){
        years = 2000;
    }
    
    
    
}      
  

int wget(char type){  
    if (type == 's') return seconds;
    if (type == 'm') return minutes;   
    if (type == 'h') return hours;   
    if (type == 'd') return days;  
   
    if (type == 'M') return months;
    if (type == 'Y') return years;
    
    
    if (type == 'W'){
        int d = days;
        int m = months;
        int y = years;

        int weekday = (d += m < 3 ? y-- : y - 2, 23*m/9 + d + 4 + y/4- y/100 + y/400)%7;
        return weekday;
    }
    
    if (type == 'c'){ //clock
        if (hours == 0) return 12;
        else if (hours > 12) return hours - 12;
        else return hours;
    }  
    
    if (type == '!'){ //! 0 for am, 1 for pm
        if (hours == 0) return 0;
        else if (hours >= 12) return 1;
        else return 0;
    }    
    
    
    return 0;
}

void wset(char type, int val){  
    if (type == 's') watchTick(1, val);
    if (type == 'm') watchTick(2, val);  
    if (type == 'h') watchTick(3, val);   
    if (type == 'd') watchTick(4, val);  
   
    if (type == 'M') watchTick(5, val);
    if (type == 'Y') watchTick(6, val);
}
