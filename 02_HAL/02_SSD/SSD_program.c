	
#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "SSD_private.h"
#include "SSD_config.h"
#include "SSD_interface.h"
#include "DIO_interface.h"




u8 SSD_u8SetNum(u8 Copy_u8Num, SSD_t* Copy_SSDInfo)
{
	u8 Local_u8ErrorState = 0;
	DIO_u8SetPortDirection(Copy_SSDInfo->Port,DIO_u8PORT_OUTPUT);
	if(Copy_SSDInfo->Com_Type == SSD_u8ANODE)
	{
		DIO_u8SetPortValue(Copy_SSDInfo->Port,~SSD_u8number[Copy_u8Num]);
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




