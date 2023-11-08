//#include <avr/io.h>
//#include <util/delay.h>
#include <util/delay.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "SSD_interface.h"
#include "CLCD_interface.h"


void LED_TEST();
void SSD_APP();
void LCD_APP1();
void LCD_APP2();


void main(void)
	{

		DIO_voidInit();
		CLCD_voidInit();
		CLCD_voidGoToRowColumn(2,3);

		CLCD_voidSendString("I can play");

		while(1)
		{
			//CLCD_voidSendData('M');
			//CLCD_voidSendData('N');
//			LCD_APP1();
		}

	}


void SSD_APP()
{
	SSD_t ssd1 = {SSD_u8ANODE,DIO_u8PORTB,DIO_u8PORTA,DIO_u8PIN3};
	SSD_t* ptr1 =&ssd1;

	SSD_t ssd2 = {SSD_u8ANODE,DIO_u8PORTB,DIO_u8PORTA,DIO_u8PIN2};
	SSD_t* ptr2 =&ssd2;

	for(int i =0; i<=9; i++)
	{
		for(int j=0; j<=9; j++)
		{
			for(int k=0;k<50; k++) //assume one second
			{
				SSD_u8Disable(ptr2);
				SSD_u8Enable(ptr1);
				SSDBCD_u8SetNum(i,ptr1);
				_delay_ms(10);
				SSD_u8Disable(ptr1);
				SSD_u8Enable(ptr2);
				SSDBCD_u8SetNum(j,ptr2);
				_delay_ms(10);
			}
		}
	}
}


void LED_TEST()
{
	DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN6,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN5,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN4,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN7,DIO_u8PIN_HIGH);
}


void LCD_APP1()
{

	u8 Person[8]={0b00001110,0b00001110,0b00000100,0b00011111,0b00000100,0b00001010,0b00001010};
	u8 dance1[8]={0b00001110,0b00001110,0b00010100,0b00011111,0b00000101,0b00001010,0b00001010};
	u8 dance2[8]={0b00001110,0b00001110,0b00000101,0b00011111,0b00010100,0b00001010,0b00001010};
	u8 Run1[8]={0b00001110,0b00001110,0b00000100,0b00011111,0b00000100,0b00001010,0b00001001};
	u8 Run2[8]={0b00001110,0b00001110,0b00000100,0b00011111,0b00000100,0b00000110,0b00000101};

	u8 Gun[8]   ={0b00000000,0b00011111,0b00011111,0b00011010,0b00011110,0b00011000,0b00000000};
	u8 Ball[8]=  {0b00000000,0b00000000,0b00000000,0b00000000,0b00001110,0b00001110,0b00001110};
	u8 Bullet[8]={0b00000000,0b00000100,0b00001110,0b00000100,0b00000000,0b00000000,0b00000000};
	u8 Dead[8]  ={0b00011111,0b00011111,0b00011111,0b00011111,0b00011111,0b00011111,0b00011111};

	CLCD_voidSendSpecialCharacter(Person,0);
	CLCD_voidSendSpecialCharacter(Gun,1);
	CLCD_voidSendSpecialCharacter(Ball,2);
	CLCD_voidSendSpecialCharacter(Bullet,3);
	CLCD_voidSendSpecialCharacter(dance1,4);
	CLCD_voidSendSpecialCharacter(dance2,5);
	CLCD_voidSendSpecialCharacter(Run1,6);
	CLCD_voidSendSpecialCharacter(Run2,7);


	CLCD_voidSendSpecialCharacter(Person,0);
	CLCD_voidSendCommand(1);
	CLCD_voidSendString("Hi, I'm Hamoksha");
	CLCD_voidGoToRowColumn(1,7);
	CLCD_voidSendData(0);
	_delay_ms(1500);

	CLCD_voidSendCommand(1);
	CLCD_voidSendString("I can play");
	CLCD_voidGoToRowColumn(1,0);
	CLCD_voidSendString("Foot Ball ");
	CLCD_voidSendData(0);
	CLCD_voidSendData(2);
	_delay_ms(1000);
	CLCD_voidSendCommand(1);
	CLCD_voidSendString("I can play");
	CLCD_voidGoToRowColumn(1,0);
	CLCD_voidSendString("Foot Ball ");
	CLCD_voidSendData(6);
	CLCD_voidSendData(2);
	_delay_ms(500);
	CLCD_voidSendCommand(1);
	CLCD_voidSendString("I can play");
	CLCD_voidGoToRowColumn(1,0);
	CLCD_voidSendString("Foot Ball ");
	CLCD_voidSendData(7);
	CLCD_voidSendString(" ");
	CLCD_voidSendData(2);
	_delay_ms(500);
	CLCD_voidSendCommand(1);
	CLCD_voidSendString("I can play");
	CLCD_voidGoToRowColumn(1,0);
	CLCD_voidSendString("Foot Ball ");
	CLCD_voidSendData(0);
	CLCD_voidSendString("  ");
	CLCD_voidSendData(2);
	_delay_ms(500);
	CLCD_voidSendCommand(1);
	CLCD_voidSendString("I can play");
	CLCD_voidGoToRowColumn(1,0);
	CLCD_voidSendString("Foot Ball ");
	CLCD_voidSendData(0);
	CLCD_voidSendString("   ");
	CLCD_voidSendData(2);
	_delay_ms(1500);

	for(u8 i=0; i<15; i++)
	{
		CLCD_voidSendCommand(1);
		CLCD_voidSendString("I can run");
		CLCD_voidGoToRowColumn(1,i);
		CLCD_voidSendData(0);
		_delay_ms(200);
		CLCD_voidSendCommand(1);
		CLCD_voidSendString("I can run");
		CLCD_voidGoToRowColumn(1,i);
		CLCD_voidSendData(6);
		_delay_ms(200);
		CLCD_voidSendCommand(1);
		CLCD_voidSendString("I can run");
		CLCD_voidGoToRowColumn(1,i);
		CLCD_voidSendData(7);
		_delay_ms(200);
	}
	CLCD_voidSendCommand(1);
	CLCD_voidSendString("I can run");
	CLCD_voidGoToRowColumn(1,15);
	CLCD_voidSendData(0);
	_delay_ms(250);
	_delay_ms(1000);


	CLCD_voidSendCommand(1);
	CLCD_voidSendString("I can dance");
	CLCD_voidGoToRowColumn(1,7);
	CLCD_voidSendData(0);
	_delay_ms(500);
	for(u8 i=0; i<7; i++)
	{
		CLCD_voidSendCommand(1);
		CLCD_voidSendString("I can dance");
		CLCD_voidGoToRowColumn(1,7);
		CLCD_voidSendData(4);
		_delay_ms(500);
		CLCD_voidSendCommand(1);
		CLCD_voidSendString("I can dance");
		CLCD_voidGoToRowColumn(1,7);
		CLCD_voidSendData(5);
		_delay_ms(500);
	}
	_delay_ms(1000);

	CLCD_voidSendCommand(1);
	CLCD_voidSendString("Don't kill me");
	CLCD_voidGoToRowColumn(1,0);
	CLCD_voidSendData(1);
	CLCD_voidGoToRowColumn(1,15);
	CLCD_voidSendData(0);
	_delay_ms(500);

	for (u8 i=0; i<14; i++)
	{
		CLCD_voidSendCommand(1);
		CLCD_voidSendString("Don't kill me");
		CLCD_voidGoToRowColumn(1,0);
		CLCD_voidSendData(1);
		CLCD_voidGoToRowColumn(1,1+i);
		CLCD_voidSendData(3);
		CLCD_voidGoToRowColumn(1,15);
		CLCD_voidSendData(0);
		_delay_ms(300);
	}

	CLCD_voidSendCommand(1);
	CLCD_voidSendString("Don't kill me");
	CLCD_voidGoToRowColumn(1,0);
	CLCD_voidSendData(1);
	CLCD_voidSendSpecialCharacter(Dead,0);
	CLCD_voidGoToRowColumn(1,15);
	CLCD_voidSendData(0);

	_delay_ms(1500);

}

