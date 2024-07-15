#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "DIO_register.h"

void MDIO_voidSetPortDirection(u8 copy_u8PortID, u8 copy_u8PortDirection)
{
	switch (copy_u8PortID)
	{
		case PORTA:
		if (copy_u8PortDirection == OUTPUT)
		{
			DDRA_REG=PORTDIR_OUTPUT;
		}
		else if (copy_u8PortDirection == INPUT)
		{
			DDRA_REG=PORTDIR_INPUT;
		}
		break;
		
		case PORTB:
		if (copy_u8PortDirection == OUTPUT)
		{
			DDRB_REG=PORTDIR_OUTPUT;
		}
		else if (copy_u8PortDirection == INPUT)
		{
			DDRB_REG=PORTDIR_INPUT;
		}
		break;
		
		case PORTC:
		if (copy_u8PortDirection == OUTPUT)
		{
			DDRC_REG=PORTDIR_OUTPUT;
		}
		else if (copy_u8PortDirection == INPUT)
		{
			DDRC_REG=PORTDIR_INPUT;
		}
		break;
		
		case PORTD:
		if (copy_u8PortDirection == OUTPUT)
		{
			DDRD_REG=PORTDIR_OUTPUT;
		}
		else if (copy_u8PortDirection == INPUT)
		{
			DDRD_REG=PORTDIR_INPUT;
		}
		break;
		
		default: /*invalid port id */ break;
	}
}

void MDIO_voidSetPortValue(u8 copy_u8PortID , u8 copy_u8PortValue)
{
	switch(copy_u8PortID)
	{
		case PORTA:
		if (copy_u8PortValue == HIGH)
		{
			PORTA_REG=PORTVAL_HIGH;
		}
		else if (copy_u8PortValue == LOW)
		{
			PORTA_REG=PORTVAL_LOW;
		}
		else 
		{
			PORTA_REG = copy_u8PortValue;
		}
		break;
		
		
		case PORTB:
		if (copy_u8PortValue == HIGH)
		{
			PORTB_REG=PORTVAL_HIGH;
		}
		else if (copy_u8PortValue == LOW)
		{
			PORTB_REG=PORTVAL_LOW;
		}
		else 
		{
			PORTB_REG = copy_u8PortValue;
		}
		break;
		
		
		case PORTC:
		if (copy_u8PortValue == HIGH)
		{
			PORTC_REG=PORTVAL_HIGH;
		}
		else if (copy_u8PortValue == LOW)
		{
			PORTC_REG=PORTVAL_LOW;
		}
		else 
		{
			PORTC_REG = copy_u8PortValue;
		}
		break;
		
		
		case PORTD:
		if (copy_u8PortValue == HIGH)
		{
			PORTD_REG=PORTVAL_HIGH;
		}
		else if (copy_u8PortValue == LOW)
		{
			PORTD_REG=PORTVAL_LOW;
		}
		else 
		{
			PORTD_REG = copy_u8PortValue;
		}
		break;
		
		
		default:
		  break;
	}
}

void MDIO_voidSetPinDirection(u8 copy_u8PortID, u8 copy_u8PinID, u8 copy_u8PinDirection)
{
	switch(copy_u8PortID)
	{
		case PORTA:
			WRITE_BIT(DDRA_REG, copy_u8PinID, copy_u8PinDirection);
		break;
		
		case PORTB:
			WRITE_BIT(DDRB_REG, copy_u8PinID, copy_u8PinDirection);
		break;
		
		case PORTC:
			WRITE_BIT(DDRC_REG, copy_u8PinID, copy_u8PinDirection);
		break;
		
		case PORTD:
			WRITE_BIT(DDRD_REG, copy_u8PinID, copy_u8PinDirection);
		break;
		
		default :
		break;
		
	}
}

void MDIO_voidSetPinValue(u8 copy_u8PortID, u8 copy_u8PinID, u8 copy_u8PinValue)
{
	switch(copy_u8PortID)
	{
		case PORTA:
			WRITE_BIT(PORTA_REG, copy_u8PinID, copy_u8PinValue);
		break;
		
		case PORTB:
			WRITE_BIT(PORTB_REG, copy_u8PinID, copy_u8PinValue);
		break;
		
		case PORTC:
			WRITE_BIT(PORTC_REG, copy_u8PinID, copy_u8PinValue);
		break;
		
		case PORTD:
			WRITE_BIT(PORTD_REG, copy_u8PinID, copy_u8PinValue);
		break;
		
		default :
		break;
		
	}
}

void MDIO_voidTogpin(u8 copy_u8PortID, u8 copy_u8PinID)
{
	switch (copy_u8PortID)
	{
		case PORTA:  TOGGLE_BIT(PORTA_REG, copy_u8PinID);          
		break;
		case PORTB:  TOGGLE_BIT(PORTB_REG, copy_u8PinID);          
		break;
		case PORTC:  TOGGLE_BIT(PORTC_REG, copy_u8PinID);          
		break;
		case PORTD:  TOGGLE_BIT(PORTD_REG, copy_u8PinID);          
		break;
		default:
		break;
	}
	
}

u8   MDIO_u8GetPinValue(u8 copy_u8PortID, u8 copy_u8PinID)
{
	u8 Local_u8PinState;
	switch(copy_u8PortID)
	{
		case PORTA:
		          Local_u8PinState=GET_BIT(PINA_REG, copy_u8PinID);
		break;
		
		case PORTB:
		          Local_u8PinState=GET_BIT(PINB_REG, copy_u8PinID);
		break;
		
		case PORTC:
		          Local_u8PinState=GET_BIT(PINC_REG, copy_u8PinID);
		break;
		
		case PORTD:
		          Local_u8PinState=GET_BIT(PIND_REG, copy_u8PinID);
		break;
		
		default :
		break;
	}
	return Local_u8PinState;
}

