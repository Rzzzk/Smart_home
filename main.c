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

#include "EEPROM_serv.h"






int main(void)
{
	DIO_enuInit();
	TWI_enuInitMaster();


	EEPROM_Handler_t hn;

	AdminORuser_t ADMIN;
	ADMIN.ID = 20;
	ADMIN.Password = 5;

	EEPROM_enuRestoreData(&hn);

    EEPROM_enuAddAdmin(&hn, &ADMIN);


	u8 Admin0;

	Admin0 = hn.AdminsCount;


	while(1)
	{

	}
}
