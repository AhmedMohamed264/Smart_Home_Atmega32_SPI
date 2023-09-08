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
#include "../MCAL/ADC/ADC_Interface.h"
#include "APP.h"


u8 G_u8Temp, G_u8LDRReading, G_u8Room1Led, G_u8Room2Led;

/*This function is responisble for
 * Reading Temperature using ADC
 * */
void APP_voidReadTemperature(void)
{
	/*ADC Read LM35 (Channel 0)*/
	u8 L_u8Reading = MADC_u8GetChannelReading(0);

	/*Calculate Milli Voltage*/
	u16 L_u16MilliVolt = (u16)(((u32)L_u8Reading * 5000UL) / 256UL);

	/*Calculate Temperature*/
	G_u8Temp = L_u16MilliVolt / 10;
}

/*This function is responsible for
 * Turning On/off fan based on temperature*/
void APP_voidUpdateFanStatus(void)
{
	/*if temp >= threshold, Fan turns On*/
	if(G_u8Temp >= TEMPERATURE_THRESHOLD)
		MDIO_voidSetPinValue('A', 2, 1);
	else
		MDIO_voidSetPinValue('A', 2, 0);
}

/*This function reads LDR Value*/
void APP_voidReadLDR(void)
{
	/*LDR Read Value*/
	/*Get ADC 1 Channel Reading*/
	G_u8LDRReading = MADC_u8GetChannelReading(1);
}

/*This function maps the LDR value
 * to another value in decimal
 * that turns of number of leds based on LDR range
 * */
void APP_voidAdjustLEDSOn(void)
{
	/*Adjust LEDS Status*/
	if(G_u8LDRReading < 40)
	{
		MDIO_voidSetPortValue('C', 31); // All leds on
	}
	else if(G_u8LDRReading >= 40 && G_u8LDRReading < 80)
	{
		MDIO_voidSetPortValue('C', 15); // 4 leds on
	}
	else if(G_u8LDRReading >= 80 && G_u8LDRReading < 120)
	{
		MDIO_voidSetPortValue('C', 7); // 3 leds on
	}
	else if(G_u8LDRReading >= 120 && G_u8LDRReading < 160)
	{
		MDIO_voidSetPortValue('C', 3); // 2 leds on
	}
	else if(G_u8LDRReading >= 160 && G_u8LDRReading < 200)
	{
		MDIO_voidSetPortValue('C', 1); // 1 led on
	}
	else if(G_u8LDRReading >= 240)
	{
		MDIO_voidSetPortValue('C', 0); // all leds off
	}
}

/*This function is responsible for checking the
 * Code received from master that updates Rooms Light status*/
void APP_voidCheckMasterCode(u8 A_u8Code)
{
	/*Check Option received*/
	switch(A_u8Code)
	{
		case ROOM_1_LIGHT_ON:
			G_u8Room1Led = 1; // Room 1 LED On Option
			break;

		case ROOM_1_LIGHT_OFF:
			G_u8Room1Led = 0; // Room 1 LED Off Option
			break;

		case ROOM_2_LIGHT_ON:
			G_u8Room2Led = 1; // Room 2 LED On Option
			break;

		case ROOM_2_LIGHT_OFF:
			G_u8Room2Led = 0; // Room 2 LED Off Option
			break;
	}
}

/*This function Send high/low signal
 * to the Light if rooms based on code received
 * from master controller*/
void APP_voidUpdateRoomsLight(void)
{
	MDIO_voidSetPinValue('C', 5, G_u8Room1Led);
	MDIO_voidSetPinValue('C', 6, G_u8Room2Led);
}

