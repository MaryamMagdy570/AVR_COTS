#include "BIT_MATH.h"
#include "STD_TYPES.h"


#include "I2C_interface.h"

#include "EEPROM_config.h"
#include "EEPROM_private.h"
#include "EEPROM_interface.h"


#include "CLCD_interface.h"


void EEPROM_voidSendDataByte(u16 Address,u8 DataByte)
{
	u8 error;

	//send start condition
	error = I2C_voidSendStartCondition();
	CLCD_voidGoToRowColumn(0,0);
	CLCD_voidSendInteger(error);

	//set slave address with write  1010 | (A2<<2) (A1 A0)(ADRESS >> 8)
	error = I2C_voidSendSlaveAddressWrite(0b01010000);
	CLCD_voidGoToRowColumn(0,2);
	CLCD_voidSendInteger(error);

	//MASTER WITE BYTE  >> 8 LSB BITS ADDRESS
	error = I2C_voidMasterWriteDataByte((u8)Address);
	CLCD_voidGoToRowColumn(0,4);
	CLCD_voidSendInteger(error);

	//MASTER WITE BYTE >> DATA
	error = I2C_voidMasterWriteDataByte(DataByte);
	CLCD_voidGoToRowColumn(0,6);
	CLCD_voidSendInteger(error);

	//stop
	I2C_voidSendStopCondition();
}

void EEPROM_voidReadDataByte(u16 Address,u8* DataByte)
{
	u8 error;
	//send start condition
    error = I2C_voidSendStartCondition();
	CLCD_voidGoToRowColumn(1,0);
	CLCD_voidSendInteger(error);

	//set slave address with write  1010 | (A2<<2) (A1 A0)(ADRESS >> 8)
	error = I2C_voidSendSlaveAddressWrite(0b01010000 | (Address>>8));
	CLCD_voidGoToRowColumn(1,2);
	CLCD_voidSendInteger(error);

	//MASTER WITE BYTE  >> 8 LSB BITS ADDRESS
	 error = I2C_voidMasterWriteDataByte((u8)Address);
	 CLCD_voidGoToRowColumn(1,4);
	 CLCD_voidSendInteger(error);

	// repeat start
	error = I2C_voidSendRepeatedStart();
	CLCD_voidGoToRowColumn(1,6);
	CLCD_voidSendInteger(error);

	//set slave address with read  1010 | (A2<<2) (A1 A0)(ADRESS >> 8)
	error = I2C_voidSendSlaveAddressRead(0b01010000 | (Address>>8));
	CLCD_voidGoToRowColumn(1,8);
	CLCD_voidSendInteger(error);


	//MASTER read BYTE >> *DATA
	error = I2C_voidMasterReadDataByteWithNAck(DataByte);
	CLCD_voidGoToRowColumn(1,12);
	CLCD_voidSendInteger(error);

	//stop
	I2C_voidSendStopCondition();

}



