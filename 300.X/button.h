/* 
 * File:   button.h
 * Author: Barret Klics
 *
 * Created on April 7, 2022, 2:11 PM
 */

#ifndef BUTTON_H
#define	BUTTON_H

int b_get_mode(void);
void b_inc_mode(void);
void b_set_mode(int m);


int b_get_middle(void);
void button(char b);

void timeset(char b);
void reoccuringSet(char b);
int b_get_rcc(void);
void alert(char b);

#endif	/* BUTTON_H */

