#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "I2C_register.h"
#include "I2C_private.h"
#include "I2C_config.h"
#include "I2C_interface.h"



//pass 0 if master has not address
void I2C_voidMaterInit(u8 address)
{   
	TWSR = 0x00;
 /*  pre-scaler TWPS=00 */
 /* Bit Rate: 400.000 kbps using zero pre-scaler TWPS=00 and F_CPU=8Mhz */
 TWBR=BITRATE(TWSR);  
 
 /* Two Wire Bus address my address if any master device want to call me: 0x1 (used in case this MC is a slave device)
  General Call Recognition: Off */
if (address !=0)
 TWAR = address<<1;

 SET_BIT(TWCR,TWEN); /* enableA TWIA*/
}


void I2C_voidSlaveInit(u8 address)
{

 TWAR = address<<1;

 SET_BIT(TWCR,TWEN);
}


I2C_ErrStatus I2C_voidSendStartCondition(void)
{

	I2C_ErrStatus error_state= NoError;
  // Send Start Condition $ clear flag
  TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWSTA);

  // Wait for TWINT flag set in TWCR Register
  while (!GET_BIT(TWCR,TWINT))
  {
    //POLLING until it is raised again
  }

  if ((TWSR & 0xF8) != START_ACK)
	  error_state = StartConditionErr;



  return error_state;
}

I2C_ErrStatus I2C_voidSendRepeatedStart(void)
{

	I2C_ErrStatus error_state= NoError;
  // Send Start Condition $ clear flag
	  TWCR = (1 << TWINT) | (1 << TWSTA)| (1 << TWEN);

  // Wait for TWINT flag set in TWCR Register
  while (!GET_BIT(TWCR,TWINT))
  {
    //POLLING until it is raised again
  }

  if ((TWSR & 0xF8) != REP_START_ACK)
	  error_state = RepeatedStartErr;



  return error_state;
}





I2C_ErrStatus I2C_voidSendSlaveAddressWrite(u8 address)
{
	I2C_ErrStatus error_state= NoError;



	TWDR = address <<1;

	CLR_BIT(TWDR,0);  //WRITEE


	TWCR = (1<<TWEN) | (1<<TWINT);

	  while (!GET_BIT(TWCR,TWINT))
	  {
	    //POLLING until it is raised again
	  }

	  if ((TWSR & 0xF8) != SLAVE_ADD_AND_WR_ACK )
		  error_state = SlaveAddressWithWriteErr;


	 return error_state;
}

I2C_ErrStatus I2C_voidSendSlaveAddressRead(u8 address)
{
	I2C_ErrStatus error_state= NoError;


	TWDR = address <<1;
	SET_BIT(TWDR,0);  //READ


TWCR = (1<<TWEN) | (1<<TWINT);

	  while (!GET_BIT(TWCR,TWINT))
	  {
	    //POLLING until it is raised again
	  }

	  if ((TWSR & 0xF8) != SLAVE_ADD_AND_RD_ACK )
		  error_state = SlaveAddressWithReadErr;

	 return error_state;
}




I2C_ErrStatus I2C_voidMasterWriteDataByte(u8 data)
{
	 I2C_ErrStatus error_state= NoError;

	TWDR = data;

	TWCR = (1<<TWEN) | (1<<TWINT);

	  while (!GET_BIT(TWCR,TWINT))
	  {
	    //POLLING until it is raised again
	  }

	  if ((TWSR & 0xF8) != MSTR_WR_BYTE_ACK )
		  error_state = MasterWriteByteErr;


	 return error_state;

}


#include "CLCD_interface.h"

I2C_ErrStatus I2C_voidMasterReadDataByteWithACK(u8* data)
{

	 I2C_ErrStatus error_state= NoError;

	 TWCR = (1<<TWEN) | (1<<TWINT) |(1<<TWEA);


	  while (!GET_BIT(TWCR,TWINT))
	  {
	    //POLLING until it is raised again
	  }



	  if ((TWSR & 0XF8) != MSTR_RD_BYTE_WITH_ACK)
		  error_state = MasterReadByteErr;


		  *data = TWDR;


	 return error_state;
}

I2C_ErrStatus I2C_voidMasterReadDataByteWithNAck(u8* data)
{

	 I2C_ErrStatus error_state= NoError;

	 TWCR = (1<<TWEN) | (1<<TWINT);


	  while (!GET_BIT(TWCR,TWINT))
	  {
	    //POLLING until it is raised again
	  }



	  if ((TWSR & 0XF8) != MSTR_RD_BYTE_WITH_NO_ACK)
		  error_state = MasterReadByteErr;

CLCD_voidGoToRowColumn(2,15);
CLCD_voidSendInteger((TWSR & 0XF8));
		  *data = TWDR;


	 return error_state;
}


void I2C_voidSendStopCondition(void)
{
  // Send Stop Condition & clear flag
  TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWSTO);

}

