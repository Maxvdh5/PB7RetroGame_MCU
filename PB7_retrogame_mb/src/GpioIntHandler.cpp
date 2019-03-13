/*
 * GpioIntHandler.cpp
 *
 *  Created on: Mar 13, 2019
 *      Author: pelle
 */

#include "GpioIntHandler.h"


GpioIntHandler::GpioIntHandler(	u32 gpioDeviceMask,
		u8 channel,
		u32 interruptMask,
		void (*callback)(u8 data))
{
	this->channel			= channel;
	this->interruptMask	 	= interruptMask;
	this->gpioDeviceMask	= gpioDeviceMask;
	this->callback			= callback;
}

GpioIntHandler::~GpioIntHandler() {
	// TODO Auto-generated destructor stub
}

void GpioIntHandler::GpioHandler(void *CallbackRef) {
	GpioIntHandler *handler	= reinterpret_cast<GpioIntHandler*>(CallbackRef);
	u8 data					= 0;
	u32	delay				= 0;

	XGpio_InterruptDisable(&handler->Gpio, handler->interruptMask);
	data = XGpio_DiscreteRead(&handler->Gpio, );

	/* Clear the Interrupt */
	XGpio_InterruptClear(&handler->Gpio, CHANNELMASK);

	while( delay++ < 10000);

	handler->callback(data);

	XGpio_InterruptEnable(&handler->Gpio, CHANNELMASK);
}

