/* 
 * File:   i2c_lcd.h
 * Author: https://www.embeddedcastle.com/2021/09/avr-twi-interfacing.html
 *
 * Obtained on April 2nd, 2022, 1:11 PM
 */
#ifndef I2C_LCD_H_
#define I2C_LCD_H_

#define F_CPU 4000000UL
#include "twi_master.h"
#include <util/delay.h>

void i2c_lcd_init(void);
void i2c_lcd_cmd(unsigned char);
void i2c_lcd_data(unsigned char);
void i2c_lcd_send_string(unsigned char str[]);
void i2c_set_cursor(uint8_t, uint8_t);

#endif /* I2C_LCD_H_ */
//------------------------------------------------------------------------------