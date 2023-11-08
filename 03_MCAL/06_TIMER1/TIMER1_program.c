#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "TIMER1_register.h"
#include "TIMER1_private.h"
#include "TIMER1_config.h"
#include "TIMER1_interface.h"



void TIMER1_voidInit()
{
	//DIVIDE BY 64
	CLR_BIT(TCCR1B,CS12);
	SET_BIT(TCCR1B,CS11);
	SET_BIT(TCCR1B,CS10);

	//MODE 14
	CLR_BIT(TCCR1A,WGM10);
	SET_BIT(TCCR1A,WGM11);
	SET_BIT(TCCR1B,WGM12);
	SET_BIT(TCCR1B,WGM13);

	//OC
	SET_BIT(TCCR1A,COM1A1);
	CLR_BIT(TCCR1A,COM1A0);


}

void TIMER1_voidSetTCNT(u16 Copy_u16Data)
{
	TCNT1 = Copy_u16Data;
}

u16 TIMER1_voidGetTCNT()
{
	u16 counts = TCNT1;
	return counts;
}


void TIMER1_voidSetOCRA(u16 Copy_u16Data)
{
	OCR1A = Copy_u16Data;
}

void TIMER1_voidSetICR(u16 Copy_u16Data)
{
	ICR = Copy_u16Data;

}



/*
void TIMER1_voidEnableOverflowInterrupt()
{
	SET_BIT(TIMSK,TOIE0);
}

void TIMER1_voidDisableOverflowInterrupt()
{
	CLR_BIT(TIMSK,TOIE0);
}

void TIMER1_voidEnableCTCInterrupt()
{
	SET_BIT(TIMSK0,OCIE0);
}

void TIMER1_voidDisaableCTCInterrupt()
{
	CLR_BIT(TIMSK0,OCIE0);
}

*/





