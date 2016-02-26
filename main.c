/*
 * mian.c
 *
 *  Created on: Feb 25, 2016
 *      Author: grigori.gutu
 */
#define F_CPU 8000000UL
#define UART_PRINTF
#include "avr/io.h"
#include "avr/interrupt.h"
#include "avr/delay.h"
#include "spi/spi.h"
#include "uart_debug/uart.h"

const char *byte_to_binary(int x) {
	static char b[9];
	b[0] = '\0';

	int z;
	for (z = 128; z > 0; z >>= 1) {
		strcat(b, ((x & z) == z) ? "1" : "0");
	}

	return b;
}

int main() {
	//Initialize IO For ENC28J60
	DDRD |= (1 << PD7);
	DDRD &= ~(1 << PD6);
	PORTD |= (1 << PD7);

	SPI_Init();
	//spiPutGetByte(0b01001000);
	USART_Init(38400);  // Initialise USART
	//sei();         // enable all interrupts
	while (1) {
		SOFT_SPI_CS_LOW;
		spiPutGetByte(0b00001000);
		unsigned char c = spiPutGetByte(0);
		SOFT_SPI_CS_HIGH;
		printf("Byte %s ", byte_to_binary(c));
		_delay_ms(250);
	}

}
