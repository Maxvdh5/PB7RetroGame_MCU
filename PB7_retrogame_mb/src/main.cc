#include "InputHandler.h"
#include "inOut.h"
#include "xil_printf.h"

inOut inout;

void callback(u8 data) {
	xil_printf("interrupt: %d\n", data);
	inout.input(data);
}

int main() {
	xil_printf("retrogame loading...");

	// create objects here
	InputHandler handler(&callback, 0, 0);

	xil_printf("done.\n");

	while(1)
	{

	}
}
