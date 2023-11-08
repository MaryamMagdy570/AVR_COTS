#ifndef _I2C_PRIVATE_H_
#define _I2C_PRIVATE_H_



#define  BITRATE(TWSR)  (((F_CPU/SCL_CLK)-16)/(2*pow(4,(TWSR&((1<<TWPS0)|(1<<TWPS1))))))


/* TWCR_REG */

#define TWINT	7
#define TWEA	6
#define TWSTA	5
#define TWSTO	4
#define TWWC	3
#define TWEN	2
#define TWIE	0

/* TWSR */

#define TWPS1 1
#define TWPS0	0


/* TWAR */

#define TWGCE	0




#endif
