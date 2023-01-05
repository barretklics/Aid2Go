#include "bUtils.h"
#include "i2c_lcd.h"
char getCharFromInt(int i);

char itoc(int i, int offset){ //2 digit and 4 digit mode
    if (i > 9999) return 'e';
    
    if (i > 99){ //enter 4 digit mode
        if (offset == 0) return getCharFromInt((i/1000)%10);
        if (offset == 1) return getCharFromInt((i/100)%10);
        if (offset == 2) return getCharFromInt((i/10)%10);
        if (offset == 3) return getCharFromInt((i/1)%10);
        return 'n';
    }
    else
    {
        //2 digit mode
        if (offset == 0) return getCharFromInt((i/10)%10);
        if (offset == 1) return getCharFromInt((i/1)%10);
        return 0;
    }
}
char getCharFromInt(int i){
    if (i == 0) return '0';
    if (i == 1) return '1';
    if (i == 2) return '2';
    if (i == 3) return '3';
    if (i == 4) return '4';
    if (i == 5) return '5';
    if (i == 6) return '6';
    if (i == 7) return '7';
    if (i == 8) return '8';
    if (i == 9) return '9';
    return 'f';
}

void clr(void){
        i2c_set_cursor(1,1);
        i2c_lcd_send_string((unsigned char*)"                ");
        i2c_set_cursor(2,1);
        i2c_lcd_send_string((unsigned char*)"                ");
}
int isLeapYear(int year){
   // leap year if perfectly divisible by 400
   if (year % 400 == 0) {
      return 1; //leap year(
   }
   // not a leap year if divisible by 100
   // but not divisible by 400
   else if (year % 100 == 0) {
      return 0; //not a leap year
   }
   
   // leap year if not divisible by 100
   // but divisible by 4
   else if (year % 4 == 0) {
      return 1; //leap year
   }
   // all other years are not leap years
   else {
      return 0; //not a leap year
   }

   return 0;   
}   



