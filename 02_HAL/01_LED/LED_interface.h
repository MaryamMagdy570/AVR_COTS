#ifndef _LED_INTERFACE_H_
#define _LED_INTERFACE_H_

/* CONNECTION TYPE OF LEDS*/
#define LED_u8SOURCE 	1
#define LED_u8SINK 		2

u8 LED_u8ON (u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Connection_Type);

u8 LED_u8OFF (u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Connection_Type);




#endif