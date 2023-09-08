/*
 * EXTI_Interface.h
 *
 *  Created on: Aug 21, 2023
 *      Author: Ahmed
 */

#ifndef MCAL_EXTI_EXTI_INTERFACE_H_
#define MCAL_EXTI_EXTI_INTERFACE_H_


void MEXTI_voidSenseControl(u8 A_u8EXTINumber, u8 A_u8State);
void MEXTI_voidEnable(u8 A_u8EXTINumber);
void MEXTI_voidDisable(u8 A_u8EXTINumber);


#endif /* MCAL_EXTI_EXTI_INTERFACE_H_ */
