/*
 * main.c
 *
 *  Created on: Aug 8, 2022
 *      Author: Omar Gamal
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "RCC_interface.h"
#include "SYSTICK_interface.h"


#include "shallow.h"

void SendAudio(void){
	GPIO_voidSetPinValue(GPIO_PORTA, 8, GPIO_HIGH);
	static u16 x = 0;
	GPIO_voidPortMaskWrite(GPIO_PORTA, 0xFF, data[x++]);

	if(x == 39288)
		x=0;

	GPIO_voidSetPinValue(GPIO_PORTA, 8, GPIO_LOW);
}

int main(void)
{

	RCC_voidInit();
	RCC_voidPeripheralClockEnable(RCC_APB2, GPIOA);

	for(u8 i=0; i<8; i++){
		GPIO_voidSetPinMode(GPIO_PORTA, i, GPIO_PIN_MODE_GP_PP_10MHZ);
	}

	GPIO_voidSetPinMode(GPIO_PORTA, 8, GPIO_PIN_MODE_GP_PP_10MHZ);

    STK_voidInit(SYSTICK_AHB_8);
	STK_voidSetPeriodicInterval(100, SendAudio);

	while(1);

	return 0;
}
