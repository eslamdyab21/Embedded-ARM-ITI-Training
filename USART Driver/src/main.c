/*
 * main.c
 *
 *  Created on: Aug 21, 2022
 *      Author: dyab
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "USART_interface.h"


int main(void){

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
    	for(delay=0; delay<100000; delay++);
    	delay=0;
    }


	return 0;
}
