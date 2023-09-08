/*
 * Servo_Interface.h
 *
 *  Created on: Sep 2, 2023
 *      Author: Ahmed
 */

#ifndef HAL_SERVO_SERVO_INTERFACE_H_
#define HAL_SERVO_SERVO_INTERFACE_H_


void HSERVO_voidInit();

/*Accepts Angle Argument from -90 to +90*/
void HSERVO_voidSetAngle(s8 A_u8Angle);


#endif /* HAL_SERVO_SERVO_INTERFACE_H_ */
