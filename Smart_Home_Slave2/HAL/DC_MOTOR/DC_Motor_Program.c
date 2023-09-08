#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "DC_Motor_Interface.h"


#define DC_MOTOR_PORT     'C'
#define DC_MOTOR_PIN1	  0
#define DC_MOTOR_PIN2	  1


void HDCMOTOTR_voidInit(void)
{
	MDIO_voidSetPinDirection(DC_MOTOR_PORT, DC_MOTOR_PIN1, 1);
	MDIO_voidSetPinDirection(DC_MOTOR_PORT, DC_MOTOR_PIN2, 1);
	MDIO_voidSetPinValue(DC_MOTOR_PORT, DC_MOTOR_PIN1, 0);
	MDIO_voidSetPinValue(DC_MOTOR_PORT, DC_MOTOR_PIN2, 0);
}

void HDCMOTOR_voidRotateClockWise(void)
{
	MDIO_voidSetPinValue(DC_MOTOR_PORT, DC_MOTOR_PIN2, 0);
	MDIO_voidSetPinValue(DC_MOTOR_PORT, DC_MOTOR_PIN1, 1);
}

void HDCMOTOR_voidRotateCounterClockWise(void)
{
	MDIO_voidSetPinValue(DC_MOTOR_PORT, DC_MOTOR_PIN1, 0);
	MDIO_voidSetPinValue(DC_MOTOR_PORT, DC_MOTOR_PIN2, 1);
}

void HDCMOTOR_voidStop(void)
{
	MDIO_voidSetPinValue(DC_MOTOR_PORT, DC_MOTOR_PIN1, 0);
	MDIO_voidSetPinValue(DC_MOTOR_PORT, DC_MOTOR_PIN2, 0);
}
