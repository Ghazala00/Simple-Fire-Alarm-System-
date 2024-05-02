
/***************************************************************
       NAME    :SmokeSensor.h
	   create  : 3/10/2024 3:55:14 PM
	   version :_v1_
	   Author  :mahmoud elgohary
****************************************************************/ 

/******************************************************************************
 *
 * Module: SmokeSensor
 *
 * File Name:SmokeSensor.h
 *
 * Description: Header file for SmokeSensor
 *
 * Author:Seif Alaa
 *
 *******************************************************************************/

#ifndef SMOKESENSOR_H_
#define SMOKESENSOR_H_

#define  SMOKE_SENSOR_CH   ADC0

void SmokeSensor_vInit(void);

u8 SmokeSensor_vReadPresentage(void);

#endif /* SMOKESENSOR_H_ */