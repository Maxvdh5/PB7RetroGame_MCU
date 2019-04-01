#include "InputHandler.h"
#include "xil_printf.h"
#include "HeapManager.h"

void callback(u8 data) {
	xil_printf("interrupt: %d\n", data);
}

int main() {
	xil_printf("retrogame loading...");

	// create objects here
	InputHandler *handler = new InputHandler(&callback, 0, 0);

	xil_printf("done.\n");

	while(1)
	{

	}
}
