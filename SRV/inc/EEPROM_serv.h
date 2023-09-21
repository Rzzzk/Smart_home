/*
 * EEPROM_serv.h
 *
 *  Created on: Sep 21, 2023
 *      Author: REZK
 */

#ifndef SRV_INC_EEPROM_SERV_H_
#define SRV_INC_EEPROM_SERV_H_

typedef struct
{
	u8 AdminID[20];
	u8 AdminPAS[20];
	u8 AdminsCount;
	u8 UserID[20];
	u8 UserPAS[20];
	u8 UsersCount;
}EEPROM_Handler_t;

typedef struct
{
	u8 ID;
	u8 Password;

}AdminORuser_t;



/*
 * restore all data from EEPROM to the handler
 */
ES_t EEPROM_enuRestoreData(EEPROM_Handler_t *Copy_pstrEEPROMHandler);


/*
 * add admin in system
 */
ES_t EEPROM_enuAddAdmin(EEPROM_Handler_t *Copy_pstrEEPROMHandler , AdminORuser_t* Copy_pstrAdmin);

/*
 * add user in system
 */
ES_t EEPROM_enuAddUser(EEPROM_Handler_t *Copy_pstrEEPROMHandler , AdminORuser_t* Copy_pstrUser);


/*
 * remove admin in system
 */
ES_t EEPROM_enuRemoveAdmin(EEPROM_Handler_t *Copy_pstrEEPROMHandler , AdminORuser_t* Copy_pstrAdmin);

/*
 * remove user in system
 */
ES_t EEPROM_enuRemoveUser(EEPROM_Handler_t *Copy_pstrEEPROMHandler , AdminORuser_t* Copy_pstrAdmin);


#endif /* SRV_INC_EEPROM_SERV_H_ */
