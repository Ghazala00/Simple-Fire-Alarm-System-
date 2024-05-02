
/******************************************************************************
 *
 * Module: Motor Switch
 *
 * File Name:Switch.c
 *
 * Description: Source file for Motor Switch
 *
 * Author:Seif Alaa
 *
 *******************************************************************************/



#include "Utils.h"
#include "StdType.h"
#include "DIO_interface.h"
#include "Switch.h"




void Switch_vEN(void)
{
    DIO_WritePin(SWITCH1,HIGH);
}

void Switch_vDisable(void)
{
	DIO_WritePin(SWITCH1,LOW);
}