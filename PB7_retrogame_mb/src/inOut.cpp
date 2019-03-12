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
	data = 0;
	XGpio_Initialize(&gpio, 0); // TODO gpio block voor output
}

inOut::~inOut() {
	// TODO Auto-generated destructor stub
}

void inOut::input(char dataIn){

	switch(dataIn)
	{
	case 000: data = 0x0500; break;
	case 001: data = 0x0501; break;
	case 010: data = 0x0502; break;
	case 011: data = 0x0503; break;
	case 100: data = 0x0504; break;
	case 101: data = 0x0505; break;
	case 110: data = 0x0506; break;
	case 111: data = 0x0507; break;
	}
}

void inOut::output()
{


	//XGpio_DiscreteWrite(&gpio, 2, data);
	while(true){
		xil_printf("\r sent data: %04x", data);
	}

}
