/*
 * GpioHandler.cpp
 *
 *  Created on: Apr 8, 2019
 *      Author: pelle
 */

#define	INTR_CHANNEL 	2
#define OUTPUT_CHANNEL 	1

#include "GpioHandler.h"
#include <cassert>

GpioHandler::GpioHandler(u8 gpioId, u8 intrId, void (*callback)(u8 data), XIntc *Intc) {
	this->Intc 		= Intc;
	this->callback	= callback;

	assert(initialize(gpioId, intrId));
}

GpioHandler::~GpioHandler() {
	// TODO stop gpio & intr?
}

bool GpioHandler::initialize(u8 gpioId, u8 intrId)
{
	int Status;

	/* Initialize the GPIO driver. If an error occurs then exit */
	Status = XGpio_Initialize(&Gpio, gpioId);
	if (Status != XST_SUCCESS) {
		return false;
	}

	XGpio_SetDataDirection(&Gpio, OUTPUT_CHANNEL, 	0x00000000); // output
	XGpio_SetDataDirection(&Gpio, INTR_CHANNEL,		0xFFFFFFFF); // input

	/* Hook up interrupt service routine */
	Status = XIntc_Connect(Intc, intrId,
			  (Xil_ExceptionHandler)IntrCallback, this);
	if (Status != XST_SUCCESS) {
		return false;
	}

	/* Enable the interrupt vector at the interrupt controller */
	XIntc_Enable(Intc, intrId);

	/*
	 * Enable the GPIO channel interrupts
	 */
	XGpio_InterruptEnable(&Gpio, INTR_CHANNEL);
	XGpio_InterruptGlobalEnable(&Gpio);

	return true;
}

void GpioHandler::IntrCallback(void *CallbackRef)
{
	GpioHandler *handler	= reinterpret_cast<GpioHandler*>(CallbackRef);
	u8 data					= 0;

	XGpio_InterruptDisable(&handler->Gpio, INTR_CHANNEL);
	data = XGpio_DiscreteRead(&handler->Gpio, INTR_CHANNEL);

	/* Clear the Interrupt */
	XGpio_InterruptClear(&handler->Gpio, INTR_CHANNEL);

	handler->callback(data);

	XGpio_InterruptEnable(&handler->Gpio, INTR_CHANNEL);

}

void GpioHandler::write(u32 data)
{
	XGpio_DiscreteWrite(&Gpio, OUTPUT_CHANNEL, data);
}

bool GpioHandler::InitializeInterruptController(XIntc *Intc, u8 intrId)
{
	int Status;

	/*
	 * Initialize the interrupt controller driver so that it's ready to use.
	 * specify the device ID that was generated in xparameters.h
	 */
	Status = XIntc_Initialize(Intc, intrId);
	if (Status != XST_SUCCESS) {
		return false;
	}

	/*
	 * Start the interrupt controller such that interrupts are recognized
	 * and handled by the processor
	 */
	Status = XIntc_Start(Intc, XIN_REAL_MODE);
	if (Status != XST_SUCCESS) {
		return false;
	}

	/*
	 * Initialize the exception table and register the interrupt
	 * controller handler with the exception table
	 */
	Xil_ExceptionInit();

	Xil_ExceptionRegisterHandler(XIL_EXCEPTION_ID_INT,
			 (Xil_ExceptionHandler)XIntc_InterruptHandler, &Intc);

	/* Enable non-critical exceptions */
	Xil_ExceptionEnable();

	return true;
}

