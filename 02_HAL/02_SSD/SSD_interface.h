#ifndef _SSD_INTERFACE_H_
#define _SSD_INTERFACE_H_


#define SSD_u8ANODE		1	//COM ON VCC , PINS ON ZERO
#define SSD_u8CATHODE	2	//COM ON ZERO , PINS ON VCC

#define SSD_u8ZERO 		0b00111111
#define SSD_u8ONE 		0b00000110
#define SSD_u8TWO 		0b01011011
#define SSD_u8THREE 	0b01001111
#define SSD_u8FOUR 		0b01100110
#define SSD_u8FIVE 		0b01101101
#define SSD_u8SIX 		0b01111101
#define SSD_u8SEVEN 	0b00000111
#define SSD_u8EIGHT 	0b01111111
#define SSD_u8NINE 		0b01101111


u8 SSD_u8number[10]={SSD_u8ZERO, SSD_u8ONE, SSD_u8TWO, SSD_u8THREE, SSD_u8FOUR, SSD_u8FIVE, SSD_u8SIX, SSD_u8SEVEN, SSD_u8EIGHT, SSD_u8NINE};


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
	SSD_u8SetNum(5,Ptr1);  or SSD_u8SetNum(5,&SSD1);
	..
	..
	..
*/


u8 SSD_u8SetNum(u8 Copy_u8Num, SSD_t* info);

u8 SSD_u8Enable(SSD_t* info);

u8 SSD_u8Disable(SSD_t* info);





#endif