/*
 * timer_priv.h
 *
 *  Created on: Dec 1, 2022
 *      Author: esraa
 */

#ifndef TIMER_PRIV_H_
#define TIMER_PRIV_H_

/******************************************************************************
* !comment : TIMER0 Registers Addresses Definition.  			         	  *
******************************************************************************/
#define TCCR0    *((volatile u8 *) 0X53)
#define TCNT0    *((volatile u8 *) 0x52)
#define OCR0     *((volatile u8 *) 0x5C)
#define TIMSK    *((volatile u8 *) 0x59)
#define TIFR     *((volatile u8 *) 0x58)
#define SREG     *((volatile u8 *) 0x5F)


#define TIMER0_F_CPU								1000.0
#define TIMER0_OVF_COUNTS							256
#define TIMER0_PHASE_COUNTS							510
#define TIMER0_PERCENTAGE_RATIO						100.0
#define TIMER0_FIXED_NUM_TWO						2.0


/******************************************************************************
* different prescalling modes                       			         	  *
******************************************************************************/
#define TIMER0_STOP              0
#define	TIMER0_SCALER_1          1
#define	TIMER0_SCALER_8          2
#define	TIMER0_SCALER_64         3
#define	TIMER0_SCALER_256        4
#define	TIMER0_SCALER_1024       5
#define	TIMER0_EXTERNAL_FALLING  6
#define	TIMER0_EXTERNAL_RISING   7



#define TIMER0_VIOD_SET_PRELOAD(COPY_U8PRELOAD)			TCNT0=COPY_U8PRELOAD
#define TIMER0_STOPTIMER                                     TCCR0=0

/******************************************************************************
*    		       Different modes in TCCR0 Register              	      	  *
******************************************************************************/
#define TIMER0_Normal     0
#define TIMER0_pwm_phase  1
#define TIMER0_ctc        2
#define TIMER0_pwm_fast   3


/******************************************************************************
*    		                TCCR0 register pins                 	      	  *
******************************************************************************/
#define CS00      (u8)0
#define CS01      (u8)1
#define CS02      (u8)2
#define WGM01     (u8)3
#define COM00     (u8)4
#define COM01     (u8)5
#define WGM00     (u8)6
#define FOC0      (u8)7

/******************************************************************************
*    		                TIMSK register pins                 	      	  *
******************************************************************************/
#define TOIE0      (u8)0
#define OCIE0      (u8)1

/******************************************************************************
*    		                SREG register pins        	         	      	  *
******************************************************************************/
#define GI         (u8)7

/******************************************************************************
*    		       Different actions on oc0 pin in TCCR0 Register             *
******************************************************************************/
#define TIMER0_OC0_DISCONNECTED_MODE    0
#define	TIMER0_OC0_TOGGLE_MODE          1
#define	TIMER0_OC0_NON_INVERTING_MODE   2
#define	TIMER0_OC0_INVERTING_MODE       3
#define	TIMER0_OC0_CLEAR_MODE           4
#define	TIMER0_OC0_SET_MODE             5


#define TIMER0_VOIDPRELOAD(COPY_U8PRELOAD)      TCNT0=COPY_U8PRELOAD
#define TIMER0_VOIDSETCTC(COPY_U8VALUE)         OCR0=COPY_U8VALUE


/******************************************************************************
*      	      	           ISR attribute.       	      					  *
******************************************************************************/

#define ISR(vector)\
void vector (void) __attribute__((signal));\
void vector (void)



/*****************************************************************************/
/**            Definitions of Vector Number of TIMER0 OVF and CTC           **/
/*****************************************************************************/
#define TIMER0_OVF_VEC								__vector_11
#define TIMER0_CTC_VEC								__vector_10



#define masking_bit								    1
#define NULL 									   ((void *)0)

#endif /* TIMER_PRIV_H_ */
