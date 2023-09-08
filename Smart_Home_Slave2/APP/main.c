#include <stdio.h>
#include <stdlib.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../MCAL/DIO/DIO_Interface.h"
#include "../MCAL/ADC/ADC_Interface.h"
#include "../MCAL/Timer/Timer_Interface.h"
#include "../MCAL/SPI/SPI_Interface.h"
#include "../HAL/LCD/LCD_Interface.h"
#include "../HAL/KEYPAD/KPD_Interface.h"
#include "../MCAL/I2C/I2C_Interface.h"
#include "APP.h"

/*Slave 2 Code*/

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

	/*Enable SPI Interrupt*/
	SET_BIT(SPCR, 7);

	/*Enable Global Interrupt*/
	sei();

	/*ADC Init*/
	MDIO_voidSetPinDirection('A', 0, 0);
	MADC_voidInit(0);

	/*Fan DC Motor Pin Output*/
	MDIO_voidSetPinDirection('A', 2, 1);

	/*LDR Pin Input*/
	MDIO_voidSetPinDirection('A', 1, 0);

	/*LEDS Port Output (PORTC)*/
	MDIO_voidSetPortDirection('C', 255);

	while(1)
	{
		/*Read Current Temperature value in celsius*/
		APP_voidReadTemperature();

		/*Update Fan Status (on/off) based on temperature*/
		APP_voidUpdateFanStatus();

		/*Read current LDR Value*/
		APP_voidReadLDR();

		/*Adjust the number of LEDs on based on LDR Value*/
		APP_voidAdjustLEDSOn();

		/*Update Rooms Light based on code received from Master*/
		APP_voidUpdateRoomsLight();
	}
}

ISR(SPI_STC_vect)
{
	/*Check Option received*/
	APP_voidCheckMasterCode(SPDR);
}
