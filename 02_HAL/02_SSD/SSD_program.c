	
#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "SSD_private.h"
#include "SSD_config.h"
#include "SSD_interface.h"
#include "DIO_interface.h"


u8 SSD_u8SetNum(u8 Copy_u8Num, SSD_t* info)
{
	u8 Local_u8ErrorState = 0;
	u8* Local_u8Ptr = info;
	DIO_u8SetPortDirection(Local_u8Ptr[1],DIO_u8PORT_OUTPUT);
	if(Local_u8Ptr[0] == SSD_u8ANODE)
	{
		DIO_u8SetPortValue(Local_u8Ptr[1],DIO_u8PORT_LOW);
	}
	else if(Local_u8Ptr[0] == SSD_u8CATHODE)
	{
		DIO_u8SetPortValue(Local_u8Ptr[1],DIO_u8PORT_HIGH);
	}
	else
	{
		Local_u8ErrorState = 1;
	}
	return Local_u8ErrorState;
}

u8 SSD_u8Enable(SSD_t* info)
{
	u8 Local_u8ErrorState = 0;
	u8* Local_u8Ptr = info;
	DIO_u8SetPinDirection(Local_u8Ptr[2],Local_u8Ptr[3],DIO_u8PIN_OUTPUT);
	if(Local_u8Ptr[0] == SSD_u8ANODE)
	{
		DIO_u8SetPinValue(Local_u8Ptr[2],Local_u8Ptr[3],DIO_u8PIN_HIGH);
	}
	else if(Local_u8Ptr[0] == SSD_u8CATHODE)
	{
		DIO_u8SetPinValue(Local_u8Ptr[2],Local_u8Ptr[3],DIO_u8PIN_LOW);
	}
	else
	{
		Local_u8ErrorState = 1;
	}
	return Local_u8ErrorState;
}

u8 SSD_u8Disable(SSD_t* info)
{
	u8 Local_u8ErrorState = 0;
	u8* Local_u8Ptr = info;
	DIO_u8SetPinDirection(Local_u8Ptr[2],Local_u8Ptr[3],DIO_u8PIN_OUTPUT);
	if(Local_u8Ptr[0] == SSD_u8ANODE)
	{
		DIO_u8SetPinValue(Local_u8Ptr[2],Local_u8Ptr[3],DIO_u8PIN_LOW);
	}
	else if(Local_u8Ptr[0] == SSD_u8CATHODE)
	{
		DIO_u8SetPinValue(Local_u8Ptr[2],Local_u8Ptr[3],DIO_u8PIN_HIGH);
	}
	else
	{
		Local_u8ErrorState = 1;
	}
	return Local_u8ErrorState;
}




