/*
 * LCD_Interface.h
 *
 *  Created on: Aug 16, 2023
 *      Author: Ahmed Mohamed
 */

#ifndef HAL_LCD_LCD_INTERFACE_H_
#define HAL_LCD_LCD_INTERFACE_H_

void HLCD_voidInit();
void HLCD_voidSendCommand(u8 A_u8Cmd);
void HLCD_voidSendData(u8 A_u8Data);
void HLCD_voidSendString(s8 *A_u8String);
void HLCD_voidGoTo(u8 A_u8Row, u8 A_u8Col);
void HLCD_voidDisplayNumber(s32 A_s32Number);
void HLCD_voidLCDReset(void);

#endif /* HAL_LCD_LCD_INTERFACE_H_ */
