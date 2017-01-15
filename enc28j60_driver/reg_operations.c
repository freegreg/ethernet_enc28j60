/*
 * reg_operations.c
 *
 *  Created on: Apr 19, 2016
 *      Author: grigori.gutu
 */

#include "reg_operations.h"
#include "stdint.h"

void SystemResetCommand(void){
	ENC26J60_SOFT_SPI_CS_LOW;
	spiPutGetByte(0xFF);
	ENC26J60_SOFT_SPI_CS_HIGH;
	//wait 1 to init ENC28J60
    _delay_ms(1);
}

//READ CONTROL REGISTER COMMAND SEQUENCE (ETH REGISTERS)
uint8_t ReadControlEthReg(uint8_t eth_addr){
	uint8_t data_out;

	ENC26J60_SOFT_SPI_CS_LOW;
	spiPutGetByte(eth_addr);
	data_out = spiPutGetByte(0x00);
	ENC26J60_SOFT_SPI_CS_HIGH;

	return data_out;
}

//READ CONTROL REGISTER COMMAND SEQUENCE (MAC AND MII REGISTERS)
uint8_t ReadControlMacMiiReg(uint8_t mac_mii_addr){
	uint8_t data_out;

	ENC26J60_SOFT_SPI_CS_LOW;
	spiPutGetByte(mac_mii_addr);
	spiPutGetByte(0x00);
	data_out = spiPutGetByte(0x00);
	ENC26J60_SOFT_SPI_CS_HIGH;

	return data_out;
}


//WRITE CONTROL REGISTER COMMAND SEQUENCE
void WriteControlReg(uint8_t reg_addr, uint8_t reg_data){
	ENC26J60_SOFT_SPI_CS_LOW;
	spiPutGetByte(0b01000000 | reg_addr);
	spiPutGetByte(reg_data);
	ENC26J60_SOFT_SPI_CS_HIGH;
}
//WRITE CONTROL REGISTER COMMAND SEQUENCE (L and H)
void WriteControlReg16(uint8_t reg_addr, uint16_t reg_data)
{
    WriteControlReg(reg_addr, reg_data);
    WriteControlReg(reg_addr+1, reg_data>>8);
}
//Select Bank
void SetBank(uint8_t bank_n){
	if (bank_n >= 0 && bank_n <= 3){
		uint8_t reg = ReadControlEthReg(ECON1);
		WriteControlReg(ECON1, (reg & 0b11111100) | bank_n);
	}
}

#define ENC28J60_SPI_RBM    0x3A
#define ENC28J60_SPI_WBM    0x7A
//Read Buffer Memory
void ReadBufferMemory(uint8_t *buf, uint16_t len){
	ENC26J60_SOFT_SPI_CS_LOW;
	spiPutGetByte(ENC28J60_SPI_RBM);
    while(len--)
        *(buf++) = spiPutGetByte(0x00);
    ENC26J60_SOFT_SPI_CS_HIGH;}
//Write Buffer Memory
void WriteBufferMemory(uint8_t *buf, uint16_t len){
	ENC26J60_SOFT_SPI_CS_LOW;
	spiPutGetByte(ENC28J60_SPI_WBM);
    while(len--)
    	spiPutGetByte(*(buf++));
    ENC26J60_SOFT_SPI_CS_HIGH;
}

void BitFieldSet(uint8_t reg_addr, uint8_t mask){
	ENC26J60_SOFT_SPI_CS_LOW;
	spiPutGetByte(0x80 | reg_addr);
	spiPutGetByte(mask);
    ENC26J60_SOFT_SPI_CS_HIGH;
}
void BitFieldClear(uint8_t reg_addr, uint8_t mask){
	ENC26J60_SOFT_SPI_CS_LOW;
	spiPutGetByte(0xA0 | reg_addr);
	spiPutGetByte(mask);
    ENC26J60_SOFT_SPI_CS_HIGH;
}

//READING PHY REGISTERS
uint16_t ReadPhyReg(uint8_t phy_reg_addr){
	uint16_t data_out;
	SetBank(2);
	WriteControlReg(BANK2_MIREGADR, phy_reg_addr);
	WriteControlReg(BANK2_MICMD, (1<<MICMD_MIIRD));
	SetBank(3);
	do{
		_delay_us(20);
	} while(ReadControlMacMiiReg(BANK3_MISTAT) & (1<<BUSY));
	SetBank(2);
	WriteControlReg(BANK2_MICMD, (0<<MICMD_MIIRD));
	data_out = ReadControlMacMiiReg(BANK2_MIRDL) | (ReadControlMacMiiReg(BANK2_MIRDH)<<8);
	return data_out;
}

//WRITING PHY REGISTERS
void WritePhyReg(uint8_t phy_reg_addr, uint16_t data_in){
	SetBank(2);
	WriteControlReg(BANK2_MIREGADR, phy_reg_addr);
	WriteControlReg(BANK2_MIWRL, (data_in));
	WriteControlReg(BANK2_MIWRH, (data_in>>8));
	SetBank(3);
	do{
		_delay_us(20);
	} while(ReadControlMacMiiReg(BANK3_MISTAT) & (1<<BUSY));
}

const char *byte_to_binary(int x) {
	static char b[9];
	b[0] = '\0';

	int z;
	for (z = 128; z > 0; z >>= 1) {
		strcat(b, ((x & z) == z) ? "1" : "0");
	}

	return b;
}

const char *byte16_to_binary(uint16_t x) {
	static char b[17];
	b[0] = '\0';

	uint16_t z;
	for (z = 32768; z > 0; z >>= 1) {
		strcat(b, ((x & z) == z) ? "1" : "0");
	}

	return b;
}
