#ifndef _TIMER1_INTERFACE_H_
#define _TIMER1_INTERFACE_H_


void TIMER1_voidInit();

void TIMER1_voidSetTCNT(u16 Copy_u8Data);

u16 TIMER1_voidGetTCNT();

void TIMER1_voidSetOCRA(u16 Copy_u16Data);

void TIMER1_voidSetICR(u16 Copy_u16Data);



/*
void TIMER1_voidEnableOverflowInterrupt();
void TIMER1_voidEnableCTCInterrupt();


void TIMER1_OV_CallBack(void(*Ptr)(void));

void TIMER_CTC_CallBack(void(*Ptr)(void));


void __vector_11(void) __attribute__((signal,used,externally_visible));  //to avoid optimization
void __vector_11(void);

void __vector_10(void) __attribute__((signal,used,externally_visible));  //to avoid optimization
void __vector_10(void);
*/



#endif
