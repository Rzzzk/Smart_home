/*
 * LED.c
 */

#include"../../LIB/stdtypes.h"
#include"../../LIB/errorstate.h"


#include"../../MCAL/DIO/DIO_Init.h"

#include"LED_priv.h"
#include"LED_config.h"
//#include"LED_int.h"

ES_t LED_init(void)
{
	DIO_enuSetPinDIR(LED1_PORT,LED1_PIN,DIO_PIN_OUTPUT);
	DIO_enuSetPinDIR(LED2_PORT,LED2_PIN,DIO_PIN_OUTPUT);
}

ES_t LED_enuON(u8 copy_port,u8 copy_pin)
{
	DIO_enuSetPinVAL(copy_port,copy_pin,DIO_HIGH);
}

ES_t LED_enuOFF(u8 copy_port,u8 copy_pin)
{
	DIO_enuSetPinVAL(copy_port,copy_pin,DIO_LOW);
}

ES_t LED_enuTOG(u8 copy_port,u8 copy_pin)
{
	DIO_enuTogPin(copy_port,copy_pin);
}
