/*
 * main.c
 *
 *  Created on: Aug 4, 2022
 *      Author: Eslam Dyab
 */

#include "STD_TYPES.h"

#include "GPIO_interface.h"
#include "RCC_interface.h"


void Init(){
        RCC_voidInit();
      	RCC_voidPeripheralClockEnable(RCC_APB2, GPIOA);

      	// make pins 1,2,3 output mode
      	GPIO_voidSetPinMode(GPIO_PORTA, 1, GPIO_PIN_MODE_GP_PP_2MHZ);
      	GPIO_voidSetPinMode(GPIO_PORTA, 2, GPIO_PIN_MODE_GP_PP_2MHZ);
      	GPIO_voidSetPinMode(GPIO_PORTA, 3, GPIO_PIN_MODE_GP_PP_2MHZ);
}

void Delay(int timeDelay){
      int i=0;
      for(i=0; i<timeDelay; i++ );

}

int main(void)
{
        Init();


	while(1){
		    GPIO_voidSetPinValue(GPIO_PORTA, 2, GPIO_HIGH);
		    Delay(10000);
		    GPIO_voidSetPinValue(GPIO_PORTA, 2, GPIO_LOW);
		    Delay(10000);

	}

	return 0;
}

