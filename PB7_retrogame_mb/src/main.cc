/*
 * Empty C++ Application
 */

#include "xparameters.h"
#include "xgpio.h"
#include "xil_exception.h"
#include "xintc.h"
#include "xil_printf.h"

#define GPIO_DEVICE_ID		XPAR_GPIO_0_DEVICE_ID
#define GPIO_CHANNEL1	1
#define INTC_GPIO_INTERRUPT_ID	XPAR_INTC_0_GPIO_0_VEC_ID
#define INTC_DEVICE_ID	XPAR_INTC_0_DEVICE_ID

#define GPIO_ALL_LEDS		0xFFFF
#define GPIO_ALL_BUTTONS	0xFFFF

#define BUTTON_CHANNEL	 1	/* Channel 1 of the GPIO Device */
#define LED_CHANNEL	 2	/* Channel 2 of the GPIO Device */
#define BUTTON_INTERRUPT XGPIO_IR_CH1_MASK /* Channel 1 Interrupt Mask */

#define LED_DELAY	1000000
#define INTR_DELAY	0x00FFFFFF

#define INTC_DEVICE_ID	XPAR_INTC_0_DEVICE_ID
 #define INTC		XIntc
#define INTC_HANDLER	XIntc_InterruptHandler

XGpio Gpio; /* The Instance of the GPIO Driver */

INTC Intc; /* The Instance of the Interrupt Controller Driver */


static u16 GlobalIntrMask; /* GPIO channel mask that is needed by
			    * the Interrupt Handler */

static volatile u32 IntrFlag; /* Interrupt Handler Flag */


void GpioHandler(void *CallBackRef);

int GpioIntrExample(INTC *IntcInstancePtr, XGpio *InstancePtr,
			u16 DeviceId, u16 IntrId,
			u16 IntrMask, u32 *DataRead);

int GpioSetupIntrSystem(INTC *IntcInstancePtr, XGpio *InstancePtr,
			u16 DeviceId, u16 IntrId, u16 IntrMask);

void GpioDisableIntr(INTC *IntcInstancePtr, XGpio *InstancePtr,
u16 IntrId, u16 IntrMask);

int getButton()
{
	int Status;
	u32 DataRead;

	  print(" Press button to Generate Interrupt\r\n");

	  Status = GpioIntrExample(&Intc, &Gpio,
				   GPIO_DEVICE_ID,
				   INTC_GPIO_INTERRUPT_ID,
				   GPIO_CHANNEL1, &DataRead);
	  XGpio_SetDataDirection(&Gpio, 2, 0x00000000); // set LED GPIO channel tristates to All Output

	//	  XGpio_DiscreteWrite(&Gpio, 2, DataRead);
	//	  xil_printf("\rDataRead: %08x", DataRead);

	if (Status == 0 ){
		if(DataRead == 0)
			xil_printf("No button pressed. \r\n");
		else
			xil_printf("Successfully ran Gpio Interrupt Tapp Example\r\n");
	} else {
		 xil_printf("Gpio Interrupt Tapp Example Failed.\r\n");
		 return XST_FAILURE;
	}

	return getButton();
}

int main(void)
{
	getButton();
}

int GpioIntrExample(INTC *IntcInstancePtr, XGpio* InstancePtr, u16 DeviceId,
			u16 IntrId, u16 IntrMask, u32 *DataRead)
{
	int Status;
	u32 delay;

	/* Initialize the GPIO driver. If an error occurs then exit */
	Status = XGpio_Initialize(InstancePtr, DeviceId);
	if (Status != XST_SUCCESS) {
		return XST_FAILURE;
	}

	Status = GpioSetupIntrSystem(IntcInstancePtr, InstancePtr, DeviceId,
					IntrId, IntrMask);
	if (Status != XST_SUCCESS) {
		return XST_FAILURE;
	}

	XGpio_SetDataDirection(&Gpio, 2, 0x00000000); // set LED GPIO channel tristates to All Output

	for(;;) {
	IntrFlag = 0;
	delay = 0;

	while(!IntrFlag && (delay < INTR_DELAY)) {
		delay++;
	}
	}

	GpioDisableIntr(IntcInstancePtr, InstancePtr, IntrId, IntrMask);

	*DataRead = IntrFlag;

	return Status;
}

int GpioSetupIntrSystem(INTC *IntcInstancePtr, XGpio *InstancePtr,
			u16 DeviceId, u16 IntrId, u16 IntrMask)
{
	int Result;

	GlobalIntrMask = IntrMask;

	/*
	 * Initialize the interrupt controller driver so that it's ready to use.
	 * specify the device ID that was generated in xparameters.h
	 */
	Result = XIntc_Initialize(IntcInstancePtr, INTC_DEVICE_ID);
	if (Result != XST_SUCCESS) {
		return Result;
	}

	/* Hook up interrupt service routine */
	XIntc_Connect(IntcInstancePtr, IntrId,
		      (Xil_ExceptionHandler)GpioHandler, InstancePtr);

	/* Enable the interrupt vector at the interrupt controller */
	XIntc_Enable(IntcInstancePtr, IntrId);

	/*
	 * Start the interrupt controller such that interrupts are recognized
	 * and handled by the processor
	 */
	Result = XIntc_Start(IntcInstancePtr, XIN_REAL_MODE);
	if (Result != XST_SUCCESS) {
		return Result;
	}

	/*
	 * Enable the GPIO channel interrupts so that push button can be
	 * detected and enable interrupts for the GPIO device
	 */
	XGpio_InterruptEnable(InstancePtr, IntrMask);
	XGpio_InterruptGlobalEnable(InstancePtr);

	/*
	 * Initialize the exception table and register the interrupt
	 * controller handler with the exception table
	 */
	Xil_ExceptionInit();

	Xil_ExceptionRegisterHandler(XIL_EXCEPTION_ID_INT,
			 (Xil_ExceptionHandler)INTC_HANDLER, IntcInstancePtr);

	/* Enable non-critical exceptions */
	Xil_ExceptionEnable();

	return XST_SUCCESS;
}

void GpioHandler(void *CallbackRef)
{
	XGpio *GpioPtr = (XGpio *)CallbackRef;

	u32 dip;
	dip = XGpio_DiscreteRead(&Gpio, 1);
	XGpio_DiscreteWrite(&Gpio, 2, dip);

	IntrFlag = 1;

	/* Clear the Interrupt */
	XGpio_InterruptClear(GpioPtr, GlobalIntrMask);

}

void GpioDisableIntr(INTC *IntcInstancePtr, XGpio *InstancePtr,
			u16 IntrId, u16 IntrMask)
{
	XGpio_InterruptDisable(InstancePtr, IntrMask);
	XIntc_Disable(IntcInstancePtr, IntrId);
	return;
}
