/*
 * uart.c
 *
 *  Created on: Feb 25, 2016
 *      Author: grigori.gutu
 */

#include "uart.h"
// Define baud rate
//#define USART_BAUDRATE 38400
//#define BAUD_PRESCALE (((8000000 / (USART_BAUDRATE * 16UL))) - 1)

volatile unsigned char value;
/* This variable is volatile so both main and RX interrupt can use it.
It could also be a uint8_t type */

void USART_Init(uint16_t USART_BAUDRATE){
   // Set baud rate
   uint16_t	BAUD_PRESCALE = (((F_CPU / (USART_BAUDRATE * 16UL))) - 1);
   UBRRH = (BAUD_PRESCALE >> 8);
   UBRRL = BAUD_PRESCALE;// Load lower 8-bits into the low byte of the UBRR register
	 /* Load upper 8-bits into the high byte of the UBRR register
    Default frame format is 8 data bits, no parity, 1 stop bit
  to change use UCSRC, see AVR datasheet*/

  // Enable receiver and transmitter and receive complete interrupt
  UCSRB = ((1<<TXEN)|(1<<RXEN));//| (1<<RXCIE)

  // setup our stdio stream
  stdout = &mystdout;
}

void USART_SendByte(uint8_t u8Data){

  // Wait until last byte has been transmitted
  while(!(UCSRA &(1<<UDRE)));

  // Transmit data
  UDR = u8Data;
}

// not being used but here for completeness
      // Wait until a byte has been received and return received data
uint8_t USART_ReceiveByte(){
  while(!(UCSRA &(1<<RXC)));
  return UDR;
}

void USART_SendStr(unsigned char *s)// Sending String
{
	while (*s != 0)
		USART_SendByte(*s++);
}

// this function is called by printf as a stream handler
int USART_putchar_printf(char var, FILE *stream) {
    // translate \n to \r for br@y++ terminal
    if (var == '\n') USART_SendByte('\r');
    USART_SendByte(var);
    return 0;
}

/* Interrupt Service Routine for Receive Complete
NOTE: vector name changes with different AVRs see AVRStudio -
Help - AVR-Libc reference - Library Reference - <avr/interrupt.h>: Interrupts
for vector names other than USART_RXC_vect for ATmega32 */

ISR(USART_RXC_vect){
   value = UDR;             //read UART register into value
}

