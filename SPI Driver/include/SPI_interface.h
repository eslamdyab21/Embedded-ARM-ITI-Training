/*
 * SPI_interface.h
 *
 *  Created on: Aug 24, 2022
 *      Author: dyab
 */

#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_


//Macros
//Data frmae size
#define SPI_8BITS    0
#define SPI_16BITS   1

//Clock Polarity and Cock Phase mode
#define SPI_CLK_MODE_0   0      //Clock Polarity = 0, Cock Phase = 0
#define SPI_CLK_MODE_1   1      //Clock Polarity = 0, Cock Phase = 1
#define SPI_CLK_MODE_2   2      //Clock Polarity = 1, Cock Phase = 0
#define SPI_CLK_MODE_3   3      //Clock Polarity = 1, Cock Phase = 1


/*
* Function to set the data frame size (8/16 bits)
* Paramters :
        Choose a frame size
            SPI_8BITS
            SPI_16BITS
*/
void SPI_voidDataFrameSize(void);



/*
* Function to configure the Clock Polarity and Cock Phase mode
* Paramters :
                
        Choose a mode in config
            SPI_CLK_MODE_0      //Clock Polarity = 0, Cock Phase = 0
            SPI_CLK_MODE_1      //Clock Polarity = 0, Cock Phase = 1
            SPI_CLK_MODE_2      //Clock Polarity = 1, Cock Phase = 0
            SPI_CLK_MODE_3      //Clock Polarity = 1, Cock Phase = 1

*/
void SPI_voidClkPolarityPhaseMode(void);

#endif /* SPI_INTERFACE_H_ */
