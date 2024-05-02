
/******************************************************************************
 *
 * Module: LM35 Sensor
 *
 * File Name:LM35.c
 *
 * Description: Source file for LM35 Sensor 
 *
 * Author:Seif Alaa
 *
 *******************************************************************************/
#include "Utils.h"
#include "StdType.h"
#include "ADC_interface.h"
#include "ADC_SERVICE.h"
#include "LM35.h"


u8 LM35_u8ReadTemp(LM35_Vref_t copy_enumVref,u16 Copy_u16VoltRefmv)
{
	 u16 Local_u16LM35Volt=ADC_SERVICE_u16ReadVoltmv(LM35_CH, copy_enumVref, Copy_u16VoltRefmv);
	 return ((u32)Local_u16LM35Volt*150)/1500;
}