/*
 * SWITCH_prog.c
 *
 *  Created on: Feb 12, 2023
 *      Author: esraa
 */

#include"../../LIB/stdtypes.h"
#include"../../LIB/errorstate.h"

#include"../../MCAL/DIO/DIO_Init.h"

#include"SWITCH_int.h"
#include"SWITCH_config.h"




ES_t SWITCH_init(void)
{
	DIO_enuSetPinDIR(SWITCH_PORT,SWITCH_PIN,DIO_PIN_INPUT);
	DIO_enuSetPinVAL(SWITCH_PORT,SWITCH_PIN,DIO_HIGH);
}


ES_t SWITCH_read(u8 copy_SWITCH_port,u8 copy_SWITCH_pin,u8 *value)
{
	DIO_enuGetPinval(copy_SWITCH_port,copy_SWITCH_pin,value); ///////////////////////////////!!!!!!!

}
