


/******************************************************************************
 *
 * Module: Potentiometer
 *
 * File Name:POT.c
 *
 * Description: source file for potentiometer
 *
 * Author:Seif Alaa
 *
 *******************************************************************************/

#include "Utils.h"

#include "StdType.h"

#include "ADC_interface.h"

#include "ADC_SERVICE.h"

#include "POT.h"

u16 POT_u16ReadVoltmv(POT_Vref_t copy_enumVref, u16 Copy_u16VoltRefmv)
{	
	 return ADC_SERVICE_u16ReadVoltmv(POT_CH, copy_enumVref, Copy_u16VoltRefmv);

}

u8 POT_u16ReadPecentage(POT_Vref_t copy_enumVref, u16 Copy_u16VoltRefmv)
{
	u16 local_u16Potvolt= ADC_SERVICE_u16ReadVoltmv(POT_CH, copy_enumVref, Copy_u16VoltRefmv);
	return ((u32)local_u16Potvolt*100)/Copy_u16VoltRefmv;
}