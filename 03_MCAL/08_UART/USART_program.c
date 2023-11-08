#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "USART_register.h"
#include "USART_private.h"
#include "USART_config.h"
#include "USART_interface.h"


void USART_voidInit()
{
	//double speed
	SET_BIT(UCSRA,U2X);

	// select to Write on UCSRC not UBRRH
	SET_BIT(UCSRC,URSEL);

	// mode synchronous
	CLR_BIT(UCSRC,UMSEL);


	//PARITY DISABLED
	CLR_BIT(UCSRC,UPM1);
	CLR_BIT(UCSRC,UPM0);

	// STOP BIT : 2 BITS
	SET_BIT(UCSRC,USBS);

	//SIZE
	CLR_BIT(UCSRB,UCSZ2);
	SET_BIT(UCSRC,UCSZ1);
	SET_BIT(UCSRC,UCSZ0);

	//BAUD RATE
	UBRRL = 207;
		//UBRRL = 103;
	//UBRRH = 0;


	SET_BIT(UCSRB,RXEN);
	SET_BIT(UCSRB,TXEN);
}

void USART_voidTransmit(u8 Copy_u8DataTransmitted)
{

	while(!GET_BIT(UCSRA,UDRE))
	{
	 //POLLING
	}
	UDR = Copy_u8DataTransmitted;


}

u8 USART_u8Receive()
{

	u8 Copy_u8DataReceived;
	while(!GET_BIT(UCSRA,RXC));
	{
	 //POLLING
	}


	Copy_u8DataReceived = UDR;

	//CLEAR FLAG
	//SET_BIT(UCSRA,RXC);

	return Copy_u8DataReceived;
}



