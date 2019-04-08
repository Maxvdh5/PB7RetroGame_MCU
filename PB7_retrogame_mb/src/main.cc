#include "HeapManager.h"
#include "GpioHandler.h"
#include "xintc.h"
#include "xil_printf.h"

void buttonCallback(u8 data) {
	xil_printf("button press: %d\n", data);
}

void vgaCallback(u8 data) {
	if(1 == data)
		xil_printf("vga callback\r\n");
}

void initializeGpio()
{
	XIntc Intc;
	GpioHandler::InitializeInterruptController(&Intc, XPAR_INTC_0_DEVICE_ID);

	GpioHandler *buttonHandler 	= new GpioHandler(XPAR_GPIO_0_DEVICE_ID, XPAR_INTC_0_GPIO_0_VEC_ID, buttonCallback, &Intc);
	GpioHandler *vgaHandler 	= new GpioHandler(XPAR_GPIO_1_DEVICE_ID, XPAR_INTC_0_GPIO_1_VEC_ID, vgaCallback, &Intc);
}

int main() {
	xil_printf("\r\nretrogame loading...");

	initializeGpio();

	xil_printf("done.\r\n");

	while(1)
	{

	}
}
