/*
 * app.h
 *
 *  Created on: Sep 15, 2023
 *      Author: esraa
 */

#ifndef APP_APP_H_
#define APP_APP_H_

//typedef enum{
//	ES_NOK=0,
//	ES_OK
//}LOGIN_STATUS;

void Add_default_User();
void Show_Data();

u8 Start(void);

u8 Get_ID_orPass();

u8 check_ID();

u8 check_Password();

u8 Login_verification();

u8 Display_options();

void LEDs_Control();

u8 Urgent_mode(u8 copy_u8KEYPAD_mode);

void TEMP();


#endif /* APP_APP_H_ */
