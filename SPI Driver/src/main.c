/*
 * main.c
 *
 *  Created on: Aug 24, 2022
 *      Author: dyab
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SPI_interface.h"

#include "RCC Driver/RCC_interface.h"
#include "GPIO/GPIO_interface.h"
#include "NVIC Driver/NVIC_interface.h"


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


    

}


void RCC_GPIO_NVIC_voidInit(void){
    /**************************RCC/GPIO*******************************/
    RCC_voidInit();
	RCC_voidPeripheralClockEnable(RCC_APB2, GPIOA);
	RCC_voidPeripheralClockEnable(RCC_APB2, SPI1);

    /*
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


    GPIO_voidSetPinMode(GPIO_PORTA, 0, GPIO_PIN_MODE_GP_PP_10MHZ);
    GPIO_voidSetPinValue(GPIO_PORTA,0,GPIO_LOW);
    GPIO_voidSetPinMode(GPIO_PORTA, 1, GPIO_PIN_MODE_GP_PP_10MHZ);
    GPIO_voidSetPinValue(GPIO_PORTA,1,GPIO_LOW);

    /*********************Enable USART NVIC-Interupt********************/
    NVIC_voidInit();
    //35    42  settable    SPI1    SPI1 global interrupt   0x0000_00CC
    NVIC_voidEnableInterrupt(35);
}



int main(void){

    u8 byteTx = 0;
    u8 byteRx = 0;

    u16 byte0 = 0x0000;
    u32 i = 0;
    u32 counter = 0;

    RCC_GPIO_NVIC_voidInit();
    SPI_voidMasterInit();

    //00000101

    //SPI_voidTx(5);
    while(1){
        
        SPI_voidTx(byteTx);
        while(!SPI_boolIsTxFrameComplete());


        for(i=0; i <10000; i++);
        GPIO_voidSetPinValue(GPIO_PORTA,0,GPIO_HIGH);
        for(i=0; i <10000; i++);
        GPIO_voidSetPinValue(GPIO_PORTA,0,GPIO_LOW);
        

        counter++;
        if(counter > 20){
            byteTx++;
            if(byteTx > 50)
                byteTx = 0;
            
            counter = 0;

            for(i=0; i <1000; i++);
            GPIO_voidSetPinValue(GPIO_PORTA,1,GPIO_HIGH);
            for(i=0; i <1000; i++);
            GPIO_voidSetPinValue(GPIO_PORTA,1,GPIO_LOW);
            
        }

        //SPI_voidTx(byte0);
        //while(!SPI_boolIsTxFrameComplete());
    }


    return 0;
}