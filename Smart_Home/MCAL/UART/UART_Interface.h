/*
 * UART_Interface.h
 *
 *  Created on: Aug 27, 2023
 *      Author: Ahmed
 */

#ifndef MCAL_UART_UART_INTERFACE_H_
#define MCAL_UART_UART_INTERFACE_H_

void MUART_voidInit();

void MUART_voidTransmit(u8 A_u8Data);

u8 MUART_u8Recieve();

#endif /* MCAL_UART_UART_INTERFACE_H_ */
