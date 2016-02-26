/*
 * uart.h
 *
 *  Created on: Feb 25, 2016
 *      Author: grigori.gutu
 */

#ifndef UART_H_
#define UART_H_
#include "avr/interrupt.h"
#include "avr/io.h"
#include <stdio.h>
#include <stdbool.h>

void USART_Init(uint16_t USART_BAUDRATE);
void USART_SendByte(uint8_t u8Data);
uint8_t USART_ReceiveByte();
void USART_SendStr(unsigned char *s);

int USART_putchar_printf(char var, FILE *stream);

static FILE mystdout = FDEV_SETUP_STREAM(USART_putchar_printf, NULL, _FDEV_SETUP_WRITE);



#endif /* UART_H_ */
