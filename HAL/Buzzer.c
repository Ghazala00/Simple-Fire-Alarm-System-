
/******************************************************************************
 *
 * Module: BUZZER
 *
 * File Name:BUZZER.c
 *
 * Description: Source file for BUZZER
 *
 * Author:Seif Alaa
 *
 *******************************************************************************/
#include "Utils.h"
#include "StdType.h"
#include "DIO_interface.h"
#include "Buzzer.h"


void Buzzer_vTurnON(void)
{
    DIO_WritePin(BUZZER_PIN,HIGH);	
}


void Buzzer_vTurnOFF(void)
{
	DIO_WritePin(BUZZER_PIN,LOW);
}

