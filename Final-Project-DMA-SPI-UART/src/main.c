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
#include "SPI Driver/SPI_interface.h"



#define USART_BASE_ADDRESS 			0x40013800
#define USART_DR_ADDRES             ( u32 *)  (USART_BASE_ADDRESS+0x04)

#define SPI_BASE_ADDRESS 			0x40013000
#define SPI_DR_ADDRES               ( u32 *)  (USART_BASE_ADDRESS+0x0C)


/*
* Master Init Function
*/
void SPI_voidMasterInit(void){


    //1.Select the BR[2:0] bits to define the serial clock baud rate 
    //(see SPI_CR1 register)
    SPI_voidBaudRateClk();

    //2.Select the CPOL and CPHA bits to define one of the four relationships 
    //between the data transfer and the serial clock
    SPI_voidClkPolarityPhaseMode();


    

    //3.Set the DFF bit to define 8- or 16-bit data frame size
    //DFF: Data frame format
    SPI_voidDataFrameSize();



    //4.Configure the LSBFIRST bit in the SPI_CR1 register to 
    //define the frame format.
    SPI_voidDataFrameFormat();


    
    //5.HW or SW Mode
    SPI_voidMasterManagmentMode();


    //6.The MSTR and SPE bits must be set (they remain set only if the NSS pin 
    //is connected to a high-level signal).
    SPI_voidEnableMaster();

    
    
    SPI_voidCommunicationProtocol();


    //Transmit sequence: 
    //Enable TXE interrupt (Tx Frame Complete)
    //SPI_voidTxeIntEnable();

    //Enable RXNE interrupt (Rx Frame Complete)
    //SPI_voidRxeInt();

    

    //7. enable SPI
    SPI_voidEnableSPI();

    //enable DMA-Rx for SPI
    SPI_voidTxDMAEnable();


}


void DMA_voidInit(u8 Copy_u8ChannelNumber, u32 *Copy_u32SourceAdress, u32 *Copy_u32DestinationAdress,
                  u32 Copy_u32NumberOfDataElements, u8 PriorityLevel, u8 Copy_u8SourceSize, 
                  u8 Copy_u8DestinationSize, u8 Copy_u8SourceIncreament, u8 Copy_u8DestinationIncreament){

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

    if(Copy_u8DestinationIncreament)
    	DMA_voidEnableDestinationIncreament(Copy_u8ChannelNumber);
    if(Copy_u8SourceIncreament)
    	DMA_voidEnableSourceIncreament(Copy_u8ChannelNumber);

    DMA_voidSourceSize(Copy_u8ChannelNumber, Copy_u8SourceSize);
    DMA_voidDestinationSize(Copy_u8ChannelNumber, Copy_u8DestinationSize);

    DMA_voidEnableTransferCompleteInterrupt(Copy_u8ChannelNumber);



    //Enable Memory to Memory
    //DMA_voidEnableMemory2MemoryMode(Copy_u8ChannelNumber);


    //6.Activate the channel by setting the ENABLE bit in the DMA_CCRx register.
    DMA_voidEnableChannel_x(Copy_u8ChannelNumber);
}


void RCC_GPIO_NVIC_USART1_SPI1_voidInit(void){
    /************************RCC/GPIO/USART1/SPI1*********************/
    RCC_voidInit();
	RCC_voidPeripheralClockEnable(RCC_APB2, GPIOA);
	RCC_voidPeripheralClockEnable(RCC_APB2, USART1);
	RCC_voidPeripheralClockEnable(RCC_AHB, DMA1);
    RCC_voidPeripheralClockEnable(RCC_APB2, SPI1);

    /*SPI
    Alternate function      SPI1_REMAP = 0      SPI1_REMAP = 1
        SPI1_NSS                  PA4               PA15
        SPI1_SCK                  PA5               PB3
        SPI1_MISO                 PA6               PB4
        SPI1_MOSI                 PA7               PB5
    */    
    //A7: MOSI (Alternating)
    GPIO_voidSetPinMode(GPIO_PORTA, 7, GPIO_PIN_MODE_AF_PP_10MHZ);
    //A5: CLK (Alternating)
    GPIO_voidSetPinMode(GPIO_PORTA, 5, GPIO_PIN_MODE_AF_PP_10MHZ);
    //A4: NSS (Alternating)
    GPIO_voidSetPinMode(GPIO_PORTA, 4, GPIO_PIN_MODE_AF_PP_10MHZ);
    //A6: MISO (Input)
    GPIO_voidSetPinMode(GPIO_PORTA, 6, GPIO_PIN_MODE_FLOATING_INPUT);


    GPIO_voidSetPinMode(GPIO_PORTA, 1, GPIO_PIN_MODE_GP_PP_10MHZ);
    GPIO_voidSetPinValue(GPIO_PORTA,1,GPIO_LOW);

    GPIO_voidSetPinMode(GPIO_PORTA, 2, GPIO_PIN_MODE_GP_PP_10MHZ);
    GPIO_voidSetPinValue(GPIO_PORTA,2,GPIO_LOW);

    GPIO_voidSetPinMode(GPIO_PORTA, 3, GPIO_PIN_MODE_GP_PP_10MHZ);
    GPIO_voidSetPinValue(GPIO_PORTA,3,GPIO_LOW);


    /*********************Enable DMA NVIC-Interupt********************/
    //NVIC_voidInit();
    /*DMA
    11 18 settable DMA1_Channel1    DMA1 Channel1 global interrupt  0x0000_006C
    12 19 settable DMA1_Channel2    DMA1 Channel2 global interrupt  0x0000_0070
    13 20 settable DMA1_Channel3    DMA1 Channel3 global interrupt  0x0000_0074
    14 21 settable DMA1_Channel4    DMA1 Channel4 global interrupt  0x0000_0078
    15 22 settable DMA1_Channel5    DMA1 Channel5 global interrupt  0x0000_007C
    16 23 settable DMA1_Channel6    DMA1 Channel6 global interrupt  0x0000_0080
    17 24 settable DMA1_Channel7    DMA1 Channel7 global interrupt  0x0000_0084
    */
    NVIC_voidEnableInterrupt(11);

    /*********************Enable SPI NVIC-Interupt********************/
    NVIC_voidInit();
    //35    42  settable    SPI1    SPI1 global interrupt   0x0000_00CC
    //NVIC_voidEnableInterrupt(35);
    
}

void DMA1_Channel5_IRQHandler(void){
    GPIO_voidSetPinValue(GPIO_PORTA,1,GPIO_LOW);
    DMA_voidClearAllFlagsChanel1();
    NVIC_voidDisableInterrupt(11);
}



int main(void){
	RCC_GPIO_NVIC_USART1_SPI1_voidInit();
    USART_voidInit();    
    SPI_voidMasterInit();

    u32 i=0;
    u32 Copy_u32NumberOfDataElements = 2;


    //DMA Channel 5 (USART-RX)
    u8 Copy_u8ChannelNumber5 = 5;
    u8 array1[Copy_u32NumberOfDataElements];
    u32 *Copy_u32SourceAdress = USART_DR_ADDRES;
    u32 *Copy_u32DestinationAdress = array1;
    u8 PriorityLevel = DMA_MEDIUM; 
    u8 Copy_u8SourceSize = DMA_8BITS;
    u8 Copy_u8DestinationSize = DMA_8BITS;
    u8 Copy_u8SourceIncreament = 0;
    u8 Copy_u8SourceDestination = 1;

    GPIO_voidSetPinValue(GPIO_PORTA,2,GPIO_LOW);
    DMA_voidInit(Copy_u8ChannelNumber5, Copy_u32SourceAdress, Copy_u32DestinationAdress,
                  Copy_u32NumberOfDataElements, PriorityLevel, Copy_u8SourceSize, 
                  Copy_u8DestinationSize, Copy_u8SourceIncreament, Copy_u8SourceDestination);



    //DMA Channel 2 (SPI-RX)
    u8 Copy_u8ChannelNumber3 = 3;
    //u8 array1[Copy_u32NumberOfDataElements];
    Copy_u32SourceAdress = array1;
    Copy_u32DestinationAdress = SPI_DR_ADDRES;
    PriorityLevel = DMA_MEDIUM;
    Copy_u8SourceSize = DMA_8BITS;
    Copy_u8DestinationSize = DMA_8BITS;
    Copy_u8SourceIncreament = 1;
    Copy_u8SourceDestination = 0;

    GPIO_voidSetPinValue(GPIO_PORTA,3,GPIO_LOW);
    DMA_voidInit(Copy_u8ChannelNumber3, Copy_u32SourceAdress, Copy_u32DestinationAdress,
                  Copy_u32NumberOfDataElements, PriorityLevel, Copy_u8SourceSize, 
                  Copy_u8DestinationSize, Copy_u8SourceIncreament, Copy_u8SourceDestination);

    /*GPIO_voidSetPinValue(GPIO_PORTA,1,GPIO_HIGH);
	for(i=0;i<100000;i++);
	GPIO_voidSetPinValue(GPIO_PORTA,1,GPIO_LOW);
	for(i=0;i<100000;i++);*/

    while (1){

    	//SPI_voidTx(0b01010000);
    	//while(!SPI_boolIsTxFrameComplete());
        //GPIO_voidSetPinValue(GPIO_PORTA,1,GPIO_HIGH);


    	GPIO_voidSetPinValue(GPIO_PORTA,1,GPIO_HIGH);
        for(i=0;i<100000;i++);
        GPIO_voidSetPinValue(GPIO_PORTA,1,GPIO_LOW);
        for(i=0;i<100000;i++);

        /*USART_voidTx(array1[0]);
        USART_voidTx(array1[1]);*/

        if(DMA_u8IsTransferComplete(Copy_u8ChannelNumber5)){
        	GPIO_voidSetPinValue(GPIO_PORTA,2,GPIO_HIGH);
        	USART_voidTx(array1[0]);
        	USART_voidTx(array1[1]);

        }
        /*if(DMA_u8IsTransferComplete(Copy_u8ChannelNumber2))
        	GPIO_voidSetPinValue(GPIO_PORTA,3,GPIO_HIGH);*/




    }

    
    return 0;
}
