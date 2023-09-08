/*
 * APP.c
 *
 *  Created on: Sep 4, 2023
 *      Author: Ahmed
 */
#include <stdio.h>
#include <stdlib.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../MCAL/DIO/DIO_Interface.h"
#include "../MCAL/Timer/Timer_Interface.h"
#include "../MCAL/SPI/SPI_Interface.h"
#include "../HAL/LCD/LCD_Interface.h"
#include "../HAL/KEYPAD/KPD_Interface.h"
#include "APP.h"

u8 G_u8Password[5] = "1234";

/*This is a welcome message
 * Function that Displays on LCD
 * */
void APP_voidWelcome(void)
{
	/*LCD Clear and goto first Line*/
	HLCD_voidLCDReset();

	/*Welcome Message*/
	HLCD_voidSendString((s8*)"Welcome");

	/*Wait 1sec*/
	_delay_ms(1000);
}

/*This function get the pressed
 * key on keypad from the user
 * using Polling technique
 * */
u8 APP_u8GetKey(void)
{
	u8 L_u8Key;

	/*Polling until a key is pressed*/
	do{
		L_u8Key = HKPD_u8GetPressedKey();
	}while(L_u8Key == 255);

	/*Return Key pressed*/
	return L_u8Key;
}

/* User Enters the password
 * This function returns
 * CORRECT_PASSWORD  --> in case pass is correct
 * WRONG_PASSWORD --> in case pass is wrong
 * */
void APP_voidGetPassword(u8 *A_u8Password)
{
	/*local iteration counter*/
	u8 i = 0;

	/*LCD Clear and goto first Line*/
	HLCD_voidLCDReset();

	/*Asking user to enter his password*/
	HLCD_voidSendString((s8*)"Enter Password:");

	/*Goto Second line first column*/
	HLCD_voidGoTo(1, 0);

	/*Reading Password*/
	for(i = 0; i < PASSWORD_LEN; i++)
	{
		/*Storing the password in the pointer argument*/
		A_u8Password[i] = APP_u8GetKey();

		/*Displaying **** instead of password on LCD */
		HLCD_voidSendData('*');
	}
	/*Last element is null termination for the string*/
	A_u8Password[i] = '\0';
}

/*Arguments are two string
 * This function compares them
 * returns CORRECT_PASSWORD or WRONG_PASSWORD
 * */
u8 APP_u8CheckPassword(u8 *string1, u8 *string2)
{
	u8 i = 0;

	/*Looping on the string*/
	while(string1[i] && string2[i])
	{
		/*if in any iteration the strings wasn't equal*/
		if(string1[i] != string2[i])
			/*Returning Wrong Password Status*/
			return WRONG_PASSWORD;
		i++;
	}

	/*if code reached here, it means the password is correct*/
	return CORRECT_PASSWORD;
}

/* This function forces user
 * to login to system before using it
 * */
u8 APP_u8LoginToSystem(void)
{
	/*Local String for stroing password*/
	u8 L_u8Password[5], L_u8FailCounter = 0;

	while(1)
	{
		/*Get Password from user*/
		APP_voidGetPassword(L_u8Password);

		/*if user entered wrong password*/
		if(APP_u8CheckPassword(L_u8Password, G_u8Password) == WRONG_PASSWORD)
		{
			/*Increasing Failed Counter*/
			L_u8FailCounter++;

			/*LCD Clear and goto first Line*/
			HLCD_voidLCDReset();

			/*Displaying Failed Times on LCD*/
			HLCD_voidSendString((s8*)"Failed [");
			HLCD_voidDisplayNumber(L_u8FailCounter);
			HLCD_voidSendString((s8*)"/3]");

			/*Wait a second*/
			_delay_ms(1000);

			/*if max fail chances reached*/
			if(L_u8FailCounter >= MAX_FAILS)
			{
				/*Clear LCD and Goto First Line*/
				HLCD_voidLCDReset();

				/*Lock Account*/
				HLCD_voidSendString((s8*)"Account Locked!");

				/*Waiting one second*/
				_delay_ms(1000);

				/*Stop the Program*/
				return ACCOUNT_LOCKED;
			}
			else
			{
				/*Clear LCD and Goto First Line*/
				HLCD_voidLCDReset();

				/*Show try again message in case didn't reach max fails*/
				HLCD_voidSendString((s8*)"Try Again!");

				/*Waiting one second*/
				_delay_ms(1000);
			}
		}
		else
		{
			/*Allow user to view options*/
			return ACCESS_GRANTED;
		}
	}
}

/*Responsible for displaying different
 * Smart home control options on LCD
 * */
void APP_voidShowOptions(APP_Options optionToShow)
{
	/*LCD Clear and goto first Line*/
	HLCD_voidLCDReset();

	/*Choose Option Message*/
	HLCD_voidSendString((s8*)"Choose an Option:");

	/*Wait one second*/
	_delay_ms(1000);

	/*LCD Clear and goto first Line*/
	HLCD_voidLCDReset();

	switch(optionToShow)
	{
		case mainMenu:
			/*Displaying Door Option on LCD*/
			HLCD_voidSendString((s8*)"1- Door Control");

			/*goto second line*/
			HLCD_voidGoTo(1, 0);

			/*Displaying Temp and Light Options*/
			HLCD_voidSendString((s8*)"2- Light Control");
			break;

		case doorMenu:
			/*Displaying Door open Option on LCD*/
			HLCD_voidSendString((s8*)"1- Door Open");

			/*goto second line*/
			HLCD_voidGoTo(1, 0);

			/*Displaying Door close and back to main menu Options*/
			HLCD_voidSendString((s8*)"2- Close 3- Exit");
			break;
		case lightMenu:
			/*Displaying Room 1 Option on LCD*/
			HLCD_voidSendString((s8*)"1- Room 1");

			/*goto second line*/
			HLCD_voidGoTo(1, 0);

			/*Displaying Room 2 and back to main menu Options*/
			HLCD_voidSendString((s8*)"2- Room 2 3-Exit");
			break;
	}
}

/*This function is responsible for
 *Taking Option as an input from user */
u8 APP_u8HandleOptions(APP_Options optionToShow)
{
	/*Get Pressed Option*/
	u8 option = APP_u8GetKey();

	/*Switching the value of option to show*/
	switch(optionToShow)
	{
		/*Converting the pressed number to
		 * a readable name that we can deal with*/
		case mainMenu:
			switch(option)
			{
				case '1': return doorMenu;
				case '2': return lightMenu;
				default: return WRONG_OPTION;
			}
			break;
		case doorMenu:
			switch(option)
			{
				case '1': return doorOpen;
				case '2': return doorClose;
				case '3': return backOption;
				default: return WRONG_OPTION;
			}
			break;

		/*Just to avoid 'lightMenu' not handled in switch Warning*/
		case lightMenu:
			break;
	}
	return WRONG_OPTION;
}

/*This function is responsible for sending
 * Room 1/2 Light on/off status code
 * using SPI Peripheral
 * */
void APP_voidSendLightStatus(u8 A_u8Room, u8 A_u8LightOption)
{
	/*Local Variable to store the code to send*/
	u8 L_u8CodeToSend = 0;

	/*Checking which room does the user choosed*/
	switch(A_u8Room)
	{
		/*in case he choosed room 1*/
		case ROOM_1:
			/*Checking wether his choice was light on or off*/
			switch(A_u8LightOption)
			{
				case LIGHT_ON:
					L_u8CodeToSend = ROOM_1_LIGHT_ON; // Code for Room 1 & Light On
					break;
				case LIGHT_OFF:
					L_u8CodeToSend = ROOM_1_LIGHT_OFF; // Code for Room 1 & Light Off
					break;
			}
			break;

		/*in case he choosed room 2*/
		case ROOM_2:
			/*Checking wether his choice was light on or off*/
			switch(A_u8LightOption)
			{
				case LIGHT_ON:
					L_u8CodeToSend = ROOM_2_LIGHT_ON; // Code for Room 2 & Light On
					break;
				case LIGHT_OFF:
					L_u8CodeToSend = ROOM_2_LIGHT_OFF; // Code for Room 2 & Light Off
					break;
			}
			break;
	}

	/*if user choosed correct options*/
	if(L_u8CodeToSend != 0)
	{
		/*Send Data to Slave2*/
		/*Activate the SS pin to low*/
		MDIO_voidSetPinValue('B', 3, 0);

		/*Send appropriate code to the slave*/
		MSPI_voidTranscieve(L_u8CodeToSend);

		/*Deactivate the SS pin to high*/
		MDIO_voidSetPinValue('B', 3, 1);
	}
}
