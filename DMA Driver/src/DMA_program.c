/*
 * DMA_program.c
 *
 *  Created on: Aug 23, 2022
 *      Author: dyab
 */

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "DMA_interface.h"
#include "DMA_config.h"
#include "DMA_private.h"



/*
* Function to take the source address
* Copy_u8ChannelNumber: Channel Number 1 to 7
*/
void DMA_voidSourceAddress(u8 Copy_u8ChannelNumber, u32 *Copy_u32SourceAdress){
    DMA1_REG->CHANNEL[Copy_u8ChannelNumber-1].CPAR = Copy_u32SourceAdress;
}



/*
* Function to take the source size
* Paramters: Copy_u8SourceSize
                0: 8-bits
                1: 16-bits
                2: 32-bits

*          : Copy_u8ChannelNumber: Channel Number 1 to 7
*/
void DMA_voidSourceSize(u8 Copy_u8ChannelNumber, u8 Copy_u8SourceSize){
    switch (Copy_u8SourceSize)
    {
    case DMA_8BITS:
        CLR_BIT(DMA1_REG->CHANNEL[Copy_u8ChannelNumber-1].CCR,8);
        CLR_BIT(DMA1_REG->CHANNEL[Copy_u8ChannelNumber-1].CCR,9);
        break;
    
    case DMA_16BITS:
        SET_BIT(DMA1_REG->CHANNEL[Copy_u8ChannelNumber-1].CCR,8);
        CLR_BIT(DMA1_REG->CHANNEL[Copy_u8ChannelNumber-1].CCR,9);
        break;
    
    case DMA_32BITS:
        CLR_BIT(DMA1_REG->CHANNEL[Copy_u8ChannelNumber-1].CCR,8);
        SET_BIT(DMA1_REG->CHANNEL[Copy_u8ChannelNumber-1].CCR,9);
        break;
    }
}



/*
* Function to take the destination address
* Copy_u8ChannelNumber: Channel Number 1 to 7
*/
void DMA_voidDestinationAddress(u8 Copy_u8ChannelNumber, u32 *Copy_u32DestinationAdress){
    DMA1_REG->CHANNEL[Copy_u8ChannelNumber-1].CMAR = Copy_u32DestinationAdress;
}


/*
* Function to take the destination size
* Paramters: Copy_u8DestinationSize
                0: 8-bits
                1: 16-bits
                2: 32-bits
*          : Copy_u8ChannelNumber: Channel Number 1 to 7
*/
void DMA_voidDestinationSize(u8 Copy_u8ChannelNumber, u8 Copy_u8DestinationSize){
    switch (Copy_u8DestinationSize)
        {
        case DMA_8BITS:
            CLR_BIT(DMA1_REG->CHANNEL[Copy_u8ChannelNumber-1].CCR,10);
            CLR_BIT(DMA1_REG->CHANNEL[Copy_u8ChannelNumber-1].CCR,11);
            break;
        
        case DMA_16BITS:
            SET_BIT(DMA1_REG->CHANNEL[Copy_u8ChannelNumber-1].CCR,10);
            CLR_BIT(DMA1_REG->CHANNEL[Copy_u8ChannelNumber-1].CCR,11);
            break;
        
        case DMA_32BITS:
            CLR_BIT(DMA1_REG->CHANNEL[Copy_u8ChannelNumber-1].CCR,10);
            SET_BIT(DMA1_REG->CHANNEL[Copy_u8ChannelNumber-1].CCR,11);
            break;
        }
}



/*
* Function to take the number of data elements to be transfered
* number of data elements from 0 to 65535
* Copy_u8ChannelNumber: Channel Number 1 to 7
*/
void DMA_voidNumberOfDataElements(u8 Copy_u8ChannelNumber, u32 Copy_u32NumberOfDataElements){
    DMA1_REG->CHANNEL[Copy_u8ChannelNumber-1].CNDTR = Copy_u32NumberOfDataElements;
}


/*
* Function to set the priority level of a channel
* Paramters:
*           Copy_u8ChannelNumber: Channel Number 1 to 7
            PriorityLevel: 0:Low
                           1:Medium
                           2:High
                           3:Very high
*/
void DMA_voidChannelPriorityLevel(u8 Copy_u8ChannelNumber, u8 PriorityLevel){
    switch (PriorityLevel)
        {
        case DMA_LOW:
            CLR_BIT(DMA1_REG->CHANNEL[Copy_u8ChannelNumber-1].CCR,12);
            CLR_BIT(DMA1_REG->CHANNEL[Copy_u8ChannelNumber-1].CCR,13);
            break;
        
        case DMA_MEDIUM:
            SET_BIT(DMA1_REG->CHANNEL[Copy_u8ChannelNumber-1].CCR,12);
            CLR_BIT(DMA1_REG->CHANNEL[Copy_u8ChannelNumber-1].CCR,13);
            break;
        
        case DMA_HIGH:
            CLR_BIT(DMA1_REG->CHANNEL[Copy_u8ChannelNumber-1].CCR,12);
            SET_BIT(DMA1_REG->CHANNEL[Copy_u8ChannelNumber-1].CCR,13);
            break;
        
        case DMA_VERY_HIGH:
            SET_BIT(DMA1_REG->CHANNEL[Copy_u8ChannelNumber-1].CCR,12);
            SET_BIT(DMA1_REG->CHANNEL[Copy_u8ChannelNumber-1].CCR,13);
            break;
        }
}
