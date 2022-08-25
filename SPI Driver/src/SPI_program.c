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



/*
* Function to set the data frame size (8/16 bits)
* Paramters :
    SPI_FRAME_SIZE
        Choose a frame size in config
            SPI_8BITS
            SPI_16BITS
*/
void SPI_voidDataFrameSize(void){
    //3.Set the DFF bit to define 8- or 16-bit data frame size
    //DFF: Data frame format
    /*
    0: 8-bit data frame format is selected for transmission/reception
    1: 16-bit data frame format is selected for transmission/reception
    */

    switch (SPI_FRAME_SIZE)
    {
    case SPI_8BITS:
        CLR_BIT(SPI1_PERIPHERAL->CR1_REG,11);
        break;
    
    case SPI_16BITS:
        SET_BIT(SPI1_PERIPHERAL->CR1_REG,11);
        break;
    }
    
}




/*
* Function to set the frame format (MSB-first or LSB-first)
* Paramters :
    SPI_FRAME_FORMAT
        Choose a format in config
            SPI_MSB_FIRST   
            SPI_LSB_FIRST 
*/
void SPI_voidDataFrameFormat(void){
    //4.Configure the LSBFIRST bit in the SPI_CR1 register to 
    //define the frame format.

    /*
    Bit 7 LSBFIRST: Frame format
    0: MSB transmitted first
    1: LSB transmitted first
    */

    switch (SPI_FRAME_FORMAT)
    {
    case SPI_MSB_FIRST:
        CLR_BIT(SPI1_PERIPHERAL->CR1_REG,7);
        break;
    
    case SPI_LSB_FIRST:
        SET_BIT(SPI1_PERIPHERAL->CR1_REG,7);
        break;
    }
}





/*
* Function to set the Master managment mode (HW or SW mode)
* Paramters :
    SPI_BAUD_RATE
        Choose a mode in config
            SPI_MASTER_HW_MODE   
            SPI_MASTER_SW_MODE 
*/
void SPI_voidMasterManagmentMode(void){
    /*
            ---Hardware NSS management (SSM = 0)---
    NSS output enabled (SSM = 0, SSOE = 1)
    This configuration is used only when the device operates in master mode. The
    NSS signal is driven low when the master starts the communication and is kept
    low until the SPI is disabled.
    */

    /*
            ---Software NSS management (SSM = 1)---
    The slave select information is driven internally by the value of the SSI bit 
    in the SPI_CR1 register. The external NSS pin remains free for other 
    application uses.
    */

    /*
    Bit 9 SSM: Software slave management(CR1)
        When the SSM bit is set, the NSS pin input is replaced with 
        the value from the SSI bit.
        0: Software slave management disabled
        1: Software slave management enabled
    */

    /*
    Bit 2 SSOE: SS output enable(CR2)
        0: SS output is disabled in master mode and the cell can 
        work in multimaster configuration

        1: SS output is enabled in master mode and when the cell 
        is enabled. The cell cannot work in a multimaster environment.
    */
    switch (SPI_BAUD_RATE)
    {
    case SPI_MASTER_HW_MODE:
        CLR_BIT(SPI1_PERIPHERAL->CR1_REG,9);

        SET_BIT(SPI1_PERIPHERAL->CR2_REG,2);
        break;

    case SPI_MASTER_SW_MODE:
        SET_BIT(SPI1_PERIPHERAL->CR1_REG,9);
        break;

    }
}