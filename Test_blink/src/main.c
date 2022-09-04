#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "RCC Driver/RCC_interface.h"
#include "GPIO/GPIO_interface.h"


int main(void)
{
  // At this stage the system clock should have already been configured
  // at high speed.
	RCC_voidInit();
	RCC_voidPeripheralClockEnable(RCC_APB2, GPIOA);
	//RCC_voidPeripheralClockEnable(RCC_AHB, DMA1);

	GPIO_voidSetPinMode(GPIO_PORTA, 0, GPIO_PIN_MODE_GP_PP_10MHZ);
	GPIO_voidSetPinValue(GPIO_PORTA,0,GPIO_LOW);

	GPIO_voidSetPinMode(GPIO_PORTA, 1, GPIO_PIN_MODE_GP_PP_10MHZ);
	GPIO_voidSetPinValue(GPIO_PORTA,1,GPIO_LOW);



	u32 i = 0;
	while (1){
		GPIO_voidSetPinValue(GPIO_PORTA,1,GPIO_HIGH);
		for(i=0;i<100000;i++);
		GPIO_voidSetPinValue(GPIO_PORTA,1,GPIO_LOW);
		for(i=0;i<100000;i++);
	}


	  return 0;

}
