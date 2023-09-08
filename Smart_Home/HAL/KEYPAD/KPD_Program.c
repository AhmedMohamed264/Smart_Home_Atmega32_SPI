#include"../../LIB/STD_TYPES.h"
#include"../../LIB/BIT_MATH.h"
#include"../../MCAL/DIO/DIO_Interface.h"


/*Global keypad buttons array*/
u8 G_u8KPDButtons[4][4] =
{
		{'7', '8', '9', '/'},
		{'4', '5', '6', '*'},
		{'1', '2', '3', '-'},
		{'#', '0', '=', '+'}
};


/*
 * scans the pressed key
 * return: the pressed key
 * return: 255 if no key pressed
 * */
u8 HKPD_u8GetPressedKey()
{
	u8 Local_u8PressedKey = 255, Col, Row;

	for(Col = 0; Col < 4; Col++)
	{
		/*Activate Current Column*/
		MDIO_voidSetPinValue('D', Col + 4 , 0);

		/*Checks row by row*/
		for(Row = 0; Row < 4; Row++)
		{
			/*Gets row value*/
			u8 L_u8PinValue = MDIO_u8GetPinValue('D', (Row));

			/*Check if Key is Pressed*/
			if(L_u8PinValue == 0)
			{
				/*Saves pressed key for returning it*/
				Local_u8PressedKey = G_u8KPDButtons[Row][Col];

				/*Waiting until key gets not pressed*/
				while(MDIO_u8GetPinValue('D', Row) == 0);

				/*return the pressed key*/
				return Local_u8PressedKey;
			}
		}
		/*Deactivate Current Column*/
		MDIO_voidSetPinValue('D', Col + 4, 1);
	}
	/*returns 255 for referring that no key is pressed*/
	return Local_u8PressedKey;
}
