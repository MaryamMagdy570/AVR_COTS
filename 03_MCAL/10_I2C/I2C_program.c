#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "I2C_register.h"
#include "I2C_private.h"
#include "I2C_config.h"
#include "I2C_interface.h"


void I2C_voidInit(void)
{   
	TWSR = 0x00;
 /*  pre-scaler TWPS=00 */
 /* Bit Rate: 400.000 kbps using zero pre-scaler TWPS=00 and F_CPU=8Mhz */
 TWBR=BITRATE(TWSR);  
 
 /* Two Wire Bus address my address if any master device want to call me: 0x1 (used in case this MC is a slave device)
  General Call Recognition: Off */
 TWAR = 0b00000010; // my address = 0x01 :) 
	
 SET_BIT(TWCR,TWEN); /* enable TWI */
}

void I2C_voidStart(void)
{
  // Send Start Condition
  TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWSTA);

  // Wait for TWINT flag set in TWCR Register
  while (!GET_BIT(TWCR,TWINT))
  {
    //POLLING
  }
}

void I2C_voidStop(void)
{
  // Send Stop Condition
  TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWSTO);
}

void void I2C_voidWrite(u8 data)
{
  // Put data On TWI Register
  TWDR = data;
  // Send Data
  TWCR = (1 << TWINT) | (1 << TWEN);
  // Wait for TWINT flag set in TWCR Register
  while (!GET_BIT(TWCR,TWINT))
  {

  }
}

u8 I2C_u8ReadACK(void)
{
  //enable Ack
  TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWEA);    
  // Wait for TWINT flag set in TWCR Register
  while (!GET_BIT(TWCR,TWINT))
  {

  }
  // Read Data
  return TWDR;
}

u8 I2C_u8ReadNACK(void)
{
  TWCR = (1 << TWINT) | (1 << TWEN);
  // Wait for TWINT flag set in TWCR Register
  while (!GET_BIT(TWCR,TWINT))
  {

  }
  // Read Data
  return TWDR;
}

u8 I2C_u8GetStatus(void)
{
  u8 status;
  status = TWSR & 0b11111000;
  return status;
}



