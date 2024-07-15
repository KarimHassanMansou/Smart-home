
#ifndef SPI_SPI_INTERFACE_H_
#define SPI_SPI_INTERFACE_H_

void SPI_voidInitAsMaster(void);
void SPI_voidInitAsSlave(void);
u8 SPI_u8Transive(u8 copy_u8SendData );
u8 SPI_u8Transive2(u8 copy_u8SendData );
u8 SPI_u8TransiveAsync(u8 copy_u8SendData, void (*ptr_to_Func)(void) );


#endif /* SPI_SPI_INTERFACE_H_ */
