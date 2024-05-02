
/******************************************************************************
 *
 * Module: LCD
 *
 * File Name:LCD_CFG.h
 *
 * Description: Headerfile for LCD configuration
 *
 * Author:Seif Alaa
 *
 *******************************************************************************/
/*
FOUR_BIT_MODE
EIGTH_BIT_MODE
*/

#ifndef LCD_CFG_H_
#define LCD_CFG_H_

#include "Utils.h"
#include "StdType.h"
#include "DIO_interface.h"

#define LCD_MODE  FOUR_BIT_MODE
#define EN        PINA2
#define LCD_PORT  PD    //configuration 8 BIT MODE
#define RS        PINA1

//configuration for 4 bit mode
#define  D7 PINA6
#define  D6 PINA5
#define  D5 PINA4
#define  D4 PINA3

 /*
 CURSOR_BLINK
 CURSOR_NOBLINK
 NOCURSOR_NOBLINK
 NOCURSOR_BLINK
 */
#define CURSOR_BLINK_MODE     CURSOR_BLINK

#endif