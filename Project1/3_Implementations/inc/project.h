

/**
 * @file project.h
 * @author Divyansh saxena
 * @brief
 * @version 0.1
 * @date 2022-02-10
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef PROJECT_H_
#define PROJECT_H_

#ifndef __AVR_ATmega328__
#define __AVR_ATmega328__
#endif

#define F_CPU 8000000UL /* Define CPU Frequency e.g. here 8MHz */
#include <avr/io.h>     /* Include AVR std. library file */
#include <math.h>       /* Include math header file */
#include <util/delay.h> /* Include Delay header file */
#include <stdlib.h>     /* Include stdlib header file */
#include <string.h>     /* Include string header file */

/**
 * @brief Define LCD data port direction for DDRB
 */
#define LCD_Dir DDRB /* Define LCD data port direction */

/**
 * @brief Define LCD data port to PORTB
 *
 */
#define LCD_Port PORTB /* Define LCD data port */

/**
 * @brief Define Register Select pin to PB0
 *
 */
#define RS PB0 /* Define Register Select pin */

/**
 * @brief Define Enable signal pin to PB1
 *
 */
#define EN PB1 /* Define Enable signal pin */

/**
 * @brief Gives Unsigned char commands to the LCD
 *
 * @param cmnd
 */
void LCD_Command(unsigned char cmnd);

/**
 * @brief Prints Character on the display
 *
 * @param data
 */
void LCD_Char(unsigned char data);

/**
 * @brief Initilizes the LCD
 *
 */
void LCD_Init(void);

/**
 * @brief Prints String on the LCD
 *
 * @param str
 */
void LCD_String(char *str);

/**
 * @brief Prints String at certain position on LCD
 *
 * @param row
 * @param pos
 * @param str
 */
void LCD_String_xy(char row, char pos, char *str);

/**
 * @brief Clears the LCD display
 *
 */
void LCD_Clear();

/**
 * @brief Sets Display Cursor to row,pos
 *
 * @param row
 * @param pos
 */
void LCD_pos(char row, char pos);

/**
 * @brief Initilize the ADC (Analog to Digital Converter)
 *
 */
void ADC_Init();

/**
 * @brief Read the ADC Value from port c channel (0-6)
 *
 * @param channel
 * @return int
 */
int ADC_Read(char channel);

/**
 * @brief Converts the value we have to Percentage
 *
 * @param percent
 * @return float
 */
float fan_led_percent_map(float percent);

/**
 * @brief Rotates Clock Wise / Anti-Clock Wise the Stepper Motor (value = 12) for Full Rotation
 *
 * @param prev_val
 * @param value
 * @param fwd
 * @param rev
 */
void stepper_rotate(int **prev_val, int **value, int **fwd, int **rev);

/**
 * @brief Generates PWM for LED
 *
 * @param pwm
 */
void timer_led(int pwm);

/**
 * @brief Generates PWM for FAN
 *
 * @param pwm
 */
void timer_fan(int pwm);

/**
 * @brief Controls and prints the cooling (FAN)
 *
 * @param temp
 * @param String
 */
void temp_fan(int **temp, char String[]);

/**
 * @brief Controls and prints the stepper motor and Cooling (FAN)
 *
 * @param prev_val
 * @param value
 * @param fwd
 * @param rev
 * @param String
 * @param room_int
 * @param user_int
 * @param temp
 */
void stepper_and_temp(int *prev_val, int *value, int *fwd, int *rev, char String[], int *room_int, int *user_int, int *temp);

#endif