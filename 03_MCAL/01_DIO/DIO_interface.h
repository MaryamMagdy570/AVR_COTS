#ifndef _DIO_INTERFACE_H_
#define _DIO_INTERFACE_H_

#define DIO_u8PORTA 	0
#define DIO_u8PORTB 	1
#define DIO_u8PORTC 	2
#define DIO_u8PORTD 	3
		
#define DIO_u8PIN0 		0
#define DIO_u8PIN1 		1
#define DIO_u8PIN2 		2
#define DIO_u8PIN3 		3
#define DIO_u8PIN4 		4
#define DIO_u8PIN5 		5
#define DIO_u8PIN6 		6
#define DIO_u8PIN7 		7

#define DIO_u8PIN_OUTPUT 	1
#define DIO_u8PIN_INPUT 	0

#define DIO_u8PORT_OUTPUT 	0xff
#define DIO_u8PORT_INPUT 	0

#define DIO_u8PIN_HIGH 		1
#define DIO_u8PIN_LOW 		0

#define DIO_u8PORT_HIGH 	0xff
#define DIO_u8PORT_LOW 		0


/* Copy_u8Direction takes the values : DIO_u8PIN_OUTPUT , DIO_u8PIN_INPUT */
u8 DIO_u8SetPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Direction);

/* Copy_u8Direction takes the values : DIO_u8PORT_OUTPUT , DIO_u8PORT_INPUT */
u8 DIO_u8SetPortDirection(u8 Copy_u8Port, u8 Copy_u8Direction);

/*  */
u8 DIO_u8GetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8* Copy_u8Value);

/* Copy_u8Value takes the values : DIO_u8PIN_HIGH , DIO_u8PIN_LOW */
u8 DIO_u8SetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value);

/* Copy_u8Value takes the values : DIO_u8PORT_HIGH , DIO_u8PORT_LOW */
u8 DIO_u8SetPortValue(u8 Copy_u8Port, u8 Copy_u8Value);

/*  */
u8 DIO_u8TogglePin(u8 Copy_u8Port, u8 Copy_u8Pin);


#endif

