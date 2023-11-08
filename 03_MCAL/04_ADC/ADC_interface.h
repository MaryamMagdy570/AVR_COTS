#ifndef _ADC_INTERFACE_H_
#define _ADC_INTERFACE_H_


void ADC_voidEnable();
void ADC_voidDisable();
u16 ADC_u16ReadADC();
void ADC_voidStartConversion();
u16 ADC_u16ReadADCInMV();

void ADC_voidInit(void);

void ADC_voidEnableInt();
void ADC_voidDisableInt();
void ADC_SetCallback( void (*ptr) (void) );

void __vector_16(void) __attribute__((signal,used,externally_visible));  //to avoid optimization
void __vector_16(void);

#endif
