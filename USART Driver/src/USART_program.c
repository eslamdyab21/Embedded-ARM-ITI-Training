/*
 * USART_program.c
 *
 *  Created on: Aug 21, 2022
 *      Author: dyab
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "USART_interface.h"
#include "USART_config.h"
#include "USART_private.h"

#include "RCC Driver/RCC_interface.h"
#include "GPIO/GPIO_interface.h"
#include "NVIC Driver/NVIC_interface.h"



u8 *Ptr_u8TxBytes;
u8 *Ptr_u8RxByte;


/*
* Init Function
*/
void USART_voidInit(void){
    /**************************RCC/GPIO*******************************/
    RCC_voidInit();
	RCC_voidPeripheralClockEnable(RCC_APB1, USART1);

    //A9: Tx, A10: Rx
    GPIO_voidSetPinMode(GPIO_PORTA, 9, GPIO_PIN_MODE_AF_PP_10MHZ);
    GPIO_voidSetPinMode(GPIO_PORTA, 10, GPIO_PIN_MODE_PULLING_INPUT);


    /*********************Enable USART NVIC-Interupt********************/
    NVIC_voidInit();
    //37  44  settable   USART1USART1 global interrupt   0x0000_00D4
    NVIC_voidEnableInterrupt(37);



    //1.Enable the USART by writing the UE bit in USART_CR1 register to 1.
    SET_BIT(USART1_REG->CR1,13);

    /*2.Program the M (Word length) bit in USART_CR1 to define the word length.
    0: 1 Start bit, 8 Data bits, n Stop bit
    1: 1 Start bit, 9 Data bits, n Stop bit
    */
    CLR_BIT(USART1_REG->CR1,12);

    //3.Program the number of stop bits in USART_CR2.
    //1 stop bit: This is the default value.
    //00: 1 Stop bit, 01: 0.5 Stop bit, 10: 2 Stop bits ,11: 1.5 Stop bit
    CLR_BIT(USART1_REG->CR2,12);
    CLR_BIT(USART1_REG->CR2,13);

    //4.Select DMA enable (DMAT) in USART_CR3 if Multi buffer Communication 
    //is to take place. Configure the DMA register as explained in multibuffer communication.


    //5.Select the desired baud rate using the USART_BRR register.
    //10Mhz USART perferal, target 9600ps
    //1041.666d --> 1041d = 411h,  0.666*16 = 10.6d = 11d = Bh
    USART1_REG->BRR = 0x411<<4 | 0xB;


    /**************************TX*******************************/
    //6.Set the TE (Transmitter enable) bit in USART_CR1 to send an 
    //idle frame as first transmission.
    SET_BIT(USART1_REG->CR1,3);


    //Set the TXEIE (TXE interrupt enable) to enable the TXE to check
    //if the DR is empty before sending new data
    SET_BIT(USART1_REG->CR1,7);


    //Set the TCIE (Transmission complete interrupt enable) to enable the TC
    SET_BIT(USART1_REG->CR1,6);



    /**************************RX*******************************/
    //6.Set the RE(Receiver enable) bit USART_CR1. This enables the 
    //receiver which begins searching for a start bit.
    SET_BIT(USART1_REG->CR1,2);

    //Set the RXNEIE (RXNE interrupt enable) to enable the RXNE: to check
    //if the DR is not empty before reading new data
    SET_BIT(USART1_REG->CR1,7);

}



/*
* function to send data
*/
void USART_voidTx(u8 Copy_u8DataByte){

    /*7.Write the data to send in the USART_DR register 
      (this clears the TXE bit). Repeat this for each data to be transmitted 
      in case of single buffer.
    *TXE: Transmit data register empty
     0: Data is not transferred to the shift register
     1: Data is transferred to the shift register)
    * need to check if TXE is 1 first before writting new data to USART_DR
    */

   //check if TXE is 1 to continue sending
   while (!GET_BIT(USART1_REG->SR,7));
   
   USART1_REG->DR = Copy_u8DataByte;

}



/*
* function to send data by Interupt
* Ptr_u8DataBytesArray: array of data bytes
*/
void USART_voidTxInt(u8 *Ptr_u8DataBytesArray){
    Ptr_u8TxBytes = Ptr_u8DataBytesArray;

}

/*
*function not used by user
*/
void USART_voidTxIntSend(void){
    USART1_REG->DR = *Ptr_u8TxBytes;
    Ptr_u8TxBytes++;
}






/*
* function to check if last frame is sent before disableing USART
* return : 0 --> Transmission is not complete
           1 --> Transmission is complete
*/
u8 USART_u8TransmissionStatus(void){
    u8 TCstate = 0;
   /*
   8.After writing the last data into the USART_DR register, wait until TC=1. 
    This indicates that the transmission of the last frame is complete. 
    This is required for instance when the USART is disabled or enters 
    the Halt mode to avoid corrupting the last transmission.
    0: Transmission is not complete
    1: Transmission is complete
   */

    if(GET_BIT(USART1_REG->SR,6))
        TCstate = 1;
    
    return TCstate;

}



/*
* function to read recived data
*/
u8 USART_u8Rx(void){
    //RXNE: Read data register not empty
    //0: Data is not received
    //1: Received data is ready to be read.

    while(!GET_BIT(USART1_REG->SR,5));
    return USART1_REG->DR;
}



/*
* function to recive data by Interupt
* Ptr_u8DataByte: Pointer to the varible to read to.
*/
void USART_voidRxInt(u8 *Ptr_u8DataByte){
    Ptr_u8RxByte = Ptr_u8DataByte;
}

/*
*function not used by user
*/
void USART_voidRxIntSend(void){
    *Ptr_u8RxByte = USART1_REG->DR;
}



/*
* Interupt hundeler for Rx and Tx
*/
void USART1_IRQHandler(void){
    if(GET_BIT(USART1_REG->SR,7))
        USART_voidTxIntSend();
    
    if(GET_BIT(USART1_REG->SR,5))
        USART_voidRxIntSend();
}