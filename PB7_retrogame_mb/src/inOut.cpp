/*
 * inOut.cpp
 *
 *  Created on: Mar 12, 2019
 *      Author: maxva
 */

#include "inOut.h"
#include "xgpio.h"
#include "xil_printf.h"


inOut::inOut() {
	// TODO Auto-generated constructor stub
	this->x = 0x1400;
	this->y = 0xf000;
	XGpio_Initialize(&gpio, 1);
}

inOut::~inOut() {
	// TODO Auto-generated destructor stub
}

void inOut::input(u8 dataIn){

	switch(dataIn)
	{
	case 0b0001: this->y--; break;
	case 0b0010: this->x--; break;
	case 0b0100: this->x++; break;
	case 0b1000: this->y++; break;
	}
	output();
}

void inOut::output()
{
	u32 output;

	output = 0x1101<<16;
	output = output|this->x;
	XGpio_DiscreteWrite(&gpio, 1, output);
	xil_printf("X: %16x\r\n", output);
	output = 0;
	XGpio_DiscreteWrite(&gpio, 1, output);

	output = 0x1102<<16;
	output = output|this->y;
	XGpio_DiscreteWrite(&gpio, 1, output);
	xil_printf("Y: %16x\r\n", output);
	output = 0;
	XGpio_DiscreteWrite(&gpio, 1, output);

	output = 0x1103<<16;
	output = output|0x00;
	XGpio_DiscreteWrite(&gpio, 1, output);
	xil_printf("S: %16x\r\n", output);
	output = 0;
	XGpio_DiscreteWrite(&gpio, 1, output);

}
