/*
 * InputHandler.cpp
 *
 *  Created on: Mar 12, 2019
 *      Author: pelle
 */


//TODO: error handling

#include "InputHandler.h"
#include "xparameters.h"
#include "xil_exception.h"

#define INTR_DELAY	0x00FFFFFF
#define CHANNELMASK	1

InputHandler::InputHandler(void (*callback)(u8 data), u8 gpioId, u8 intrId) {
	this->callback 	= callback;
	this->gpioId	= gpioId;
	this->intrId	= intrId;

	initialize();
}

InputHandler::~InputHandler() {
	// TODO Auto-generated destructor stub
}

int InputHandler::initialize() {

	int Status;

	/* Initialize the GPIO driver. If an error occurs then exit */
	Status = XGpio_Initialize(&Gpio, gpioId);
	if (Status != XST_SUCCESS) {
		return XST_FAILURE;
	}

	XGpio_SetDataDirection(&Gpio, CHANNELMASK, 0xFF); // set GPIO channel tristates to All Output

	/*
	 * Initialize the interrupt controller driver so that it's ready to use.
	 * specify the device ID that was generated in xparameters.h
	 */
	Status = XIntc_Initialize(&Intc, intrId);
	if (Status != XST_SUCCESS) {
		return XST_FAILURE;
	}

	/* Hook up interrupt service routine */
	XIntc_Connect(&Intc, intrId,
			  (Xil_ExceptionHandler)GpioHandler, this);

	/* Enable the interrupt vector at the interrupt controller */
	XIntc_Enable(&Intc, intrId);

	/*
	 * Start the interrupt controller such that interrupts are recognized
	 * and handled by the processor
	 */
	Status = XIntc_Start(&Intc, XIN_REAL_MODE);
	if (Status != XST_SUCCESS) {
		return Status;
	}

	/*
	 * Enable the GPIO channel interrupts so that push button can be
	 * detected and enable interrupts for the GPIO device
	 */
	XGpio_InterruptEnable(&Gpio, CHANNELMASK);
	XGpio_InterruptGlobalEnable(&Gpio);

	/*
	 * Initialize the exception table and register the interrupt
	 * controller handler with the exception table
	 */
	Xil_ExceptionInit();

	Xil_ExceptionRegisterHandler(XIL_EXCEPTION_ID_INT,
			 (Xil_ExceptionHandler)XIntc_InterruptHandler, &Intc);

	/* Enable non-critical exceptions */
	Xil_ExceptionEnable();


	return Status;
}

void InputHandler::GpioHandler(void *CallbackRef)
{
	InputHandler *handler	= reinterpret_cast<InputHandler*>(CallbackRef);
	u8 data					= 0;
	u32	delay				= 0;

	XGpio_InterruptDisable(&handler->Gpio, CHANNELMASK);
	data = XGpio_DiscreteRead(&handler->Gpio, CHANNELMASK);

	/* Clear the Interrupt */
	XGpio_InterruptClear(&handler->Gpio, CHANNELMASK);

	while( delay++ < 10000);

	handler->callback(data);

	XGpio_InterruptEnable(&handler->Gpio, CHANNELMASK);

}
