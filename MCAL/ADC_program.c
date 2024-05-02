

/******************************************************************************
 *
 * Module: ADC_program
 *
 * File Name:ADC_program.c
 *
 * Description: source file for ADC program
 
 * Author:Seif Alaa
 *
 *******************************************************************************/

#include "Utils.h"
#include "StdType.h"
#include "ADC_interface.h"
#include "ADC_config.h"
#include "ADC_Private.h"
#include "Vector_Table.h"

void ADC_vInit(ADC_Prescaler_t Copy_enumPrescaler, ADC_Vref_t Copy_enumVoltRef )
{
		// clock
		ADCSRA=ADCSRA&0xf8;
		ADCSRA=ADCSRA|Copy_enumPrescaler;
		
		switch(Copy_enumVoltRef)
		{
			case Vref_AREV:
			CLR_BIT(ADMUX,REFS0);
			CLR_BIT(ADMUX,REFS1);
			break;
			case Vref_AVCC:
			SET_BIT(ADMUX,REFS0);
			CLR_BIT(ADMUX,REFS1);
			break;
			case Vref_256:
			SET_BIT(ADMUX,REFS0);
			SET_BIT(ADMUX,REFS1);
			break;
		}
		
		CLR_BIT(ADCSRA,ADIE);//Disable interrupt
		
		CLR_BIT(ADCSRA,ADATE);//Disable Auto trigger
		
		// way of store result in reg
		#if ADC_ADJUST_MODE ==  ADC_LEFT_ADJUST
		SET_BIT(ADMUX,ADLAR);  
		#else
		CLR_BIT(ADMUX,ADLAR);
		#endif
		
		SET_BIT(ADCSRA,ADEN);   //ADC enable
}

/****************************************************************************************************************************/

u16 ADC_vReadDigitalValueSingleConversionBlocking(ADC_Channel_t Copy_enumChannel)
{
	/* select channel*/
	ADMUX=ADMUX&0xE0;
	ADMUX=ADMUX|Copy_enumChannel;
	/*Disable Auto trigger*/
	CLR_BIT(ADCSRA,ADATE);
	/* start conversion*/
	SET_BIT(ADCSRA,ADSC);
	/* wait until conversion end*/
	while(READ_BIT(ADCSRA,ADSC));  //busy wait or blocking loop
	/* read register */
	CLR_BIT(ADCSRA,ADIF);//Clear flag interrupt
	return ADC;
}
 




/****************************************************************************************************************************/
void ADC_vEnableInterrupt(void)
{
	/*Enable Interrupt conversion complete*/
	SET_BIT(ADCSRA,ADIE);
	//default global interrupt enable
}
/****************************************************************************************************************************/
void ADC_vDisableInterrupt(void)
{
	/*Disable Interrupt*/
	CLR_BIT(ADCSRA,ADIE);
}
/****************************************************************************************************************************/
 void ADC_vEnableADC(void)
 {
	 SET_BIT(ADCSRA,ADEN);   //ADC enable
 }
/****************************************************************************************************************************/
 void ADC_vDisableADC(void)
 {
	 CLR_BIT(ADCSRA,ADEN);   //ADC Disable
 }
/****************************************************************************************************************************/

void ADC_vSetVoltReference(ADC_Vref_t copy_enumVref)
{
    switch(copy_enumVref)
    {
    	case Vref_AREV:
    	CLR_BIT(ADMUX,REFS0);
    	CLR_BIT(ADMUX,REFS1);
    	break;
    	case Vref_AVCC:
    	SET_BIT(ADMUX,REFS0);
    	CLR_BIT(ADMUX,REFS1);
    	break;
    	case Vref_256:
    	SET_BIT(ADMUX,REFS0);
    	SET_BIT(ADMUX,REFS1);
    	break;
    }	
}

