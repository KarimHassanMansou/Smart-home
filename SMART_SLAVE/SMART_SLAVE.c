/*
 * SMART_SLAVE.c
 *
 * Created: 12/8/2021 8:42:27 PM
 *  Author: karim hassan
 */ 


#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "DIO_interface.h"
#include "SPI_interface.h"
#include "LED_interface.h"
#include "LCD_interface.h"
#include "GIE_interface.h"
#include "ADC_interface.h"
#include <util/delay.h>

#define LDR 500

void ISR();


u8 Global_u8RecievedValue;

int main ()
{

	u16 Temp;
	u16 APP_u16ADCReading;
	u16 MilliVolt;

	u8 Global_copy_u8READ_LDR;

	HLCD_voidInatialize();
	SPI_voidInitAsSlave();
	MADC_INIT();

	GIE_voidEnable();

	MDIO_voidSetPinDirection(PORTA, PIN0, INPUT); //adc pin
	MDIO_voidSetPinDirection(PORTA, PIN1, INPUT); //adc pin

	MDIO_voidSetPinDirection(PORTB , PIN0 , OUTPUT);//HEATER
	MDIO_voidSetPinDirection(PORTD , PIN3 , OUTPUT);//DC FAN
	MDIO_voidSetPinDirection(PORTD , PIN4 , OUTPUT);//RECEPTION LED
	MDIO_voidSetPinDirection(PORTD, PIN5, OUTPUT);
	MDIO_voidSetPinDirection(PORTD, PIN6, OUTPUT);
	MDIO_voidSetPinDirection(PORTD, PIN7, OUTPUT);

	HLCD_voidSendString(" Temperature:");

	while (1)
	{
		
		APP_u16ADCReading=MADC_u8StartConversionSync(0);
		MilliVolt =(u16)((u32)(APP_u16ADCReading*5000UL)/1024UL);
		Temp=(MilliVolt / 10);
		
		LCD_Go_To(0,12);
		HLCD_voidWriteNumber(Temp);
		HLCD_voidSendData(0XDF);//dot before C
		HLCD_voidSendString("C");

		HLCD_voidSendCommand(0xC0);
		
		if(Temp > 30)
		{
			
			HLCD_voidSendString("Cooler mode");
			HLCD_voidSendCommand(0xF0);

			MDIO_voidSetPinValue(PORTD , PIN3 , HIGH);//COOLER ON

			MDIO_voidSetPinValue(PORTB , PIN0 , LOW);//HEATER OFF

		}
		else if (Temp < 20)
		{

			HLCD_voidSendString("Heater mode   ");
			HLCD_voidSendCommand(0xF0);

			MDIO_voidSetPinValue(PORTB , PIN0 , HIGH);//heater

		}
		else if(Temp <= 30 && Temp >= 20)
		{

			HLCD_voidSendString("Normal mode   ");
			HLCD_voidSendCommand(0xF0);

			MDIO_voidSetPinValue(PORTD , PIN3 , LOW);
			MDIO_voidSetPinValue(PORTB , PIN0 , LOW);
		}



		Global_copy_u8READ_LDR=MADC_u8StartConversionSync(1);

		if (Global_copy_u8READ_LDR > 10 && Global_copy_u8READ_LDR < LDR)
		{
			HLED_voidLedOn(4);
		}
		else
		{
			HLED_voidLedOff(4);
		}




		Global_u8RecievedValue = SPI_u8TransiveAsync(0 , &ISR);

	}

}



void ISR()
{
	if (Global_u8RecievedValue == 1)
	{
		HLED_voidLedOn(7);
		HLED_voidLedOff(5);
		HLED_voidLedOff(6);

	}

	else if (Global_u8RecievedValue == 2)
	{
		HLED_voidLedOn(6);
		HLED_voidLedOff(5);
		HLED_voidLedOff(7);

	}
	else if (Global_u8RecievedValue == 3)
	{
		HLED_voidLedOn(5);
		HLED_voidLedOff(6);
		HLED_voidLedOff(7);

	}
}




