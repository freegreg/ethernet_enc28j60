/*
 * driver.h
 *
 *  Created on: Apr 20, 2016
 *      Author: grigori.gutu
 */

#ifndef ENC28J60_DRIVER_DRIVER_ENC28J60_H_
#define ENC28J60_DRIVER_DRIVER_ENC28J60_H_

#include "reg_description.h"
#include "reg_operations.h"

void enc28j60Init(uint8_t *macadr);
void GetMac(uint8_t *macadr);

#endif /* ENC28J60_DRIVER_DRIVER_ENC28J60_H_ */
