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
#define MPU9150_WIA		0x00	// (RO) Who I Am (Device ID)
#define MPU9150_INFO	0x01	// (RO)
#define MPU9150_ST1		0x02	// (RO) status 1

#define MPU9150_HXL		0x03	// (RO) x-axis data
#define MPU9150_HXH		0x04
#define MPU9150_HYL		0x05	// (RO) y-axis data
#define MPU9150_HYH		0x06
#define MPU9150_HZL		0x07	// (RO) z-axis data
#define MPU9150_HZH		0x08

#define MPU9150_ST2		0x09	// (RO) status 2
#define MPU9150_CTRL	0x0A	// (RW)
#define MPU9150_RSV		0x0B	// (RW) Do not access
#define MPU9150_ASTC	0x0C	// (RW) Self-test
#define MPU9150_TS1		0x0D	// (RW) Do not access
#define MPU9150_TS2		0x0E	// (RW) Do not access
#define MPU9150_I2CDIS	0x0F	// (RW)
#define MPU9150_ASAX	0x10	// (RO) x-axis sensitivity adjustment value (Valid ONLY in FUSE ACCESS mode)
#define MPU9150_ASAY	0x11	// (RO) y-axis sensitivity adjustment value (Valid ONLY in FUSE ACCESS mode)
#define MPU9150_ASAZ	0x12	// (RO) z-axis sensitivity adjustment value (Valid ONLY in FUSE ACCESS mode)

// Bit
#define MPU9150_ST1_DRDY_BIT	0	// Data ready

#define MPU9150_ST2_DERR_BIT	2	// Data error
#define MPU9150_ST2_HOFL_BIT	3	// Sensor overflow

#define MPU9150_ASTC_SELF_BIT	6	// Self test control

// Mask
#define MPU9150_ST1_DRDY_MASK	(0x01 << MPU9150_ST1_DRDY_BIT)

#define MPU9150_ST2_DERR_MASK	(0x01 << MPU9150_ST2_DERR_BIT)
#define MPU9150_ST2_HOFL_MASK	(0x01 << MPU9150_ST2_HOFL_BIT)

#define MPU9150_CTRL_MODE_MASK	0x0F

#define MPU9150_ASTC_SELF_MASK	(1 << MPU9150_ASTC_SELF_MASK)

// Misc
#define MPU9150_I2CDIS_KEY		0x1D	// Write this key to I2CDIS register to disable I2C interface (reset only by VDD off)

//-------------------------------------------------------------------

//-------------------------------------------------------------------
// Register Map for Gyroscope and Accelerometer
//-------------------------------------------------------------------

// Offset
#define	MPU9150_SELF_TEST_X				0x0D	// (RW)
#define	MPU9150_SELF_TEST_Y				0x0E	// (RW)
#define	MPU9150_SELF_TEST_Z				0x0F	// (RW)
#define	MPU9150_SELF_TEST_A				0x10	// (RW)

#define MPU9150_SMPLRT_DIV				0x19	// (RW)

#define MPU9150_CONFIG					0x1A	// (RW)
#define MPU9150_GYRO_CONFIG				0x1B	// (RW)
#define MPU9150_ACCEL_CONFIG			0x1C	// (RW)

#define MPU9150_FIFO_EN					0x23	// (RW)
#define MPU9150_I2C_MST_CTRL			0x24	// (RW)

#define MPU9150_I2C_SLV0_ADDR			0x25	// (RW)
#define MPU9150_I2C_SLV0_REG			0x26	// (RW)
#define MPU9150_I2C_SLV0_CTRL			0x27	// (RW)

#define MPU9150_I2C_SLV1_ADDR			0x28	// (RW)
#define MPU9150_I2C_SLV1_REG			0x29	// (RW)
#define MPU9150_I2C_SLV1_CTRL			0x2A	// (RW)

#define MPU9150_I2C_SLV2_ADDR			0x2B	// (RW)
#define MPU9150_I2C_SLV2_REG			0x2C	// (RW)
#define MPU9150_I2C_SLV2_CTRL			0x2D	// (RW)

#define MPU9150_I2C_SLV3_ADDR			0x2E	// (RW)
#define MPU9150_I2C_SLV3_REG			0x2F	// (RW)
#define MPU9150_I2C_SLV3_CTRL			0x30	// (RW)

#define MPU9150_I2C_SLV4_ADDR			0x31	// (RW)
#define MPU9150_I2C_SLV4_REG			0x32	// (RW)
#define MPU9150_I2C_SLV4_DO				0x33	// (RW)
#define MPU9150_I2C_SLV4_CTRL			0x34	// (RW)
#define MPU9150_I2C_SLV4_DI				0x35	// (RO)

#define MPU9150_I2C_MST_STATUS			0x36	// (RO)

#define MPU9150_INT_PIN_CFG				0x37	// (RW)
#define MPU9150_INT_ENABLE				0x38	// (RW)
#define MPU9150_INT_STATUS				0x3A	// (RO)

#define MPU9150_ACCEL_XOUT_H			0x3B	// (RO)
#define MPU9150_ACCEL_XOUT_L			0x3C	// (RO)
#define MPU9150_ACCEL_YOUT_H			0x3D	// (RO)
#define MPU9150_ACCEL_YOUT_L			0x3E	// (RO)
#define MPU9150_ACCEL_ZOUT_H			0x3F	// (RO)
#define MPU9150_ACCEL_ZOUT_L			0x40	// (RO)

#define MPU9150_TEMP_OUT_H				0x41	// (RO)
#define MPU9150_TEMP_OUT_L				0x42	// (RO)

#define MPU9150_GYRO_XOUT_H				0x43	// (RO)
#define MPU9150_GYRO_XOUT_L				0x44	// (RO)
#define MPU9150_GYRO_YOUT_H				0x45	// (RO)
#define MPU9150_GYRO_YOUT_L				0x46	// (RO)
#define MPU9150_GYRO_ZOUT_H				0x47	// (RO)
#define MPU9150_GYRO_ZOUT_L				0x48	// (RO)

#define MPU9150_EXT_SENS_DATA_00		0x49	// (RO)
#define MPU9150_EXT_SENS_DATA_01		0x4A	// (RO)
#define MPU9150_EXT_SENS_DATA_02		0x4B	// (RO)
#define MPU9150_EXT_SENS_DATA_03		0x4C	// (RO)
#define MPU9150_EXT_SENS_DATA_04		0x4D	// (RO)
#define MPU9150_EXT_SENS_DATA_05		0x4E	// (RO)
#define MPU9150_EXT_SENS_DATA_06		0x4F	// (RO)
#define MPU9150_EXT_SENS_DATA_07		0x50	// (RO)
#define MPU9150_EXT_SENS_DATA_08		0x51	// (RO)
#define MPU9150_EXT_SENS_DATA_09		0x52	// (RO)
#define MPU9150_EXT_SENS_DATA_10		0x53	// (RO)
#define MPU9150_EXT_SENS_DATA_11		0x54	// (RO)
#define MPU9150_EXT_SENS_DATA_12		0x55	// (RO)
#define MPU9150_EXT_SENS_DATA_13		0x56	// (RO)
#define MPU9150_EXT_SENS_DATA_14		0x57	// (RO)
#define MPU9150_EXT_SENS_DATA_15		0x58	// (RO)
#define MPU9150_EXT_SENS_DATA_16		0x59	// (RO)
#define MPU9150_EXT_SENS_DATA_17		0x5A	// (RO)
#define MPU9150_EXT_SENS_DATA_18		0x5B	// (RO)
#define MPU9150_EXT_SENS_DATA_19		0x5C	// (RO)
#define MPU9150_EXT_SENS_DATA_20		0x5D	// (RO)
#define MPU9150_EXT_SENS_DATA_21		0x5E	// (RO)
#define MPU9150_EXT_SENS_DATA_22		0x5F	// (RO)
#define MPU9150_EXT_SENS_DATA_23		0x60	// (RO)

#define MPU9150_I2C_SLV0_DO				0x63	// (RW)
#define MPU9150_I2C_SLV1_DO				0x64	// (RW)
#define MPU9150_I2C_SLV2_DO				0x65	// (RW)
#define MPU9150_I2C_SLV3_DO				0x66	// (RW)

#define MPU9150_I2C_MST_DELAY_CTRL		0x67	// (RW)

#define MPU9150_SIGNAL_PATH_RESET		0x68	// (RW)

#define MPU9150_USER_CTRL				0x6A	// (RW)

#define MPU9150_PWR_MGMT_1				0x6B	// (RW)
#define MPU9150_PWR_MGMT_2				0x6C	// (RW)

#define MPU9150_FIFO_COUNTH				0x72	// (RW)
#define MPU9150_FIFO_COUNTL				0x73	// (RW)
#define MPU9150_FIFO_R_W				0x74	// (RW)

#define MPU9150_WHO_I_AM				0x75	// (RO)

// Bit
#define	MPU9150_SELF_TEST_X_XG_TEST_BIT		0
#define	MPU9150_SELF_TEST_X_XA_TEST_BIT		5
#define	MPU9150_SELF_TEST_Y_YG_TEST_BIT		0
#define	MPU9150_SELF_TEST_Y_YA_TEST_BIT		5
#define	MPU9150_SELF_TEST_Z_ZG_TEST_BIT		0
#define	MPU9150_SELF_TEST_Z_ZA_TEST_BIT		5
#define	MPU9150_SELF_TEST_A_XA_TEST_BIT		0
#define	MPU9150_SELF_TEST_A_YA_TEST_BIT		2
#define	MPU9150_SELF_TEST_A_ZA_TEST_BIT		4

#define MPU9150_CONFIG_DLPF_CFG_BIT			0
#define MPU9150_CONFIG_EXT_SYNC_SET_BIT		3

#define MPU9150_GYRO_CONFIG_FS_SEL_BIT		3
#define MPU9150_GYRO_CONFIG_ZG_ST_BIT		5
#define MPU9150_GYRO_CONFIG_YG_ST_BIT		6
#define MPU9150_GYRO_CONFIG_XG_ST_BIT		7

#define MPU9150_ACCEL_CONFIG_AFS_SEL_BIT	3
#define MPU9150_ACCEL_CONFIG_ZA_ST_BIT		5
#define MPU9150_ACCEL_CONFIG_YA_ST_BIT		6
#define MPU9150_ACCEL_CONFIG_XA_ST_BIT		7

#define MPU9150_FIFO_EN_SLV0_BIT			0
#define MPU9150_FIFO_EN_SLV1_BIT			1
#define MPU9150_FIFO_EN_SLV2_BIT			2
#define MPU9150_FIFO_EN_ACCEL_BIT			3
#define MPU9150_FIFO_EN_ZG_BIT				4
#define MPU9150_FIFO_EN_YG_BIT				5
#define MPU9150_FIFO_EN_XG_BIT				6
#define MPU9150_FIFO_EN_TEMP_BIT			7

#define MPU9150_I2C_MST_CTRL_I2C_MST_CLK_BIT	0
#define MPU9150_I2C_MST_CTRL_I2C_MST_P_NSR_BIT	4
#define MPU9150_I2C_MST_CTRL_SLV3_FIFO_EN_BIT	5
#define MPU9150_I2C_MST_CTRL_WAIT_FOR_ES_BIT	6
#define MPU9150_I2C_MST_CTRL_MULT_MST_EN_BIT	7

#define MPU9150_I2C_SLV0_ADDR_ADDR_BIT			0
#define MPU9150_I2C_SLV0_ADDR_RW_BIT			7

#define MPU9150_I2C_SLV0_CTRL_LEN_BIT			0
#define MPU9150_I2C_SLV0_CTRL_GRP_BIT			4
#define MPU9150_I2C_SLV0_CTRL_REG_DIS_BIT		5
#define MPU9150_I2C_SLV0_CTRL_BYTE_SW_BIT		6
#define MPU9150_I2C_SLV0_CTRL_EN_BIT			7

#define MPU9150_I2C_SLV1_ADDR_ADDR_BIT			0
#define MPU9150_I2C_SLV1_ADDR_RW_BIT			7

#define MPU9150_I2C_SLV1_CTRL_LEN_BIT			0
#define MPU9150_I2C_SLV1_CTRL_GRP_BIT			4
#define MPU9150_I2C_SLV1_CTRL_REG_DIS_BIT		5
#define MPU9150_I2C_SLV1_CTRL_BYTE_SW_BIT		6
#define MPU9150_I2C_SLV1_CTRL_EN_BIT			7

#define MPU9150_I2C_SLV2_ADDR_ADDR_BIT			0
#define MPU9150_I2C_SLV2_ADDR_RW_BIT			7

#define MPU9150_I2C_SLV2_CTRL_LEN_BIT			0
#define MPU9150_I2C_SLV2_CTRL_GRP_BIT			4
#define MPU9150_I2C_SLV2_CTRL_REG_DIS_BIT		5
#define MPU9150_I2C_SLV2_CTRL_BYTE_SW_BIT		6
#define MPU9150_I2C_SLV2_CTRL_EN_BIT			7

#define MPU9150_I2C_SLV3_ADDR_ADDR_BIT			0
#define MPU9150_I2C_SLV3_ADDR_RW_BIT			7

#define MPU9150_I2C_SLV3_CTRL_LEN_BIT			0
#define MPU9150_I2C_SLV3_CTRL_GRP_BIT			4
#define MPU9150_I2C_SLV3_CTRL_REG_DIS_BIT		5
#define MPU9150_I2C_SLV3_CTRL_BYTE_SW_BIT		6
#define MPU9150_I2C_SLV3_CTRL_EN_BIT			7

#define MPU9150_I2C_SLV4_ADDR_ADDR_BIT			0
#define MPU9150_I2C_SLV4_ADDR_RW_BIT			7

#define MPU9150_I2C_SLV4_CTRL_MST_DLY_BIT		0
#define MPU9150_I2C_SLV4_CTRL_REG_DIS_BIT		5
#define MPU9150_I2C_SLV4_CTRL_INT_EN_BIT		6
#define MPU9150_I2C_SLV4_CTRL_EN_BIT			7

#define MPU9150_I2C_MST_STATUS_SLV0_NACK_BIT	0
#define MPU9150_I2C_MST_STATUS_SLV1_NACK_BIT	1
#define MPU9150_I2C_MST_STATUS_SLV2_NACK_BIT	2
#define MPU9150_I2C_MST_STATUS_SLV3_NACK_BIT	3
#define MPU9150_I2C_MST_STATUS_SLV4_NACK_BIT	4
#define MPU9150_I2C_MST_STATUS_LOST_ARB_BIT		5
#define MPU9150_I2C_MST_STATUS_SLV4_DONE_BIT	6
#define MPU9150_I2C_MST_STATUS_PASS_THROUGH_BIT	7

#define MPU9150_INT_PIN_CFG_BYPASS_EN_BIT		1
#define MPU9150_INT_PIN_CFG_FSYNC_INT_EN_BIT	2
#define MPU9150_INT_PIN_CFG_FSYNC_INT_LEVEL_BIT	3
#define MPU9150_INT_PIN_CFG_INT_RD_CLEAR_BIT	4
#define MPU9150_INT_PIN_CFG_LATCH_INT_EN_BIT	5
#define MPU9150_INT_PIN_CFG_INT_OPEN_BIT		6
#define MPU9150_INT_PIN_CFG_INT_LEVEL_BIT		7

#define MPU9150_INT_ENABLE_DATA_RDY_EN_BIT		0
#define MPU9150_INT_ENABLE_MST_INT_EN_BIT		3
#define MPU9150_INT_ENABLE_FIFO_OFLOW_EN_BIT	4

#define MPU9150_INT_STATUS_DATA_RDY_INT_BIT		0
#define MPU9150_INT_STATUS_MST_INT_INT_BIT		3
#define MPU9150_INT_STATUS_FIFO_OFLOW_INT_BIT	4

#define MPU9150_I2C_MST_DELAY_CTRL_SLV0_EN_BIT	0
#define MPU9150_I2C_MST_DELAY_CTRL_SLV1_EN_BIT	1
#define MPU9150_I2C_MST_DELAY_CTRL_SLV2_EN_BIT	2
#define MPU9150_I2C_MST_DELAY_CTRL_SLV3_EN_BIT	3
#define MPU9150_I2C_MST_DELAY_CTRL_SLV4_EN_BIT	4
#define MPU9150_I2C_MST_DELAY_CTRL_ES_SHADOW_BIT	7

#define MPU9150_SIGNAL_PATH_RESET_TEMP_BIT		0
#define MPU9150_SIGNAL_PATH_RESET_ACCEL_BIT		1
#define MPU9150_SIGNAL_PATH_RESET_GYRO_BIT		2

#define MPU9150_USER_CTRL_SIG_COND_RESET_BIT	0
#define MPU9150_USER_CTRL_I2C_MST_RESET_BIT		1
#define MPU9150_USER_CTRL_FIFO_RESET_BIT		2
#define MPU9150_USER_CTRL_SIG_IF_DIS_BIT		4
#define MPU9150_USER_CTRL_I2C_MST_EN_BIT		5
#define MPU9150_USER_CTRL_FIFO_EN_BIT			6

#define MPU9150_PWR_MGMT_1_CLK_SEL_BIT			0
#define MPU9150_PWR_MGMT_1_TEMP_DIS_BIT			3
#define MPU9150_PWR_MGMT_1_CYCLE_BIT			5
#define MPU9150_PWR_MGMT_1_SLEEP_BIT			6
#define MPU9150_PWR_MGMT_1_DEVICE_RESET_BIT		7

#define MPU9150_PWR_MGMT_2_STBY_ZG_BIT			0
#define MPU9150_PWR_MGMT_2_STBY_YG_BIT			1
#define MPU9150_PWR_MGMT_2_STBY_XG_BIT			2
#define MPU9150_PWR_MGMT_2_STBY_ZA_BIT			3
#define MPU9150_PWR_MGMT_2_STBY_YA_BIT			4
#define MPU9150_PWR_MGMT_2_STBY_XA_BIT			5
#define MPU9150_PWR_MGMT_2_LP_WAKE_BIT			6

#define MPU9150_WHO_I_AM_BIT					1
// Mask
#define	MPU9150_SELF_TEST_X_XG_TEST_MASK	(0x1F << MPU9150_SELF_TEST_X_XG_TEST_BIT)
#define	MPU9150_SELF_TEST_X_XA_TEST_MASK	(0x03 << MPU9150_SELF_TEST_X_XA_TEST_BIT)
#define	MPU9150_SELF_TEST_Y_YG_TEST_MASK	(0x1F << MPU9150_SELF_TEST_Y_YG_TEST_BIT)
#define	MPU9150_SELF_TEST_Y_YA_TEST_MASK	(0x03 << MPU9150_SELF_TEST_Y_YA_TEST_BIT)
#define	MPU9150_SELF_TEST_Z_ZG_TEST_MASK	(0x1F << MPU9150_SELF_TEST_Z_ZG_TEST_BIT)
#define	MPU9150_SELF_TEST_Z_ZA_TEST_MASK	(0x03 << MPU9150_SELF_TEST_Z_ZA_TEST_BIT)
#define	MPU9150_SELF_TEST_A_XA_TEST_MASK	(0x03 << MPU9150_SELF_TEST_A_XA_TEST_BIT)
#define	MPU9150_SELF_TEST_A_YA_TEST_MASK	(0x03 << MPU9150_SELF_TEST_A_YA_TEST_BIT)
#define	MPU9150_SELF_TEST_A_ZA_TEST_MASL	(0x03 << MPU9150_SELF_TEST_A_ZA_TEST_BIT)

#define MPU9150_CONFIG_DLPF_CFG_MASK		(0x07 << MPU9150_CONFIG_DLPF_CFG_BIT)
#define MPU9150_CONFIG_EXT_SYNC_SET_MASK	(0x07 << MPU9150_CONFIG_EXT_SYNC_SET_BIT)

#define MPU9150_GYRO_CONFIG_FS_SEL_MASK		(0x03 << MPU9150_GYRO_CONFIG_FS_SEL_BIT)
#define MPU9150_GYRO_CONFIG_ZG_ST_MASK		(0x01 << MPU9150_GYRO_CONFIG_ZG_ST_BIT)
#define MPU9150_GYRO_CONFIG_YG_ST_MASK		(0x01 << MPU9150_GYRO_CONFIG_YG_ST_BIT)
#define MPU9150_GYRO_CONFIG_XG_ST_MASK		(0x01 << MPU9150_GYRO_CONFIG_XG_ST_BIT)

#define MPU9150_ACCEL_CONFIG_AFS_SEL_MASK	(0x03 << MPU9150_ACCEL_CONFIG_AFS_SEL_BIT)
#define MPU9150_ACCEL_CONFIG_ZA_ST_MASK		(0x01 << MPU9150_ACCEL_CONFIG_ZA_ST_BIT)
#define MPU9150_ACCEL_CONFIG_YA_ST_MASK		(0x01 << MPU9150_ACCEL_CONFIG_YA_ST_BIT)
#define MPU9150_ACCEL_CONFIG_XA_ST_MASK		(0x01 << MPU9150_ACCEL_CONFIG_XA_ST_BIT)

#define MPU9150_FIFO_EN_SLV0_MASK			(0x01 << MPU9150_FIFO_EN_SLV0_BIT)
#define MPU9150_FIFO_EN_SLV1_MASK			(0x01 << MPU9150_FIFO_EN_SLV1_BIT)
#define MPU9150_FIFO_EN_SLV2_MASK			(0x01 << MPU9150_FIFO_EN_SLV2_BIT)
#define MPU9150_FIFO_EN_ACCEL_MASK			(0x01 << MPU9150_FIFO_EN_ACCEL_BIT)
#define MPU9150_FIFO_EN_ZG_MASK				(0x01 << MPU9150_FIFO_EN_ZG_BIT)
#define MPU9150_FIFO_EN_YG_MASK				(0x01 << MPU9150_FIFO_EN_YG_BIT)
#define MPU9150_FIFO_EN_XG_MASK				(0x01 << MPU9150_FIFO_EN_XG_BIT)
#define MPU9150_FIFO_EN_TEMP_MASK			(0x01 << MPU9150_FIFO_EN_TEMP_BIT)

#define MPU9150_I2C_MST_CTRL_I2C_MST_CLK_MASK	(0x0F << MPU9150_I2C_MST_CTRL_I2C_MST_CLK_BIT)
#define MPU9150_I2C_MST_CTRL_I2C_MST_P_NSR_MASK	(0x01 << MPU9150_I2C_MST_CTRL_I2C_MST_P_NSR_BIT)
#define MPU9150_I2C_MST_CTRL_SLV3_FIFO_EN_MASK	(0x01 << MPU9150_I2C_MST_CTRL_SLV3_FIFO_EN_BIT)
#define MPU9150_I2C_MST_CTRL_WAIT_FOR_ES_MASK	(0x01 << MPU9150_I2C_MST_CTRL_WAIT_FOR_ES_BIT)
#define MPU9150_I2C_MST_CTRL_MULT_MST_EN_MASK	(0x01 << MPU9150_I2C_MST_CTRL_MULT_MST_EN_BIT)

#define MPU9150_I2C_SLV0_ADDR_ADDR_MASK			(0x7F << MPU9150_I2C_SLV0_ADDR_ADDR_BIT)
#define MPU9150_I2C_SLV0_ADDR_RW_MASK			(0x01 << MPU9150_I2C_SLV0_ADDR_RW_BI)

#define MPU9150_I2C_SLV0_CTRL_LEN_MASK			(0x0F << MPU9150_I2C_SLV0_CTRL_LEN_BIT)
#define MPU9150_I2C_SLV0_CTRL_GRP_MASK			(0x01 << MPU9150_I2C_SLV0_CTRL_GRP_BIT)
#define MPU9150_I2C_SLV0_CTRL_REG_DIS_MASK		(0x01 << MPU9150_I2C_SLV0_CTRL_REG_DIS_BIT)
#define MPU9150_I2C_SLV0_CTRL_BYTE_SW_MASK		(0x01 << MPU9150_I2C_SLV0_CTRL_BYTE_SW_BIT)
#define MPU9150_I2C_SLV0_CTRL_EN_MASK			(0x01 << MPU9150_I2C_SLV0_CTRL_EN_BIT)

#define MPU9150_I2C_SLV1_ADDR_ADDR_MASK			(0x7F << MPU9150_I2C_SLV1_ADDR_ADDR_BIT)
#define MPU9150_I2C_SLV1_ADDR_RW_MASK			(0x01 << MPU9150_I2C_SLV1_ADDR_RW_BI)

#define MPU9150_I2C_SLV1_CTRL_LEN_MASK			(0x0F << MPU9150_I2C_SLV1_CTRL_LEN_BIT)
#define MPU9150_I2C_SLV1_CTRL_GRP_MASK			(0x01 << MPU9150_I2C_SLV1_CTRL_GRP_BIT)
#define MPU9150_I2C_SLV1_CTRL_REG_DIS_MASK		(0x01 << MPU9150_I2C_SLV1_CTRL_REG_DIS_BIT)
#define MPU9150_I2C_SLV1_CTRL_BYTE_SW_MASK		(0x01 << MPU9150_I2C_SLV1_CTRL_BYTE_SW_BIT)
#define MPU9150_I2C_SLV1_CTRL_EN_MASK			(0x01 << MPU9150_I2C_SLV1_CTRL_EN_BIT)

#define MPU9150_I2C_SLV2_ADDR_ADDR_MASK			(0x7F << MPU9150_I2C_SLV2_ADDR_ADDR_BIT)
#define MPU9150_I2C_SLV2_ADDR_RW_MASK			(0x01 << MPU9150_I2C_SLV2_ADDR_RW_BI)

#define MPU9150_I2C_SLV2_CTRL_LEN_MASK			(0x0F << MPU9150_I2C_SLV2_CTRL_LEN_BIT)
#define MPU9150_I2C_SLV2_CTRL_GRP_MASK			(0x01 << MPU9150_I2C_SLV2_CTRL_GRP_BIT)
#define MPU9150_I2C_SLV2_CTRL_REG_DIS_MASK		(0x01 << MPU9150_I2C_SLV2_CTRL_REG_DIS_BIT)
#define MPU9150_I2C_SLV2_CTRL_BYTE_SW_MASK		(0x01 << MPU9150_I2C_SLV2_CTRL_BYTE_SW_BIT)
#define MPU9150_I2C_SLV2_CTRL_EN_MASK			(0x01 << MPU9150_I2C_SLV2_CTRL_EN_BIT)

#define MPU9150_I2C_SLV3_ADDR_ADDR_MASK			(0x7F << MPU9150_I2C_SLV3_ADDR_ADDR_BIT)
#define MPU9150_I2C_SLV3_ADDR_RW_MASK			(0x01 << MPU9150_I2C_SLV3_ADDR_RW_BI)

#define MPU9150_I2C_SLV3_CTRL_LEN_MASK			(0x0F << MPU9150_I2C_SLV3_CTRL_LEN_BIT)
#define MPU9150_I2C_SLV3_CTRL_GRP_MASK			(0x01 << MPU9150_I2C_SLV3_CTRL_GRP_BIT)
#define MPU9150_I2C_SLV3_CTRL_REG_DIS_MASK		(0x01 << MPU9150_I2C_SLV3_CTRL_REG_DIS_BIT)
#define MPU9150_I2C_SLV3_CTRL_BYTE_SW_MASK		(0x01 << MPU9150_I2C_SLV3_CTRL_BYTE_SW_BIT)
#define MPU9150_I2C_SLV3_CTRL_EN_MASK			(0x01 << MPU9150_I2C_SLV3_CTRL_EN_BIT)

#define MPU9150_I2C_SLV4_ADDR_ADDR_MASK			(0x7F << MPU9150_I2C_SLV4_ADDR_ADDR_BIT)
#define MPU9150_I2C_SLV4_ADDR_RW_MASK			(0x01 << MPU9150_I2C_SLV4_ADDR_RW_BI)

#define MPU9150_I2C_SLV4_CTRL_MST_DLY_MASK		(0x1F << MPU9150_I2C_SLV4_CTRL_LEN_BIT)
#define MPU9150_I2C_SLV4_CTRL_REG_DIS_MASK		(0x01 << MPU9150_I2C_SLV4_CTRL_REG_DIS_BIT)
#define MPU9150_I2C_SLV4_CTRL_INT_EN_MASK		(0x01 << MPU9150_I2C_SLV4_CTRL_BYTE_SW_BIT)
#define MPU9150_I2C_SLV4_CTRL_EN_MASK			(0x01 << MPU9150_I2C_SLV4_CTRL_EN_BIT)

#define MPU9150_I2C_MST_STATUS_SLV0_NACK_MASK	(0x01 << MPU9150_I2C_MST_STATUS_SLV0_NACK_BIT)
#define MPU9150_I2C_MST_STATUS_SLV1_NACK_MASK	(0x01 << MPU9150_I2C_MST_STATUS_SLV1_NACK_BIT)
#define MPU9150_I2C_MST_STATUS_SLV2_NACK_MASK	(0x01 << MPU9150_I2C_MST_STATUS_SLV2_NACK_BIT)
#define MPU9150_I2C_MST_STATUS_SLV3_NACK_MASK	(0x01 << MPU9150_I2C_MST_STATUS_SLV3_NACK_BIT)
#define MPU9150_I2C_MST_STATUS_SLV4_NACK_MASK	(0x01 << MPU9150_I2C_MST_STATUS_SLV4_NACK_BIT)
#define MPU9150_I2C_MST_STATUS_LOST_ARB_MASK	(0x01 << MPU9150_I2C_MST_STATUS_LOST_ARB_BIT)
#define MPU9150_I2C_MST_STATUS_SLV4_DONE_MASK	(0x01 << MPU9150_I2C_MST_STATUS_SLV4_DONE_BIT)
#define MPU9150_I2C_MST_STATUS_PASS_THROUGH_MASK	(0x01 << MPU9150_I2C_MST_STATUS_PASS_THROUGH_BIT)

#define MPU9150_INT_PIN_CFG_BYPASS_EN_MASK		(0x01 << MPU9150_INT_PIN_CFG_BYPASS_EN_BIT)
#define MPU9150_INT_PIN_CFG_FSYNC_INT_EN_MASK	(0x01 << MPU9150_INT_PIN_CFG_FSYNC_INT_EN_BIT)
#define MPU9150_INT_PIN_CFG_FSYNC_INT_LEVEL_MASK	(0x01 << MPU9150_INT_PIN_CFG_FSYNC_INT_LEVEL_BIT)
#define MPU9150_INT_PIN_CFG_INT_RD_CLEAR_MASK	(0x01 << MPU9150_INT_PIN_CFG_INT_RD_CLEAR_BIT)
#define MPU9150_INT_PIN_CFG_LATCH_INT_EN_MASK	(0x01 << MPU9150_INT_PIN_CFG_LATCH_INT_EN_BIT)
#define MPU9150_INT_PIN_CFG_INT_OPEN_MASK		(0x01 << MPU9150_INT_PIN_CFG_INT_OPEN_BIT)
#define MPU9150_INT_PIN_CFG_INT_LEVEL_MASK		(0x01 << MPU9150_INT_PIN_CFG_INT_LEVEL_BIT)

#define MPU9150_INT_ENABLE_DATA_RDY_EN_MASK		(0x01 << MPU9150_INT_ENABLE_DATA_RDY_EN_BIT)
#define MPU9150_INT_ENABLE_MST_INT_EN_MASK		(0x01 << MPU9150_INT_ENABLE_MST_INT_EN_BIT)
#define MPU9150_INT_ENABLE_FIFO_OFLOW_EN_MASK	(0x01 << MPU9150_INT_ENABLE_FIFO_OFLOW_EN_BIT)

#define MPU9150_INT_STATUS_DATA_RDY_INT_MASK	(0x01 << MPU9150_INT_STATUS_DATA_RDY_INT_BIT)
#define MPU9150_INT_STATUS_MST_INT_INT_MASK		(0x01 << MPU9150_INT_STATUS_MST_INT_INT_BIT)
#define MPU9150_INT_STATUS_FIFO_OFLOW_INT_MASK	(0x01 << MPU9150_INT_STATUS_FIFO_OFLOW_INT_BIT)

#define MPU9150_I2C_MST_DELAY_CTRL_SLV0_EN_MASK	(0x01 << MPU9150_I2C_MST_DELAY_CTRL_SLV0_EN_BIT)
#define MPU9150_I2C_MST_DELAY_CTRL_SLV1_EN_MASK	(0x01 << MPU9150_I2C_MST_DELAY_CTRL_SLV1_EN_BIT)
#define MPU9150_I2C_MST_DELAY_CTRL_SLV2_EN_MASK	(0x01 << MPU9150_I2C_MST_DELAY_CTRL_SLV2_EN_BIT)
#define MPU9150_I2C_MST_DELAY_CTRL_SLV3_EN_MASK	(0x01 << MPU9150_I2C_MST_DELAY_CTRL_SLV3_EN_BIT)
#define MPU9150_I2C_MST_DELAY_CTRL_SLV4_EN_MASK	(0x01 << MPU9150_I2C_MST_DELAY_CTRL_SLV4_EN_BIT)
#define MPU9150_I2C_MST_DELAY_CTRL_ES_SHADOW_MASK	(0x01 << MPU9150_I2C_MST_DELAY_CTRL_ES_SHADOW_BIT)

#define MPU9150_SIGNAL_PATH_RESET_TEMP_MASK		(0x01 << MPU9150_SIGNAL_PATH_RESET_TEMP_BIT)
#define MPU9150_SIGNAL_PATH_RESET_ACCEL_MASK	(0x01 << MPU9150_SIGNAL_PATH_RESET_ACCEL_BIT)
#define MPU9150_SIGNAL_PATH_RESET_GYRO_MASK		(0x01 << MPU9150_SIGNAL_PATH_RESET_GYRO_BIT)

#define MPU9150_USER_CTRL_SIG_COND_RESET_MASK	(0x01 << MPU9150_USER_CTRL_SIG_COND_RESET_BIT)
#define MPU9150_USER_CTRL_I2C_MST_RESET_MASK	(0x01 << MPU9150_USER_CTRL_I2C_MST_RESET_BIT)
#define MPU9150_USER_CTRL_FIFO_RESET_MASK		(0x01 << MPU9150_USER_CTRL_FIFO_RESET_BIT)
#define MPU9150_USER_CTRL_SIG_IF_DIS_MASK		(0x01 << MPU9150_USER_CTRL_SIG_IF_DIS_BIT)
#define MPU9150_USER_CTRL_I2C_MST_EN_MASK		(0x01 << MPU9150_USER_CTRL_I2C_MST_EN_BIT)
#define MPU9150_USER_CTRL_FIFO_EN_MASK			(0x01 << MPU9150_USER_CTRL_FIFO_EN_BIT)

#define MPU9150_PWR_MGMT_1_CLK_SEL_MASK			(0x07 << MPU9150_PWR_MGMT_1_CLK_SEL_BIT)
#define MPU9150_PWR_MGMT_1_TEMP_DIS_MASK		(0x01 << MPU9150_PWR_MGMT_1_TEMP_DIS_BIT)
#define MPU9150_PWR_MGMT_1_CYCLE_MASK			(0x01 << MPU9150_PWR_MGMT_1_CYCLE_BIT)
#define MPU9150_PWR_MGMT_1_SLEEP_MASK			(0x01 << MPU9150_PWR_MGMT_1_SLEEP_BIT)
#define MPU9150_PWR_MGMT_1_DEVICE_RESET_MASK	(0x01 << MPU9150_PWR_MGMT_1_DEVICE_RESET_BIT)

#define MPU9150_PWR_MGMT_2_STBY_ZG_MASK			(0x01 << MPU9150_PWR_MGMT_2_STBY_ZG_BIT)
#define MPU9150_PWR_MGMT_2_STBY_YG_MASK			(0x01 << MPU9150_PWR_MGMT_2_STBY_YG_BIT)
#define MPU9150_PWR_MGMT_2_STBY_XG_MASK			(0x01 << MPU9150_PWR_MGMT_2_STBY_XG_BIT)
#define MPU9150_PWR_MGMT_2_STBY_ZA_MASK			(0x01 << MPU9150_PWR_MGMT_2_STBY_ZA_BIT)
#define MPU9150_PWR_MGMT_2_STBY_YA_MASK			(0x01 << MPU9150_PWR_MGMT_2_STBY_YA_BIT)
#define MPU9150_PWR_MGMT_2_STBY_XA_MASK			(0x01 << MPU9150_PWR_MGMT_2_STBY_XA_BIT)
#define MPU9150_PWR_MGMT_2_LP_WAKE_MASK			(0x03 << MPU9150_PWR_MGMT_2_LP_WAKE_BIT)

#define MPU9150_WHO_I_AM_MASK					(0x3F << MPU9150_WHO_I_AM_BIT)


#endif /* MPU9150_DEF_H_ */
