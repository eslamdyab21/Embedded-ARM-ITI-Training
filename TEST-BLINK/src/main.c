/*
 * main.c
 *
 *  Created on: Aug 4, 2022
 *      Author: Eslam Dyab
 */

#include "STD_TYPES.h"

#include "GPIO_interface.h"
#include "RCC_interface.h"


int main(void)
{

	RCC_voidInit();
	RCC_voidPeripheralClockEnable(RCC_APB2, GPIOA);

	GPIO_voidSetPinMode(GPIO_PORTA, 1, GPIO_PIN_MODE_PULLING_INPUT);
	GPIO_voidSetPinValue(GPIO_PORTA, 1, GPIO_HIGH);

	return 0;
}
