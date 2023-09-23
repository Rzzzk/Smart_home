/*
 * main.c
 *
 *  Created on: Sep 7, 2023
 *      Author: REZK
 */


/*library layer*/
#include "stdTypes.h"
#include "commonMacros.h"
#include "errorStates.h"
#include "util/delay.h"

/*MCAL layer*/
#include "EEPROM_int.h"
#include "DIO_int.h"
#include "TWI_int.h"


/*HAL*/
#include "LCD_int.h"

/*SRV*/
#include "EEPROM_serv.h"

int main(void)
{
	DIO_enuInit();
	TWI_enuInitMaster();
	LCD_enuInit();


	EEPROM_enuInit();


	EEPROM_Handler_t hn;

	EEPROM_enuRestoreData(&hn);


	if(hn.AdminID[0] == 50)
	{
		DIO_enuSetPinValue(DIO_u8PORTA, DIO_u8PIN0, DIO_u8PIN_HIGH);
	}
	else
	{
		DIO_enuSetPinValue(DIO_u8PORTA, DIO_u8PIN0, DIO_u8PIN_LOW);
	}


	if(hn.AdminPAS[0] == 11)
	{
		DIO_enuSetPinValue(DIO_u8PORTA, DIO_u8PIN1, DIO_u8PIN_HIGH);
	}
	else
	{
		DIO_enuSetPinValue(DIO_u8PORTA, DIO_u8PIN1, DIO_u8PIN_LOW);
	}


	if(hn.UserID[0] == 92)
	{
		DIO_enuSetPinValue(DIO_u8PORTA, DIO_u8PIN5, DIO_u8PIN_HIGH);
	}
	else
	{
		DIO_enuSetPinValue(DIO_u8PORTA, DIO_u8PIN5, DIO_u8PIN_LOW);
	}

	if(hn.UserPAS[0] == 15)
	{
		DIO_enuSetPinValue(DIO_u8PORTA, DIO_u8PIN6, DIO_u8PIN_HIGH);
	}
	else
	{
		DIO_enuSetPinValue(DIO_u8PORTA, DIO_u8PIN6, DIO_u8PIN_LOW);
	}

	AdminORuser_t NewAdmin = {22 , 13}; //create a new admin with id 22 and password 13
	EEPROM_enuAddAdmin(&hn, &NewAdmin);


	LCD_enuDisplayNumber((s16)hn.UserID[0]);

	while(1)
	{

	}
}
