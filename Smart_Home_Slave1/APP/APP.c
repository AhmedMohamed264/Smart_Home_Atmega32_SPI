/*
 * APP.c
 *
 *  Created on: Sep 7, 2023
 *      Author: Ahmed
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../MCAL/DIO/DIO_Interface.h"
#include "../MCAL/Timer/Timer_Interface.h"
#include "../HAL/LCD/LCD_Interface.h"
#include "../HAL/Servo/Servo_Interface.h"
#include "APP.h"


/*This function is responsible for Opening door
 * (setting servo motor angle to +90)
 * */
void APP_voidDoorOpen(void)
{
	/*Open Door*/
	HSERVO_voidSetAngle(90);

	/*Reset LCD*/
	HLCD_voidLCDReset();

	/*LCD Door Opened Message*/
	HLCD_voidSendString((s8*)"Door Opened!");
}

/*This function is responsible for Closing door
 * (setting servo motor angle to -90)
 * */
void APP_voidDoorClose(void)
{
	/*Close Door*/
	HSERVO_voidSetAngle(-90);

	/*Reset LCD*/
	HLCD_voidLCDReset();

	/*LCD Door Closed Message*/
	HLCD_voidSendString((s8*)"Door Closed!");
}

