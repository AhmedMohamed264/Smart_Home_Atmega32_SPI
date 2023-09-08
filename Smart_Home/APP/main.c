#include <stdio.h>
#include <stdlib.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../MCAL/DIO/DIO_Interface.h"
#include "../MCAL/GIE/GIE_Interface.h"
#include "../MCAL/EXTI/EXTI_Interface.h"
#include "../MCAL/Timer/Timer_Interface.h"
#include "../MCAL/SPI/SPI_Interface.h"
#include "../HAL/LCD/LCD_Interface.h"
#include "../HAL/KEYPAD/KPD_Interface.h"
#include "APP.h"
#include "../MCAL/I2C/I2C_Interface.h"

/*Master Code*/

int main()
{
	/*SS1 Pin Output*/
	MDIO_voidSetPinDirection('B', 4, 1);
	/*SS1 High*/
	MDIO_voidSetPinValue('B', 4, 1);

	/*SS2 Pin Output*/
	MDIO_voidSetPinDirection('B', 3, 1);
	/*SS2 High*/
	MDIO_voidSetPinValue('B', 3, 1);

	/*MOSI Pin Output*/
	MDIO_voidSetPinDirection('B', 5, 1);

	/*MISO Pin Input*/
	MDIO_voidSetPinDirection('B', 6, 0);

	/*SCLK Pin Output*/
	MDIO_voidSetPinDirection('B', 7, 1);

	/*Master SPI Init*/
	MSPI_voidMasterInit();

	/*LCD Initialization*/
	HLCD_voidInit();

	/*Keypad Initialization*/
	MDIO_voidSetPortDirection('D', 0xF0);
	MDIO_voidSetPortValue('D', 0xFF);

	/*Welcome Message only once*/
	APP_voidWelcome();

	/*Ask user to login to system
	 * then checks if account was locked*/
	if(APP_u8LoginToSystem() == ACCOUNT_LOCKED)
		return 0;

	/*Local variables*/
	u8 L_u8OptionReturned, L_u8LightOption;

	while(1)
	{
		/*Access Granted*/

		/*Show available options*/
		APP_voidShowOptions(mainMenu);

		/*Handling user option input*/
		L_u8OptionReturned = APP_u8HandleOptions(mainMenu);

		/*Check option returned*/
		switch(L_u8OptionReturned)
		{
		case doorMenu:
			/*Display Door options*/
			APP_voidShowOptions(doorMenu);

			/*Get Option from user*/
			L_u8OptionReturned = APP_u8GetKey();

			/*Only two options*/
			if(L_u8OptionReturned == '1' || L_u8OptionReturned == '2')
			{
				/*Send Data to Slave 1*/
				MDIO_voidSetPinValue('B', 4, 0);
				MSPI_voidTranscieve(L_u8OptionReturned);
				MDIO_voidSetPinValue('B', 4, 1);
			}
			break;

		case lightMenu:
			/*Display Light options*/
			APP_voidShowOptions(lightMenu);

			/*Get Option from user*/
			L_u8OptionReturned = APP_u8GetKey();

			if(L_u8OptionReturned == '1' || L_u8OptionReturned == '2')
			{
				/*LCD Clear and goto first Line*/
				HLCD_voidLCDReset();

				/*Choose Option Message*/
				HLCD_voidSendString((s8*)"Choose an Option:");

				/*Wait one second*/
				_delay_ms(1000);

				/*LCD Clear and goto first Line*/
				HLCD_voidLCDReset();

				/*Displaying Room Light Options on LCD*/
				HLCD_voidSendString((s8*)"1- Light On");

				/*goto second line*/
				HLCD_voidGoTo(1, 0);

				/*Displaying Temp and Light Options*/
				HLCD_voidSendString((s8*)"2- Light Off");
			}

			/*Read Light Option from user*/
			L_u8LightOption = APP_u8GetKey();

			/*Sending slave the option choosed*/
			APP_voidSendLightStatus(L_u8OptionReturned, L_u8LightOption);

			break;
		}
	}
}
