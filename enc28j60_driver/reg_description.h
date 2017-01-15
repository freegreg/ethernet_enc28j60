/*
 * reg.h
 *
 *  Created on: Apr 19, 2016
 *      Author: grigori.gutu
 */

#ifndef ENC28J60_DRIVER_REG_DESCRIPTION_H_
#define ENC28J60_DRIVER_REG_DESCRIPTION_H_

#define BANK0	0
#define BANK1	1
#define BANK2	2
#define BANK3	3
//Bank 0
//Beffer pointers
#define BANK0_ERDPTL       0x00   //Read Pointer Low Byte
#define BANK0_ERDPTH       0x01   //Read Pointer High Byte
#define BANK0_EWRPTL       0x02   //Write Pointer Low Byte
#define BANK0_EWRPTH       0x03   //Write Pointer High Byte
#define BANK0_ETXSTL       0x04   //TX Start Low Byte
#define BANK0_ETXSTH       0x05   //TX Start High Byte
#define BANK0_ETXNDL       0x06   //TX End Low Byte
#define BANK0_ETXNDH       0x07   //TX End High Byte
#define BANK0_ERXSTL       0x08   //RX Start Low Byte
#define BANK0_ERXSTH       0x09   //RX Start High Byte
#define BANK0_ERXNDL       0x0A   //RX End Low Byte
#define BANK0_ERXNDH       0x0B   //RX End High Byte
#define BANK0_ERXRDPTL     0x0C   //RX RD Pointer Low Byte
#define BANK0_ERXRDPTH     0x0D   //RX RD Pointer High Byte
#define BANK0_ERXWRPTL     0x0E   //RX WR Pointer Low Byte
#define BANK0_ERXWRPTH     0x0F   //RX WR Pointer High Byte

//DMA
#define BANK0_EDMASTL      0x10   //DMA Start Low Byte
#define BANK0_EDMASTH      0x11   //DMA Start High Byte
#define BANK0_EDMANDL      0x12   //DMA End Low Byte
#define BANK0_EDMANDH      0x13   //DMA End High Byte
#define BANK0_EDMADSTL     0x14   //DMA Destination Low Byte
#define BANK0_EDMADSTH     0x15   //DMA Destination High Byte
#define BANK0_EDMACSL      0x16   //DMA Checksum Low Byte
#define BANK0_EDMACSH      0x17   //DMA Checksum High Byte

//INTERRUPTS
#define EIE          0x1B	//Ethernet Interrupt Enable
#define EIR          0x1C	//Ethernet Interrupt Request, Flag

//General
#define ESTAT        0x1D		//Ethernet Status
#define ECON2        0x1E		//ETHERNET CONTROL REGISTER 2
#define ECON1        0x1F		//ETHERNET CONTROL REGISTER 1
	#define ECON1_RXEN	(1<<2)
	#define ECON1_TXRTS	(1<<3)
//Bank 1

//Packet Filtering
#define BANK1_EHT0         0x00      //Hash Table Byte 0
#define BANK1_EHT1         0x01      //Hash Table Byte 1
#define BANK1_EHT2         0x02      //Hash Table Byte 2
#define BANK1_EHT3         0x03      //Hash Table Byte 3
#define BANK1_EHT4         0x04      //Hash Table Byte 4
#define BANK1_EHT5         0x05      //Hash Table Byte 5
#define BANK1_EHT6         0x06      //Hash Table Byte 6
#define BANK1_EHT7         0x07      //Hash Table Byte 7
#define BANK1_EPMM0        0x08      //Pattern Match Mask Byte 0
#define BANK1_EPMM1        0x09      //Pattern Match Mask Byte 1
#define BANK1_EPMM2        0x0A      //Pattern Match Mask Byte 2
#define BANK1_EPMM3        0x0B      //Pattern Match Mask Byte 3
#define BANK1_EPMM4        0x0C      //Pattern Match Mask Byte 4
#define BANK1_EPMM5        0x0D      //Pattern Match Mask Byte 5
#define BANK1_EPMM6        0x0E      //Pattern Match Mask Byte 6
#define BANK1_EPMM7        0x0F      //Pattern Match Mask Byte 7
#define BANK1_EPMCSL       0x10 	   //Pattern Match Checksum Low Byte
#define BANK1_EPMCSH       0x11	   //Pattern Match Checksum High Byte

#define BANK1_EPMOL        0x14	   //Pattern Match Offset Low Byte
#define BANK1_EPMOH        0x15	   //Pattern Match Offset High Byte

#define BANK1_ERXFCON	     0x18		//Ethernet Receive Filter Control

//General
#define BANK1_EPKTCNT      0x19		//Ethernet Packet Count

//Bank 2
//MAC Registers
#define BANK2_MACON1       0x00		//MAC CONTROL REGISTER 1
	#define MACON1_MARXEN 		(1<<0)		// enable the MAC to receive frames
	#define MACON1_TXPAUS		(1<<3)
	#define MACON1_RXPAUS		(1<<2) // FLow Control
#define BANK2_MACON3       0x02		//MAC CONTROL REGISTER 3
	#define    MACON3_PADCFG0   (1<<5) //
	#define    MACON3_TXCRCEN   (1<<4) //
	#define    MACON3_FRMLNEN   (1<<1) //
    #define    MACON3_FULDPX    (1<<0)

#define BANK2_MACON4       0x03		//MAC CONTROL REGISTER 4
	#define MACON4_DEFER	6		//Defer Transmission Enable bit (applies to half duplex only)
#define BANK2_MABBIPG      0x04		//Back-to-Back Inter-Packet Gap

#define BANK2_MAIPGL       0x06		//Non-Back-to-Back Inter-Packet Gap Low Byte
#define BANK2_MAIPGH       0x07		//Non-Back-to-Back Inter-Packet Gap High Byte
#define BANK2_MACLCON1     0x08		//Retransmission Maximum
#define BANK2_MACLCON2     0x09		//Collision Window (COLWIN<5:0>)
#define BANK2_MAMXFLL      0x0A		//Maximum Frame Length Low Byte (MAMXFL<7:0>)
#define BANK2_MAMXFLH      0x0B		//Maximum Frame Length High Byte (MAMXFL<15:8>)

#define BANK2_MICMD        0x12		//MII COMMAND REGISTER
	#define MICMD_MIISCAN	(1<<1)
	#define MICMD_MIIRD		(1<<0)

#define BANK2_MIREGADR     0x14		//MII Register Address (MIREGADR<4:0>)

//Other
#define BANK2_MIWRL        0x16		//MII Write Data Low Byte
#define BANK2_MIWRH        0x17		//MII Write Data High Byte
#define BANK2_MIRDL        0x18		//MII Read Data Low Byte
#define BANK2_MIRDH        0x19		//MII Read Data High Byte

//Bank 3
//General
#define BANK3_MAADR5       0x00		//MAC Address Byte 5
#define BANK3_MAADR6       0x01       //MAC Address Byte 6
#define BANK3_MAADR3       0x02       //MAC Address Byte 3
#define BANK3_MAADR4       0x03       //MAC Address Byte 4
#define BANK3_MAADR1       0x04       //MAC Address Byte 1
#define BANK3_MAADR2       0x05       //MAC Address Byte 2

//BUILT-IN SELF-TEST
#define BANK3_EBSTSD       0x06		//Built-in Self-Test Fill Seed
#define BANK3_EBSTCON      0x07		//ETHERNET SELF-TEST CONTROL REGISTER
#define BANK3_EBSTCSL      0x08		//Built-in Self-Test Checksum Low Byte
#define BANK3_EBSTCSH      0x09		//Built-in Self-Test Checksum High Byte

//Other
#define BANK3_MISTAT       0x0A		//MISTAT: MII STATUS REGISTER
	#define 	NVALID 	(1<<2)
	#define 	SCAN 	(1<<1)
	#define 	BUSY	(1<<0)
//Ethernet Revision ID
#define BANK3_EREVID       0x12		//Ethernet Revision ID

//Clock Output Control
#define BANK3_ECOCON       0x15		//CLOCK OUTPUT CONTROL REGISTER

//FLOW CONTROL
#define BANK3_EFLOCON      0x17		//ETHERNET FLOW CONTROL REGISTER
#define BANK3_EPAUSL       0x18		//Pause Timer Value Low Byte
#define BANK3_EPAUSH       0x19		//Pause Timer Value High Byte


//PHY Registers
#define PHCON1       0x00		//PHY CONTROL REGISTER 1
	#define	PHCON1_PDPXMD (1<<8)
#define PHSTAT1      0x01		//PHYSICAL LAYER STATUS REGISTER 1
#define PHID1        0x02		//constant data for identify
#define PHID2        0x03		//constant data for identify
#define PHCON2       0x10		//PHY CONTROL REGISTER 2
	#define PHCON2_HDLDIS (1<<8)
#define PHSTAT2      0x11		//PHYSICAL LAYER STATUS REGISTER 2
#define PHIE         0x12		//PHY INTERRUPT ENABLE REGISTER
#define PHIR         0x13		//PHY INTERRUPT REQUEST (FLAG) REGISTER
#define PHLCON       0x14		//PHY MODULE LED CONTROL REGISTER
	#define PHLCON_LACFG2 (1<<10)
	#define PHLCON_LBCFG2 (1<<6)
	#define PHLCON_LBCFG1 (1<<5)
	#define PHLCON_LBCFG0 (1<<4)
	#define PHLCON_LFRQ0  (1<<3)
	#define PHLCON_STRCH  (1<<1)

#endif /* ENC28J60_DRIVER_REG_DESCRIPTION_H_ */
