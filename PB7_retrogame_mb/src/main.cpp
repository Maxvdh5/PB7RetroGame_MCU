#include "HeapManager.h"
#include "GpioHandler.h"
#include "game.h"

#include "xintc.h"
#include "xil_printf.h"
#include <cassert>

//TODO: player deaths
//TODO: finish -> next level
//TODO: reset button
//TODO: prevent double jump
//TODO: fix moveable block clipping

Game 		*game;
GpioHandler *buttonHandler;
GpioHandler *vgaHandler;

void buttonCallback(u8 data) {
	xil_printf("button press: %d\r\n", data);
//	game->handleUserInput(data);

}

void vgaCallback(u8 data) {
	if(1 == data)
	{
		game->handleUserInput(buttonHandler->read() & 0xFF);
		game->runFrame(vgaHandler);
	}
}

void initializeGpio()
{
	XIntc Intc;
	assert(GpioHandler::InitializeInterruptController(&Intc, XPAR_INTC_0_DEVICE_ID));

	buttonHandler 	= new GpioHandler(XPAR_GPIO_0_DEVICE_ID, XPAR_INTC_0_GPIO_0_VEC_ID, buttonCallback, &Intc);
	vgaHandler 		= new GpioHandler(XPAR_GPIO_1_DEVICE_ID, XPAR_INTC_0_GPIO_1_VEC_ID, vgaCallback, &Intc);
}

int main() {

	// volatile bool to prevent the busy-loop from being optimized out.
	volatile bool 	Running 	= true;

	xil_printf("\r\nretrogame loading...");

	game = new Game();
	initializeGpio();

	xil_printf("done.\r\n");

	while (Running);
}
