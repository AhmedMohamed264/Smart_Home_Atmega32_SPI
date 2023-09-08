/*
 * APP.h
 *
 *  Created on: Sep 4, 2023
 *      Author: Ahmed
 */

#ifndef APP_APP_H_
#define APP_APP_H_


#define PASSWORD_LEN		4
#define WRONG_PASSWORD		0
#define CORRECT_PASSWORD 	1
#define MAX_FAILS			3

#define ACCOUNT_LOCKED		0
#define ACCESS_GRANTED		1

#define WRONG_OPTION		10

#define ROOM_1				'1'
#define ROOM_2				'2'
#define LIGHT_ON			'1'
#define LIGHT_OFF			'2'
#define ROOM_1_LIGHT_ON		'1'
#define ROOM_1_LIGHT_OFF	'2'
#define ROOM_2_LIGHT_ON		'3'
#define ROOM_2_LIGHT_OFF	'4'

typedef enum
{
	mainMenu = 0,
	doorMenu,
	lightMenu,
}APP_Options;

typedef enum
{
	doorOpen = 5,
	doorClose,
	backOption
}APP_DoorOptions;


void APP_voidWelcome(void);

u8 APP_u8GetKey(void);

void APP_voidGetPassword(u8 *A_u8Password);

u8 APP_u8CheckPassword(u8 *string1, u8 *string2);

u8 APP_u8LoginToSystem(void);

void APP_voidShowOptions(APP_Options optionToShow);

u8 APP_u8HandleOptions(APP_Options optionToShow);

void APP_voidShowData(APP_Options dataToShow);

u8 APP_u8HandleOptions(APP_Options optionToShow);

void APP_voidSendLightStatus(u8 A_u8Room, u8 A_u8LightOption);

#endif /* APP_APP_H_ */


