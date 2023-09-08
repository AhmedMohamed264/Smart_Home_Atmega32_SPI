/*
 * TIMER_Program.c
 *
 *  Created on: Aug 23, 2023
 *      Author: Ahmed
 */

#include "avr/io.h"
#include "avr/interrupt.h"
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "Timer_Interface.h"

/*
 * Timer Options:
 * A_u8TimerMode  ---> 0 ---> Normal Mode
 * A_u8TimerMode  ---> 1 ---> Compare Match Mode
 * A_u8TimerMode  ---> 2 ---> Fast PWM
 * A_u8TimerMode  ---> 3 ---> Phase Correct Mode
 * */

void MTIMER_voidInit(u8 A_u8TimerMode)
{
	/*Timer Mode Selection*/
	switch(A_u8TimerMode)
	{

	case 0:
		/*Normal Mode Selection*/
		CLR_BIT(TCCR0, 3);
		CLR_BIT(TCCR0, 6);

		/*Timer Overflow Interrupt Enable*/
		SET_BIT(TIMSK, 0);
		break;

	case 1:
		/*CTC Mode Selection*/
		SET_BIT(TCCR0, 3);
		CLR_BIT(TCCR0, 6);

		/*CTC Interrupt Enable*/
		SET_BIT(TIMSK, 1);
		break;

	case 2:
		/*Fast PWM Selection*/
		SET_BIT(TCCR0, 3);
		SET_BIT(TCCR0, 6);

		/*Clear then Set*/
		CLR_BIT(TCCR0, 4);
		SET_BIT(TCCR0, 5);
		break;

	case 3:
		/*Phase Correct Selection*/
		CLR_BIT(TCCR0, 3);
		SET_BIT(TCCR0, 6);

		/*Clear then Set*/
		CLR_BIT(TCCR0, 4);
		SET_BIT(TCCR0, 5);
		break;
	}
}

void MTIMER_voidSetPreload(u8 A_u8Timer_Mode, u8 A_u8Preload)
{
	if(A_u8Timer_Mode == 0)
		TCNT0 = A_u8Preload;
	else
		OCR0 = A_u8Preload;
}

void MTIMER_voidStart()
{
	/*Start Timer with CLk/8 prescaling*/
	CLR_BIT(TCCR0, 0);
	SET_BIT(TCCR0, 1);
	CLR_BIT(TCCR0, 2);
}

void MTIMER_voidStop()
{
	/*Start Stop, No clock source*/
	CLR_BIT(TCCR0, 0);
	CLR_BIT(TCCR0, 1);
	CLR_BIT(TCCR0, 2);
}


void MTimer1_voidInit(){

	/*Select Clear on TOP and Set On Compare*/
	CLR_BIT(TCCR1A, 6);
	SET_BIT(TCCR1A, 7);

	/*Fast PWM mode 14*/
	CLR_BIT(TCCR1A, 0);
	SET_BIT(TCCR1A, 1);
	SET_BIT(TCCR1B, 3);
	SET_BIT(TCCR1B, 4);

	/*Select Ps 8* */
	CLR_BIT(TCCR1B,0);
	SET_BIT(TCCR1B,1);
	CLR_BIT(TCCR1B,2);
}


void MTimer1_voidSetValue(u16 A_u16Value){
	TCNT1 = A_u16Value;
}

u16 MTimer1_u16ReadTimer1Value(){
	return TCNT1;
}


void MTimer1_voidSetICR1(u16 A_u16Value)
{
	ICR1 = A_u16Value;
}

void MTimer1_voidSetCTCValue(u16 A_u16Value)
{
	OCR1A = A_u16Value;
}


