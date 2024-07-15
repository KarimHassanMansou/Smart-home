#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include <util/delay.h>
#include <string.h>

#include "LCD_interface.h"
#include "LCD_config.h"
#include "LCD_private.h"

void HLCD_voidSendCommand(u8 copy_u8Command)
{

	MDIO_voidSetPinValue(LCD_PORT_CONTROL, LCD_RW, LOW);
	MDIO_voidSetPinValue(LCD_PORT_CONTROL, LCD_RS, LOW);

	MDIO_voidSetPortValue(LCD_PORT, copy_u8Command);

	MDIO_voidSetPinValue(LCD_PORT_CONTROL, LCD_E, HIGH);
	_delay_ms(2);
	MDIO_voidSetPinValue(LCD_PORT_CONTROL, LCD_E, LOW);
	//_delay_ms(1);
}

void HLCD_voidSendData(u8 copy_u8Data)
{


	MDIO_voidSetPinValue(LCD_PORT_CONTROL, LCD_RS, HIGH);
	MDIO_voidSetPinValue(LCD_PORT_CONTROL, LCD_RW, LOW);

	MDIO_voidSetPortValue(LCD_PORT, copy_u8Data);

	MDIO_voidSetPinValue(LCD_PORT_CONTROL, LCD_E, HIGH);
	_delay_ms(2);
	MDIO_voidSetPinValue(LCD_PORT_CONTROL, LCD_E, LOW);
	//_delay_ms(1);
}

void HLCD_voidInatialize(void)
{


	MDIO_voidSetPortDirection(LCD_PORT, OUTPUT);

	MDIO_voidSetPinDirection(LCD_PORT_CONTROL, LCD_RS, OUTPUT);
	MDIO_voidSetPinDirection(LCD_PORT_CONTROL, LCD_RW, OUTPUT);
	MDIO_voidSetPinDirection(LCD_PORT_CONTROL, LCD_E, OUTPUT);

	//MDIO_voidSetPinValue(LCD_PORT_CONTROL, LCD_E, LOW);
	_delay_ms(40);
	HLCD_voidSendCommand(0b00111000);
	HLCD_voidSendCommand(0b00001100);
	HLCD_voidSendCommand(0x01);
}

void HLCD_voidSendString(const char *ptr_charData)
{
	u8 i=0;
	while (ptr_charData[i] != '\0')
	{
		HLCD_voidSendData(ptr_charData[i]);
		i++;
	}
}

void LCD_Go_To (u8 line ,u8 x){   //indexies for lines are 0,1
	if(line==0){

		HLCD_voidSendCommand(0x80 + x);
	}
	else if (line==1){
		HLCD_voidSendCommand(0xC0 + x);

	}
}


void HlCD_voidClearLcd()
{
	HLCD_voidSendCommand(0x01);
	//HLCD_voidSendString("                  ");
	LCD_Go_To(1,1);
	HLCD_voidSendString("                  ");
}


void HLCD_voidWriteNumber(u8 number)
{
	u8 * localPtr_str[16]={0};
	itoa(number, (char*)localPtr_str, 10);
	HLCD_voidSendString((u8 *)localPtr_str);
}

