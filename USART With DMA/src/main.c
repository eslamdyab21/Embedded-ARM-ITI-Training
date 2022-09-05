/*
 * main.c
 *
 *  Created on: Aug 23, 2022
 *      Author: dyab
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DMA_interface.h"

#include "RCC Driver/RCC_interface.h"
#include "GPIO/GPIO_interface.h"
#include "NVIC Driver/NVIC_interface.h"
#include "USART Driver/USART_interface.h"


#define USART_BASE_ADDRESS 			0x40013800
#define USART_DR_ADDRES             ( u32 *)  (USART_BASE_ADDRESS+0x04)


void DMA_voidInit(u8 Copy_u8ChannelNumber, u32 *Copy_u32SourceAdress, u32 *Copy_u32DestinationAdress,
                  u32 Copy_u32NumberOfDataElements, u8 PriorityLevel, u8 Copy_u8SourceSize, 
                  u8 Copy_u8DestinationSize){

    //1.Set the peripheral register address in the DMA_CPARx register
    DMA_voidSourceAddress(Copy_u8ChannelNumber, Copy_u32SourceAdress);

    //2.Set the memory address in the DMA_CMARx register
    DMA_voidDestinationAddress(Copy_u8ChannelNumber, Copy_u32DestinationAdress);


    //3.Configure the total number of data to be transferred in the DMA_CNDTRx register.
    DMA_voidNumberOfDataElements(Copy_u8ChannelNumber, Copy_u32NumberOfDataElements);


    //4.Configure the channel priority using the PL[1:0] bits in the DMA_CCRx register
    DMA_voidChannelPriorityLevel(Copy_u8ChannelNumber, PriorityLevel);


    //5.Configure data transfer direction, circular mode, peripheral & memory incremented
    //mode, peripheral & memory data size, and interrupt after half and/or full transfer 
    //in the DMA_CCRx register
    DMA_voidDataTransferDirection(Copy_u8ChannelNumber);

    DMA_voidEnableDestinationIncreament(Copy_u8ChannelNumber);
    //DMA_voidEnableSourceIncreament(Copy_u8ChannelNumber);

    DMA_voidSourceSize(Copy_u8ChannelNumber, Copy_u8SourceSize);
    DMA_voidDestinationSize(Copy_u8ChannelNumber, Copy_u8DestinationSize);

    DMA_voidEnableTransferCompleteInterrupt(Copy_u8ChannelNumber);



    //Enable Memory to Memory
    //DMA_voidEnableMemory2MemoryMode(Copy_u8ChannelNumber);


    //6.Activate the channel by setting the ENABLE bit in the DMA_CCRx register.
    DMA_voidEnableChannel_x(Copy_u8ChannelNumber);
}


void RCC_GPIO_NVIC_voidInit(void){
    /**************************RCC/GPIO*******************************/
    RCC_voidInit();
	RCC_voidPeripheralClockEnable(RCC_APB2, GPIOA);
	RCC_voidPeripheralClockEnable(RCC_APB2, USART1);
	RCC_voidPeripheralClockEnable(RCC_AHB, DMA1);

    GPIO_voidSetPinMode(GPIO_PORTA, 1, GPIO_PIN_MODE_GP_PP_10MHZ);
    GPIO_voidSetPinValue(GPIO_PORTA,1,GPIO_LOW);

    GPIO_voidSetPinMode(GPIO_PORTA, 2, GPIO_PIN_MODE_GP_PP_10MHZ);
    GPIO_voidSetPinValue(GPIO_PORTA,2,GPIO_LOW);


    /*********************Enable DMA NVIC-Interupt********************/
    //NVIC_voidInit();
    /*
    11 18 settable DMA1_Channel1    DMA1 Channel1 global interrupt  0x0000_006C
    12 19 settable DMA1_Channel2    DMA1 Channel2 global interrupt  0x0000_0070
    13 20 settable DMA1_Channel3    DMA1 Channel3 global interrupt  0x0000_0074
    14 21 settable DMA1_Channel4    DMA1 Channel4 global interrupt  0x0000_0078
    15 22 settable DMA1_Channel5    DMA1 Channel5 global interrupt  0x0000_007C
    16 23 settable DMA1_Channel6    DMA1 Channel6 global interrupt  0x0000_0080
    17 24 settable DMA1_Channel7    DMA1 Channel7 global interrupt  0x0000_0084
    */
    NVIC_voidEnableInterrupt(11);
    
}

void DMA1_Channel5_IRQHandler(void){
    GPIO_voidSetPinValue(GPIO_PORTA,1,GPIO_LOW);
    DMA_voidClearAllFlagsChanel1();
    NVIC_voidDisableInterrupt(11);
}



int main(void){
    RCC_GPIO_NVIC_voidInit();
    USART_voidInit();

    //Test DMA
    u8 array1[2];

    u32 i=0;



    //u8 DMA_Rx;
    //DMA Channel 5 (USART-RX)
    u8 Copy_u8ChannelNumber =5;
    u32 *Copy_u32SourceAdress = USART_DR_ADDRES;
    u32 *Copy_u32DestinationAdress = array1;
    u32 Copy_u32NumberOfDataElements = 2;
    u8 PriorityLevel = DMA_MEDIUM; 
    u8 Copy_u8SourceSize = DMA_8BITS;
    u8 Copy_u8DestinationSize = DMA_8BITS;


    GPIO_voidSetPinValue(GPIO_PORTA,2,GPIO_HIGH);
    DMA_voidInit(Copy_u8ChannelNumber, Copy_u32SourceAdress, Copy_u32DestinationAdress,
                  Copy_u32NumberOfDataElements, PriorityLevel, Copy_u8SourceSize, 
                  Copy_u8DestinationSize);


    /*GPIO_voidSetPinValue(GPIO_PORTA,1,GPIO_HIGH);
	for(i=0;i<100000;i++);
	GPIO_voidSetPinValue(GPIO_PORTA,1,GPIO_LOW);
	for(i=0;i<100000;i++);*/

    while (1){


        GPIO_voidSetPinValue(GPIO_PORTA,1,GPIO_HIGH);
        for(i=0;i<100000;i++);
        GPIO_voidSetPinValue(GPIO_PORTA,1,GPIO_LOW);
        for(i=0;i<100000;i++);

        /*USART_voidTx(array1[0]);
        USART_voidTx(array1[1]);*/

        if(DMA_voidIsTransferComplete(Copy_u8ChannelNumber)){
        	GPIO_voidSetPinValue(GPIO_PORTA,2,GPIO_LOW);
        	USART_voidTx(array1[0]);
        	USART_voidTx(array1[1]);

        	/*if(array1[0] == 'a')
				GPIO_voidSetPinValue(GPIO_PORTA,2,GPIO_HIGH);

			if(array1[1] == 'b')
				GPIO_voidSetPinValue(GPIO_PORTA,3,GPIO_HIGH);*/

        }



    }

    
    return 0;
}
