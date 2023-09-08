/*
 * Servo_Program.c
 *
 *  Created on: Sep 2, 2023
 *      Author: Ahmed
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../MCAL/Timer/Timer_Interface.h"
#include "Servo_Interface.h"


void HSERVO_voidInit()
{
	/*Set PD5 (OC1A) as Output*/
	MDIO_voidSetPinDirection('D', 5, 1);

	/*Init Timer 1 Fast PWM Mode 14*/
	MTimer1_voidInit();

	/*Set Period Time*/
	MTimer1_voidSetICR1(20000); // 20ms
}

/*Accepts Angle Argument from -90 to +90*/
void HSERVO_voidSetAngle(s8 A_u8Angle)
{
	/*Mapping the Values to get the required CTC for Time on*/
	u16 L_u8CTCValue = (u16)(1500.0 + ((50.0/9.0) * (f32)(A_u8Angle)));

	MTimer1_voidSetCTCValue(L_u8CTCValue);
}

