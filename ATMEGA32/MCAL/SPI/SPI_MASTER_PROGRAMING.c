/*************************************************************************************/
/**********************    Author: Mohamed diaa  *************************************/
/**********************    Layer:  MCAL         **************************************/
/**********************    SWC:    SPI          ***********************************/
/**********************   Version: 1.00        *************************************/
/***********************************************************************************/

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "SPI_MASTER_CONFIG.h"
#include "SPI_MASTER_INTERFACE.h"
#include "SPI_MASTER_PRIVET.h"


void SPI_Master_Init()
{
	//Set to master
	SET_BIT(SPCR,SPCR_MASTER);

	//clock 16
	CLR_BIT(SPSR,SPSR_SPI2X);
	SET_BIT(SPCR,SPCR_SPR0);
	CLR_BIT(SPCR,SPCR_SPR1);

	// SPI Enable
	SET_BIT(SPCR,SPCR_SPE);
}

void SPI_SLAVE_Init()
{
	//Set to salve
		CLR_BIT(SPCR,SPCR_MASTER);
		// SPI Enable
		SET_BIT(SPCR,SPCR_SPE);
}


u8 SPI_Transfaer_Data(u8 copy_data)
{
	SPDR=copy_data;
	while(GET_BIT(SPSR,SPSR_SPIF) == 0);

	return SPDR;

}
