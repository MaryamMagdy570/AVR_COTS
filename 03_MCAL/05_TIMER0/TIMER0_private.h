#ifndef _TIMER0_PRIVATE_H_
#define _TIMER0_PRIVATE_H_

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
#define  WGM00		6
#define  COM01		5
#define  COM00		4
#define  WGM01		3
#define  CS02		2
#define  CS01		1
#define  CS00		0



#define  OCIE0		1
#define  TOIE0		0




#endif
