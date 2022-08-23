/*
 * DMA_interface.h
 *
 *  Created on: Aug 23, 2022
 *      Author: dyab
 */

#ifndef DMA_INTERFACE_H_
#define DMA_INTERFACE_H_


//Macros
#define DMA_8BITS    0
#define DMA_16BITS   1
#define DMA_32BITS   2


/*
* Function to take the source address
* Copy_u8ChannelNumber: Channel Number 1 to 7
*/
void DMA_voidSourceAddress(u8 Copy_u8ChannelNumber, u32 *Copy_u32SourceAdress);


/*
* Function to take the source size
* Paramters: Copy_u32SourceSize
                0: 8-bits
                1: 16-bits
                2: 32-bits

*          : Copy_u8ChannelNumber: Channel Number 1 to 7
*/
void DMA_voidSourceSize(u8 Copy_u8ChannelNumber, u8 Copy_u32SourceSize);


/*
* Function to take the destination address
*/
void DMA_voidDestinationAddress(u8 Copy_u8ChannelNumber, u32 Copy_u32DestinationAdress);


/*
* Function to take the destination size
* Paramters: Copy_u32DestinationSize
                0: 8-bits
                1: 16-bits
                2: 32-bits
*          : Copy_u8ChannelNumber: Channel Number 1 to 7
*/
void DMA_voidDestinationSize(u8 Copy_u8ChannelNumber, u8 Copy_u32DestinationSize);



/*
* Function to take the number of data elements to be transfered
* number of data elements from 0 to 65535
* Copy_u8ChannelNumber: Channel Number 1 to 7
*/
void DMA_voidNumberOfDataElements(u8 Copy_u8ChannelNumber, u32 Copy_u32NumberOfDataElements);


/*
* Function to set the priority level of a channel
* Paramters:
*           Copy_u8ChannelNumber: Channel Number 1 to 7
            PriorityLevel: 0:Low
                           1:Medium
                           2:High
                           3:Very high
*/
void DMA_voidChannelPriorityLevel(u8 Copy_u8ChannelNumber, u8 PriorityLevel);



/*
* Function to enable Memory to memory mode
* Paramters:
*           Copy_u8ChannelNumber: Channel Number 1 to 7
*/
void DMA_voidEnableMemory2MemoryMode(u8 Copy_u8ChannelNumber);


/*
* Function to disabled Memory to memory mode
* Paramters:
*           Copy_u8ChannelNumber: Channel Number 1 to 7
*/
void DMA_voidDisabledMemory2MemoryMode(u8 Copy_u8ChannelNumber);



/*
* Function to Enable source increament mode
* Paramters:
*           Copy_u8ChannelNumber: Channel Number 1 to 7
*/
void DMA_voidEnableSourceIncreament(u8 Copy_u8ChannelNumber);


/*
* Function to disabled source increament mode
* Paramters:
*           Copy_u8ChannelNumber: Channel Number 1 to 7
*/
void DMA_voidDisabledSourceIncreament(u8 Copy_u8ChannelNumber);



/*
* Function to Enable destination increament mode
* Paramters:
*           Copy_u8ChannelNumber: Channel Number 1 to 7
*/
void DMA_voidEnableDestinationIncreament(u8 Copy_u8ChannelNumber);


/*
* Function to disabled destination increament mode
* Paramters:
*           Copy_u8ChannelNumber: Channel Number 1 to 7
*/
void DMA_voidDisableDestinationIncreament(u8 Copy_u8ChannelNumber);



/*
* Function to enable Transfer complete interrupt 
* Paramters:
*           Copy_u8ChannelNumber: Channel Number 1 to 7
*/
void DMA_voidEnableTransferCompleteInterrupt(u8 Copy_u8ChannelNumber);


/*
* Function to disabled destination increament mode
* Paramters:
*           Copy_u8ChannelNumber: Channel Number 1 to 7
*/
void DMA_voidDisableTransferCompleteInterrupt(u8 Copy_u8ChannelNumber);


/*
* Function to enable a channel_x
* Paramters:
*           Copy_u8ChannelNumber: Channel Number 1 to 7
*/
void DMA_voidEnableChannel_x(u8 Copy_u8ChannelNumber);


/*
* Function to enable a channel_x
* Paramters:
*           Copy_u8ChannelNumber: Channel Number 1 to 7
*/
void DMA_voidDisableChannel_x(u8 Copy_u8ChannelNumber);


#endif /* DMA_INTERFACE_H_ */
