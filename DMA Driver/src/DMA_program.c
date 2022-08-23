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
* Paramters: Copy_u32SourceSize
                0: 8-bits
                1: 16-bits
                2: 32-bits

*          : Copy_u8ChannelNumber: Channel Number 1 to 7
*/
void DMA_voidSourceSize(u8 Copy_u8ChannelNumber, u8 Copy_u32SourceSize){
    switch (Copy_u32SourceSize)
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