/*

 * ADC_int.h
 *
 *  Created on: Apr 9, 2023
 *      Author: esraa
 */

#ifndef ADC_INT_H_
#define ADC_INT_H_

#include"../../LIB/stdtypes.h"
/******************************************************************************
* !comment : ADC Registers Addesses Definition.  			         	      *
******************************************************************************/

#define ADMUX       *((volatile u8  *) 0x27)
#define ADCSRA      *((volatile u8  *) 0x26)
#define ADCH        *((volatile u8  *) 0x25)
#define ADCL        *((volatile u8  *) 0x24)
#define ADC         *((volatile u16 *) 0x24)
#define SFIOR       *((volatile u8  *) 0x50)


/******************************************************************************
* !comment : ADMUX Register PINS Definition.  			         	          *
******************************************************************************/

#define MUX0      0
#define MUX1      1
#define MUX2      2
#define MUX3      3
#define MUX4      4
#define ADLAR     5
#define REFS0     6
#define REFS1     7


/******************************************************************************
* !comment : ADCSRA Register PINS Definition.  			         	 		  *
******************************************************************************/

#define ADPS0     0
#define ADPS1     1
#define ADPS2     2
#define ADIE      3
#define ADIF      4
#define ADATE     5
#define ADSC      6
#define ADEN      7


/******************************************************************************
* !comment : SFIOR Register PINS Definition.  			         	 		  *
******************************************************************************/

#define ADTS0     5
#define ADTS1     6
#define ADTS2     7

#define MASKING_BIT 1

/******************************************************************************
* !comment : Driver APIs					 			         	 		  *
******************************************************************************/

void ADC_init(void);
void ADC_read(u16 *copy_u16Read);

#endif /* ADC_INT_H_ */
