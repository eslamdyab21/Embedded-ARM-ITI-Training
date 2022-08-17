/*
 * main.c
 *
 *  Created on: Aug 17, 2022
 *      Author: Dyab
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO/GPIO_interface.h"
#include "RCC Driver/RCC_interface.h"
#include "SYSTICK Driver/SYSTICK_interface.h"
#include "7Segment_interface.h"


void SevenSegment_Update(u8 number){
    GPIO_voidSetPinValue(GPIO_PORTA, 0, ((number>>0)&0x01));
    GPIO_voidSetPinValue(GPIO_PORTA, 1, ((number>>1)&0x01));
    GPIO_voidSetPinValue(GPIO_PORTA, 2, ((number>>2)&0x01));
    GPIO_voidSetPinValue(GPIO_PORTA, 3, ((number>>3)&0x01));
    GPIO_voidSetPinValue(GPIO_PORTA, 4, ((number>>4)&0x01));
    GPIO_voidSetPinValue(GPIO_PORTA, 5, ((number>>5)&0x01));
    GPIO_voidSetPinValue(GPIO_PORTA, 6, ((number>>6)&0x01));
}

void PeriodicDisplay(){
    static u8 flip = 1;
    GPIO_voidSetPinValue(GPIO_PORTA, 8, GPIO_HIGH);
    GPIO_voidSetPinValue(GPIO_PORTA, 9, GPIO_HIGH);

    switch (flip){
        case 1:
            GPIO_voidSetPinValue(GPIO_PORTA, 8, GPIO_LOW);
            SevenSegment_Update(segmentNumber[5]);
            flip = 0;
            break;

        case 0:
            GPIO_voidSetPinValue(GPIO_PORTA, 9, GPIO_LOW);
            SevenSegment_Update(segmentNumber[1]);
            flip = 1;
            break;
    }
    
}


int main(void)
{

	RCC_voidInit();
	RCC_voidPeripheralClockEnable(RCC_APB2, GPIOA);

	for(u8 i=0; i<=9; i++){
		GPIO_voidSetPinMode(GPIO_PORTA, i, GPIO_PIN_MODE_GP_PP_10MHZ);
	}


    STK_voidInit(SYSTICK_AHB_8);
	STK_voidSetPeriodicInterval(5000, PeriodicDisplay);
    
	while(1);

	return 0;
}
