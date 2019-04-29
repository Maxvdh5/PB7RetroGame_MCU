#include "HeapManager.h"
#include "GpioHandler.h"
#include "game.h"

#include "xintc.h"
#include "xil_printf.h"
#include <cassert>

//TODO: replace button interupt with a single read before readframe
//TODO: improve collission gap
//TODO: push blocks
//TODO: player deaths
//TODO: push block fall off screen
//TODO: finish -> next level
//TODO: reset button

Game 		*game;
GpioHandler *buttonHandler;
GpioHandler *vgaHandler;

void buttonCallback(u8 data) {
	xil_printf("button press: %d\r\n", data);
	game->handleUserInput(data);

}

void vgaCallback(u8 data) {
	if(1 == data)
	{
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
