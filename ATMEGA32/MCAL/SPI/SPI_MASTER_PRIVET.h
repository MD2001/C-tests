/*************************************************************************************/
/**********************    Author: Mohamed diaa  *************************************/
/**********************    Layer:  MCAL         **************************************/
/**********************    SWC:    SPI          ***********************************/
/**********************   Version: 1.00        *************************************/
/***********************************************************************************/

#ifndef SPI_MASTER_PRIVET_H
#define SPI_MASTER_PRIVET_H


#define SPDR				*((volatile u8 *)0x2F)             //spi data register

#define SPSR				*((volatile u8 *)0x2E)			// spi staute register
#define SPSR_SPIF				7
#define SPSR_SPI2X				0

#define SPCR				*((volatile u8 *)0x2D)
#define SPCR_SPE 				6								//spi enable
#define SPCR_MASTER 			4								//master bit
#define SPCR_SPR1				1
#define SPCR_SPR0				0










#endif

