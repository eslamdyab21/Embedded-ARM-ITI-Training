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

u16 tick_green=0;
u16 tick_yellow=0;
u16 tick_red=0;

void Init(){
        RCC_voidInit();
      	RCC_voidPeripheralClockEnable(RCC_APB2, GPIOA);
      	RCC_voidPeripheralClockEnable(RCC_APB2, GPIOB);

      	// make pins 1,2,3 output mode
      	GPIO_voidSetPinMode(GPIO_PORTA, GREEN_LED, GPIO_PIN_MODE_GP_PP_2MHZ);
      	GPIO_voidSetPinMode(GPIO_PORTA, YELLOW_LED, GPIO_PIN_MODE_GP_PP_2MHZ);
      	GPIO_voidSetPinMode(GPIO_PORTA, RED_LED, GPIO_PIN_MODE_GP_PP_2MHZ);

      	GPIO_voidSetPinMode(GPIO_PORTB, 0, GPIO_PIN_MODE_GP_PP_2MHZ);
      	GPIO_voidSetPinMode(GPIO_PORTB, 1, GPIO_PIN_MODE_GP_PP_2MHZ);
      	GPIO_voidSetPinMode(GPIO_PORTB, 2, GPIO_PIN_MODE_GP_PP_2MHZ);
      	GPIO_voidSetPinMode(GPIO_PORTB, 3, GPIO_PIN_MODE_GP_PP_2MHZ);
      	GPIO_voidSetPinMode(GPIO_PORTB, 4, GPIO_PIN_MODE_GP_PP_2MHZ);
      	GPIO_voidSetPinMode(GPIO_PORTB, 5, GPIO_PIN_MODE_GP_PP_2MHZ);
      	GPIO_voidSetPinMode(GPIO_PORTB, 6, GPIO_PIN_MODE_GP_PP_2MHZ);
}

u8 BlinkGreen(u16 timeDelay){

      tick_green++;
      if (tick_green >= timeDelay)
	    return 1;
      else
	    return 0;
}

u8 BlinkYellow(u16 timeDelay){

      tick_yellow++;
      if (tick_yellow >= timeDelay)
	    return 1;
      else
	    return 0;
}

u8 BlinkRed(u16 timeDelay){

      tick_red++;
      if (tick_red >= timeDelay)
	    return 1;
      else
	    return 0;
}


void BlinkLed(u8 Copy_u8Pin, u16 BlinkTime){

	switch(Copy_u8Pin){
	      case GREEN_LED:
		    if(BlinkGreen(BlinkTime)){
			      GPIO_voidSetPinValue(GPIO_PORTA, Copy_u8Pin, !GPIO_u8GetPinValue(GPIO_PORTA,Copy_u8Pin));
			      tick_green= 0;
		    }
		    break;


	      case YELLOW_LED:
		    if(BlinkYellow(BlinkTime)){
			    GPIO_voidSetPinValue(GPIO_PORTA, Copy_u8Pin, !GPIO_u8GetPinValue(GPIO_PORTA,Copy_u8Pin));
			    tick_yellow= 0;
		    }
		    break;

	      case RED_LED:
		    if(BlinkRed(BlinkTime)){
			  GPIO_voidSetPinValue(GPIO_PORTA, Copy_u8Pin, !GPIO_u8GetPinValue(GPIO_PORTA,Copy_u8Pin));
			  tick_red= 0;
		    }
		    break;
	}


}



void SevenSegment_Update(u8 number){
      GPIO_voidSetPinValue(GPIO_PORTB, 0, ((number>>0)&0x01));
      GPIO_voidSetPinValue(GPIO_PORTB, 1, ((number>>1)&0x01));
      GPIO_voidSetPinValue(GPIO_PORTB, 2, ((number>>2)&0x01));
      GPIO_voidSetPinValue(GPIO_PORTB, 3, ((number>>3)&0x01));
      GPIO_voidSetPinValue(GPIO_PORTB, 4, ((number>>4)&0x01));
      GPIO_voidSetPinValue(GPIO_PORTB, 5, ((number>>5)&0x01));
      GPIO_voidSetPinValue(GPIO_PORTB, 6, ((number>>6)&0x01));
}



int main(void)
{
        u16 green_led_blink_time = 30*10000;
        u16 yellow_led_blink_time = 3*10000;
        u16 red_led_blink_time = 30*10000;


        Init();

	while(1){
		    SevenSegment_Update(segmentNumber[3]);

		    BlinkLed(GREEN_LED, green_led_blink_time);
		    BlinkLed(YELLOW_LED, yellow_led_blink_time);
		    BlinkLed(RED_LED, red_led_blink_time);

	}


	return 0;
}

