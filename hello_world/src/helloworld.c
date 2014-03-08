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

// void print(char *str);

int I2C_DeviceInit(XIicPs *this, int id, int clk_freq);

int main()
{
	XIicPs i2c_drv;

    init_platform();

    if(I2C_DeviceInit(&i2c_drv, XPAR_XIICPS_0_DEVICE_ID, 100000) == XST_SUCCESS)
    {
    	print("I2C device initialized successfully! \n\r");
    }
    else
    {
    	print("I2C device initialized fail! \n\r");
    }


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

	XIicPs_SetSClk(this, clk_freq);

	return XST_SUCCESS;
}
