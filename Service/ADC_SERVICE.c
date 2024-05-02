
#include "Utils.h"
#include "StdType.h"
#include "ADC_interface.h"
#include "ADC_SERVICE.h"

u16 ADC_SERVICE_u16ReadVoltmv(ADC_Channel_t ch, ADC_Vref_t copy_enumVref, u16 Copy_u16VoltRefmv)
{
	u16 Local_u16Resolution=1;
	//ADC_vSetVoltReference(copy_enumVref);
	u16 Local_u16ADCRead=ADC_vReadDigitalValueSingleConversionBlocking(ch);	
	for (u8 i=0 ;i<RESO;i++)
	{
		Local_u16Resolution*=2;
	}
	return ((u32)Local_u16ADCRead*Copy_u16VoltRefmv)/Local_u16Resolution;
}