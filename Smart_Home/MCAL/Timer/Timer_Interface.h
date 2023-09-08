/*
 * TIMER_Interface.h
 *
 *  Created on: Aug 23, 2023
 *      Author: Ahmed
 */

#ifndef MCAL_TIMER_TIMER_INTERFACE_H_
#define MCAL_TIMER_TIMER_INTERFACE_H_

void MTIMER_voidInit(u8 A_u8TimerMode);

void MTIMER_voidSetPreload(u8 A_u8Timer_Mode, u8 A_u8Preload);

void MTIMER_voidStart();

void MTIMER_voidStop();

void MTIMER1_voidInit();

void MTIMER1_voidSetValue(u8 A_u8Value);

u16 MTIMER1_u16Read();

#endif /* MCAL_TIMER_TIMER_INTERFACE_H_ */
