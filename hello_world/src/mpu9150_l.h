/*
 * mpu9150_l.h
 *
 *  Created on: 2014/3/8
 *      Author: koyunbaba
 */

#ifndef MPU9150_L_H_
#define MPU9150_L_H_

#include "xiicps.h"

int MPU9150_WriteReg(XIicPs *i2c_drv, u8 addr, u8 *data, int len);
int MPU9150_ReadReg(XIicPs *i2c_drv, u8 addr, u8 *data, int len);


#endif /* MPU9150_L_H_ */
