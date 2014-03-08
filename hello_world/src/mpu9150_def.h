/*
 * mpu9150_def.h
 *
 *  Created on: 2014/3/8
 *      Author: koyunbaba
 */

#ifndef MPU9150_DEF_H_
#define MPU9150_DEF_H_

#define MPU9150_I2C_ADDR	0x68

//-------------------------------------------------------------------
// Register Map for Magnetometer
//-------------------------------------------------------------------

// Offset
#define MPU9150_MAG_WIA		0x00	// (RO) Who I Am (Device ID)
#define MPU9150_MAG_INFO	0x01	// (RO)
#define MPU9150_MAG_ST1		0x02	// (RO) status 1

#define MPU9150_MAG_HXL		0x03	// (RO) x-axis data
#define MPU9150_MAG_HXH		0x04
#define MPU9150_MAG_HYL		0x05	// (RO) y-axis data
#define MPU9150_MAG_HYH		0x06
#define MPU9150_MAG_HZL		0x07	// (RO) z-axis data
#define MPU9150_MAG_HZH		0x08

#define MPU9150_MAG_ST2		0x09	// (RO) status 2
#define MPU9150_MAG_CTRL	0x0A	// (RW)
#define MPU9150_MAG_RSV		0x0B	// (RW) Do not access
#define MPU9150_MAG_ASTC	0x0C	// (RW) Self-test
#define MPU9150_MAG_TS1		0x0D	// (RW) Do not access
#define MPU9150_MAG_TS2		0x0E	// (RW) Do not access
#define MPU9150_MAG_I2CDIS	0x0F	// (RW)
#define MPU9150_MAG_ASAX	0x10	// (RO) x-axis sensitivity adjustment value (Valid ONLY in FUSE ACCESS mode)
#define MPU9150_MAG_ASAY	0x11	// (RO) y-axis sensitivity adjustment value (Valid ONLY in FUSE ACCESS mode)
#define MPU9150_MAG_ASAZ	0x12	// (RO) z-axis sensitivity adjustment value (Valid ONLY in FUSE ACCESS mode)

// Bit
#define MPU9150_MAG_ST1_DRDY_BIT	0	// Data ready

#define MPU9150_MAG_ST2_DERR_BIT	2	// Data error
#define MPU9150_MAG_ST2_HOFL_BIT	3	// Sensor overflow

#define MPU9150_MAG_ASTC_SELF_BIT	6	// Self test control

// Mask
#define MPU9150_MAG_ST1_DRDY_MASK	(0x01 << MPU9150_MAG_ST1_DRDY_BIT)

#define MPU9150_MAG_ST2_DERR_MASK	(0x01 << MPU9150_MAG_ST2_DERR_BIT)
#define MPU9150_MAG_ST2_HOFL_MASK	(0x01 << MPU9150_MAG_ST2_HOFL_BIT)

#define MPU9150_MAG_CTRL_MODE_MASK	0x0F

#define MPU9150_MAG_ASTC_SELF_MASK	(1 << MPU9150_MAG_ASTC_SELF_MASK)

// Misc
#define MPU9150_MAG_I2CDIS_KEY		0x1D	// Write this key to I2CDIS register to disable I2C interface (reset only by VDD off)

//-------------------------------------------------------------------



#endif /* MPU9150_DEF_H_ */
