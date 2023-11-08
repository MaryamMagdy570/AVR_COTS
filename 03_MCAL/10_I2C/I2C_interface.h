#ifndef _SPI_INTERFACE_H_
#define _SPI_INTERFACE_H_



#define TW_MT_ARB_LOST   0x38
#define TW_MR_ARB_LOST   0x38
#define TW_START         0x08
#define TW_REP_START     0x10
#define TW_MT_SLA_ACK    0x18
#define TW_MT_DATA_ACK   0x28
#define TW_MR_DATA_NOT_ACK  0x58
#define TW_MR_SLA_NOT_ACK   0x48
#define TW_MT_SLA_NOT_ACK   0x20
#define TW_MT_DATA_NOT_ACK  0x30
#define TW_MR_DATA_ACK   0x50
#define TW_MR_SLA_ACK    0x40


void I2C_voidInit(void);

void I2C_voidStart(void);

void I2C_voidStop(void);

void I2C_voidWrite(u8 data);

u8 I2C_u8ReadACK(void);

u8 I2C_u8ReadNACK(void);

u8 I2C_u8GetStatus(void);



#endif
