#ifndef _SPI_INTERFACE_H_
#define _SPI_INTERFACE_H_


//#define DOUBLE_SPEED_MODE 	0
//#define DOUBLE_SPEED_MODE 	3


void SPI_voidInit(void);


u8 SPI_u8Transfer(u8 Copy_Data);

void SPI_voidSetCallBack( void (*PtrToFunc) (void) );

u8 SPI_u8ReadDataISR(void);

void SPI_voidSendDataISR(u8 Copy_Data);

void __vector_12(void) __attribute__((signal,used,externally_visible));  //to avoid optimization
void __vector_12(void);

#endif
