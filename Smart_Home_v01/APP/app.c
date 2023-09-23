#include <util/delay.h>

#include"../LIB/stdtypes.h"
#include"../LIB/errorstate.h"

#include"../MCAL/DIO/DIO_Init.h"
#include"../MCAL/ADC/ADC_int.h"
#include"../MCAL/TIMER/timer_init.h"
#include"../MCAL/TWI/TWI_int.h"

#include"../HAL/KEYPAD/KEYPAD_int.h"
#include"../HAL/LCD/LCD_int.h"
#include"../HAL/LED/LED_int.h"
#include"../HAL/SWITCH/SWITCH_int.h"
#include"../HAL/DC_Motor/DC_Motor_Int.h"
#include"../HAL/EEPROM/EEPROM_Int.h"

#include"../SRV/EEPROM_serv.h"

#include"app.h"





EEPROM_Handler_t GlobalPstr_User_Data;
#define eprom_counter 2
u8 user_IDs[eprom_counter]={1,2};
u8 user_Passes[eprom_counter]={77,88};

/*
 * pre: none
 * post: returns a flag indicates if it is urgent mode or not
 */
void TEMP()
{
	u16 temp_value;
	ADC_read(&temp_value);
	temp_value*=0.25;
	if(temp_value>28)
	{
		DC_Motor_ON();
	}

	if(temp_value<21)
	{
		DC_Motor_OFF();
	}
}

void Add_default_User()
{
	EEPROM_enuWriteDataByte(1,40);
	_delay_ms(50);
	EEPROM_enuWriteDataByte(77,60);
	_delay_ms(50);
	EEPROM_enuWriteDataByte(1,95);
	_delay_ms(50);
}

void Show_Data()
{
	//Show_Data();
	LCD_voidClearScreen();
	LCD_voidWriteString("Enter Index");
	u8 read;
	Keypad_enuGetPressedKey(&read);
	read-='0';
	if(read-1<GlobalPstr_User_Data.UsersCount)
	{
		LCD_voidClearScreen();
		u8 user_id=GlobalPstr_User_Data.UserID[0];
		LCD_voidWriteNumber((u16)user_id);
		u8 user_pass=GlobalPstr_User_Data.UserPAS[0];
		LCD_voidSetPosition(1,0);
		LCD_voidWriteNumber((u16)user_pass);
		_delay_ms(5000);
	}
	//LCD_voidWriteString("Enter Index");
//	u8 read;
//	Keypad_enuGetPressedKey(&read);
//	read-='0';
//	if(read-1<GlobalPstr_User_Data.UsersCount)
//	{
//		LCD_voidClearScreen();
//		u8 user_id=GlobalPstr_User_Data.UserID[read-1];
//		LCD_voidWriteNumber((u16)user_id);
//		u8 user_pass=GlobalPstr_User_Data.UserPAS[read-1];
//		LCD_voidWriteNumber((u16)user_pass);
//	}

//	for(u8 Local_u8Iterator=0;Local_u8Iterator<GlobalPstr_User_Data.UsersCount;Local_u8Iterator++)
//	{
//		LCD_voidClearScreen();
//		//LCD_voidSetPosition(0,0);
//		//LCD_voidWriteString("User ");
//		//LCD_voidSetPosition(0,5);
//		LCD_voidWriteNumber((u16)Local_u8Iterator);
//		//LCD_voidSetPosition(0,6);
//		//LCD_voidWriteString(" ID: ");
//		LCD_voidWriteNumber((u16)GlobalPstr_User_Data.UserID[Local_u8Iterator]);
//		//LCD_voidSetPosition(1,0);
//		//LCD_voidWriteString("Pass:");
//		LCD_voidWriteNumber((u16)GlobalPstr_User_Data.UserPAS[Local_u8Iterator]);
//		_delay_ms(5000);
//	}
}


u8 Start()
{
	SWITCH_init();
	ADC_init();
	LCD_voidInit();
	Keypad_enuInit();
	LED_init();
	DC_Motor_Init();
	TWI_enuInitMaster();
	//uart int

	//LCD_voidWriteString("Enter your ID");
	//LCD_voidCursorOff();
	//uart display

	/*start timer, to call TEMP every 5 seconds*/
	Timer0_enuInit();
	Timer0_enuAsysncDelay(5000);
	TIMER0_enuEnableOVF_Interrupt();
	TIMER_voidCall_Back_OVF(TEMP);
	TIMER_voidEnable_GI();

	/*Restore user Data*/
	EEPROM_enuInit();
	EEPROM_enuRestoreData(&GlobalPstr_User_Data);

	u8 flag;

	_delay_ms(500);
	SWITCH_read(DIO_u8PORTB,DIO_PIN1,&flag);

	return flag;
}


u8 Get_ID_orPass()
{
	u8 Local_u8Value=0;
	u8 Local_u8KEYPAD_read;
	u8 Local_u8Helper=100;
	for(u8 i=0;i<3;i++)
	{
		LCD_voidSetPosition(1,i);
		Keypad_enuGetPressedKey(&Local_u8KEYPAD_read);
		LCD_voidWriteData(Local_u8KEYPAD_read);
		_delay_ms(50);
		LCD_voidSetPosition(1,i);
		LCD_voidWriteData('*');
		Local_u8Value+=(Local_u8KEYPAD_read-'0')*Local_u8Helper;
		Local_u8Helper/=10;
	}
	return Local_u8Value;
}

u8 check_ID()
{
	u8 Local_u8User_ID;
	u8 Local_State=0;
	u8 Local_u8trials=0;
	while(Local_u8trials<3)
	{
		LCD_voidClearScreen();
		LCD_voidSetPosition(0,0);
		LCD_voidWriteString("Enter your ID");
		LCD_voidCursorOn();
		Local_u8User_ID=Get_ID_orPass();

		for(u8 local_u8Iterator=0;local_u8Iterator<GlobalPstr_User_Data.UsersCount;local_u8Iterator++)
		{
			if(Local_u8User_ID==GlobalPstr_User_Data.UserID[local_u8Iterator])
			{
				Local_State=1;
				return Local_State;
			}
		}

		Local_u8trials++;
		LCD_voidClearScreen();
		LCD_voidSetPosition(0,0);
		LCD_voidWriteString("Wrong ID");
		_delay_ms(500);
	}
	return Local_State;
}


u8 check_Password()
{
	u8 Local_u8User_pass;
	u8 Local_State=0;
	u8 Local_u8trials=0;
	while(Local_u8trials<3)
	{
		LCD_voidClearScreen();
		LCD_voidSetPosition(0,0);
		LCD_voidWriteString("Enter Ur Pass");
		LCD_voidCursorOn();
		Local_u8User_pass=Get_ID_orPass();

		for(u8 local_u8Iterator=0;local_u8Iterator<GlobalPstr_User_Data.UsersCount;local_u8Iterator++)
		{
			if(Local_u8User_pass==GlobalPstr_User_Data.UserPAS[local_u8Iterator])
			{
				Local_State=1;
				return Local_State;
			}
		}

		Local_u8trials++;
		LCD_voidClearScreen();
		LCD_voidSetPosition(0,0);
		LCD_voidWriteString("Wrong Password");
		_delay_ms(500);
	}
	return Local_State;
}

u8 Login_verification()
{
	u8 Local_u8Is_user=0;
	if(check_ID())
	{
		if(check_Password())
		{
			Local_u8Is_user=1;
			return Local_u8Is_user;
		}
		// else -> out of trials, take action->while 1, buzzer on
		else
		{
			while(1);
		}
	}
	else
	{
		while(1);
		//out of trials, take action
	}

}

u8 Display_options()
{
	LCD_voidClearScreen();
	LCD_voidSetPosition(0,0);
	LCD_voidWriteString("1-Users");
	LCD_voidSetPosition(1,0);
	LCD_voidWriteString("2-LEDs");
	u8 Local_Pressed_Key=0;
	Keypad_enuGetPressedKey(&Local_Pressed_Key);
	//LCD_voidClearScreen();

	return (Local_Pressed_Key-'0');
}

void LEDs_Control()
{
	LCD_voidClearScreen();
	LCD_voidSetPosition(0,0);
	LCD_voidWriteString("1-Open");
	LCD_voidSetPosition(1,0);
	LCD_voidWriteString("2-Close");

	u8 Local_Pressed_Key=0;
	Keypad_enuGetPressedKey(&Local_Pressed_Key);
	Local_Pressed_Key-='0';
	//LCD_voidClearScreen();

	if(Local_Pressed_Key==1)
	{
		LCD_voidClearScreen();
		LCD_voidSetPosition(0,0);
		LCD_voidWriteString("1-LED 1");

		LCD_voidSetPosition(1,0);
		LCD_voidWriteString("2-LED 2");

		u8 Local_Pressed_Key=0;
		Keypad_enuGetPressedKey(&Local_Pressed_Key);
		Local_Pressed_Key-='0';
		LCD_voidClearScreen();

		if(Local_Pressed_Key==1)
		{
			LED_enuON(LED1_PORT,LED1_PIN);
		}
		else if(Local_Pressed_Key==2)
		{
			LED_enuON(LED2_PORT,LED2_PIN);
		}
	}
	else if(Local_Pressed_Key==2)
	{
		LCD_voidClearScreen();
		LCD_voidSetPosition(0,0);
		LCD_voidWriteString("1-LED 1");

		LCD_voidSetPosition(1,0);
		LCD_voidWriteString("2-LED 2");

		u8 Local_Pressed_Key=0;
		Keypad_enuGetPressedKey(&Local_Pressed_Key);
		Local_Pressed_Key-='0';
		//LCD_voidClearScreen();

		if(Local_Pressed_Key==1)
		{
			LED_enuOFF(LED1_PORT,LED1_PIN);
		}
		else if(Local_Pressed_Key==2)
		{
			LED_enuOFF(LED2_PORT,LED2_PIN);
		}
	}
}

/*
 * pre: called after start()
 * post:returns a flag to indicate if it is a user or not to continue to options function
 * parameters: a keypad flag that start() returns
 */
u8 Urgent_mode(u8 copy_u8KEYPAD_mode)
{
	if(copy_u8KEYPAD_mode==0)
	{
		u8 Local_u8Is_User=0;
		Local_u8Is_User=Login_verification();
		LCD_voidCursorOff();
		LCD_voidClearScreen();
		LCD_voidSetPosition(0,0);
		LCD_voidWriteString("Succeeded");
		_delay_ms(150);
		LCD_voidClearScreen();

		u8 Local_Pressed_Key= Display_options();
		if(Local_Pressed_Key==1)
		{
			Show_Data();
		}
		else if(Local_Pressed_Key==2)
		{
			LEDs_Control();
		}


		return Local_u8Is_User;
	}
}


