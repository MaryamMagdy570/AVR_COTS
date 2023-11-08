#ifndef _TIMER1_PRIVATE_H_
#define _TIMER1_PRIVATE_H_

#define NORMAL				0
#define CTC					1
#define PWM_FAST			2
#define PWM_PHASE_CORRECT	3

/* oc
#define DISCONNECTED		0
#define SET					1
#define CLEAR				2
#define TOGGLE				3
*/

#define  NO_CLOCK			0
#define  NO_PRESCALER		1
#define  DIVIDE_BY_8		2
#define  DIVIDE_BY_64       3
#define  DIVIDE_BY_256		4
#define  DIVIDE_BY_1024		5
#define  ON_FALLING_EDGE	6
#define  ON_RISING_EDGE 	7






/******* PIN CONFIGURATION ********/
#define  COM1A1		7
#define  COM1A0		6
#define  COM1B1		5
#define  COM1B0		4
#define  FOC1A		3
#define  FOC1B		2
#define  WGM11		1
#define  WGM10		0


#define  ICNC1		7
#define  ICES1		6
#define  WGM13		4
#define  WGM12		3
#define  CS12		2
#define  CS11		1
#define  CS10		0






#endif
