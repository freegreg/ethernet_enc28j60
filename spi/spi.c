// INCLUDES ***********************************************

#include "spi.h"

/**
 * This function writes a byte out onto the SPI OUT port, and reads a byte from
 * the SPI IN port.
 *
 * @param c Gives the byte to write out onto the SPI port
 *
 * @return Returns the byte read from the SPI IN port
 */
unsigned char spiPutGetByte(unsigned char c) {
	volatile unsigned char ret;
	volatile unsigned int mask;
	//SPI Mode 0. CS active low. Clock idle 0. Clock rising edge.
	SOFT_SPI_CLK_LOW;
	//Enable SPI communication. The SPI Enable signal must be pulsed low for each byte sent!

	//Ensure a minimum delay of 500ns between falling edge of SPI Enable signal
	//and rising edge of SPI Clock!
	SPI_Delay();
	mask = 0x80; //Initialize to write and read bit 7
	ret = 0; //Initialize read byte with 0

	do {
		if (c & mask)
			SOFT_SPI_MOSI_HIGH;
		else
			SOFT_SPI_MOSI_LOW; //Clock out current bit onto SPI Out line

		SPI_Delay();

		SOFT_SPI_CLK_HIGH; //Set SPI Clock line

		SPI_Delay();

		if (SOFT_SPI_MISO_READ)
			ret |= mask; //Read current bit fromSPI In line

		SPI_Delay();

		SOFT_SPI_CLK_LOW; //Set SPI Clock line
		mask = mask >> 1; //Shift mask so that next bit is written and read from SPI lines



	} while (mask != 0);

	//Ensure a minimum delay of 750ns between falling edge of SPI Clock signal
	//and rising edge of SPI Enable!
	//Disable SPI communication. The SPI Enable signal must be pulsed low for each byte sent!
	return ret;
}

void SPI_Init(void) {
	SPI_MOSI_INIT;
	SPI_MISO_INIT;
	SPI_CLK_INIT;
}

void SPI_Delay(void) {
	int i = SPI_DELAY;
	while (i-- > 0)
		;
}
