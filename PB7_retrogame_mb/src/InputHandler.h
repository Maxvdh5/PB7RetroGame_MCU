/*
 * InputHandler.h
 *
 *  Created on: Mar 12, 2019
 *      Author: pelle
 */

#ifndef SRC_INPUTHANDLER_H_
#define SRC_INPUTHANDLER_H_

#include "xil_types.h"
#include "xgpio.h"
#include "xintc.h"

class InputHandler {
public:
	InputHandler(void (*callback)(u8 data), u8 gpioId, u8 intrId);
	virtual ~InputHandler();

private:
	u8		gpioId;
	u8		intrId;
	void	(*callback)(u8 data);
	XGpio	Gpio;
	XIntc 	Intc;

	int		initialize();
	static 	void GpioHandler(void *CallbackRef);
};

#endif /* SRC_INPUTHANDLER_H_ */
