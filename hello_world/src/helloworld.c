/*
 * Copyright (c) 2009-2012 Xilinx, Inc.  All rights reserved.
 *
 * Xilinx, Inc.
 * XILINX IS PROVIDING THIS DESIGN, CODE, OR INFORMATION "AS IS" AS A
 * COURTESY TO YOU.  BY PROVIDING THIS DESIGN, CODE, OR INFORMATION AS
 * ONE POSSIBLE   IMPLEMENTATION OF THIS FEATURE, APPLICATION OR
 * STANDARD, XILINX IS MAKING NO REPRESENTATION THAT THIS IMPLEMENTATION
 * IS FREE FROM ANY CLAIMS OF INFRINGEMENT, AND YOU ARE RESPONSIBLE
 * FOR OBTAINING ANY RIGHTS YOU MAY REQUIRE FOR YOUR IMPLEMENTATION.
 * XILINX EXPRESSLY DISCLAIMS ANY WARRANTY WHATSOEVER WITH RESPECT TO
 * THE ADEQUACY OF THE IMPLEMENTATION, INCLUDING BUT NOT LIMITED TO
 * ANY WARRANTIES OR REPRESENTATIONS THAT THIS IMPLEMENTATION IS FREE
 * FROM CLAIMS OF INFRINGEMENT, IMPLIED WARRANTIES OF MERCHANTABILITY
 * AND FITNESS FOR A PARTICULAR PURPOSE.
 *
 */

/*
 * helloworld.c: simple test application
 *
 * This application configures UART 16550 to baud rate 9600.
 * PS7 UART (Zynq) is not initialized by this application, since
 * bootrom/bsp configures it to baud rate 115200
 *
 * ------------------------------------------------
 * | UART TYPE   BAUD RATE                        |
 * ------------------------------------------------
 *   uartns550   9600
 *   uartlite    Configurable only in HW design
 *   ps7_uart    115200 (configured by bootrom/bsp)
 */

#include <stdio.h>
#include "platform.h"

#include "xparameters.h"
#include "xiicps.h"
#include "xil_printf.h"

#include "mpu9150_l.h"

// void print(char *str);

int I2C_DeviceInit(XIicPs *this, int id, int clk_freq);

int I2CMUX_SelectWrite(XIicPs *i2c_drv, u8 sel);
int I2CMUX_SelectRead(XIicPs *i2c_drv, u8 *sel);

// I2C mux (PCA9548) parameters
#define I2C_MUX_ADDR				0x74  		// 0b1110100

#define	I2C_MUX_SEL(s) I2C_MUX_SEL_##s##_MASK

#define I2C_MUX_SEL_NONE_MASK		0x00
#define I2C_MUX_SEL_USR_CLK_MASK	0x01
#define I2C_MUX_SEL_HDMI_MASK		0x02
#define I2C_MUX_SEL_EEPROM_MASK		0x04
#define I2C_MUX_SEL_EXPAND_MASK		0x08

#define I2C_MUX_SEL_RTC_MASK		0x10
#define I2C_MUX_SEL_FMC1_MASK		0x20
#define I2C_MUX_SEL_FMC2_MASK		0x40
#define I2C_MUX_SEL_PMBUS_MASK		0x80

XIicPs i2c_drv;

u8 i2c_send_buffer[128];
u8 i2c_recv_buffer[128];

int main()
{
	u8 mpu9150_reg_addr;

    init_platform();

    if(I2C_DeviceInit(&i2c_drv, XPAR_XIICPS_0_DEVICE_ID, 400000) == XST_SUCCESS)
    {
    	print("I2C device initialized successfully! \n\r");
    }
    else
    {
    	print("I2C device initialized fail! \n\r");
    }


    I2CMUX_SelectWrite(&i2c_drv, I2C_MUX_SEL(NONE));
	xil_printf("PCA9548 register wrote\n\r");

    I2CMUX_SelectRead(&i2c_drv, &i2c_recv_buffer[0]);
    xil_printf("PCA9548 register read back: 0x%x \n\r", i2c_recv_buffer[0]);

    I2CMUX_SelectWrite(&i2c_drv, I2C_MUX_SEL(PMBUS));
	xil_printf("PCA9548 register wrote\n\r");

	XIicPs_MasterRecvPolled(&i2c_drv, i2c_recv_buffer, 1, I2C_MUX_ADDR);
	xil_printf("PCA9548 register read back: 0x%x \n\r", i2c_recv_buffer[0]);


	mpu9150_reg_addr = 0x75;
	MPU9150_ReadReg(&i2c_drv, mpu9150_reg_addr, i2c_recv_buffer, 1);
	xil_printf("MPU9150 register 0x%x read back: 0x%x \n\r", mpu9150_reg_addr, i2c_recv_buffer[0]);

    return 0;
}

int I2C_DeviceInit(XIicPs *this, int id, int clk_freq)
{
	int status;

	XIicPs_Config *config;

	config = XIicPs_LookupConfig(id);

	if (config == NULL) {
		return XST_FAILURE;
	}

	status = XIicPs_CfgInitialize(this, config, config->BaseAddress);

	if (status != XST_SUCCESS) {
		return XST_FAILURE;
	}

	status = XIicPs_SelfTest(this);

	if (status != XST_SUCCESS) {
		return XST_FAILURE;
	}

	status = XIicPs_SetSClk(this, clk_freq);

	if (status != XST_SUCCESS) {
		return XST_FAILURE;
	}

	return XST_SUCCESS;
}

int I2CMUX_SelectWrite(XIicPs *i2c_drv, u8 sel)
{
	int status;

	status = XIicPs_MasterSendPolled(i2c_drv, &sel, 1, I2C_MUX_ADDR);

	while (XIicPs_BusIsBusy(i2c_drv));

	return status;
}

int I2CMUX_SelectRead(XIicPs *i2c_drv, u8 *sel)
{
	return XIicPs_MasterRecvPolled(i2c_drv, sel, 1, I2C_MUX_ADDR);
}
