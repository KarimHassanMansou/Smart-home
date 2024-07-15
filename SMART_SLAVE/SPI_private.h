
#ifndef SPI_SPI_PRIVATE_H_
#define SPI_SPI_PRIVATE_H_

/*
 * TO ENABLE OR DISABLE THE SPI
 */
#define SPI_ENABLE            1
#define SPI_DISABLE           0

/*
 * MASTER SLAVE SELECT
 */
#define MASTER_SPI_MODE       1
#define SLAVE_SPI_MODE        0

/*
 * CLOCK_POLARITY
 */
#define RISING_LEADING_EDGE_FALLING_TRAILING_EDGE  0
#define FALLING_LEADING_EDGE_RISING_TRAILING_EDGE  1


/*
 * Clock Phase
 */
#define SAMPLE_LEADING_EDGE_SETUP_TRAILING_EDGE    0
#define SETUP_LEADING_EDGE_SAMPLE_TRAILING_EDGE    1

/*
 * SPI CLOCK RATE
 */
#define DIVIDE_BY_4       0
#define DIVIDE_BY_16      1
#define DIVIDE_BY_64      2
#define DIVIDE_BY_128     3
#define DIVIDE_BY_2       4
#define DIVIDE_BY_8       5
#define DIVIDE_BY_32      6





/* number 12 for SPI interrupt  in vector table */
void __vector_12 (void) __attribute__((signal));




#endif /* SPI_SPI_PRIVATE_H_ */
