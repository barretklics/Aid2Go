#include "reoccurring.h"
#include "watch.h"
int day[99]; //arg 0
int hour[99]; //arg 1
int minute[99]; //arg 2
int type[99]; //0: ALARM, 1:MED, 2:DOC //arg 3
int enable[99]; //0: disable, 1: enable //arg 4

int missed[99]; //arg 5



int get_missed_events(void){
    int missed = 0;
    int i;
    for (i = 0; i < 99; i++){
      if (get_reoccurring_event(5, i) == 1) missed++; //event i is enable
    }
    return missed;
}


int get_reoccurring_event(int arg, int index){
    if (arg == 0) return day[index];
    if (arg == 1) return hour[index];
    if (arg == 2) return minute[index];
    if (arg == 3) return type[index];    
    if (arg == 4) return enable[index];
    if (arg == 5) return missed[index];
    return -1;
}

void set_reoccurring_event(int arg, int index, int value){
    if (arg == 0) day[index] = value;
    if (arg == 1) hour[index] = value;
    if (arg == 2) minute[index] = value;
    if (arg == 3) type[index] = value;    
    if (arg == 4) enable[index] = value;
    if (arg == 5) missed[index] = value;
}

void checkEvents(){ //This is only triggered once a minute rolls over
    int day = wget('W');
    int hour = wget('h');
    int minute = wget('m');
    
    int i ;
    
    
    for (i = 0; i < 99; i++){
      if (get_reoccurring_event(4, i) == 1){ //event i is enable
          if(get_reoccurring_event(0,i) != day) continue; //if day is not the same, dont care
          if(get_reoccurring_event(1, i) != hour) continue; //exit if bad hour
          if(get_reoccurring_event(2, i) != minute) continue; //exit if badminute
          set_reoccurring_event(5, i, 1); //set event to missed
      }
    }
}

