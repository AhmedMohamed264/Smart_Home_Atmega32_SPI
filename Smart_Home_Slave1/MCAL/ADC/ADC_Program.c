/*
 * ADC_Program.c
 *
 *  Created on: Aug 22, 2023
 *      Author: Ahmed
 */

#include "avr/io.h"
#include "avr/interrupt.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"


/**
 * AREF  	--- 0
 * AVCC  	--- 1
 * Internal --- 2
 */

void MADC_voidInit(u8 A_u8Aref)
{
	/*AREF Selection*/
	switch(A_u8Aref)
	{
	case 0:
		CLR_BIT(ADMUX, 6);
		CLR_BIT(ADMUX, 7);
		break;
	case 1:
		SET_BIT(ADMUX, 6);
		CLR_BIT(ADMUX, 7);
		break;
	case 2:
		SET_BIT(ADMUX, 6);
		SET_BIT(ADMUX, 7);
		break;
	}

	/*Left Adjust*/
	SET_BIT(ADMUX, 5);

	/*128 prescaler*/
	SET_BIT(ADCSRA, 0);
	SET_BIT(ADCSRA, 1);
	SET_BIT(ADCSRA, 2);

	/*Enable ADC*/
	SET_BIT(ADCSRA, 7);
}

u8 MADC_u8GetChannelReading(u8 A_u8Channel)
{
	/*Channel Selection*/
	ADMUX &= 0b11100000;
	ADMUX |= A_u8Channel;

	/*Start Conversion*/
	SET_BIT(ADCSRA, 6);

	/*Waiting conversion*/
	while(GET_BIT(ADCSRA, 4) == 0);

	/*Clear ADC Flag*/
	SET_BIT(ADCSRA, 4);

	/*Return result*/
	return ADCH;
}


