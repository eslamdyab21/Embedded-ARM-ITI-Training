/*
 * SPI_program.c
 *
 *  Created on: Aug 24, 2022
 *      Author: dyab
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_config.h"



/*
* Function to define the serial clock baud rate
* Paramters :
    SPI_BAUD_RATE
        Choose a Baud rate in config
            SPI_BAUD_RATE_F_2       
            SPI_BAUD_RATE_F_4       
            SPI_BAUD_RATE_F_8       
            SPI_BAUD_RATE_F_16      
            SPI_BAUD_RATE_F_32      
            SPI_BAUD_RATE_F_64    
            SPI_BAUD_RATE_F_128     
            SPI_BAUD_RATE_F_256
*/
void SPI_voidBaudRateClk(void){
    //1.Select the BR[2:0] bits to define the serial clock baud rate 
    //(see SPI_CR1 register)
    //BR[2:0]: Baud rate control

    CLR_BIT(SPI1_PERIPHERAL->CR1_REG,3);
    CLR_BIT(SPI1_PERIPHERAL->CR1_REG,4);
    CLR_BIT(SPI1_PERIPHERAL->CR1_REG,5);

    SPI1_PERIPHERAL->CR1_REG |= SPI_BAUD_RATE;
    
}



/*
* Function to configure the Clock Polarity and Cock Phase mode
* Paramters :
    SPI_CLK_MODE            
        Choose a mode in config
            SPI_CLK_MODE_0      //Clock Polarity = 0, Cock Phase = 0
            SPI_CLK_MODE_1      //Clock Polarity = 0, Cock Phase = 1
            SPI_CLK_MODE_2      //Clock Polarity = 1, Cock Phase = 0
            SPI_CLK_MODE_3      //Clock Polarity = 1, Cock Phase = 1

*/
void SPI_voidClkPolarityPhaseMode(void){
    //2.Select the CPOL and CPHA bits to define one of the four relationships 
    //between the data transfer and the serial clock

    //CPOL: Clock polarity
    //CPHA: Clock phase

    CLR_BIT(SPI1_PERIPHERAL->CR1_REG,0);
    CLR_BIT(SPI1_PERIPHERAL->CR1_REG,1);

    SPI1_PERIPHERAL->CR1_REG |= SPI_CLK_MODE;

}