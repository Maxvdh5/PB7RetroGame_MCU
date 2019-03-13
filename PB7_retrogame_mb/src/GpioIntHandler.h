/*
 * GpioIntHandler.h
 *
 *  Created on: Mar 13, 2019
 *      Author: pelle
 */

#ifndef SRC_GPIOINTHANDLER_H_
#define SRC_GPIOINTHANDLER_H_

#include "InputHandler.h"
#include "xbasic_types.h"
#include "xgpio.h"

class GpioIntHandler {
public:
	GpioIntHandler(	u32 gpioDeviceMask,
					u8 channel,
					u32 interruptMask,
					void (*callback)(u8 data));
	virtual ~GpioIntHandler();

private:
	u8		channel;
	u32		gpioDeviceMask;
	u32		interruptMask;
	XGpio	Gpio;
	void	(*callback)(u8 data);
	static 	void GpioHandler(void *CallbackRef);
};

#endif /* SRC_GPIOINTHANDLER_H_ */
