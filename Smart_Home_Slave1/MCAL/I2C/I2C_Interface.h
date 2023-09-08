/*
 * I2C_Interface.h
 *
 *  Created on: Aug 29, 2023
 *      Author: mahmo
 */

#ifndef MCAL_I2C_I2C_INTERFACE_H_
#define MCAL_I2C_I2C_INTERFACE_H_


typedef enum{
	NoError,
	StartConditionErr,
	SlaveAdderssWithWriteErr,
	MasterWriteDataErr,
	SlaveAdderessRecievedErr,
	SlaveDataRecievedErr

}TWI_ErrStatus;

void MTWI_voidMasterInit();

void MTWI_voidSlaveInit(u8 A_u8SalveAddress);


TWI_ErrStatus MTWI_SendStartCondition();

TWI_ErrStatus MTWI_SendSlaveAdderssWithWrite(u8 A_u8SalveAddress);
TWI_ErrStatus MTWI_MasterWriteDataByte(u8 A_u8Data);


void MTWI_voidSendStopCondition();


#endif /* MCAL_I2C_I2C_INTERFACE_H_ */
