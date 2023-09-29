	
#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "SSD_private.h"
#include "SSD_config.h"
#include "SSD_interface.h"
#include "DIO_interface.h"


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

u8 SSD_u8SetNum(u8 Copy_u8Num, SSD_t* Copy_SSDInfo)
{
	u8 Local_u8ErrorState = 0;
	DIO_u8SetPortDirection(Copy_SSDInfo->Port,DIO_u8PORT_OUTPUT);
	if(Copy_SSDInfo->Com_Type == SSD_u8ANODE)
	{
		DIO_u8SetPortValue(Copy_SSDInfo->Port,~SSSD_u8number[Copy_u8Num]);  
	}
	else if(Copy_SSDInfo->Com_Type == SSD_u8CATHODE)
	{
		DIO_u8SetPortValue(Copy_SSDInfo->Port,SSD_u8number[Copy_u8Num]);  
	}
	else
	{
		Local_u8ErrorState = 1;
	}
	return Local_u8ErrorState;
}

u8 SSD_u8Enable(SSD_t* Copy_SSDInfo)
{
	u8 Local_u8ErrorState = 0;
	u8* Local_u8Ptr = info;
	DIO_u8SetPinDirection(Copy_SSDInfo->Enable_Port,Copy_SSDInfo->Enable_Pin,DIO_u8PIN_OUTPUT);
	if(Copy_SSDInfo->Com_Type == SSD_u8ANODE)
	{
		DIO_u8SetPinValue(Copy_SSDInfo->Enable_Port,Copy_SSDInfo->Enable_Pin,DIO_u8PIN_HIGH);
	}
	else if(Copy_SSDInfo->Com_Type == SSD_u8CATHODE)
	{
		DIO_u8SetPinValue(Copy_SSDInfo->Enable_Port,Copy_SSDInfo->Enable_Pin,DIO_u8PIN_LOW);
	}
	else
	{
		Local_u8ErrorState = 1;
	}
	return Local_u8ErrorState;
}

u8 SSD_u8Disable(SSD_t* Copy_SSDInfo)
{
	u8 Local_u8ErrorState = 0;
	u8* Local_u8Ptr = info;
	DIO_u8SetPinDirection(Copy_SSDInfo->Enable_Port,Copy_SSDInfo->Enable_Pin,DIO_u8PIN_OUTPUT);
	if(Copy_SSDInfo->Com_Type == SSD_u8ANODE)
	{
		DIO_u8SetPinValue(Copy_SSDInfo->Enable_Port,Copy_SSDInfo->Enable_Pin,DIO_u8PIN_LOW);
	}
	else if(Copy_SSDInfo->Com_Type == SSD_u8CATHODE)
	{
		DIO_u8SetPinValue(Copy_SSDInfo->Enable_Port,Copy_SSDInfo->Enable_Pin,DIO_u8PIN_HIGH);
	}
	else
	{
		Local_u8ErrorState = 1;
	}
	return Local_u8ErrorState;
}




