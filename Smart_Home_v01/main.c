/*
 * main.c
 *
 *  Created on: Sep 21, 2023
 *      Author: esraa
 */
#include <util/delay.h>
#include"LIB/stdtypes.h"

#include"APP/app.h"


#include"MCAL/DIO/DIO_Init.h"

#include"MCAL/ADC/ADC_int.h"

#include"HAL/LCD/LCD_int.h"
#include"HAL/KEYPAD/KEYPAD_int.h"


#include"HAL/EEPROM/EEPROM_Int.h"

#include"SRV/EEPROM_serv.h"
#include"MCAL/TWI/TWI_int.h"


int main()
{

	/*
	 * testing
	 */

	DIO_enuSetPinDIR(DIO_u8PORTC,DIO_PIN0,DIO_PIN_OUTPUT);
	DIO_enuSetPinDIR(DIO_u8PORTC,DIO_PIN1,DIO_PIN_OUTPUT);
	/* test start function return, 0 is expected */
	u8 flag=Start();

	Urgent_mode(flag);



	/* */

	while(1)
	{
		//TEMP();

	}
}
