/*
 * UART_Program.c
 *
 *  Created on: Aug 27, 2023
 *      Author: Ahmed
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include "UART_Interface.h"

void MUART_voidInit()
{
	/*UART Configuration*/
	UCSRB = 0b00011000;
	UCSRC = 0b10000110;

	/*Select Baud Rate 9600*/
	UBRRL = 51;
}

void MUART_voidTransmit(u8 A_u8Data)
{
	/*Polling until transmit buffer is empty*/
	while(GET_BIT(UCSRA, 5) == 0);

	/*Put data In TXD to be transmitted*/
	UDR = A_u8Data;
}


u8 MUART_u8Recieve()
{
	/*Polling to wait until data is received*/
	while(GET_BIT(UCSRA, 7) == 0);

	/*Return the data received*/
	return UDR;
}
