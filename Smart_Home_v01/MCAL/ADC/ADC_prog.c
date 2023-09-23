/*

 * ADC_prog.c
 *
 *  Created on: Apr 9, 2023
 *      Author: esraa
 */

#include"../../LIB/stdtypes.h"
#include"ADC_int.h"

void ADC_init(void)
{
	//VREF CONFIG
	ADMUX|=(MASKING_BIT<<REFS0);
	ADMUX|=(MASKING_BIT<<REFS1);
	//CHANNEL7
	ADMUX|=(MASKING_BIT<<0);
	ADMUX|=(MASKING_BIT<<1);
	ADMUX|=(MASKING_BIT<<2);
	//ENABLE ADC
	ADCSRA|=(MASKING_BIT<<ADEN);
	//AUTO TRIGGER ENABLE
	ADCSRA|=(MASKING_BIT<<ADATE);
	//CLOCK ADJ
	ADCSRA|=(MASKING_BIT<<ADPS2);
	ADCSRA|=(MASKING_BIT<<ADPS1);
	//FREE RUNNING

}


void ADC_read(u16 *copy_u16Read)
{
	ADCSRA|=(MASKING_BIT<<ADSC);
	while(((ADCSRA>>ADIF)&MASKING_BIT)==0);
	ADCSRA|=(MASKING_BIT<<ADIF);
	*copy_u16Read=(ADCL);
	*copy_u16Read|=(ADCH<<8);
}
