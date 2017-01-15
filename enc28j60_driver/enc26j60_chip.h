/*
 * enc26j60_chip.h
 *
 *  Created on: Apr 19, 2016
 *      Author: grigori.gutu
 */

#ifndef ENC28J60_DRIVER_ENC26J60_CHIP_H_
#define ENC28J60_DRIVER_ENC26J60_CHIP_H_
#include "avr/io.h"

#define ENC26J60_SPI_CS_PIN          PIND     /* Define SPI CS signal to be PIC port RC3 */
#define ENC26J60_SPI_CS_DDR          DDRD     /* Define SPI CS signal to be PIC port RC3 */
#define ENC26J60_SPI_CS_BIT          PD5     /* Define SPI CS signal to be PIC port RC3 */
#define ENC26J60_SPI_CS_PORT         PORTD     /* Define SPI CS signal to be PIC port RC3 */
#define ENC26J60_SPI_CS_INIT 		ENC26J60_SPI_CS_DDR |= (1<<ENC26J60_SPI_CS_BIT); ENC26J60_SOFT_SPI_CS_HIGH
#define ENC26J60_SOFT_SPI_CS_HIGH   ENC26J60_SPI_CS_PORT |= (1<<ENC26J60_SPI_CS_BIT)
#define ENC26J60_SOFT_SPI_CS_LOW    ENC26J60_SPI_CS_PORT &= ~(1<<ENC26J60_SPI_CS_BIT)


#endif /* ENC28J60_DRIVER_ENC26J60_CHIP_H_ */
