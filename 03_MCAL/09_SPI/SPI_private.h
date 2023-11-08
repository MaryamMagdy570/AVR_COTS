#ifndef _SPI_PRIVATE_H_
#define _SPI_PRIVATE_H_


//MACROS
#define ENABLED             0
#define DISABLED            1

#define LSB_FIRST           0
#define MSB_FIRST           1

#define MASTER              0
#define SLAVE               1

#define IDLE_LOW            0
#define IDLE_HIGH           1

#define SAMPLE_AT_LEADING   0
#define SETUP_AT_LEADING    1

#define DIVIDE_BY_4         0
#define DIVIDE_BY_2         1


/*******PIN CONFIGUARATION ********/
/* SPCR_REG */

#define SPIE	7
#define SPE		6
#define DORD	5
#define MSTR	4
#define CPOL	3
#define CPHA	2
#define SPR1	1
#define SPR0	0


/* SPSR_REG */

#define SPIF	7
#define WCOL	6
#define SPI2X	0




#endif
