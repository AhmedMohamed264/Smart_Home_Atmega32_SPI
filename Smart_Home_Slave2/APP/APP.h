/*
 * APP.h
 *
 *  Created on: Sep 7, 2023
 *      Author: Ahmed
 */

#ifndef APP_APP_H_
#define APP_APP_H_


#define TEMPERATURE_THRESHOLD	30

#define ROOM_1_LIGHT_ON			'1'
#define ROOM_1_LIGHT_OFF		'2'
#define ROOM_2_LIGHT_ON			'3'
#define ROOM_2_LIGHT_OFF		'4'


void APP_voidReadTemperature(void);

void APP_voidUpdateFanStatus(void);

void APP_voidReadLDR(void);

void APP_voidAdjustLEDSOn(void);

void APP_voidCheckMasterCode(u8 A_u8Code);

void APP_voidUpdateRoomsLight(void);


#endif /* APP_APP_H_ */
