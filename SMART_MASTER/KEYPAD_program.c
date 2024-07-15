#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "util/delay.h"

#include "KEYPAD_interface.h"
#include "KEYPAD_private.h"
#include "KEYPAD_config.h"

void HKEYPAD_voidInitialize (void)
{
	/*ROW Initialization*/

	MDIO_voidSetPinDirection(KEYPAD_PORT, KEYPAD_R1, INPUT);
	MDIO_voidSetPinDirection(KEYPAD_PORT, KEYPAD_R2, INPUT);
	MDIO_voidSetPinDirection(KEYPAD_PORT, KEYPAD_R3, INPUT);
	MDIO_voidSetPinDirection(KEYPAD_PORT, KEYPAD_R4, INPUT);

	/*COLUM Initialization*/

	MDIO_voidSetPinDirection(KEYPAD_PORT, KEYPAD_C1, OUTPUT);
	MDIO_voidSetPinDirection(KEYPAD_PORT, KEYPAD_C2, OUTPUT);
	MDIO_voidSetPinDirection(KEYPAD_PORT, KEYPAD_C3, OUTPUT);
	//MDIO_voidSetPinDirection(KEYPAD_PORT, KEYPAD_C4, OUTPUT);

	/*VALUE Initialization*/

	MDIO_voidSetPortValue(KEYPAD_PORT, HIGH);

}

u8 HKEYPAD_u8GetPressedKey (void)
{

	u8 Local_u8PressedKey=KeyPad_Not_Pressed;
	u8 row, column;
	static u8 Local_u8KeypadKeys[4][4] = KPD_Array;
	static u8 Local_u8Col_Num [Col_Num]={KEYPAD_C1,KEYPAD_C2,KEYPAD_C3};
	static u8 Local_u8Row_Num [Row_Num]={KEYPAD_R1,KEYPAD_R2,KEYPAD_R3,KEYPAD_R4};

	while(1)
	{
		for(column=0; column<Col_Num; column++)
		{
			MDIO_voidSetPinValue(KEYPAD_PORT, Local_u8Col_Num[column], LOW);
			for(row=0; row<Row_Num; row++)
			{
				if(MDIO_u8GetPinValue(KEYPAD_PORT, Local_u8Row_Num[row]) == 0)
				{
					Local_u8PressedKey = Local_u8KeypadKeys[row][column];
					//polling until the key released
					while (MDIO_u8GetPinValue(KEYPAD_PORT, Local_u8Row_Num[row]) == 0)
					{
						Local_u8PressedKey = Local_u8KeypadKeys[row][column];
					}
					return Local_u8PressedKey;
				}
			}

			MDIO_voidSetPinValue(KEYPAD_PORT, Local_u8Col_Num[column], HIGH);
		}

	}
	return Local_u8PressedKey;
}
