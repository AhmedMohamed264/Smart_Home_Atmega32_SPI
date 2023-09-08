#include <avr/io.h>
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "EXTI_Interface.h"


/*
 * State Argument Options
 * 0 -----> Low level
 * 1 -----> On change
 * 2 -----> Falling
 * 3 -----> Rising
 *
 * */
void MEXTI_voidSenseControl(u8 A_u8EXTINumber, u8 A_u8State)
{
	switch(A_u8EXTINumber)
	{
		case 0:
			switch(A_u8State)
			{
				case 0:
					CLR_BIT(MCUCR, 0);
					CLR_BIT(MCUCR, 1);
				break;

				case 1:
					SET_BIT(MCUCR, 0);
					CLR_BIT(MCUCR, 1);
				break;

				case 2:
					CLR_BIT(MCUCR, 0);
					SET_BIT(MCUCR, 1);
			    break;

				case 3:
					SET_BIT(MCUCR, 0);
					SET_BIT(MCUCR, 1);
				break;
			}
		break;

		case 1:
			switch(A_u8State)
			{
				case 0:
					CLR_BIT(MCUCR,2);
					CLR_BIT(MCUCR,3);
				break;

				case 1:
					SET_BIT(MCUCR, 2);
					CLR_BIT(MCUCR, 3);
				break;

				case 2:
					CLR_BIT(MCUCR, 2);
					SET_BIT(MCUCR, 3);
				break;

				case 3:
					SET_BIT(MCUCR, 2);
					SET_BIT(MCUCR, 3);
				break;
			}
		break;

		case 2:
			switch(A_u8State)
			{
				case 2: CLR_BIT(MCUCSR, 6); break;
				case 3: SET_BIT(MCUCSR, 6); break;
			}
		break;
	}
}

void MEXTI_voidEnable(u8 A_u8EXTINumber)
{
	switch(A_u8EXTINumber)
	{
		case 0: SET_BIT(GICR, 6); break;

		case 1: SET_BIT(GICR, 7); break;

		case 2: SET_BIT(GICR, 5); break;
	}
}

void MEXTI_voidDisable(u8 A_u8EXTINumber)
{
	switch(A_u8EXTINumber)
	{
		case 0: CLR_BIT(GICR, 6); break;

		case 1: CLR_BIT(GICR, 7); break;

		case 2: CLR_BIT(GICR, 5); break;
	}
}
