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

/*
 * Timer 1 Prototypes
 * **/
void MTimer1_voidInit();

void MTimer1_voidSetValue(u16 A_u16Value);

u16 MTimer1_u16ReadTimer1Value();

/*Set value of period time of timer 1*/
void MTimer1_voidSetICR1(u16 A_u16Value);

void MTimer1_voidSetCTCValue(u16 A_u16Value);

#endif /* MCAL_TIMER_TIMER_INTERFACE_H_ */
