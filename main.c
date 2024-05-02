#include "StdType.h"
#include "Utils.h"
#include "DIO_interface.h"
#include "LCD_interface.h"
#include "ADC_interface.h"
#include "FireAlarmSystem.h"
#include "LM35.h"
#include "POT.h"
#include "SmokeSensor.h"
#include "ADC_SERVICE.h"

int main(void)
{
    DIO_Init();
	LCD_vInit();
	ADC_vInit(ADC_Prescaler64,Vref_AVCC);
    FIREALARMSYSTEM_voidAlarmSystemIntit();
    while (1) 
    {
	   FIREALARMSYSTEM_voidAlarmSystemRunnable();
    }
}

