/*
 * inOut.h
 *
 *  Created on: Mar 12, 2019
 *      Author: maxva
 */

#include "xgpio.h"

#ifndef SRC_INOUT_H_
#define SRC_INOUT_H_

class inOut {
public:
	inOut();
	virtual ~inOut();

public:
	void input(u8);
	void output();

private:
	u8 x;
	u8 y;
	XGpio gpio;
};

#endif /* SRC_INOUT_H_ */
