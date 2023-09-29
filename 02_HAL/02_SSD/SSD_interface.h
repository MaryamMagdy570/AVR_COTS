#ifndef _SSD_INTERFACE_H_
#define _SSD_INTERFACE_H_


#define SSD_u8ANODE		1	//COM ON VCC , PINS ON ZERO
#define SSD_u8CATHODE	2	//COM ON ZERO , PINS ON VCC

typedef struct{
	u8 Com_Type;
	u8 Port;
	u8 Enable_Port;
	u8 Enable_Pin;
}SSD_t;

/* in main:
	#include "SSD_interface"
	#include "DIO_interface"
	SSD_t SSD1={SSD_u8ANODE,DIO_u8PORTA,DIO_u8PORTC,DIO_u8PIN0}
	SSD_t* Ptr1 = &SSD1;
	SSD_u8Enable(Ptr1);
	SSD_u8SetNum(5,Ptr1);
	..
	..
	..
*/


u8 SSD_u8SetNum(u8 Copy_u8Num, SSD_t* info);

u8 SSD_u8Enable(SSD_t* info);

u8 SSD_u8Disable(SSD_t* info);





#endif