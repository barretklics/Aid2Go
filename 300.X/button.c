#include "bUtils.h"
#include "button.h"
#include "watch.h"
#include "reoccurring.h"

// Maximum supported modes excluding alert mode
// 0 = debug, 1 = main, 2 = set time, 3 = set an event
// -1 = alert (cannot be accessed without missing an event)
const int max_modes = 3; 

//Keeps track of the current mode that the device is operating in
int mode = 0;

//temporarily keeps track of middle button presses. Reset on mode increment
int middle_counter = 0;

//temporary variables for time setting
int tts_year;
int tts_month;
int tts_day;
int tts_hour;
int tts_minute;

//Index for what reoccurring event is being edited. Reset on mode increment
int reoccurring_index;

void b_set_mode(int m){
    mode = m;
}
int b_get_mode(void){
    return mode;
}
void b_inc_mode(void){
    middle_counter = 0;
    reoccurring_index = 0;
    clr();
    mode++;
    if (mode == 0) mode = 1;
    if (mode > max_modes) mode = 1;
}

int b_get_middle(void){
    return middle_counter;
}

void button(char b)
{
    if (mode == -1) alert(b);
    if (mode == 2) timeset(b);
    if (mode == 3) reoccuringSet(b);
}

void timeset(char b)
{
    if (b == 'm') middle_counter++;
    tts_year = wget('Y');
    tts_month = wget('M');
    tts_day = wget('d');
    tts_hour = wget('h');
    tts_minute = wget('m');
 
    if (middle_counter == 1)
    {
        if (b == 'r') tts_year++;
        if (b == 'l') tts_year--;
        wset('Y', tts_year);
    }
    if (middle_counter == 2)
    {
        if (b == 'r') tts_month++;
        if (b == 'l') tts_month--;
        wset('M', tts_month);
    }   
    if (middle_counter == 3)
    {
        if (b == 'r') tts_day++;
        if (b == 'l') tts_day--;
        wset('d', tts_day);
    }      
    if (middle_counter == 4)
    {
        if (b == 'r') tts_hour++;
        if (b == 'l') tts_hour--;
        wset('h', tts_hour);
    }
    if (middle_counter == 5)
    {
        if (b == 'r') tts_minute++;
        if (b == 'l') tts_minute--;
        wset('m', tts_minute);
    }
    if (middle_counter == 6)
    {
        middle_counter = 0;
    }
}
void reoccuringSet(char b){
    if (b == 'm'){
        if (reoccurring_index != 0) middle_counter++;          
    }

    if (middle_counter == 0){
        if (b == 'r'){
            reoccurring_index++;
            if (reoccurring_index > 99) reoccurring_index = 0;
        }
        if (b == 'l'){
            reoccurring_index--;
            if (reoccurring_index < 0) reoccurring_index = 99;
        }
    }
    
    else if (middle_counter == 1) //Set day
    {
        //still at reoccurring index
        int day = get_reoccurring_event(0, reoccurring_index);
        
        if (b == 'r') day++;
        if (b == 'l') day--;
        
        if (day > 6) day = 0;
        if (day < 0) day = 6;
        
        set_reoccurring_event(0, reoccurring_index, day);
    }
        
    else if (middle_counter == 2) //Set Hour
    {
        //still at reoccurring index
        int hour = get_reoccurring_event(1, reoccurring_index);
        
        if (b == 'r') hour++;
        if (b == 'l') hour--;
        
        if (hour > 23) hour = 0;
        if (hour < 0) hour = 23;
        
        set_reoccurring_event(1, reoccurring_index, hour);
    }
        
    else if (middle_counter == 3) //Set Minute
    {
        //still at reoccurring index
        int min = get_reoccurring_event(2, reoccurring_index);
        
        if (b == 'r') min++;
        if (b == 'l') min--;
        
        if (min > 59) min = 0;
        if (min < 0) min = 59;
        
        set_reoccurring_event(2, reoccurring_index, min);
    }
    else if (middle_counter == 4) //Set Type
    {
        //still at reoccurring index
        int type = get_reoccurring_event(3, reoccurring_index);
        
        if (b == 'r') type++;
        if (b == 'l') type--;
        
        if (type > 2) type = 0;
        if (type < 0) type = 2;
        
        set_reoccurring_event(3, reoccurring_index, type);
    }
    else if (middle_counter == 5) //Set Enable 
    {
        //still at reoccurring index
        int enable = get_reoccurring_event(4, reoccurring_index);
        
        if (b == 'r') enable++;
        if (b == 'l') enable--;
        
        if (enable > 1) enable = 0;
        if (enable < 0) enable = 1;
        
        set_reoccurring_event(4, reoccurring_index, enable);
    }    
        
    else if (middle_counter == 6) middle_counter = 0;
    
    else middle_counter = 0;
}

int b_get_rcc(void){
    return reoccurring_index;
}

void alert(char b){

    if (b == 'm'){ //clear current missed event (the last one in the list)
        int index = 0;   
        int i;
        for (i = 0; i < 99; i++){
            if (get_reoccurring_event(5, i) == 1){ //always displays last event
                index = i;
            }
        }
        
        set_reoccurring_event(5, index, 0); //clears latest event   
        if (get_missed_events() == 0){
            b_inc_mode();
           // playSound(0);
        }
    }
}