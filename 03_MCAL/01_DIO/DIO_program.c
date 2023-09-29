/* 	#include STD_TYPES.h before IDO_Interface.h and 
	DIO_private.h because we use them in these 2 files
	*/	
	
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_register.h"
#include "DIO_private.h"
#include "DIO_config.h"
#include "DIO_interface.h"


/*****************************************************************************************/


u8 DIO_u8SetPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Direction)
{
	u8 Local_u8ErrorState = 0;
	if(Copy_u8Pin <= 7)
	{
		if(DIO_u8PIN_INPUT == Copy_u8Direction)
		{
			switch(Copy_u8Port)
			{ 
				case DIO_u8PORTA:	CLR_BIT(DDRA_REG, Copy_u8Pin); 	break;
				case DIO_u8PORTB:	CLR_BIT(DDRB_REG, Copy_u8Pin); 	break;
				case DIO_u8PORTC:	CLR_BIT(DDRC_REG, Copy_u8Pin); 	break;
				case DIO_u8PORTD:	CLR_BIT(DDRD_REG, Copy_u8Pin); 	break;
				default:			Local_u8ErrorState = 1;	break;
			}	
		}
		else if(DIO_u8PIN_OUTPUT == Copy_u8Direction)
		{
			switch(Copy_u8Port)
			{ 
				case DIO_u8PORTA:	SET_BIT(DDRA_REG, Copy_u8Pin); 	break;
				case DIO_u8PORTB:	SET_BIT(DDRB_REG, Copy_u8Pin); 	break;
				case DIO_u8PORTC:	SET_BIT(DDRC_REG, Copy_u8Pin); 	break;
				case DIO_u8PORTD:	SET_BIT(DDRD_REG, Copy_u8Pin); 	break;
				default:			Local_u8ErrorState = 1; break;
			}
		}
		else
		{
			Local_u8ErrorState = 1;
		}
	else
	{
		Local_u8ErrorState = 1;
	}		
	return Local_u8ErrorState;
}

/*****************************************************************************************/

u8 DIO_u8SetPortDirection(u8 Copy_u8Port, u8 Copy_u8Direction);
{
	u8 Local_u8ErrorState = 0;
	switch(Copy_u8Port)
	{ 
		case DIO_u8PORTA:	DDRA_REG = Copy_u8Direction; 	break;
		case DIO_u8PORTB:	DDRB_REG = Copy_u8Direction; 	break;
		case DIO_u8PORTC:	DDRC_REG = Copy_u8Direction; 	break;
		case DIO_u8PORTD:	DDRD_REG = Copy_u8Direction; 	break;
		default:			Local_u8ErrorState = 1; break;
	}
	return Local_u8ErrorState;
}

/*****************************************************************************************/

u8 DIO_u8GetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8* Copy_u8Value);

{
	u8 Local_u8ErrorState = 0;
	if((Copy_u8Pin <= 7) && (Copy_u8Value == NULL))
	{  
		switch(Copy_u8Port)
		{    
		  case DIO_u8PORTA:	*Copy_u8Value = GET_BIT(PINA_REG, Copy_u8Pin);	break;
		  case DIO_u8PORTB:	*Copy_u8Value = GET_BIT(PINB_REG, Copy_u8Pin);	break;
		  case DIO_u8PORTC:	*Copy_u8Value = GET_BIT(PINC_REG, Copy_u8Pin);	break;
		  case DIO_u8PORTD:	*Copy_u8Value = GET_BIT(PIND_REG, Copy_u8Pin);	break;
		  default:			Local_u8ErrorState = 1; break;
		}
	}
	else
	{
		Local_u8ErrorState = 1;
	}
	return Local_u8ErrorState;
}


/*****************************************************************************************/

u8 DIO_u8SetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value);
{
	u8 Local_u8ErrorState = 0;
	if(Copy_u8Pin <= 7)
	{
		if(Copy_u8Value == DIO_u8PIN_HIGH)
		{
			switch(Copy_u8Port)
			{
				case DIO_u8PORTA:  SET_BIT(PORTA_REG,Copy_u8Pin);	break;
				case DIO_u8PORTB:  SET_BIT(PORTB_REG,Copy_u8Pin);	break;
				case DIO_u8PORTC:  SET_BIT(PORTC_REG,Copy_u8Pin);	break;
				case DIO_u8PORTD:  SET_BIT(PORTD_REG,Copy_u8Pin);	break;
				default:		   Local_u8ErrorState = 1; break;	
			}
		}
		else if (Copy_u8Value == DIO_u8PIN_LOW)
		{
			switch(Copy_u8Port)
			{
				case DIO_u8PortA:	CLR_BIT(PORTA_REG,Copy_u8Pin);  break;
				case DIO_u8PortB:	CLR_BIT(PORTB_REG,Copy_u8Pin);  break;
				case DIO_u8PortC:	CLR_BIT(PORTC_REG,Copy_u8Pin);  break;
				case DIO_u8PortD:	CLR_BIT(PORTD_REG,Copy_u8Pin);  break;
				default : 			Local_u8ErrorState = 1; break;	
			}
		}
		else
		{
			Local_u8ErrorState = 1;
		}
		
	}
	else
	{
		Local_u8ErrorState = 1;
	}
	return Local_u8ErrorState;
}

/*****************************************************************************************/

u8 DIO_u8SetPortValue(u8 Copy_u8Port, u8 Copy_u8Value);
{
	u8 Local_u8ErrorState = 0;
	switch(Copy_u8Port)
	{
		case DIO_u8PORTA:  PORTA_REG = Copy_u8Value;	break;
		case DIO_u8PORTB:  PORTB_REG = Copy_u8Value;	break;
		case DIO_u8PORTC:  PORTC_REG = Copy_u8Value;	break;
		case DIO_u8PORTD:  PORTD_REG = Copy_u8Value;	break;
		default:		   Local_u8ErrorState = 1; break;	
	}
	return Local_u8ErrorState;
}

/*****************************************************************************************/


u8 DIO_u8TogglePin(u8 Copy_u8Port, u8 Copy_u8Pin );
{
	u8 Local_u8ErrorState = 0;
	if(Copy_u8Pin <= 7)
	{
		switch (copy_U8Port)
		{
			case DIO_u8PORTA: TOGGLE_BIT(PORTA_REG,Copy_u8Pin);  break;
			case DIO_u8PORTB: TOGGLE_BIT(PORTB_REG,Copy_u8Pin);  break;
			case DIO_u8PORTC: TOGGLE_BIT(PORTC_REG,Copy_u8Pin);  break;
			case DIO_u8PORTD: TOGGLE_BIT(PORTD_REG,Copy_u8Pin);  break;
			default: 	      Local_u8ErrorState = 1;
		}
	}
	else
	{
		Local_u8ErrorState = 1;
	}
	return Local_u8ErrorState;
}


/*****************************************************************************************/
