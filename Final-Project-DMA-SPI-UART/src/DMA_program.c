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
    /*
    PSIZE[1:0]: Peripheral size
        00: 8-bits
        01: 16-bits
        10: 32-bits
        11: Reserved
    */

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
    /*
    MSIZE[1:0]: Memory size
        00: 8-bits
        01: 16-bits
        10: 32-bits
        11: Reserved
    */

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
    /*
    PL[1:0]: Channel priority level
        00: Low
        01: Medium
        10: High
        11: Very high
    */

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



/*
* Function to enable Memory to memory mode
* Paramters:
*           Copy_u8ChannelNumber: Channel Number 1 to 7
*/
void DMA_voidEnableMemory2MemoryMode(u8 Copy_u8ChannelNumber){
    /*
    MEM2MEM: Memory to memory mode
        0: Memory to memory mode disabled
        1: Memory to memory mode enabled
    */
    SET_BIT(DMA1_REG->CHANNEL[Copy_u8ChannelNumber-1].CCR,14);
}


/*
* Function to disabled Memory to memory mode
* Paramters:
*           Copy_u8ChannelNumber: Channel Number 1 to 7
*/
void DMA_voidDisabledMemory2MemoryMode(u8 Copy_u8ChannelNumber){
    /*
    MEM2MEM: Memory to memory mode
        0: Memory to memory mode disabled
        1: Memory to memory mode enabled
    */
    CLR_BIT(DMA1_REG->CHANNEL[Copy_u8ChannelNumber-1].CCR,14);
}





/*
* Function to Enable source increament mode
* Paramters:
*           Copy_u8ChannelNumber: Channel Number 1 to 7
*/
void DMA_voidEnableSourceIncreament(u8 Copy_u8ChannelNumber){
    /*
    PINC: Peripheral increment mode
        0: Peripheral increment mode disabled
        1: Peripheral increment mode enabled
    */
    SET_BIT(DMA1_REG->CHANNEL[Copy_u8ChannelNumber-1].CCR,6);
}


/*
* Function to disabled source increament mode
* Paramters:
*           Copy_u8ChannelNumber: Channel Number 1 to 7
*/
void DMA_voidDisabledSourceIncreament(u8 Copy_u8ChannelNumber){
    /*
    PINC: Peripheral increment mode
        0: Peripheral increment mode disabled
        1: Peripheral increment mode enabled
    */
    CLR_BIT(DMA1_REG->CHANNEL[Copy_u8ChannelNumber-1].CCR,6);
}



/*
* Function to Enable destination increament mode
* Paramters:
*           Copy_u8ChannelNumber: Channel Number 1 to 7
*/
void DMA_voidEnableDestinationIncreament(u8 Copy_u8ChannelNumber){
    /*
    MINC: Memory increment mode
        0: Peripheral increment mode disabled
        1: Peripheral increment mode enabled
    */
   SET_BIT(DMA1_REG->CHANNEL[Copy_u8ChannelNumber-1].CCR,7);
}


/*
* Function to disabled destination increament mode
* Paramters:
*           Copy_u8ChannelNumber: Channel Number 1 to 7
*/
void DMA_voidDisableDestinationIncreament(u8 Copy_u8ChannelNumber){
    /*
    MINC: Memory increment mode
        0: Peripheral increment mode disabled
        1: Peripheral increment mode enabled
    */

    CLR_BIT(DMA1_REG->CHANNEL[Copy_u8ChannelNumber-1].CCR,7);
}



/*
* Function to check Transfer complete
* Paramters:
*           Copy_u8ChannelNumber: Channel Number 1 to 7
*/
u8 DMA_u8IsTransferComplete(u8 Copy_u8ChannelNumber){
    /*
    Bits 25, 21, 17, 13, TCIFx: Channel x transfer complete flag (x = 1 ..7)
	9, 5, 1
	This bit is set by hardware. It is cleared by software writing 1 to the corresponding bit in the
	DMA_IFCR register.
		0: No transfer complete (TC) event on channel x
		1: A transfer complete (TC) event occurred on channel x
    */
    if(Copy_u8ChannelNumber == 5)
        return GET_BIT(DMA1_REG->ISR,17);
    else if(Copy_u8ChannelNumber == 3)
        return GET_BIT(DMA1_REG->ISR,9);
}


/*
* Function to enable Transfer complete interrupt 
* Paramters:
*           Copy_u8ChannelNumber: Channel Number 1 to 7
*/
void DMA_voidEnableTransferCompleteInterrupt(u8 Copy_u8ChannelNumber){
    /*
    TCIE: Transfer complete interrupt enable
        0: TC interrupt disabled
        1: TC interrupt enabled
    */

   SET_BIT(DMA1_REG->CHANNEL[Copy_u8ChannelNumber-1].CCR,1);
}


/*
* Function to disabled Transfer complete interrupt
* Paramters:
*           Copy_u8ChannelNumber: Channel Number 1 to 7
*/
void DMA_voidDisableTransferCompleteInterrupt(u8 Copy_u8ChannelNumber){
    /*
    TCIE: Transfer complete interrupt enable
        0: TC interrupt disabled
        1: TC interrupt enabled
    */

   CLR_BIT(DMA1_REG->CHANNEL[Copy_u8ChannelNumber-1].CCR,1);
}



/*
* Function to enable a channel_x
* Paramters:
*           Copy_u8ChannelNumber: Channel Number 1 to 7
*/
void DMA_voidEnableChannel_x(u8 Copy_u8ChannelNumber){
    /*
    EN: Channel enable
        0: Channel disabled
        1: Channel enabled
    */

   SET_BIT(DMA1_REG->CHANNEL[Copy_u8ChannelNumber-1].CCR,0);
}


/*
* Function to enable a channel_x
* Paramters:
*           Copy_u8ChannelNumber: Channel Number 1 to 7
*/
void DMA_voidDisableChannel_x(u8 Copy_u8ChannelNumber){
    /*
    EN: Channel enable
        0: Channel disabled
        1: Channel enabled
    */

   CLR_BIT(DMA1_REG->CHANNEL[Copy_u8ChannelNumber-1].CCR,0);
}



/*
* Function to set data flow direction, source to destination (perph to mem)
* Paramters:
*           Copy_u8ChannelNumber: Channel Number 1 to 7
*/
void DMA_voidDataTransferDirection(u8 Copy_u8ChannelNumber){
    /*
    DIR: Data transfer direction
        0: Read from peripheral
        1: Read from memory
    */

   CLR_BIT(DMA1_REG->CHANNEL[Copy_u8ChannelNumber-1].CCR,4);

}


/*
* Function to sclear all flags: GIF, TEIF, HTIF and TCIF flags 
*/
void DMA_voidClearAllFlagsChanel1(void){
    DMA1_REG->IFCR = 1;
}
