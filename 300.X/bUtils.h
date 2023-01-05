/* 
 * File:   bUtils.h
 * Author: Barret Klics
 *
 * Created on April 5, 2022, 6:51 PM
 */

#ifndef BUTILS_H
#define	BUTILS_H

char itoc(int i, int offset);
/*
 * Returns a char representation of the digit at i[offset]
 * 
 * Works for 2 digit or 4 digit numbers
 */

int isLeapYear(int year);
/*
 * returns 1 if the input it a leap year, 0 otherwise
 * 
 */
void clr(void);
/*
 * Clears screen
 */
#endif	/* BUTILS_H */

