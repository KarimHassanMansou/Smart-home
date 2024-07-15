#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H

#define PORTA  0
#define PORTB  1
#define PORTC  2
#define PORTD  3

#define OUTPUT 1
#define INPUT  0

#define HIGH 1
#define LOW  0

#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7

#define PORTDIR_OUTPUT  0xFF
#define PORTDIR_INPUT   0x00

#define PORTVAL_HIGH    0xFF
#define PORTVAL_LOW     0x00


void MDIO_voidSetPortDirection(u8 copy_u8PortID, u8 copy_u8PortDirection);
void MDIO_voidSetPortValue(u8 copy_u8PortID , u8 copy_u8PortValue);
void MDIO_voidSetPinDirection(u8 copy_u8PortID, u8 copy_u8PinID, u8 copy_u8PinDir);
void MDIO_voidSetPinValue(u8 copy_u8PortID, u8 copy_u8PinID, u8 copy_u8PinValue);
void MDIO_voidTogpin(u8 copy_u8PortID, u8 copy_u8PinID);
u8   MDIO_u8GetPinValue(u8 copy_u8PortID, u8 copy_u8PinID);


#endif
