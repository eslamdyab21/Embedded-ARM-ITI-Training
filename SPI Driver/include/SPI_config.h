/*
 * SPI_config.h
 *
 *  Created on: Aug 24, 2022
 *      Author: dyab
 */

#ifndef SPI_CONFIG_H_
#define SPI_CONFIG_H_

//+++++++++++++++++++++++++++++++++++BOTH++++++++++++++++++++++++++++++++
//Macros

//Data frmae size
/*
Choose a frame size
    SPI_8BITS
    SPI_16BITS
*/
#define SPI_FRAME_SIZE  SPI_8BITS  




//Clock Polarity and Cock Phase mode
/*
Choose a mode
    SPI_CLK_MODE_0      //Clock Polarity = 0, Cock Phase = 0
    SPI_CLK_MODE_1      //Clock Polarity = 0, Cock Phase = 1
    SPI_CLK_MODE_2      //Clock Polarity = 1, Cock Phase = 0
    SPI_CLK_MODE_3      //Clock Polarity = 1, Cock Phase = 1
*/
#define SPI_CLK_MODE   SPI_CLK_MODE_0




//frame format (MSB-first or LSB-first)
/*
Choose a format
    SPI_MSB_FIRST   
    SPI_LSB_FIRST   
*/
#define SPI_FRAME_FORMAT    SPI_MSB_FIRST
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++






//+++++++++++++++++++++++++++++++++++SLAVE++++++++++++++++++++++++++++++++
//Slave managment mode (HW or SW mode)
/*
Choose a format
    SPI_SLAVE_HW_MODE   
    SPI_SLAVE_SW_MODE  
*/
#define SPI_SLAVE_CNTRL_MODE    SPI_SLAVE_HW_MODE
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++






//+++++++++++++++++++++++++++++++++++MASTER++++++++++++++++++++++++++++++++
//Macros

//Baud rate control F_x ---> F/x
/*
Choose a Baud rate
    SPI_BAUD_RATE_F_2       
    SPI_BAUD_RATE_F_4       
    SPI_BAUD_RATE_F_8       
    SPI_BAUD_RATE_F_16      
    SPI_BAUD_RATE_F_32      
    SPI_BAUD_RATE_F_64    
    SPI_BAUD_RATE_F_128     
    SPI_BAUD_RATE_F_256
*/
#define SPI_BAUD_RATE   SPI_BAUD_RATE_F_2


//Master managment mode (HW or SW mode)
/*
Choose a mode
    SPI_MASTER_HW_MODE   
    SPI_MASTER_SW_MODE  
*/
#define SPI_MASTER_CNTRL_MODE    SPI_MASTER_HW_MODE



#endif /* SPI_CONFIG_H_ */
