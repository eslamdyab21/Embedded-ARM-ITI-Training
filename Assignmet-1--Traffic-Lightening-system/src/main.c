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

u8 statue = GPIO_LOW;

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

u8 Blink(u16 timeDelay, u16 *start_time){
      //u16 i=0;
      //for(i=0; i<timeDelay; i++ );
      *start_time = *start_time+1;
      if (*start_time >= timeDelay)
	    return 1;
      else
	    return 0;
}


void BlinkLed(u8 Copy_u8Pin, u16 BlinkTime,u16 *start_time){

	if(Blink(BlinkTime, start_time)){
		    if(statue == GPIO_LOW){
			  GPIO_voidSetPinValue(GPIO_PORTA, Copy_u8Pin, GPIO_HIGH);
			  statue = GPIO_HIGH;
		    }
		    else{
			  GPIO_voidSetPinValue(GPIO_PORTA, Copy_u8Pin, GPIO_LOW);
			  statue = GPIO_LOW;
		    }
		    *start_time = 0;
	}

	else{
		    if(statue == GPIO_LOW)
			GPIO_voidSetPinValue(GPIO_PORTA, Copy_u8Pin, GPIO_LOW);
		   else
			GPIO_voidSetPinValue(GPIO_PORTA, Copy_u8Pin, GPIO_HIGH);
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
        u16 green_led_blink_time = 10*10000;
        u16 yellow_led_blink_time = 3*10000;
        u16 red_led_blink_time = 10*10000;

        u16 start_time=0;
        Init();

	while(1){
		    SevenSegment_Update(segmentNumber[3]);

		    BlinkLed(GREEN_LED, green_led_blink_time,&start_time);
		    //BlinkLed(YELLOW_LED, yellow_led_blink_time);
		   //BlinkLed(RED_LED, red_led_blink_time);

	}


	return 0;
}

