#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "SPI_register.h"
#include "SPI_private.h"
#include "SPI_config.h"
#include "SPI_interface.h"

void SPI_voidInit(void)
{


#if SPI_MASTER_SLAVE_MODE  ==  MASTER
	SET_BIT(SPCR,MSTR);
#elif SPI_MASTER_SLAVE_MODE == SLAVE
	CLR_BIT(SPCR,MSTR);
#endif

#if SPI_DATA_ORDER == LSB_FIRST
	SET_BIT(SPCR,DORD);
#elif SPI_DATA_ORDER == MSB_FIRST
	CLR_BIT(SPCR,DORD);
#endif

#if SPI_CLOCK_POLARITY == IDLE_LOW
	CLR_BIT(SPCR,CPOL);
#elif SPI_CLOCK_POLARITY == IDLE_HIGH
	SET_BIT(SPCR,CPOL);
#endif

#if SPI_CLOCK_PHASE == SAMPLE_AT_LEADING
	CLR_BIT(SPCR,CPHA);
#elif SPI_CLOCK_PHASE == SETUP_AT_LEADING
	SET_BIT(SPCR,CPHA);
#endif

#if SPI_FREQUENCY == DIVIDE_BY_2
	SET_BIT(SPSR,SPI2X);
	CLR_BIT(SPCR,SPR1);
	CLR_BIT(SPCR,SPR0);
#elif SPI_FREQUENCY == DIVIDE_BY_4
	CLR_BIT(SPSR,SPI2X);
	CLR_BIT(SPCR,SPR1);
	CLR_BIT(SPCR,SPR0);
#endif

	//Enable SPI
	SET_BIT(SPCR,SPE);

	//Enable Interrupt
#if SPI_INTERRUPT_MODE  == ENABLED
	SET_BIT(SPCR,SPIE);
#elif SPI_INTERRUPT_MODE == DISABLED
	CLR_BIT(SPCR,SPIE);
#endif

}



u8 SPI_u8Transfer(u8 Copy_Data)
{
	SPDR = Copy_Data;
	while(!GET_BIT(SPSR,SPIF));
	return SPDR;
}


u8 SPI_u8ReadDataISR(void)
{
	return SPDR;
}

void SPI_voidSendDataISR(u8 Copy_Data)
{
	SPDR = Copy_Data;
}


void (*SPI_CallBackPtr) (void) = NULL;

void SPI_voidSetCallBack( void (*PtrToFunc) (void) )
{
		SPI_CallBackPtr = PtrToFunc;
}

void __vector_12(void) __attribute__((signal,used,externally_visible));  //to avoid optimization
void __vector_12(void)
{
	if (SPI_CallBackPtr != NULL)
		SPI_CallBackPtr();
}



