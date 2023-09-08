/*
 * DIO_Program.c
 *
 *  Created on: Aug 15, 2023
 *      Author: Ahmed
 */


#include <avr/io.h>
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "DIO_Interface.h"


void MDIO_voidSetPinDirection(u8 A_u8PortNumber, u8 A_u8PinNumber, u8 A_u8Dir)
{
	if(A_u8PinNumber < 8 && A_u8Dir < 2)
	{
		switch(A_u8PortNumber)
		{
			case 'A':
				switch(A_u8Dir)
				{
					case 0: CLR_BIT(DDRA, A_u8PinNumber); break;
					case 1: SET_BIT(DDRA, A_u8PinNumber); break;
				}
				break;

			case 'B':
				switch(A_u8Dir)
				{
					case 0: CLR_BIT(DDRB, A_u8PinNumber); break;
					case 1: SET_BIT(DDRB, A_u8PinNumber); break;
				}
				break;

			case 'C':
				switch(A_u8Dir)
				{
					case 0: CLR_BIT(DDRC, A_u8PinNumber); break;
					case 1: SET_BIT(DDRC, A_u8PinNumber); break;
				}
				break;

			case 'D':
				switch(A_u8Dir)
				{
						case 0: CLR_BIT(DDRD, A_u8PinNumber); break;
						case 1: SET_BIT(DDRD, A_u8PinNumber); break;
				}
				break;
		}
	}
}

void MDIO_voidSetPinValue(u8 A_u8PortNumber, u8 A_u8PinNumber, u8 A_u8PinValue)
{
	if(A_u8PinNumber < 8  && A_u8PinValue < 2)
	{
		switch(A_u8PortNumber)
		{
			case 'A':
				switch(A_u8PinValue)
				{
					case 0: CLR_BIT(PORTA, A_u8PinNumber); break;
					case 1: SET_BIT(PORTA, A_u8PinNumber); break;
				}
				break;

			case'B':
				switch(A_u8PinValue)
				{
					case 0: CLR_BIT(PORTB, A_u8PinNumber); break;
					case 1: SET_BIT(PORTB, A_u8PinNumber); break;
				}
				break;

			case 'C':
				switch(A_u8PinValue)
				{
					case 0: CLR_BIT(PORTC, A_u8PinNumber); break;
					case 1: SET_BIT(PORTC, A_u8PinNumber); break;
				}
				break;

			case 'D':
				switch(A_u8PinValue)
				{
					case 0: CLR_BIT(PORTD, A_u8PinNumber); break;
					case 1: SET_BIT(PORTD, A_u8PinNumber); break;
				}
				break;
		}
	}

}


void MDIO_voidSetPortDirection(u8 A_u8PortNumber, u8 A_u8Dir)
{
	switch(A_u8PortNumber)
	{
		case 'A': DDRA = A_u8Dir; break;

		case 'B': DDRB = A_u8Dir; break;

		case 'C': DDRC = A_u8Dir; break;

		case 'D': DDRD = A_u8Dir; break;
	}
}

void MDIO_voidSetPortValue(u8 A_u8PortNumber, u8 A_u8PortValue)
{
	switch(A_u8PortNumber)
	{
		case 'A': PORTA = A_u8PortValue; break;

		case 'B': PORTB = A_u8PortValue; break;

		case 'C': PORTC = A_u8PortValue; break;

		case 'D': PORTD = A_u8PortValue; break;
	}
}

/* return 0 1 */
u8 MDIO_u8GetPinValue(u8 A_u8PortNumber, u8 A_u8PinNumber)
{
	u8 Local_u8Result;
	if(A_u8PinNumber < 8)
	{
		switch(A_u8PortNumber)
		{
			case 'A': Local_u8Result = GET_BIT(PINA, A_u8PinNumber); break;
			case 'B': Local_u8Result = GET_BIT(PINB, A_u8PinNumber); break;
			case 'C': Local_u8Result = GET_BIT(PINC, A_u8PinNumber); break;
			case 'D': Local_u8Result = GET_BIT(PIND, A_u8PinNumber); break;
		}
	}
	else
	{
		Local_u8Result = 255;
	}
	return Local_u8Result;
}
