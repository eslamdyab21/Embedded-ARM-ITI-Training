/*
 * SPI_config.h
 *
 *  Created on: Aug 24, 2022
 *      Author: dyab
 */

#ifndef SPI_CONFIG_H_
#define SPI_CONFIG_H_

//Macros

/*
Choose a frame size
    SPI_8BITS
    SPI_16BITS
*/
#define SPI_FRAME_SIZE  SPI_8BITS  


/*
Choose a mode
    SPI_CLK_MODE_0      //Clock Polarity = 0, Cock Phase = 0
    SPI_CLK_MODE_1      //Clock Polarity = 0, Cock Phase = 1
    SPI_CLK_MODE_2      //Clock Polarity = 1, Cock Phase = 0
    SPI_CLK_MODE_3      //Clock Polarity = 1, Cock Phase = 1
*/
#define SPI_CLK_MODE   SPI_CLK_MODE_0




#endif /* SPI_CONFIG_H_ */
