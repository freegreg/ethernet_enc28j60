/*
 * File:   soft_spi.h
 * Author: freeg
 *
 * Created on 6 ???????? 2014 ?., 17:46
 */

#ifndef SOFT_SPI_H
#define	SOFT_SPI_H

#include "avr/io.h"

static unsigned int SPI_DELAY = 50;        //in us

//Define all SPI Pins
#define SPI_MOSI_BIT        PD3     /* Define SPI SDO signal to be PIC port RC4 */
#define SPI_MISO_BIT        PD4     /* Define SPI SDI signal to be PIC port RC5 */
#define SPI_CLK_BIT         PD2     /* Define SPI CLK signal to be PIC port RC3 */


//Define all SPI PORT
#define SPI_MOSI_PORT       PORTD     /* Define SPI SDO signal to be PIC port RC4 */
#define SPI_MISO_PORT       PORTD     /* Define SPI SDI signal to be PIC port RC5 */
#define SPI_CLK_PORT        PORTD     /* Define SPI CLK signal to be PIC port RC3 */


//Define all SPI DDR
#define SPI_MOSI_DDR        DDRD     /* Define SPI SDO signal to be PIC port RC4 */
#define SPI_MISO_DDR        DDRD     /* Define SPI SDI signal to be PIC port RC5 */
#define SPI_CLK_DDR         DDRD     /* Define SPI CLK signal to be PIC port RC3 */


//Define all SPI PIN
#define SPI_MOSI_PIN        PIND     /* Define SPI SDO signal to be PIC port RC4 */
#define SPI_MISO_PIN        PIND     /* Define SPI SDI signal to be PIC port RC5 */
#define SPI_CLK_PIN         PIND     /* Define SPI CLK signal to be PIC port RC3 */

#define SOFT_SPI_CLK_HIGH    SPI_CLK_PORT |= (1<<SPI_CLK_BIT)
#define SOFT_SPI_CLK_LOW     SPI_CLK_PORT &= ~(1<<SPI_CLK_BIT)

#define SOFT_SPI_MOSI_HIGH   SPI_MOSI_PORT |= (1<<SPI_MOSI_BIT)
#define SOFT_SPI_MOSI_LOW    SPI_MOSI_PORT &= ~(1<<SPI_MOSI_BIT)

#define SOFT_SPI_MISO_READ   (SPI_MISO_PIN & (1<<SPI_MISO_BIT))

#define SPI_MOSI_INIT 		SPI_MOSI_DDR |= (1<<SPI_MOSI_BIT)
#define SPI_MISO_INIT 		SPI_MISO_DDR &= ~(1<<SPI_MISO_BIT)
#define SPI_CLK_INIT 		SPI_CLK_DDR |= (1<<SPI_CLK_BIT); SOFT_SPI_CLK_LOW

void SPI_Init(void);
void SPI_Delay(void);
unsigned char spiPutGetByte(unsigned char c);

#endif	/* SOFT_SPI_H */

