#include "twi_master.h"
#include "i2c_lcd.h"
#include <avr/io.h>
#include "menu.h"
#include "bUtils.h"
#include "watch.h"
#include "button.h"
#include "reoccurring.h"
void menu(int mode){
    
    if (mode == -1){    //ALERT MODE. Cannot be accessed through buttons
                        // Must be triggered through missed events
        
        
        int missed_events = get_missed_events();
        
        char line1[] = "ALERT: Missed xx";//display missed events
        char line2[] = "Type[xx] hh:mmAM";
        
        line1[14] = itoc(missed_events, 0);
        line1[15] = itoc(missed_events, 1);
        
        int i;
        for (i = 0; i < 99; i++){
            if (get_reoccurring_event(5, i) == 1){ //always displays last event
                int type = get_reoccurring_event(3, i);
                
                
                if (type == 0){
                    line2[0] = 'A';
                    line2[1] = 'L';   
                    line2[2] = 'R';  
                    line2[3] = 'M';  
                }   
                if (type == 1){
                    line2[0] = 'M';
                    line2[1] = 'E';   
                    line2[2] = 'D';  
                    line2[3] = 'S';  
   
                }
                if (type == 2){
                    line2[0] = 'D';
                    line2[1] = 'C';   
                    line2[2] = 'T';  
                    line2[3] = 'R';  
                }
                line2[4] = '[';  
                line2[5] = itoc(i, 0);  
                line2[6] = itoc(i, 1);  
                line2[7] = ']';
                
                
                line2[8] = ' ';
                
                int hour = get_reoccurring_event(1, i);
                
                int hour12;
                
                
                if (hour == 0) hour12 = 12;
                else if (hour > 12) hour12 = hour - 12;
                else hour12 = hour;
                
                
                line2[9] = itoc(hour12, 0); 
                line2[10] = itoc(hour12, 1); 
                line2[11] = ':';
                int minute = get_reoccurring_event(2, i);
                line2[12] = itoc(minute, 0); 
                line2[13] = itoc(minute, 1);                          

                line2[14] = 'A';
                if (hour >= 12) line2[14] = 'P';
                
                line2[15] = 'M'; 
                
                 
            }
        }
        
        i2c_set_cursor(1,1);
        i2c_lcd_send_string((unsigned char*)line1);
        i2c_set_cursor(2,1);
        i2c_lcd_send_string((unsigned char*)line2);         
    }
    
    if (mode == 0){ // Debug Mode ---to be disabled for final product---
                    // Values adjusted at will
        i2c_set_cursor(1,1);
    
        char example1[] = "debug:         ";
        ////////////////= "debug: 789abcdef
        example1[7] = itoc(get_missed_events(), 0);
        example1[8] = itoc(get_missed_events(), 1);

        example1[14] = itoc(wget('s'), 0);
        example1[15] = itoc(wget('s'), 1);
      
        i2c_lcd_send_string((unsigned char*)example1);

        i2c_set_cursor(2,1);

        char example[] = "TUE APR DD HH:MM";

        //tests
        example[0] = itoc(wget('Y'), 0);
        example[1] = itoc(wget('Y'), 1);
        example[2] = itoc(wget('Y'), 2);
        example[3] = itoc(wget('Y'), 3);   

        example[4] = '-';  
        example[5] = itoc(wget('M'), 0);   
        example[6] = itoc(wget('M'), 1);   
        //

        example[8] = itoc(wget('d'), 0);
        example[9] = itoc(wget('d'), 1);

        example[11] = itoc(wget('c'), 0);
        example[12] = itoc(wget('c'), 1);

        example[14] = itoc(wget('m'), 0);
        example[15] = itoc(wget('m'), 1);  


        i2c_lcd_send_string((unsigned char*)example);

         //i2c_lcd_send_string((unsigned char*)"TUE APR 05 06:09");    
    }
    
    
    if (mode == 1){ //Main Menu-------------------------------------------------
        char line1[] = "AID2GO  MMM YYYY";
        //           = "0123456789abcdef";
        int m = wget('M');
        int Y = wget('Y');
        
        
        if (m == 1){
            line1[8] = 'J'; 
            line1[9] = 'A'; 
            line1[10] = 'N';          
        }
        if (m == 2){
            line1[8] = 'F'; 
            line1[9] = 'E'; 
            line1[10] = 'B';          
        }       
        if (m == 3){
            line1[8] = 'M'; 
            line1[9] = 'A'; 
            line1[10] = 'R';          
        }        
        if (m == 4){
            line1[8] = 'A'; 
            line1[9] = 'P'; 
            line1[10] = 'R';          
        }           
        if (m == 5){
            line1[8] = 'M'; 
            line1[9] = 'A'; 
            line1[10] = 'Y';          
        }            
        if (m == 6){
            line1[8] = 'J'; 
            line1[9] = 'U'; 
            line1[10] = 'N';          
        }            
        if (m == 7){
            line1[8] = 'J'; 
            line1[9] = 'U'; 
            line1[10] = 'L';          
        } 
        if (m == 8){
            line1[8] = 'A'; 
            line1[9] = 'U'; 
            line1[10] = 'G';          
        }            
        if (m == 9){
            line1[8] = 'S'; 
            line1[9] = 'E'; 
            line1[10] = 'P';          
        }            
        if (m == 10){
            line1[8] = 'O'; 
            line1[9] = 'C'; 
            line1[10] = 'T';          
        }            
        if (m == 11){
            line1[8] = 'N'; 
            line1[9] = 'O'; 
            line1[10] = 'V';          
        }
        if (m == 12){
            line1[8] = 'D'; 
            line1[9] = 'E'; 
            line1[10] = 'C';          
        }            
        line1[12] = itoc(Y, 0);
        line1[13] = itoc(Y, 1);
        line1[14] = itoc(Y, 2);
        line1[15] = itoc(Y, 3);  
        
        
        i2c_set_cursor(1,1);
        i2c_lcd_send_string((unsigned char*)line1);


        
        char line2[] = "DDD dd   hh:mm!!";
        //           = "0123456789abcdef";
 
        
        int day = wget('W');
        if (day == 0){
          line2[0] = 'S';
          line2[1] = 'U';
          line2[2] = 'N';
        }
        if (day == 1){
          line2[0] = 'M';
          line2[1] = 'O';
          line2[2] = 'N';
        }       
        if (day == 2){
          line2[0] = 'T';
          line2[1] = 'U';
          line2[2] = 'E';
        }
        if (day == 3){
          line2[0] = 'W';
          line2[1] = 'E';
          line2[2] = 'D';
        }       
        if (day == 4){
          line2[0] = 'T';
          line2[1] = 'H';
          line2[2] = 'U';
        }
        if (day == 5){
          line2[0] = 'F';
          line2[1] = 'R';
          line2[2] = 'I';
        }
        if (day == 6){
          line2[0] = 'S';
          line2[1] = 'A';
          line2[2] = 'T';
        }
        
        int date_day = wget('d'); // date day
        line2[3] = ' '; 
        line2[4] = itoc(date_day, 0);
        line2[5] = itoc(date_day, 1);
        
        
        int c = wget('c'); //12 hour clock
        int minute = wget('m');
        int ampm = wget('!'); //am or pm
         
        //
        line2[9] = itoc(c, 0);
        line2[10] = itoc(c, 1);
        line2[11] = ':';
        line2[12] = itoc(minute, 0);
        line2[13] = itoc(minute, 1);

        
        
        if (ampm == 0) line2[14] = 'A';
        if (ampm == 1) line2[14] = 'P';
        line2[15] = 'M';  

        i2c_set_cursor(2,1);
        i2c_lcd_send_string((unsigned char*)line2);
    }
    
    if (mode == 2){ //Time set--------------------------------------------------
        
        i2c_set_cursor(1,1);
        
        char line1[] = "Time Set: NONE  ";
        char line2[] = "    ";
        int middle_counter = b_get_middle();
       if (middle_counter == 1){
            line1[10] = 'Y';
            line1[11] = 'Y';
            line1[12] = 'Y';
            line1[13] = 'Y';
            
            line2[0] = itoc(wget('Y'), 0);
            line2[1] = itoc(wget('Y'), 1);
            line2[2] = itoc(wget('Y'), 2);
            line2[3] = itoc(wget('Y'), 3);
       }
       if (middle_counter == 2){
            line1[10] = 'M';
            line1[11] = 'M';
            line1[12] = ' ';
            line1[13] = ' ';
            
            
            line2[0] = itoc(wget('M'), 0);
            line2[1] = itoc(wget('M'), 1);
            line2[2] = ' ';
            line2[3] = ' ';            
       }
       if (middle_counter == 3){
            line1[10] = 'd';
            line1[11] = 'd';
            line1[12] = ' ';
            line1[13] = ' ';
            
            line2[0] = itoc(wget('d'), 0);
            line2[1] = itoc(wget('d'), 1);
            line2[2] = ' ';
            line2[3] = ' '; 
       }       
       if (middle_counter == 4){
            line1[10] = 'h';
            line1[11] = 'h';
            line1[12] = ' ';
            line1[13] = ' ';
            
            line2[0] = itoc(wget('h'), 0);
            line2[1] = itoc(wget('h'), 1);
            line2[2] = ' ';
            line2[3] = ' '; 
       }       
        if (middle_counter == 5){
            line1[10] = 'm';
            line1[11] = 'm';
            line1[12] = ' ';
            line1[13] = ' ';
            
            line2[0] = itoc(wget('m'), 0);
            line2[1] = itoc(wget('m'), 1);
            line2[2] = ' ';
            line2[3] = ' '; 
       }            
       
        i2c_lcd_send_string((unsigned char*)line1);
        i2c_set_cursor(2,1);
        i2c_lcd_send_string((unsigned char*)line2);
    }    
    if (mode == 3){ //Reoccuring Event set--------------------------------------
        char line1[] = "SET RCC: NONE   ";
        //           = "SET RCC: 01 DAY  ";
        //           = "0123456789abcdef";
        char line2[] = "                ";
        
        int middle_counter = b_get_middle();
        int r = b_get_rcc();
        if (r == 0){
            line1[9] = 'N';
            line1[10] = 'O';
            line1[11] = 'N';
            line1[12] = 'E';              
        }
        else{
            line1[9] = itoc(r, 0);   
            line1[10] = itoc(r, 1); 
            line1[11] = ' ';
            line1[12] = ' '; 
        }
        if (middle_counter != 0) line1[15] = '!';
        

        if (middle_counter == 1){
            line1[12] = 'D';   
            line1[13] = 'A';
            line1[14] = 'Y';
            
            int day = get_reoccurring_event(0, r);
            if (day == 0){
              line2[0] = 'S';
              line2[1] = 'U';
              line2[2] = 'N';
            }
            if (day == 1){
              line2[0] = 'M';
              line2[1] = 'O';
              line2[2] = 'N';
            }       
            if (day == 2){
              line2[0] = 'T';
              line2[1] = 'U';
              line2[2] = 'E';
            }
            if (day == 3){
              line2[0] = 'W';
              line2[1] = 'E';
              line2[2] = 'D';
            }       
            if (day == 4){
              line2[0] = 'T';
              line2[1] = 'H';
              line2[2] = 'U';
            }
            if (day == 5){
              line2[0] = 'F';
              line2[1] = 'R';
              line2[2] = 'I';
            }
            if (day == 6){
              line2[0] = 'S';
              line2[1] = 'A';
              line2[2] = 'T';
            }              
        }
        if (middle_counter == 2){
            line1[12] = 'H';   
            line1[13] = 'R';
            line1[14] = ' ';
            int hour = get_reoccurring_event(1, r);
            line2[0] = itoc(hour, 0);
            line2[1] = itoc(hour, 1);            
        }
        if (middle_counter == 3){
            line1[12] = 'M';   
            line1[13] = 'I';
            line1[14] = 'N';
            int min = get_reoccurring_event(2, r);
            line2[0] = itoc(min, 0);
            line2[1] = itoc(min, 1);            
        }      
        if (middle_counter == 4){
            line1[12] = 'T';   
            line1[13] = 'Y';
            line1[14] = 'P';
            int type = get_reoccurring_event(3, r);
            if (type == 0){
                line2[0] = 'A';
                line2[1] = 'L';   
                line2[2] = 'A';  
                line2[3] = 'R';  
                line2[4] = 'M';  
            }   
            if (type == 1){
                line2[0] = 'M';
                line2[1] = 'E';   
                line2[2] = 'D';  
                line2[3] = 'I';  
                line2[4] = 'C';                  
                line2[5] = 'I';  
                line2[6] = 'N';  
                line2[7] = 'E';     
            }
            if (type == 2){
                line2[0] = 'D';
                line2[1] = 'O';   
                line2[2] = 'C';  
                line2[3] = 'T';  
                line2[4] = 'O';                  
                line2[5] = 'R';      
            }
        }
        if (middle_counter == 5){
            line1[12] = 'E';   
            line1[13] = 'N';
            line1[14] = ' ';
            int enable = get_reoccurring_event(4, r);
            if (enable == 1){
                line2[0] = 'O';
                line2[1] = 'N';   
                line2[2] = ' ';  
                line2[3] = ' ';  
                line2[4] = ' ';
                line2[5] = ' '; 
            }
            if (enable == 0){
                line2[0] = 'O';
                line2[1] = 'F';   
                line2[2] = 'F';  
                line2[3] = ' ';  
                line2[4] = ' ';
                line2[5] = ' '; 
            }        
        }
    i2c_set_cursor(1,1);
    i2c_lcd_send_string((unsigned char*)line1);
    i2c_set_cursor(2,1);
    i2c_lcd_send_string((unsigned char*)line2);
    }
}
