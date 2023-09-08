/*
 * SPI_Interface.h
 *
 *  Created on: Aug 28, 2023
 *      Author: Ahmed
 */

#ifndef MCAL_SPI_SPI_INTERFACE_H_
#define MCAL_SPI_SPI_INTERFACE_H_

void MSPI_voidMasterInit();

void MSPI_voidSlaveInit();

u8 MSPI_voidTranscieve(u8 A_u8Data);

#endif /* MCAL_SPI_SPI_INTERFACE_H_ */
