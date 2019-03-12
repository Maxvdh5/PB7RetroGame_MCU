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
	void input(char);
	void output();

private:
	int data;
	XGpio gpio;
	u32 out;
};

#endif /* SRC_INOUT_H_ */
