	
#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "LED_private.h"
#include "LED_config.h"
#include "LED_interface.h"
#include "DIO_interface.h"



u8 LED_u8ON (u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Connection_Type)
{
	u8 Local_u8ErrorState = 0;
	DIO_u8SetPinDirection(Copy_u8Port,Copy_u8Pin,DIO_u8PIN_OUTPUT);
	if(Copy_u8Connection_Type == LED_u8SOURCE)
	{
		DIO_u8SetPinValue(Copy_u8Port,Copy_u8Pin,DIO_u8PIN_HIGH);
	}
	else if(Copy_u8Connection_Type == LED_u8SINK)
	{
		DIO_u8SetPinValue(Copy_u8Port,Copy_u8Pin,DIO_u8PIN_LOW);
	}
	else
	{
		Local_u8ErrorState=1;
	}
	return Local_u8ErrorState;
}



u8 LED_u8OFF (u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Connection_Type)
{
	u8 Local_u8ErrorState = 0;
	DIO_u8SetPinDirection(Copy_u8Port,Copy_u8Pin,DIO_u8PIN_OUTPUT);
	if(Copy_u8Connection_Type == LED_u8SOURCE)
	{
		DIO_u8SetPinValue(Copy_u8Port,Copy_u8Pin,DIO_u8PIN_LOW);
	}
	else if(Copy_u8Connection_Type == LED_u8SINK)
	{
		DIO_u8SetPinValue(Copy_u8Port,Copy_u8Pin,DIO_u8PIN_HIGH);
	}
	else
	{
		Local_u8ErrorState=1;
	}
	return Local_u8ErrorState;
}
