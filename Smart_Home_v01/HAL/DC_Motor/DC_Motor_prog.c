/*
 * DC_Motor_prog.c
 *
 *  Created on: Sep 21, 2023
 *      Author: esraa
 */

#include"../../MCAL/DIO/DIO_Init.h"

#include"DC_Motor_config.h"

void DC_Motor_Init(void)
{
	DIO_enuSetPinDIR(Motor_PORT,Motor_PIN,DIO_PIN_OUTPUT);
}

void DC_Motor_ON(void)
{
	DIO_enuSetPinVAL(Motor_PORT,Motor_PIN,DIO_HIGH);
}

void DC_Motor_OFF(void)
{
	DIO_enuSetPinVAL(Motor_PORT,Motor_PIN,DIO_LOW);
}
