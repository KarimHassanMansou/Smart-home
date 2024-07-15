/*
 * SMART_MASTER.c
 *
 * Created: 12/8/2021 8:37:08 PM
 *  Author: karim hassan
 */ 

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include <util/delay.h>

#include <stdlib.h>

#include "DIO_interface.h"
#include "SPI_interface.h"
#include "KEYPAD_interface.h"
#include "LCD_interface.h"
#include "LED_interface.h"


u32 Global_u32Password = 1907;

void Led_Red();
void Led_blue();

int main ()
{


	u8 *Local_u8Receivedvalue = NULL;
	u16 Local_u16Receivedvalue2;
	
    HLCD_voidInatialize();
	SPI_voidInitAsMaster();
	HKEYPAD_voidInitialize();
	
	while (1)
	{
		
		
		*Local_u8Receivedvalue = HKEYPAD_u8GetPressedKey();

		Local_u16Receivedvalue2 = atoi(Local_u8Receivedvalue);

		SPI_u8Transive(Local_u16Receivedvalue2);
		

	}

}






void Led_Red()
{
	
}


void Led_blue()
{
	
}


