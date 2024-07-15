#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "SPI_config.h"
#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_register.h"
#include "DIO_interface.h"

void (*ptrForSPI)(void);

void SPI_voidInitAsMaster(void)
{
	MDIO_voidSetPinDirection(PORTB, PIN5, OUTPUT); //MOSI
	MDIO_voidSetPinDirection(PORTB, PIN6, INPUT);  //MISO
	MDIO_voidSetPinDirection(PORTB, PIN7, OUTPUT); //SOURCE CLOCK
	/*
	 * TO MAKE SS (INPUT PULL UP)
	 */
	MDIO_voidSetPinDirection(PORTB, PIN4, INPUT);
	MDIO_voidSetPinValue(PORTB, PIN4, HIGH);

	/*
	 * to set as a master
	 */
	SET_BIT(SPCR, SPCR_MSTR);

	/*
	 * clock polarity
	 */
#if CLOCK_POLARITY ==  RISING_LEADING_EDGE_FALLING_TRAILING_EDGE
	CLEAR_BIT(SPCR, SPCR_CPOL);

#elif CLOCK_POLARITY ==  FALLING_LEADING_EDGE_RISING_TRAILING_EDGE
	SET_BIT(SPCR, SPCR_CPOL);
#endif


	/*
	 * clock phase
	 */
#if CLOCK_PHASE == SAMPLE_LEADING_EDGE_SETUP_TRAILING_EDGE
	CLEAR_BIT(SPCR, SPCR_CPHA);

#elif CLOCK_PHASE == SETUP_LEADING_EDGE_SAMPLE_TRAILING_EDGE
	SET_BIT(SPCR, SPCR_CPHA);
#endif


#if CLOCK_RATE == DIVIDE_BY_4
	CLEAR_BIT(SPCR, SPCR_SPR0);
	CLEAR_BIT(SPCR, SPCR_SPR1);
	CLEAR_BIT(SPSR, SPSR_SPI2X);

#elif CLOCK_RATE == DIVIDE_BY_16
	SET_BIT(SPCR, SPCR_SPR0);
	CLEAR_BIT(SPCR, SPCR_SPR1);
	CLEAR_BIT(SPSR, SPSR_SPI2X);
#endif

	/*
	 * to set spi enable or disable
	 */
#if SPI == SPI_ENABLE
	SET_BIT(SPCR, SPCR_SPE);

#elif SPI == SPI_DISABLE
	CLEAR_BIT(SPCR, SPCR_SPE);
#endif

}

void SPI_voidInitAsSlave(void)
{

	MDIO_voidSetPinDirection(PORTB, PIN4, INPUT);
	MDIO_voidSetPinDirection(PORTB, PIN5, INPUT);
	MDIO_voidSetPinDirection(PORTB, PIN6, OUTPUT);
	MDIO_voidSetPinDirection(PORTB, PIN7, INPUT);

	/*
	 * to set as a slave
	 */
	CLEAR_BIT(SPCR, SPCR_MSTR);

	/*
	 * clock polarity
	 */
#if CLOCK_POLARITY ==  RISING_LEADING_EDGE_FALLING_TRAILING_EDGE
	CLEAR_BIT(SPCR, SPCR_CPOL);

#elif CLOCK_POLARITY ==  FALLING_LEADING_EDGE_RISING_TRAILING_EDGE
	SET_BIT(SPCR, SPCR_CPOL);
#endif

	/*
	 * clock phase
	 */
#if CLOCK_PHASE == SAMPLE_LEADING_EDGE_SETUP_TRAILING_EDGE
	CLEAR_BIT(SPCR, SPCR_CPHA);

#elif CLOCK_PHASE == SETUP_LEADING_EDGE_SAMPLE_TRAILING_EDGE
	SET_BIT(SPCR, SPCR_CPHA);
#endif

	/*
	 * to set spi enable or disable
	 */
#if SPI == SPI_ENABLE
	SET_BIT(SPCR, SPCR_SPE);

#elif SPI == SPI_DISABLE
	CLEAR_BIT(SPCR, SPCR_SPE);
#endif
}



u8 SPI_u8Transive(u8 copy_u8SendData )
{
	SPDR = copy_u8SendData;
	while(GET_BIT(SPSR, SPSR_SPIF) != 1);
	return SPDR;
}



u8 SPI_u8Transive2(u8 copy_u8SendData )
{
	SPDR = copy_u8SendData;
	while(GET_BIT(SPSR, SPSR_SPIF) != 1);
	return SPDR;
}



u8 SPI_u8TransiveAsync(u8 copy_u8SendData, void (*ptr_to_Func)(void))
{
	SPDR = copy_u8SendData;
	ptrForSPI = ptr_to_Func;
	SET_BIT(SPCR,SPCR_SPIE);
	return SPDR;
}



void __vector_12 (void)
{
	ptrForSPI();
	CLEAR_BIT(SPCR,SPCR_SPIE);
}
