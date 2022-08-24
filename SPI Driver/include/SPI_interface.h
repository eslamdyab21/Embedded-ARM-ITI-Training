/*
 * SPI_interface.h
 *
 *  Created on: Aug 24, 2022
 *      Author: dyab
 */

#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_


/*
* Function to set the data frame size (8/16 bits)
* Paramters: Copy_u8FramSize :
                            SPI_8BITS    0
                            SPI_16BITS   1
*/
void SPI_voidDataFrameSize(u8 Copy_u8FramSize);



/*
* Function to configure the Clock Polarity and Cock Phase mode
* Paramters: Copy_u8FramSize :
                SPI_CLK_MODE_0      //Clock Polarity = 0, Cock Phase = 0
                SPI_CLK_MODE_1      //Clock Polarity = 0, Cock Phase = 1
                SPI_CLK_MODE_2      //Clock Polarity = 1, Cock Phase = 0
                SPI_CLK_MODE_3      //Clock Polarity = 1, Cock Phase = 1
*/
void SPI_voidClkPolarityPhaseMode(u8 Copy_u8ClkMode);

#endif /* SPI_INTERFACE_H_ */
