/*
 * EEPROM_serv.c
 *
 *  Created on: Sep 21, 2023
 *      Author: REZK
 */

/*library layer*/
#include "../LIB/stdtypes.h"
#include "../LIB/commonMacros.h"
#include "../LIB/errorstate.h"
#include "util/delay.h"

/*MCAL layer*/
#include "../HAL/EEPROM/EEPROM_int.h"

/*services layer*/
#include "EEPROM_serv.h"

#include"../HAL/LCD/LCD_int.h"


ES_t EEPROM_enuRestoreData(EEPROM_Handler_t *Copy_pstrEEPROMHandler)
{
	ES_t Local_enuErrState=ES_NOK;

	u8 temp ;

	/*at first read the admins and users count*/
	EEPROM_enuReadDataByte(&(Copy_pstrEEPROMHandler->AdminsCount) , 90); // number of admins
	_delay_ms(50);
	EEPROM_enuReadDataByte(&(Copy_pstrEEPROMHandler->UsersCount)  , 95); // number of users
	_delay_ms(50);


	/*******************************************************
	               array of admins IDs
	 ******************************************************/

	/*Admin ID from address 0 to 19*/
	temp = Copy_pstrEEPROMHandler->AdminsCount;
	for(u8 i=0 ; i<temp; i++)
	{
		EEPROM_enuReadDataByte((Copy_pstrEEPROMHandler->AdminID + i) , i);
		_delay_ms(50);
	}

	/*******************************************************
	               array of admins passwords
	 ******************************************************/

	/*Admin password from address 20 to 39*/
	temp = Copy_pstrEEPROMHandler->AdminsCount + 20;
	for(u8 i=20 ; i<temp ; i++)
	{
		u8 Local_u8ArrIndex = 0;

		EEPROM_enuReadDataByte((Copy_pstrEEPROMHandler->AdminPAS + Local_u8ArrIndex) , i);
		Local_u8ArrIndex++;

		_delay_ms(50);
	}



	/*******************************************************
	               array of users IDs
	 ******************************************************/
	/*User ID from address 40 to 59*/
	temp = Copy_pstrEEPROMHandler->UsersCount + 40;
	for(u8 i=40 ; i<temp ; i++)
	{
		u8 Local_u8ArrIndex = 0;

		EEPROM_enuReadDataByte((Copy_pstrEEPROMHandler->UserID + Local_u8ArrIndex) , i);
		Local_u8ArrIndex++;

		_delay_ms(50);
	}


	/*******************************************************
	               array of users passwords
	 ******************************************************/
	/*User password from address 60 to 79*/
	temp = Copy_pstrEEPROMHandler->UsersCount + 60;
	for(u8 i=60 ; i<temp ;i++)
	{
		u8 Local_u8ArrIndex = 0;

		EEPROM_enuReadDataByte((Copy_pstrEEPROMHandler->UserPAS + Local_u8ArrIndex) , i);
		Local_u8ArrIndex++;

		_delay_ms(50);
	}

	Local_enuErrState=ES_OK;

	return Local_enuErrState;
}




/*
 * add admin in system
 */
ES_t EEPROM_enuAddAdmin(EEPROM_Handler_t *Copy_pstrEEPROMHandler , AdminORuser_t* Copy_pstrAdmin)
{
	ES_t Local_enuErrState=ES_NOK;

	if(Copy_pstrEEPROMHandler->AdminsCount < 20)
	{
		/*add the admin in the array*/
		Copy_pstrEEPROMHandler->AdminID[Copy_pstrEEPROMHandler->AdminsCount] = Copy_pstrAdmin->ID ;
		Copy_pstrEEPROMHandler->AdminPAS[Copy_pstrEEPROMHandler->AdminsCount] = Copy_pstrAdmin->Password ;

		/*add the admin in EEPROM*/
		EEPROM_enuWriteDataByte(Copy_pstrAdmin->ID, Copy_pstrEEPROMHandler->AdminsCount);
		_delay_ms(50);
		EEPROM_enuWriteDataByte(Copy_pstrAdmin->Password, Copy_pstrEEPROMHandler->AdminsCount+20);
		_delay_ms(50);

		/*save the number of admins*/
		Copy_pstrEEPROMHandler->AdminsCount++;
		EEPROM_enuWriteDataByte(Copy_pstrEEPROMHandler->AdminsCount, 90);
		_delay_ms(50);
		Local_enuErrState=ES_OK;
	}
	else
	{
		/*the system has max number admins */
		Local_enuErrState=ES_NOK;
	}

	return Local_enuErrState;
}

/*
 * add user in system
 */
ES_t EEPROM_enuAddUser(EEPROM_Handler_t *Copy_pstrEEPROMHandler , AdminORuser_t* Copy_pstrUser)
{
	ES_t Local_enuErrState=ES_NOK;
	if(Copy_pstrEEPROMHandler->AdminsCount < 20)
	{
		/*add the admin in the array*/
		Copy_pstrEEPROMHandler->UserID[Copy_pstrEEPROMHandler->UsersCount] = Copy_pstrUser->ID ;
		Copy_pstrEEPROMHandler->UserPAS[Copy_pstrEEPROMHandler->UsersCount] = Copy_pstrUser->Password ;

		/*add the admin in EEPROM*/
		EEPROM_enuWriteDataByte(Copy_pstrUser->ID, Copy_pstrEEPROMHandler->UsersCount + 40);
		_delay_ms(50);
		EEPROM_enuWriteDataByte(Copy_pstrUser->Password, Copy_pstrEEPROMHandler->UsersCount +60);
		_delay_ms(50);

		/*save the number of admins*/
		Copy_pstrEEPROMHandler->UsersCount++;
		EEPROM_enuWriteDataByte(Copy_pstrEEPROMHandler->UsersCount, 95);
		_delay_ms(50);
		Local_enuErrState=ES_OK;
	}
	else
	{
		/*the system has max number admins */
		Local_enuErrState=ES_NOK;
	}

	return Local_enuErrState;
}


/*
 * remove admin in system
 */
ES_t EEPROM_enuRemoveAdmin(EEPROM_Handler_t *Copy_pstrEEPROMHandler , AdminORuser_t* Copy_pstrAdmin)
{
	ES_t Local_enuErrState=ES_NOK;

	return Local_enuErrState;
}

/*
 * remove user in system
 */
ES_t EEPROM_enuRemoveUser(EEPROM_Handler_t *Copy_pstrEEPROMHandler , AdminORuser_t* Copy_pstrUser)
{
	ES_t Local_enuErrState=ES_NOK;

	return Local_enuErrState;
}





