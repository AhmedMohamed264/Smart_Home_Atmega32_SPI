/*
 * SPI_Program.c
 *
 *  Created on: Aug 28, 2023
 *      Author: Ahmed
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"


void MSPI_voidMasterInit()
{
	/*Master Selection Mode*/
	SET_BIT(SPCR, 4);

	/*Clock Select Rate bit*/
	SET_BIT(SPCR, 0);
	CLR_BIT(SPCR, 1);
	CLR_BIT(SPCR, 0);

	/*SPI Enable*/
	SET_BIT(SPCR, 6);
}

void MSPI_voidSlaveInit()
{
	/*Slave Selection Mode*/
	CLR_BIT(SPCR, 4);

	/*SPI Enable*/
	SET_BIT(SPCR, 6);
}

u8 MSPI_voidTranscieve(u8 A_u8Data)
{
	/*Send data*/
	SPDR = A_u8Data;

	/*Polling waiting transfer complete*/
	while(GET_BIT(SPSR, 7) == 0);

	/*Return received data*/
	return SPDR;
}
