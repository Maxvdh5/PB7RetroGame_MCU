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
	GpioHandler(u8 gpioId, u8 intrId, void	(*callback)(u8 data), XIntc *Intc);
	virtual ~GpioHandler();

public:
	static 	bool InitializeInterruptController(XIntc *Intc, u8 intrId);
	void 	write(u32 data);

private:
	XGpio	Gpio;
	XIntc	*Intc;

	bool	initialize(u8 gpioId, u8 intrId);
	void	(*callback)(u8 data);
	static 	void IntrCallback(void *CallbackRef);
};

#endif /* SRC_GPIOHANDLER_H_ */
