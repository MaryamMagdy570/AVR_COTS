#ifndef _ADC_CONFIG_H
#define _ADC_CONFIG_H


/* CHOOSE AVCC OR AVREF OR INTERNAL */
#define VOLTAGE_REFERENCE			AVCC


/* value of reference voltage */
#define ADC_VREF	5


/* RESOLUTION */
#define ADC_RESOLUTION 	10


/* CHOOSE RIGHT_ADJUSTMENT OR LEFT_ADJUSTMENT */
#define ADJUSTMENT					RIGHT_ADJUSTMENT

/* choose from A0 to A7 */
#define ADC_CHANNEL_NUMBER			0

/* CHOOSE SINGLE_CONVERSION MODE OR AUTOTRIGGERED MODE*/
#define ADC_MODE					SINGLE_CONVERSION

/* CHOOSE FROM (FREE_RUNNING_MODE,ANALOG_COMPARATOR,EXTI0,
 * TIMER0_COMPARE_MATCH,TIMER0_OVERFOLW,TIMER0_COMPARE_MATCH
 * TIMER1_COMPARE_MATCH, TIMER1_OVERFLOW,TIMER1_CAPTUREEVENT
 * */
#define ADC_AUTO_TRIGGER_SOURCE		FREE_RUNNING_MODE

/* CHOOSE DIVIDE_BY_2,4,8,16,32,64,128 */
#define ADC_PRESCALLER				DIVID_BY_128




#endif

