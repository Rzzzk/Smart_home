/*
 * timer_config.h
 *
 *  Created on: Dec 1, 2022
 *      Author: esraa
 */

#ifndef TIMER_CONFIG_H_
#define TIMER_CONFIG_H_



/************************************************************************************
*     Different prescallers in TCCR0 Register  ={TIMER0_SCALER_1,TIMER0_SCALER_8,   *
*    		                          TIMER0_SCALER_64,TIMER0_SCALER_256,           *
*    		                      	  TIMER0_SCALER_1024,TIMER0_EXTERNAL_FALLING,   *
*    		                      	  TIMER0_EXTERNAL_RISING}
*
*TIMER0_STOP
TIMER0_SCALER_1
TIMER0_SCALER_8
TIMER0_SCALER_64
TIMER0_SCALER_256
TIMER0_SCALER_1024
TIMER0_EXTERNAL_FALLING
TIMER0_EXTERNAL_RISING                       *
************************************************************************************/
#define TIMER0_PRESCALER				TIMER0_SCALER_8



/*
 * TIMER0_Normal
TIMER0_pwm_phase
TIMER0_ctc
TIMER0_pwm_fast
 */
#define TIMER0_MODE						TIMER0_Normal

/******************************************************************************
*    		       Different actions on oc0 pin in TCCR0 Register             *
*TIMER0_OC0_DISCONNECTED_MODE
TIMER0_OC0_TOGGLE_MODE
TIMER0_OC0_NON_INVERTING_MODE
TIMER0_OC0_INVERTING_MODE
******************************************************************************/


#define TIMER0_OC0_PIN_STATE TIMER0_OC0_DISCONNECTED_MODE

#endif /* TIMER_CONFIG_H_ */
