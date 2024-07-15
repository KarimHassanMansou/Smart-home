#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "LED_interface.h"
#include "LED_config.h"


void HLED_voidLedInitialize()
{
	MDIO_voidSetPortDirection(LED_PORT, OUTPUT);
}


void HLED_voidLedOn(u8 LED_PIN)
{
	MDIO_voidSetPinValue(LED_PORT, LED_PIN, HIGH);
}


void HLED_voidLedOff(u8 LED_PIN)
{
	MDIO_voidSetPinValue(LED_PORT, LED_PIN, LOW);
}


void HLED_voidLedToggle( u8 LED_PIN)
{
	MDIO_voidTogpin(LED_PORT, LED_PIN);
}
