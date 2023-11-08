#ifndef _I2C_INTERFACE_H_
#define _I2C_INTERFACE_H_


typedef enum
{
NoError,
StartConditionErr,
RepeatedStartErr,
SlaveAddressWithWriteErr,
SlaveAddressWithReadErr,
MasterWriteByteErr,
MasterReadByteErr,
}I2C_ErrStatus;

//pass 0 if master has not address
void I2C_voidMaterInit(u8 address);

void I2C_voidSlaveInit(u8 address);

I2C_ErrStatus I2C_voidSendStartCondition(void);

I2C_ErrStatus I2C_voidSendRepeatedStart(void);


I2C_ErrStatus I2C_voidSendSlaveAddressWrite(u8 address);

I2C_ErrStatus I2C_voidSendSlaveAddressRead(u8 address);


I2C_ErrStatus I2C_voidMasterWriteDataByte(u8 data);

I2C_ErrStatus I2C_voidMasterReadDataByteWithAck(u8* data);
I2C_ErrStatus I2C_voidMasterReadDataByteWithNAck(u8* data);

void I2C_voidSendStopCondition(void);

#endif
