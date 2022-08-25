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
    GPIO_voidSetPinMode(GPIO_PORTA, 6, GPIO_PIN_MODE_PULLING_INPUT);


    GPIO_voidSetPinMode(GPIO_PORTA, 0, GPIO_PIN_MODE_GP_PP_10MHZ);
    GPIO_voidSetPinValue(GPIO_PORTA,0,GPIO_LOW);


    /*********************Enable USART NVIC-Interupt********************/
    NVIC_voidInit();
    //35    42  settable    SPI1    SPI1 global interrupt   0x0000_00CC
    NVIC_voidEnableInterrupt(35);
}



int main(void){

    u8 byteTx = 'c';
    u8 byteRx = 0;
    u32 i = 0;

    RCC_GPIO_NVIC_voidInit();
    SPI_voidMasterInit();

    SPI_voidTx(byteTx);

    while(1){
        if(SPI_boolIsTxFrameComplete())
            SPI_voidTx(byteTx);

        if(SPI_boolIsRxFrameComplete())
            byteRx = SPI_16Rx();

 
        for(i=0; i <1000000; i++);
        GPIO_voidSetPinValue(GPIO_PORTA,0,GPIO_HIGH);
        for(i=0; i <1000000; i++);
        GPIO_voidSetPinValue(GPIO_PORTA,0,GPIO_LOW);
    }


    return 0;
}