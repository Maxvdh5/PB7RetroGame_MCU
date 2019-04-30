/*
 * GpioHandler.h
 *
 *  Created on: Apr 8, 2019
 *      Author: pelle
 */

#include "xil_types.h"
#include "xgpio.h"
#include "xintc.h"

#ifndef SRC_GPIOHANDLER_H_
#define SRC_GPIOHANDLER_H_

class GpioHandler {
public:
    // Initializes GPIO device and sets up an interrupt callback.
    // param:   gpioId:     ID of the GPIO device. (see xparameters.h)
    //          intrId:     ID of the interrupt vector for the GPIO device.
    //          callback:   callback to the function to call on interrupt.
    //          Intc:       pointer to the interrupt device object to register the
    //                      interrupt to.
	GpioHandler(u8 gpioId, u8 intrId, void	(*callback)(u8 data), XIntc *Intc);
	virtual ~GpioHandler();

public:
    // Initialize and enable interrupt controller.
    // param:   Intc:   pointer to XIntc object.
    //          intrId: ID of the interrupt controller to be initialized (see xparameters.h)
    // return:  true on success; false otherwise.
	static 	bool InitializeInterruptController(XIntc *Intc, u8 intrId);
    // write data to GPIO channel 1
    // param:   data:   Mask for the GPIO channel
	void 	write(u32 data);
	// read data on GPIO channel 2
	u32		read();

private:
	XGpio	Gpio;
	XIntc	*Intc;

	bool	initialize(u8 gpioId, u8 intrId);
	void	(*callback)(u8 data);
	static 	void IntrCallback(void *CallbackRef);
};

#endif /* SRC_GPIOHANDLER_H_ */
