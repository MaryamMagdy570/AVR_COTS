#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "TIMER0_register.h"
#include "TIMER0_private.h"
#include "TIMER0_config.h"
#include "TIMER0_interface.h"



void TIMER0_voidInit()
{
	//select mode
#if MODE == NORMAL
	CLR_BIT(TCCR0,WGM01);
	CLR_BIT(TCCR0,WGM00);
	TIMER0_voidEnableOverflowInterrupt();
#elif MODE == CTC
	SET_BIT(TCCR0,WGM01);
	CLR_BIT(TCCR0,WGM00);
	TIMER0_voidEnableCTCInterrupt();
#elif MODE == PWM_FAST
	CLR_BIT(TCCR0,WGM01);
	SET_BIT(TCCR0,WGM00);
#elif MODE == PWM_PHASE_CORRECT
	SET_BIT(TCCR0,WGM01);
	SET_BIT(TCCR0,WGM00);
#endif
/*
	// action on oc0
#if OC_PIN_BEHAVIOR == DISCONNECTED
	CLR_BIT(TCCR0,COM01);
	CLR_BIT(TCCR0,COM00);
	// action on oc0
#elif OC_PIN_BEHAVIOR == TOGGLE
	CLR_BIT(TCCR0,COM01);
	SET_BIT(TCCR0,COM00);
	// action on oc0
#elif OC_PIN_BEHAVIOR == DISCONNECTED
	SET_BIT(TCCR0,COM01);
	CLR_BIT(TCCR0,COM00);
	// action on oc0
#elif OC_PIN_BEHAVIOR == DISCONNECTED
	SET_BIT(TCCR0,COM01);
	SET_BIT(TCCR0,COM00);
#endif
*/


	SET_BIT(TCCR0,COM01);
	SET_BIT(TCCR0,COM00);

//selecting prescaler

#if PRESCALER == NO_CLOCK
	CLR_BIT(TCCR0,CS02);
	CLR_BIT(TCCR0,CS01);
	CLR_BIT(TCCR0,CS00);
#elif PRESCALER == NO_PRESCALER
	CLR_BIT(TCCR0,CS02);
	CLR_BIT(TCCR0,CS01);
	SET_BIT(TCCR0,CS00);
#elif PRESCALER == DIVIDE_BY_8
	CLR_BIT(TCCR0,CS02);
	SET_BIT(TCCR0,CS01);
	CLR_BIT(TCCR0,CS00);
#elif PRESCALER == DIVIDE_BY_64
	CLR_BIT(TCCR0,CS02);
	SET_BIT(TCCR0,CS01);
	SET_BIT(TCCR0,CS00);
#elif PRESCALER == DIVIDE_BY_256
	SET_BIT(TCCR0,CS02);
	CLR_BIT(TCCR0,CS01);
	CLR_BIT(TCCR0,CS00);
#elif PRESCALER == DIVIDE_BY_1024
	SET_BIT(TCCR0,CS02);
	CLR_BIT(TCCR0,CS01);
	SET_BIT(TCCR0,CS00);
#elif PRESCALER == ON_FALLING_EDGE
	SET_BIT(TCCR0,CS02);
	SET_BIT(TCCR0,CS01);
	CLR_BIT(TCCR0,CS00);
#elif PRESCALER == ON_RISING_EDGE
	SET_BIT(TCCR0,CS02)
	SET_BIT(TCCR0,CS01)
	SET_BIT(TCCR0,CS00)
#endif

}
/*
void TIMER0_voidStart()
{

}

void TIMER0_voidStop()
{

}
*/
void TIMER0_voidSetTCNT(u8 Copy_u8Data)
{
	TCNT0 = Copy_u8Data;
}

u8 TIMER0_voidGetTCNT()
{
	u8 counts = TCNT0;
	return counts;
}

void TIMER0_voidSetOCR(u8 Copy_u8Data)
{
	OCR0 = Copy_u8Data;
}


void TIMER0_voidEnableOverflowInterrupt()
{
	SET_BIT(TIMSK0,TOIE0);
}

void TIMER0_voidDisableOverflowInterrupt()
{
	CLR_BIT(TIMSK0,TOIE0);
}

void TIMER0_voidEnableCTCInterrupt()
{
	SET_BIT(TIMSK0,OCIE0);
}

void TIMER0_voidDisaableCTCInterrupt()
{
	CLR_BIT(TIMSK0,OCIE0);
}




void (*Timer0_OV_Ptr)(void) = NULL;
void (*Timer0_CTC_Ptr)(void) = NULL;

void TIMER0_OV_CallBack(void(*Ptr)(void))
{
	Timer0_OV_Ptr = Ptr;
}
void TIMER_CTC_CallBack(void(*Ptr)(void))
{
	Timer0_CTC_Ptr = Ptr;
}

void __vector_11(void) __attribute__((signal,used,externally_visible));  //to avoid optimization
void __vector_11(void)
{
	if(Timer0_OV_Ptr!= NULL)
		Timer0_OV_Ptr();
}

void __vector_10(void) __attribute__((signal,used,externally_visible));  //to avoid optimization
void __vector_10(void)
{
	if(Timer0_CTC_Ptr!= NULL)
		Timer0_CTC_Ptr();
}

