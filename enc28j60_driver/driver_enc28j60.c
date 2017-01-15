/*
 * driver.c

 *
 *  Created on: Apr 20, 2016
 *      Author: grigori.gutu
 */

#include "driver_enc28j60.h"

#define ENC28J60_BUFSIZE    	0x2000
#define ENC28J60_RXSIZE         0x1A00
#define ENC28J60_MAXFRAME    	1500

#define ENC28J60_RXSTART    	0
#define ENC28J60_RXEND          (ENC28J60_RXSIZE-1)
#define ENC28J60_TXSTART    	ENC28J60_RXSIZE
#define ENC28J60_BUFEND        	(ENC28J60_BUFSIZE-1)

void enc28j60Init(uint8_t *macadr){
	//Initialize Receive Buffers
	SetBank(0);
	WriteControlReg(BANK0_ERXSTL, 0x00);
	WriteControlReg(BANK0_ERXSTH, 0x00);
	WriteControlReg(BANK0_ERXNDH, 0xFF);
	WriteControlReg(BANK0_ERXNDL, 0x00);

	WriteControlReg(BANK0_ERXRDPTL, 0x00);
	WriteControlReg(BANK0_ERXRDPTH, 0x00);

	SetBank(2);
    // MAC Initialization Settings
	//WriteControlReg(MACON2, 0); // очищаем сброс
	WriteControlReg(BANK2_MACON1, MACON1_TXPAUS|MACON1_RXPAUS| // to allow IEEE defined flow control to function.
        MACON1_MARXEN); // enable the MAC to receive frames
	WriteControlReg(BANK2_MACON3, MACON3_PADCFG0| // enable automatic padding to at least	60 bytes
        MACON3_TXCRCEN| //and always append a valid CRC
        MACON3_FRMLNEN| //enable frame length status reporting
        MACON3_FULDPX);//enable full-duplex
	WriteControlReg(BANK2_MACON4, MACON4_DEFER); //
	WriteControlReg16(BANK2_MAMXFLL, ENC28J60_MAXFRAME); // maximum frame length to be permitted to be received	or transmitted
    WriteControlReg(BANK2_MABBIPG, 0x15); // Configure the Back-to-Back Inter-Packet Gap register
    WriteControlReg(BANK2_MAIPGL, 0x12); //Configure the Non-Back-to-Back Inter-Packet Gap register low byte
    WriteControlReg(BANK2_MAIPGH, 0x0C);
    SetBank(3);
    WriteControlReg(BANK3_MAADR6, macadr[0]); // local MAC address
    WriteControlReg(BANK3_MAADR5, macadr[1]);
    WriteControlReg(BANK3_MAADR4, macadr[2]);
    WriteControlReg(BANK3_MAADR3, macadr[3]);
    WriteControlReg(BANK3_MAADR2, macadr[4]);
    WriteControlReg(BANK3_MAADR1, macadr[5]);

    // Setting PHY
    WritePhyReg(PHCON1, PHCON1_PDPXMD); // enable FULL Duplex
    WritePhyReg(PHCON2, PHCON2_HDLDIS); // disable loopback
    WritePhyReg(PHLCON, PHLCON_LACFG2| // LED Settings
        PHLCON_LBCFG2|PHLCON_LBCFG1|PHLCON_LBCFG0|
        PHLCON_LFRQ0|PHLCON_STRCH);

    // enable receive packets
    BitFieldSet(ECON1, ECON1_RXEN);
}

void GetMac(uint8_t *macadr){
    SetBank(3);
    macadr[5] = ReadControlMacMiiReg(BANK3_MAADR6); // local MAC address
    macadr[4] = ReadControlMacMiiReg(BANK3_MAADR5);
    macadr[3] = ReadControlMacMiiReg(BANK3_MAADR4);
    macadr[2] = ReadControlMacMiiReg(BANK3_MAADR3);
    macadr[1] = ReadControlMacMiiReg(BANK3_MAADR2);
    macadr[0] = ReadControlMacMiiReg(BANK3_MAADR1);
}
