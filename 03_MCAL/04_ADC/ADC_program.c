#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "ADC_register.h"
#include "ADC_interface.h"
#include "ADC_config.h"
#include "ADC_private.h"


void ADC_voidInit(void)
{
	ADC_voidEnable();

  #if VOLTAGE_REFERENCE == AVREF
    CLR_BIT(ADMUX,REFS1);
    CLR_BIT(ADMUX,REFS0);
  #elif VOLTAGE_REFERENCE == AVCC
    CLR_BIT(ADMUX,REFS1);
    SET_BIT(ADMUX,REFS0);
  #elif VOLTAGE_REFERENCE == INTERNAL
    SET_BIT(ADMUX,REFS1);
    SET_BIT(ADMUX,REFS0);
  #endif

  #if ADJUSTMENT == LEFT_ADJUSTMENT
    SET_BIT(ADMUX,ADLAR);
  #elif ADJUSTMENT == RIGHT_ADJUSTMENT
    CLR_BIT(ADMUX,ADLAR);
  #endif

  #if ADC_CHANNEL_NUMBER == 0
    CLR_BIT(ADMUX,MUX0);
    CLR_BIT(ADMUX,MUX1);
    CLR_BIT(ADMUX,MUX2);
    CLR_BIT(ADMUX,MUX3);
    CLR_BIT(ADMUX,MUX4);
  #elif ADC_CHANNEL_NUMBER == 1
    SET_BIT(ADMUX,MUX0);
    CLR_BIT(ADMUX,MUX1);
    CLR_BIT(ADMUX,MUX2);
    CLR_BIT(ADMUX,MUX3);
    CLR_BIT(ADMUX,MUX4);
  #elif ADC_CHANNEL_NUMBER == 2
    CLR_BIT(ADMUX,MUX0);
    SET_BIT(ADMUX,MUX1);
    CLR_BIT(ADMUX,MUX2);
    CLR_BIT(ADMUX,MUX3);
    CLR_BIT(ADMUX,MUX4);
  #elif ADC_CHANNEL_NUMBER == 3
    SET_BIT(ADMUX,MUX0);
    SET_BIT(ADMUX,MUX1);
    CLR_BIT(ADMUX,MUX2);
    CLR_BIT(ADMUX,MUX3);
    CLR_BIT(ADMUX,MUX4);
  #elif ADC_CHANNEL_NUMBER == 4
    CLR_BIT(ADMUX,MUX0);
    CLR_BIT(ADMUX,MUX1);
    SET_BIT(ADMUX,MUX2);
    CLR_BIT(ADMUX,MUX3);
    CLR_BIT(ADMUX,MUX4);
  #elif ADC_CHANNEL_NUMBER == 5
    SET_BIT(ADMUX,MUX0);
    CLR_BIT(ADMUX,MUX1);
    SET_BIT(ADMUX,MUX2);
    CLR_BIT(ADMUX,MUX3);
    CLR_BIT(ADMUX,MUX4);
  #elif ADC_CHANNEL_NUMBER == 6
    CLR_BIT(ADMUX,MUX0);
    SET_BIT(ADMUX,MUX1);
    SET_BIT(ADMUX,MUX2);
    CLR_BIT(ADMUX,MUX3);
    CLR_BIT(ADMUX,MUX4);
  #elif ADC_CHANNEL_NUMBER == 7
    SET_BIT(ADMUX,MUX0);
    SET_BIT(ADMUX,MUX1);
    SET_BIT(ADMUX,MUX2);
    CLR_BIT(ADMUX,MUX3);
    CLR_BIT(ADMUX,MUX4);
  #endif

  #if ADC_PRESCALLER == DIVID_BY_128
    SET_BIT(ADCSRA,ADPS2);
    SET_BIT(ADCSRA,ADPS1);
    SET_BIT(ADCSRA,ADPS0);
  #endif

  #if ADC_MODE == SINGLE_CONVERSION
    CLR_BIT(ADCSRA,ADATE);
  #elif ADC_MODE == AUTOTRIGGERED
    SET_BIT(ADCSRA,ADATE);
  #if ADC_AUTO_TRIGGER_SOURCE == FREE_RUNNING_MODE
    ADC_voidStartConversion();
    CLR_BIT(SFIOR,ADTS0);
    CLR_BIT(SFIOR,ADTS1);
    CLR_BIT(SFIOR,ADTS2);
  #endif
  #endif
} 


void ADC_voidEnable()
{
  SET_BIT(ADCSRA,ADEN);
}

void ADC_voidDisable()
{
  CLR_BIT(ADCSRA,ADEN);
}

u16 ADC_u16ReadADC()
{
	u16 Local_u16Digital;

	#if ADC_MODE == SINGLE_CONVERSION
	ADC_voidStartConversion();
	while(GET_BIT(ADCSRA,ADSC))
	{
		//POLLING : BUSY WAITING UNTIL EVENT
	}
	#endif

	Local_u16Digital = ((u16)ADCH<<2);

	return Local_u16Digital;
}

void ADC_voidStartConversion()
{
  SET_BIT(ADCSRA,ADSC);
}

u16 ADC_u16ReadADCInMV()
{
	u16 Local_u16Analog,Local_u16Digital;
	Local_u16Digital = ADC_u16ReadADC();
	Local_u16Analog = Local_u16Digital * 5000ul / 1024;
	return Local_u16Analog;
}

void ADC_voidEnableInt()
{
	SET_BIT(ADCSRA,ADIE);
}

void ADC_voidDisableInt()
{
	CLR_BIT(ADCSRA,ADIE);
}


void (*ADC_ptr) (void);

void ADC_SetCallback( void (*ptr) (void) )
{
	ADC_ptr = ptr;
}

void __vector_16(void) __attribute__((signal,used,externally_visible));  //to avoid optimization
void __vector_16(void)
{
	if(ADC_ptr!= NULL)
		ADC_ptr();
}



/*
u16 MADC_u16ReadData(u8 Copy_u8Channel);
*/

