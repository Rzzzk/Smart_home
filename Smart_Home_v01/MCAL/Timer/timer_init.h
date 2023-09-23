/*
 * timer_init.h
 *
 *  Created on: Dec 1, 2022
 *      Author: esraa
 */

#ifndef TIMER_INIT_H_
#define TIMER_INIT_H_

#include"../../LIB/errorstate.h"
#include "../../LIB/stdtypes.h"

/******************************************************************************
* Description 	: TIMER0 Initialization Function to select timer mode         *
*			      & Prescaler vale.                                           *
*                                                                             *
* Parameters  	: Mode( TIMER0_NORMAL_MODE, TIMER0_PHASE_CORRECT_MODE         *
* 				        TIMER0_CTC_MODE, TIMER0_FAST_PWM_MODE ).              *
* 				  Scaler( TIMER0_STOP, TIMER0_SCALER_1, TIMER0_SCALER_8,      *
* 				          TIMER0_SCALER_64, TIMER0_SCALER_256,                *
* 				          TIMER0_SCALER_1024, TIMER0_EXTERNAL_FALLING,        *
* 				          TIMER0_EXTERNAL_RISING).			   		          *
* Return type 	: void                       								  *
*******************************************************************************
* Pre_condition : none.      												  *
******************************************************************************/
ES_t Timer0_enuInit(void);


/******************************************************************************
* Description 	: TIMER0 Output Compare initialization Function to            *
*                 Select Output Compare Mode.                                 *
* Parameters  	: Output Compare Mode( TIMER0_OC0_DISCONNECTED_MODE, 		  *
* 				  TIMER0_OC0_TOGGLE_MODE, TIMER0_OC0_NON_INVERTING_MODE,      *
* 				  TIMER0_OC0_INVERTING_MODE ).								  *
* Return type 	: void                       								  *
*******************************************************************************
* Pre_condition : This function must be used after timer initialization.      *
******************************************************************************/
ES_t Timer0_enuOC0modes(u8 copy_mode);



/*************************************************************************************************
* Description 	: TIMER0 Update Duty Cycle Value Function                                        *
* 			      and put it in the OCR0 register.                                               *
* Parameters  	: Duty Cycle ( 1 ---> 100)//duty cycle= percentage to decide the speed (freq)    *
* Return type 	: void                       							                    	 *
**************************************************************************************************
* Pre_condition : This function must be used after timer initialization                          *
* 				  and output compare initialization.				 	                         *
*************************************************************************************************/
ES_t Timer0_enuSyncDlay(int copy_ms);

ES_t Timer0_enuDlayMS(int copy_ms);

ES_t Timer0_enuAsysncDelay(int copy_ms);

ES_t Timer0_enuSetPreload(u8 copy_preload);

ES_t Timer0_enuSetCTC_Value(u8 Copy_u8CTC_Value);

/*****************************************************************************/
/** Function Name   : TIMER0_enuGeneratePWM.                                **/
/** Return Type     : ERROR_STATES enum.                                    **/
/** Arguments       : Duty cycle of PWM.                                    **/
/** Functionality   : At Fast PWM, the frequency equals :                   **/
/**	                : PRE_1= 31250 Hz, PRE_8= 39026.25 Hz, PRE_64= 488.3 Hz.**/
/**	                : PRE_256= 122 Hz, PRE_1024= 30.5 Hz.                   **/
/**	                                                                        **/
/**	                : At Phase Correct PWM, the frequency equals :          **/
/**	                : PRE_1= 15686.3 Hz, PRE_8= 1960.8 Hz, PRE_64= 245.1 Hz.**/
/**	                : PRE_256= 61.3 Hz, PRE_1024= 15.3 Hz.                  **/
/*****************************************************************************/
ES_t TIMER0_enuGeneratePWM(u8 Copy_u8DutyCycle);


ES_t TIMER0_enuEnableOVF_Interrupt(void);

void TIMER0_voidEnableCTC_Interrupt(void);

void TIMER_voidCall_Back_CTC(void (*copy_pf)(void));

void TIMER_voidCall_Back_OVF(void (*copy_pf)(void));

void TIMER_voidEnable_GI();

void TIMER_voidDisable_GI();

#endif /* TIMER_INIT_H_ */
