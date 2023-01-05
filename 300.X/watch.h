/* 
 * File:   watch.h
 * Author: Barret Klics
 *
 * Created on April 5, 2022, 6:17 PM
 */

#ifndef WATCH_H
#define	WATCH_H


void watchTick(int arg, int val);
/*
 * 
 *  This is used internally for incrementing time, debug
 *  wget and wset should be used instead of this for mid level access
 *  to the clock
 * 
 * 
 *      arg == -1 -> years is incremented (debug)
 *      arg == 0 -> seconds is incremented (used for RTC)
 *
 *      arg == 1 -> seconds = val
 *      arg == 2 -> minutes = val
 *      arg == 3 -> hours = val
 *      arg == 4 -> days = val
 *      arg == 5 -> months = val
 *      arg == 6 -> years = val
 */

int wget(char type); //Read
void wset(char type, int val); //Write
/*
 * Watch Arguments:
 *      's' - seconds
 *      'm' - minutes
 *      'h' - hours
 *      'd' - days
 *      'M' - months
 *      'Y' - years
 * 
 *      READ ONLY:
 *      'W' - day of week, (0-sun, 1, mon, etc)
 *      'c' - 12 hour representation of hour
 *      '!' - returns 0 for AM, 1 for PM
 * 
 */
#endif	/* WATCH_H */

