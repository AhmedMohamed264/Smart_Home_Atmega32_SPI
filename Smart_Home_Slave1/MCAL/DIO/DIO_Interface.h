/*
 * DIO_Interface.h
 *
 *  Created on: Aug 15, 2023
 *      Author: Ahmed
 */

#ifndef MCAL_DIO_DIO_INTERFACE_H_
#define MCAL_DIO_DIO_INTERFACE_H_

void MDIO_voidSetPinDirection(u8 A_u8PortNumber, u8 A_u8PinNumber, u8 A_u8Dir);

void MDIO_voidSetPinValue(u8 A_u8PortNumber, u8 A_u8PinNumber, u8 A_u8PinValue);

void MDIO_voidSetPortDirection(u8 A_u8PortNumber, u8 A_u8Dir);

void MDIO_voidSetPortValue(u8 A_u8PortNumber, u8 A_u8PortValue);

u8 MDIO_u8GetPinValue(u8 A_u8PortNumber, u8 A_u8PinNumber);

#endif /* MCAL_DIO_DIO_INTERFACE_H_ */
