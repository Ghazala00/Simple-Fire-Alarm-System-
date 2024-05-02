

/******************************************************************************
 *
 * Module: Potentiometer
 *
 * File Name:POT.h
 *
 * Description: Header file for potentiometer
 *
 * Author:Seif Alaa
 *
 *******************************************************************************/
#ifndef POT_H_
#define POT_H_

#include "ADC_interface.h"

/*Select Channel of POT
ADC0
ADC1
ADC2
ADC3
ADC4
ADC5
ADC6
ADC7
*/
#define POT_CH   ADC0


typedef ADC_Vref_t  POT_Vref_t;

u16 POT_u16ReadVoltmv(POT_Vref_t copy_enumVref, u16 Copy_u16VoltRefmv);

u8 POT_u16ReadPecentage(POT_Vref_t copy_enumVref, u16 Copy_u16VoltRefmv);

#endif
