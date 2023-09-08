/*
 * LCD_Program.c
 *
 *  Created on: Aug 16, 2023
 *      Author: Ahmed Mohamed
 */


#include <avr/io.h>
#include <util/delay.h>
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "LCD_Interface.h"


void HLCD_voidInit()
{
	/*DATA PORTD as Output*/
	MDIO_voidSetPortDirection('A', 255); // PORTA Output

	/*Control pins output */
	MDIO_voidSetPinDirection('C', 0, 1); // PA0 Output
	MDIO_voidSetPinDirection('C', 1, 1); // PA1 Output
	MDIO_voidSetPinDirection('C', 2, 1); // PA2 Output

	/*Power ON delay 30ms*/
	_delay_ms(31);
	/*Function Set Command Send*/
	HLCD_voidSendCommand(0x38);
	/*Function Set Delay*/
	_delay_ms(1);
	/*Display On/Off Command Send*/
	HLCD_voidSendCommand(0x0C); // use 0x0F for blinking cursor
	/*Display On/Off Delay*/
	_delay_ms(1);
	/*Dispaly Clear Command Send*/
	HLCD_voidSendCommand(0x01);
	/*Display Clear Delay*/
	_delay_ms(1);
	/*Entery Set*/
	HLCD_voidSendCommand(0x06);
}

void HLCD_voidSendCommand(u8 A_u8Cmd)
{
	/*Initialize control pins RS/RW*/
	MDIO_voidSetPinValue('C', 0, 0); // Sending Command
	MDIO_voidSetPinValue('C', 1, 0); // RW = 0 (Writing on LCD)

	/*Write command on data pins*/
	MDIO_voidSetPortValue('A', A_u8Cmd);

	/*Pulse the Enable*/
	MDIO_voidSetPinValue('C', 2, 1); // EN High
	_delay_ms(1);
	MDIO_voidSetPinValue('C', 2, 0); // EN Low
	_delay_ms(1);

}

void HLCD_voidSendData(u8 A_u8Data)
{
	/*Initialize control pins RS/RW*/
	MDIO_voidSetPinValue('C', 0, 1); // Sending Data (RS High)
	MDIO_voidSetPinValue('C', 1, 0); // RW = 0 (Writing on LCD)

	/*Write command on data pins*/
	MDIO_voidSetPortValue('A', A_u8Data);

	/*Pulse the Enable*/
	MDIO_voidSetPinValue('C', 2, 1); // EN High
	_delay_ms(1);
	MDIO_voidSetPinValue('C', 2, 0); // EN Low
	_delay_ms(1);
}

void HLCD_voidSendString(s8 *A_u8String)
{
	u8 i = 0;
	while(A_u8String[i] != '\0')
	{
		HLCD_voidSendData(A_u8String[i]);
		i++;
	}
}

void HLCD_voidGoTo(u8 A_u8Row, u8 A_u8Col)
{
	u8 L_u8DdramAddress;
	if(A_u8Row < 2 && A_u8Col < 16) // Check for wrong arguments
	{
		if(A_u8Row == 0) // check if it is the first row
			L_u8DdramAddress = 0x00 + A_u8Col; // first address + required column
		else
			L_u8DdramAddress = 0x40 + A_u8Col; // second line address + required column

		SET_BIT(L_u8DdramAddress, 7); // Datasheet required Set Bit for the command to  work
		HLCD_voidSendCommand(L_u8DdramAddress); // Send finalized address to LCD
	}
}

void HLCD_voidDisplayNumber(s32 A_s32Number)
{
	u32 local_u32Number=1;
	if (A_s32Number==0)
	{
		HLCD_voidSendData('0');
	}
	if (A_s32Number<0)
	{
		HLCD_voidSendData('-');
		A_s32Number *=-1;
	}
	while (A_s32Number!=0)
	{
		local_u32Number = ((local_u32Number * 10)+(A_s32Number % 10));
		A_s32Number = A_s32Number /10;
	}
	while (local_u32Number!=1)
	{
		HLCD_voidSendData((local_u32Number%10)+48);
		local_u32Number=local_u32Number/10;
	}
}

/*This function for clearing the LCD
 * and pointing to the first line
 * */
void HLCD_voidLCDReset(void)
{
	/*Clear LCD*/
	HLCD_voidSendCommand(1);

	/*Go to First Line*/
	HLCD_voidGoTo(0, 0);
}

