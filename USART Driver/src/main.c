/*
 * main.c
 *
 *  Created on: Aug 21, 2022
 *      Author: dyab
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "USART_interface.h"

#include "RCC Driver/RCC_interface.h"
#include "GPIO/GPIO_interface.h"
#include "NVIC Driver/NVIC_interface.h"

void RCC_GPIO_NVIC_voidInit(void){
    /**************************RCC/GPIO*******************************/
    RCC_voidInit();
	RCC_voidPeripheralClockEnable(RCC_APB2, GPIOA);
	RCC_voidPeripheralClockEnable(RCC_APB2, USART1);

    //A9: Tx, A10: Rx
    GPIO_voidSetPinMode(GPIO_PORTA, 9, GPIO_PIN_MODE_AF_PP_10MHZ);
    GPIO_voidSetPinMode(GPIO_PORTA, 10, GPIO_PIN_MODE_PULLING_INPUT);

    GPIO_voidSetPinMode(GPIO_PORTA, 0, GPIO_PIN_MODE_GP_PP_10MHZ);
    GPIO_voidSetPinValue(GPIO_PORTA,0,GPIO_LOW);


    /*********************Enable USART NVIC-Interupt********************/
    NVIC_voidInit();
    //37  44  settable   USART1USART1 global interrupt   0x0000_00D4
    //NVIC_voidEnableInterrupt(37);
}



int main(void){
    RCC_GPIO_NVIC_voidInit();
    USART_voidInit();

    u32 delay=0;
    //Tx
    //u8 bytes[] = {"hello world\r\n"};
    //USART_voidTxInt(bytes);

    u8 byte = 'd';
    //Rx
    //u8 RecivedByte = 0;
    //USART_voidRxInt(&RecivedByte);


    while(1){
    	USART_voidTx(byte);
    	if(USART_u8Rx() == 'a')
    		GPIO_voidSetPinValue(GPIO_PORTA,0,GPIO_HIGH);

    	if(USART_u8Rx() == 'b')
    	    GPIO_voidSetPinValue(GPIO_PORTA,0,GPIO_LOW);

    	for(delay=0; delay<100000; delay++);
    	delay=0;
    }


	return 0;
}
