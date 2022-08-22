/*
 * main.c
 *
 *  Created on: Aug 21, 2022
 *      Author: dyab
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "USART_interface.h"
#include "GPIO/GPIO_interface.h"


int main(void){

    USART_voidInit();
    GPIO_voidSetPinMode(GPIO_PORTA, 0, GPIO_PIN_MODE_GP_PP_2MHZ);
    GPIO_voidSetPinValue(GPIO_PORTA,0,GPIO_LOW);

    u32 delay=0;
    //Tx
    //u8 bytes[] = {"hello world\r\n"};
    //USART_voidTxInt(bytes);

    u8 byte = 'd';
    //Rx
    //u8 RecivedByte = 0;
    //USART_voidRxInt(&RecivedByte);


    while(1){
    	//USART_voidTx(byte);
    	if(USART_u8Rx() == 'a')
    		GPIO_voidSetPinValue(GPIO_PORTA,0,GPIO_HIGH);

    	if(USART_u8Rx() == 'b')
    	    GPIO_voidSetPinValue(GPIO_PORTA,0,GPIO_LOW);

    	for(delay=0; delay<100000; delay++);
    	delay=0;
    }


	return 0;
}
