/*
 * timer_prog.c
 *
 *  Created on: Dec 1, 2022
 *      Author: esraa
 */

#include <math.h>

#include"../../LIB/errorstate.h"
#include "../../LIB/stdtypes.h"

#include"timer_priv.h"
#include"timer_config.h"

u8 u8_OVF_num=0;
void (*TIMER0_OVF_CallBack)(void)= NULL;
void (*TIMER0_CTC_CallBack)(void)= NULL;


ES_t Timer0_enuInit()
{
#if TIMER0_PRESCALER==TIMER0_STOP

#elif TIMER0_PRESCALER==TIMER0_SCALER_1
	TCCR0|=(masking_bit<<CS00);
#elif TIMER0_PRESCALER==TIMER0_SCALER_8
	TCCR0|=(masking_bit<<CS01);
#elif TIMER0_PRESCALER==TIMER0_SCALER_64
	TCCR0|=(masking_bit<<CS00);
	TCCR0|=(masking_bit<<CS01);
#elif TIMER0_PRESCALER==TIMER0_SCALER_256
	TCCR0|=(masking_bit<<CS02);
#elif TIMER0_PRESCALER==TIMER0_SCALER_1024
	TCCR0|=(masking_bit<<CS00);
	TCCR0|=(masking_bit<<CS02);
#elif TIMER0_PRESCALER==TIMER0_EXTERNAL_FALLING
	TCCR0|=(masking_bit<<CS01);
	TCCR0|=(masking_bit<<CS02);
#elif TIMER0_PRESCALER==TIMER0_EXTERNAL_RISING
	TCCR0|=(masking_bit<<CS00);
	TCCR0|=(masking_bit<<CS01);
	TCCR0|=(masking_bit<<CS02);
#endif

#if TIMER0_MODE==TIMER0_Normal

//default

#elif TIMER0_MODE==TIMER0_pwm_phase
	TCCR0|=(masking_bit<<WGM00);

#if TIMER0_OC0_PIN_STATE==TIMER0_OC0_DISCONNECTED_MODE
	//0 0
#elif TIMER0_OC0_PIN_STATE==TIMER0_OC0_NON_INVERTING_MODE
	TCCR0|=(masking_bit<<COM01);// 01
#elif TIMER0_OC0_PIN_STATE==TIMER0_OC0_INVERTING_MODE
	TCCR0|=(masking_bit<<COM00);// 11
	TCCR0|=(masking_bit<<COM01);
#else
	#error"Attention!!, OC0_PIN state is wrong or the mode is not CTC...."
	#endif

#elif TIMER0_MODE==TIMER0_ctc
	//wave
	TCCR0|=(masking_bit<<WGM01);
	//0c0
#if TIMER0_OC0_PIN_STATE==TIMER0_OC0_DISCONNECTED_MODE
#elif TIMER0_OC0_PIN_STATE==TIMER0_OC0_TOGGLE_MODE
	TCCR0|=(masking_bit<<COM00);
#elif TIMER0_OC0_PIN_STATE==TIMER0_OC0_CLEAR_MODE
	TCCR0|=(masking_bit<<COM01);
#elif TIMER0_OC0_PIN_STATE==TIMER0_OC0_SET_MODE
	TCCR0|=(masking_bit<<COM00);
	TCCR0|=(masking_bit<<COM00);
#else
	#error"Attention!!, OC0_PIN state is wrong or the mode is not CTC...."
	#endif


#elif TIMER0_MODE==TIMER0_pwm_fast
	//wave generator setting
	TCCR0|=(masking_bit<<WGM00);
	TCCR0|=(masking_bit<<WGM01);
	//oc0 settings
#if TIMER0_OC0_PIN_STATE==TIMER0_OC0_DISCONNECTED_MODE
	//0 0
#elif TIMER0_OC0_PIN_STATE==TIMER0_OC0_NON_INVERTING_MODE
	TCCR0|=(masking_bit<<COM01);// 01
#elif TIMER0_OC0_PIN_STATE==TIMER0_OC0_INVERTING_MODE
	TCCR0|=(masking_bit<<COM00);// 11
	TCCR0|=(masking_bit<<COM01);
#else
	#error"Attention!!, OC0_PIN state is wrong or the mode is not CTC...."
	#endif

#endif
	return ES_OK;
}

ES_t Timer0_enuSetPreload(u8 copy_u8preload)
{
	TIMER0_VOIDPRELOAD(copy_u8preload);
	//return ES_OK;
}


ES_t Timer0_enuSetCTC_Value(u8 Copy_u8CTC_Value)
{
	TIMER0_VOIDSETCTC(Copy_u8CTC_Value);
	//return ES_OK;
}





ES_t Timer0_enuAsysncDelay(int copy_ms)
{
	if(TIMER0_MODE==TIMER0_Normal)
	{
		//(TIMER0_PRESCALER==TIMER0_SCALER_1||TIMER0_PRESCALER==TIMER0_SCALER_8)&&
	    float local_ovf_t= (float)TIMER0_OVF_COUNTS * ((float)TIMER0_PRESCALER/TIMER0_F_CPU);
		float local_ovf_num= copy_ms/local_ovf_t;
		u8_OVF_num=(int)local_ovf_num;
		if(local_ovf_num-(int)local_ovf_num!=0.0)
		{
			//int int_ovf_num=(int)ovf_num+1;
			int preload=TIMER0_OVF_COUNTS-((local_ovf_num-(int)local_ovf_num)*256);
			u8_OVF_num=ceil(local_ovf_num)+1;
			TIMER0_VIOD_SET_PRELOAD(preload);
		}
	}
	else if(TIMER0_MODE==TIMER0_ctc&&OCR0>0)				//
	{
		float local_ovf_t= (float)OCR0+1 * ((float)TIMER0_PRESCALER/TIMER0_F_CPU);
		float local_ovf_num= copy_ms/local_ovf_t;
		u8_OVF_num=(int)local_ovf_num;
		if(local_ovf_num-(int)local_ovf_num!=0.0)
		{
			int preload=TIMER0_OVF_COUNTS-((local_ovf_num-(int)local_ovf_num)*TIMER0_OVF_COUNTS);
			u8_OVF_num=(int)local_ovf_num+1;
			TIMER0_VIOD_SET_PRELOAD(preload);
	  }
	}
	else
	{
		#warning "Attention!!, Delay function has no effect at this mode or prescaler...."
		#warning "To take high accuracy on Delay function, Choose OVF mode and one or eight prescaler";\
		 "OR CTC mode , 64 prescaler and OCR0 = 124"
	}


}


ES_t TIMER0_enuGeneratePWM(int Copy_u8DutyCycle)
{
if(TIMER0_MODE==TIMER0_pwm_fast){
#if   TIMER0_OC0_PIN_STATE == TIMER0_OC0_NON_INVERTING_MODE
		u8 Local_u8OCR_Value = ((f32)Copy_u8DutyCycle/TIMER0_PERCENTAGE_RATIO) * (f32)TIMER0_OVF_COUNTS;
		TIMER0_VOIDSETCTC(--Local_u8OCR_Value);
#elif TIMER0_OC0_PIN_STATE == TIMER0_OC0_INVERTING_MODE
		u8 Local_u8OCR_Value = TIMER0_OVF_COUNTS - (TIMER0_OVF_COUNTS * ((f32)Copy_u8DutyCycle /TIMER0_PERCENTAGE_RATIO));
		TIMER0_VOIDSETCTC(--Local_u8OCR_Value);
#else
	//#error"Attention!!, OC0_PIN state is wrong or the mode is not Fast PWM...."
	#endif

}
else if(TIMER0_MODE==TIMER0_pwm_phase){
#if   TIMER0_OC0_PIN_STATE == TIMER0_OC0_NON_INVERTING_MODE
	u8 Local_u8OCR_Value = (TIMER0_PHASE_COUNTS * (f32)((f32)Copy_u8DutyCycle /(TIMER0_PERCENTAGE_RATIO * TIMER0_FIXED_NUM_TWO)));
		TIMER0_VOIDSETCTC(--Local_u8OCR_Value);
#elif TIMER0_OC0_PIN_STATE == TIMER0_OC0_INVERTING_MODE
		u8 Local_u8OCR_Value = (TIMER0_PHASE_COUNTS / TIMER0_FIXED_NUM_TWO)-(TIMER0_PHASE_COUNTS * (f32)((f32)Copy_u8DutyCycle /(TIMER0_PERCENTAGE_RATIO * TIMER0_FIXED_NUM_TWO)));
		TIMER0_VOIDSETCTC(--Local_u8OCR_Value);
#else
	//#error"Attention!!, OC0_PIN state is wrong or the mode is not Fast PWM...."
	#endif
}

}

//

ES_t Timer0_enuSyncDlay(int copy_ms)
{
	    float ttick=TIMER0_PRESCALER/TIMER0_F_CPU;
		float tmaxdelay=TIMER0_OVF_COUNTS*ttick;  //ovf real time
		char nof,preload;
		if(copy_ms<tmaxdelay)
		{
			nof=1;
			preload=TIMER0_OVF_COUNTS-(((float)copy_ms/tmaxdelay)*(float)TIMER0_OVF_COUNTS);//(tmaxdelay-copy_ms)/ttick;
		}
		else if(copy_ms==(int)tmaxdelay)
		{
			nof=1;
			preload=0;
		}
		else
		{
			nof=ceil((float)copy_ms/tmaxdelay);
			float fraction =((float)copy_ms/tmaxdelay)-((int)(float)copy_ms/tmaxdelay);
			preload=TIMER0_OVF_COUNTS-(fraction*(float)TIMER0_OVF_COUNTS);
					//TIMER0_OVF_COUNTS-(copy_ms/ttick)/nof;
		}
		TIMER0_VIOD_SET_PRELOAD(0);
		TIMER0_VIOD_SET_PRELOAD(preload);
		while(nof>0)
		{
			while(((TIFR>>0)&1)==0);
			nof--;
			TIFR|=(1<<0);
		}
}

void TIMER0_voidEnableCTC_Interrupt(void)
{
	TIMSK|=(masking_bit<<OCIE0);
	TIMSK&=~(masking_bit<<TOIE0);
}


ES_t TIMER0_enuEnableOVF_Interrupt(void)
{
	TIMSK|=(masking_bit<<TOIE0);
	TIMSK&=~(masking_bit<<OCIE0);
}


void TIMER_voidEnable_GI()
{
	SREG|=(masking_bit<<GI);
}

void TIMER_voidDisable_GI()
{
	SREG&=~(masking_bit<<GI);
}

void TIMER_voidCall_Back_OVF(void (*copy_pf)(void))
{
	if(copy_pf!=NULL)
	{
		TIMER0_OVF_CallBack=copy_pf;
	}
}

void TIMER_voidCall_Back_CTC(void (*copy_pf)(void))
{
	if(copy_pf!=NULL)
	{
		TIMER0_CTC_CallBack=copy_pf;
	}
}


ISR(TIMER0_OVF_VEC)
{
	static u32 local_count=0;
	local_count++;
	if(u8_OVF_num==local_count){
		//TIMER0_STOPTIMER;
		TIMER0_OVF_CallBack();
		local_count=0;
	}
}


ISR(TIMER0_CTC_VEC)
{
	static u32 local_count=0;
	local_count++;
	if(u8_OVF_num==local_count){
		TIMER0_STOPTIMER;
		local_count=0;
	}
}
