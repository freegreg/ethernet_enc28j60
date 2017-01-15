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
#include "enc28j60_driver/reg_description.h"
#include "enc28j60_driver/reg_operations.h"
#include "enc28j60_driver/driver_enc28j60.h"

void tohex(uint8_t * in, uint8_t insz, char * out, uint8_t outsz);
char MAC_ADDR_HEX[20];
uint8_t MAC_ADDR_R[6];
uint8_t MAC_ADDR[6] = {0x01, 0x23, 0x45, 0x67, 0x89, 0xA1};
int main() {
	//Initialize IO For ENC28J60
	DDRD |= (1 << PD7);
	DDRD &= ~(1 << PD6);
	PORTD |= (1 << PD7);

	SPI_Init();
	//spiPutGetByte(0b01001000);
	USART_Init(38400);  // Initialise USART
	//sei();         // enable all interrupts

	//enc28j60Init(MAC_ADDR);

	while (1) {
		//GetMac(MAC_ADDR_R);
		//tohex(MAC_ADDR_R, 6, MAC_ADDR_HEX, 20);
		//printf("MAC: %s ", MAC_ADDR_HEX);BANK3_EREVID
		//WriteControlReg(BANK3_MAADR6, 0xAB); // local MAC address
		SetBank(0);
		uint8_t d = ReadControlEthReg(BANK0_ERDPTL);
		printf("%d ", d);
		SetBank(3);
		d = ReadControlEthReg(BANK3_EPAUSH);
		printf("%d ", d);
		WriteControlReg(BANK3_MAADR6, 0xAB); // local MAC address
		d = ReadControlMacMiiReg(BANK3_MAADR6);
		printf("%d ", d);
		_delay_ms(250);

	}

}

void tohex(uint8_t * in, uint8_t insz, char * out, uint8_t outsz)
{
	uint8_t * pin = in;
	uint8_t * hex = "0123456789ABCDEF";
    char * pout = out;
    for(; pin < in+insz; pout +=3, pin++){
        pout[0] = hex[(*pin>>4) & 0xF];
        pout[1] = hex[ *pin     & 0xF];
        pout[2] = ':';
        if (pout + 3 - out > outsz){
            /* Better to truncate output string than overflow buffer */
            /* it would be still better to either return a status */
            /* or ensure the target buffer is large enough and it never happen */
            break;
        }
    }
    pout[-1] = 0;
}
