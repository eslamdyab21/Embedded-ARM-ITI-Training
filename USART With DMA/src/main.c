/*
 * main.c
 *
 *  Created on: Aug 23, 2022
 *      Author: dyab
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DMA_interface.h"


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
    DMA_voidEnableSourceIncreament(Copy_u8ChannelNumber);

    DMA_voidSourceSize(Copy_u8ChannelNumber, Copy_u8SourceSize);
    DMA_voidDestinationSize(Copy_u8ChannelNumber, Copy_u8DestinationSize);

    DMA_voidEnableTransferCompleteInterrupt(Copy_u8ChannelNumber);



    //Enable Memory to Memory
    DMA_voidEnableMemory2MemoryMode(Copy_u8ChannelNumber);


    //6.Activate the channel by setting the ENABLE bit in the DMA_CCRx register.
    DMA_voidEnableChannel_x(Copy_u8ChannelNumber);
}



void DMA1_Channel1_IRQHandler(void){
    DMA_voidClearAllFlagsChanel1();
}



int main(void){

    return 0;
}