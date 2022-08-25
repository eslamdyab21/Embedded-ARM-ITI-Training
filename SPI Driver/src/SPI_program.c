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
    CLR_BIT(SPI1_PERIPHERAL->CR1_REG,3);
    CLR_BIT(SPI1_PERIPHERAL->CR1_REG,4);
    CLR_BIT(SPI1_PERIPHERAL->CR1_REG,5);

    SPI1_PERIPHERAL->CR1_REG |= SPI_BAUD_RATE;
    
}