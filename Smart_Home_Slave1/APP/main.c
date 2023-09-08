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
#include "../MCAL/I2C/I2C_Interface.h"
#include "../HAL/Servo/Servo_Interface.h"
#include "APP.h"

/*Slave 1 Code*/


int main(void)
{
	/*SS Pin Output*/
	MDIO_voidSetPinDirection('B', 4, 0);

	/*MOSI Pin*/
	MDIO_voidSetPinDirection('B', 5, 0);

	/*MISO Pin*/
	MDIO_voidSetPinDirection('B', 6, 1);

	/*SCLK Pin Output*/
	MDIO_voidSetPinDirection('B', 7, 0);

	/*Slave SPI Init*/
	MSPI_voidSlaveInit();

	/*LCD init*/
	HLCD_voidInit();

	/*Servo Init*/
	HSERVO_voidInit();

	/*Initially Close Door*/
	APP_voidDoorClose();

	while(1)
	{
		/*Receive desired option from master*/
		u8 option = MSPI_voidTranscieve('x');

		if(option == DOOR_OPEN)
		{
			/*Opening Door*/
			APP_voidDoorOpen();
		}
		else if(option == DOOR_CLOSE)
		{
			/*Close Door*/
			APP_voidDoorClose();
		}
	}
}
