#ifndef _I2C_PRIVATE_H_
#define _I2C_PRIVATE_H_

#define F_CPU 		8000000UL
#define SCL_CLK 	400000ul

#define  BITRATE(TWSR)  (((F_CPU/SCL_CLK)-16)/(2*POWER(4,(TWSR&((1<<TWPS0)|(1<<TWPS1))))))


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




//ACKS
//TRANSMITTER MODE
#define START_ACK                  0x08
#define REP_START_ACK              0x10
#define SLAVE_ADD_AND_WR_ACK       0x18
#define SLAVE_ADD_AND_WR_NO_ACK    0x20
#define MSTR_WR_BYTE_ACK           0x28
#define MSTR_WR_BYTE_NO_ACK        0x30
//RECIEVER MODE

#define SLAVE_ADD_AND_RD_ACK       0x40
#define SLAVE_ADD_AND_RD_NO_ACK    0x48
#define MSTR_RD_BYTE_WITH_ACK      0x50
#define MSTR_RD_BYTE_WITH_NO_ACK   0x58

/*
#define SLAVE_ADD_RCVD_RD_REQ      0xA8
#define SLAVE_ADD_RCVD_MR_REQ      0x60
#define SLAVE_DATA_RECEIVED        0x80
#define SLAVE_BYTE_TRANSMITTED     0xB8
*/



#endif
