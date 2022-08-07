/*
 * main.c
 *
 *  Created on: Aug 4, 2022
 *      Author: Eslam Dyab
 */

#include "STD_TYPES.h"

#include "GPIO_interface.h"
#include "RCC_interface.h"
#include "Led_interface.h"


void Init(){
        RCC_voidInit();
      	RCC_voidPeripheralClockEnable(RCC_APB2, GPIOA);

      	// make pins 1,2,3 output mode
      	GPIO_voidSetPinMode(GPIO_PORTA, GREEN_LED, GPIO_PIN_MODE_GP_PP_2MHZ);
      	GPIO_voidSetPinMode(GPIO_PORTA, YELLOW_LED, GPIO_PIN_MODE_GP_PP_2MHZ);
      	GPIO_voidSetPinMode(GPIO_PORTA, RED_LED, GPIO_PIN_MODE_GP_PP_2MHZ);
}

void Delay(u16 timeDelay){
      u16 i=0;
      for(i=0; i<timeDelay; i++ );

}

void BlinkLed(u8 Copy_u8Pin, u16 BlinkTime){
        GPIO_voidSetPinValue(GPIO_PORTA, Copy_u8Pin, GPIO_LOW);
	Delay(BlinkTime);
	GPIO_voidSetPinValue(GPIO_PORTA, Copy_u8Pin, GPIO_HIGH);
	Delay(BlinkTime);
}

int main(void)
{
        u16 green_led_blink_time = 10*10000;
        u16 yellow_led_blink_time = 3*10000;
        u16 red_led_blink_time = 10*10000;
        Init();

	while(1){
		    BlinkLed(GREEN_LED, green_led_blink_time);
		    BlinkLed(YELLOW_LED, yellow_led_blink_time);
		    BlinkLed(RED_LED, red_led_blink_time);
	}


	return 0;
}

