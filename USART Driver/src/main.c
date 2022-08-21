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
    
    //Tx
    u8 bytes[10] = {0,1,2,3,4,5,6,7,8,9};
    USART_voidTxInt(bytes);

    //Rx
    u8 RecivedByte = 0;
    USART_voidRxInt(&RecivedByte);


    while(1);


	return 0;
}
