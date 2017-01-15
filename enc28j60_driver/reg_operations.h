/*
 * reg_operations.h
 *
 *  Created on: Apr 19, 2016
 *      Author: grigori.gutu
 */

#ifndef ENC28J60_DRIVER_REG_OPERATIONS_H_
#define ENC28J60_DRIVER_REG_OPERATIONS_H_

#include "reg_description.h"
#include "../spi/spi.h"
#include "enc26j60_chip.h"
#include "avr/delay.h"

uint8_t ReadControlEthReg(uint8_t eth_addr);
uint8_t ReadControlMacMiiReg(uint8_t mac_mii_addr);
void WriteControlReg(uint8_t reg_addr, uint8_t reg_data);

void SetBank(uint8_t bank_n);
uint16_t ReadPhyReg(uint8_t phy_reg_addr);
void WritePhyReg(uint8_t phy_reg_addr, uint16_t data_in);

void BitFieldSet(uint8_t reg_addr, uint8_t mask);
void BitFieldClear(uint8_t reg_addr, uint8_t mask);

const char *byte_to_binary(int x);
const char *byte16_to_binary(uint16_t x);
#endif /* ENC28J60_DRIVER_REG_OPERATIONS_H_ */
