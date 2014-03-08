/*
 * mpu9150_l.c
 *
 *  Created on: 2014/3/8
 *      Author: koyunbaba
 */

#include "mpu9150_l.h"
#include "mpu9150_def.h"


int MPU9150_WriteReg(XIicPs *i2c_drv, u8 addr, u8 *data, int len)
{
	int status;
	int i;
	u8	packet[2];

	// TODO: burst write

	packet[0] = addr;

	for(i = 0; i < len; i++)
	{
		packet[1] = data[i];

		status = XIicPs_MasterSendPolled(i2c_drv, packet, 2, MPU9150_I2C_ADDR);
		while (XIicPs_BusIsBusy(i2c_drv));

		if(status != XST_SUCCESS)
			break;
	}

	return status;
}

int MPU9150_ReadReg(XIicPs *i2c_drv, u8 addr, u8 *data, int len)
{
	int status;

	status = XIicPs_MasterSendPolled(i2c_drv, &addr, 1, MPU9150_I2C_ADDR);
	while (XIicPs_BusIsBusy(i2c_drv));

	if(status != XST_SUCCESS)
		return status;

	status = XIicPs_MasterRecvPolled(i2c_drv, data, len, MPU9150_I2C_ADDR);

	if(status != XST_SUCCESS)
		return status;

	return XST_SUCCESS;
}



