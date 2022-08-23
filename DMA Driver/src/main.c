/*
 * main.c
 *
 *  Created on: Aug 23, 2022
 *      Author: dyab
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DMA_interface.h"



void DMA_voidInit(u8 Copy_u8ChannelNumber, u32 *Copy_u32SourceAdress, u32 *Copy_u32DestinationAdress, u32 Copy_u32NumberOfDataElements, u8 PriorityLevel){
    //1.Set the peripheral register address in the DMA_CPARx register
    void DMA_voidSourceAddress(u8 Copy_u8ChannelNumber, u32 *Copy_u32SourceAdress);

    //2.Set the memory address in the DMA_CMARx register
    void DMA_voidDestinationAddress(u8 Copy_u8ChannelNumber, u32 *Copy_u32DestinationAdress);


    //3.Configure the total number of data to be transferred in the DMA_CNDTRx register.
    void DMA_voidNumberOfDataElements(u8 Copy_u8ChannelNumber, u32 Copy_u32NumberOfDataElements);


    //4.Configure the channel priority using the PL[1:0] bits in the DMA_CCRx register
    void DMA_voidChannelPriorityLevel(u8 Copy_u8ChannelNumber, u8 PriorityLevel);


    //5.Configure data transfer direction, circular mode, peripheral & memory incremented
    //mode, peripheral & memory data size, and interrupt after half and/or full transfer 
    //in the DMA_CCRx register
    
}


int main(void){


    return 0;
}