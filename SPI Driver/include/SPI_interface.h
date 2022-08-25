/*
 * SPI_interface.h
 *
 *  Created on: Aug 24, 2022
 *      Author: dyab
 */

#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_



//+++++++++++++++++++++++++++++++++++BOTH++++++++++++++++++++++++++++++++
//Macros
//Data frmae size
#define SPI_8BITS    0
#define SPI_16BITS   1

//Clock Polarity and Cock Phase mode
#define SPI_CLK_MODE_0   0b00      //Clock Polarity = 0, Cock Phase = 0
#define SPI_CLK_MODE_1   0b01      //Clock Polarity = 0, Cock Phase = 1
#define SPI_CLK_MODE_2   0b10      //Clock Polarity = 1, Cock Phase = 0
#define SPI_CLK_MODE_3   0b11      //Clock Polarity = 1, Cock Phase = 1


//frame format (MSB-first or LSB-first)
#define SPI_MSB_FIRST   0
#define SPI_LSB_FIRST   1


//Enable/Disale TXE interrupt
#define SPI_ENABLE_INT  1
#define SPI_DISABLE_INT 0


//Enable/Disale RXNE interrupt
#define SPI_ENABLE_INT  1
#define SPI_DISABLE_INT 0


//Communication Protocol         (BIDIMODE=0 and RXONLY=0)
#define SPI_FULL_DUBLEX                   0b00
#define SPI_UNI_DIRCTION_RESEIVE_ONLY     0b01
#define SPI_BIDIRCTIONAL_TX               0b11
#define SPI_BIDIRCTIONAL_RX               0b10
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++







//+++++++++++++++++++++++++++++++++++SLAVE++++++++++++++++++++++++++++++++
//Slave managment mode (HW or SW mode)
#define SPI_SLAVE_HW_MODE     0
#define SPI_SLAVE_SW_MODE     1
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++




//+++++++++++++++++++++++++++++++++++MASTER++++++++++++++++++++++++++++++++
//Macros

//Baud rate control
#define SPI_BAUD_RATE_F_2       0b000
#define SPI_BAUD_RATE_F_4       0b001
#define SPI_BAUD_RATE_F_8       0b010
#define SPI_BAUD_RATE_F_16      0b011
#define SPI_BAUD_RATE_F_32      0b100
#define SPI_BAUD_RATE_F_64      0b101
#define SPI_BAUD_RATE_F_128     0b110
#define SPI_BAUD_RATE_F_256     0b111


//Master managment mode (HW or SW mode)
#define SPI_MASTER_HW_MODE     0
#define SPI_MASTER_SW_MODE     1
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++





//+++++++++++++++++++++++++++++++++++BOTH++++++++++++++++++++++++++++++++
/*
* Function to set the data frame size (8/16 bits)
* Paramters :
    SPI_FRAME_SIZE
        Choose a frame size in config
            SPI_8BITS
            SPI_16BITS
*/
void SPI_voidDataFrameSize(void);



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
void SPI_voidClkPolarityPhaseMode(void);




/*
* Function to set the frame format (MSB-first or LSB-first)
* Paramters :
    SPI_FRAME_FORMAT
        Choose a format in config
            SPI_MSB_FIRST   
            SPI_LSB_FIRST 
*/
void SPI_voidDataFrameFormat(void);



/*
* Function to enable SPI
*/
void SPI_voidEnableSPI(void);


/*
* Function to disable SPI
*/
void SPI_voidDisableSPI(void);



/*
* Function to Transmit data
*/
void SPI_voidTx(u16 Copy_u16TxData);


/*
* Function to Receive data
*/
u16 SPI_u16Rx(void);





/*
* Function to check if frame is transmited (Enable TXE first)
* Returns :
    1: frame is transferd so you can send a new frame
    0: frame is not transferd yet so you need to wait before sending a new frame
*/
u8 SPI_boolIsTxFrameComplete(void);




/*
* Function to check if frame is recived (Enable RXNE first)
* Returns :
    1: frame is recived so you can recive a new frame
    0: frame is not recived yet so you need to wait before reciving a new frame
*/
u8 SPI_boolIsRxFrameComplete(void);




/*
* Function to set the Communication Protocol
* Paramters :
    SPI_COMMUNICATION_PROTCOL
    Choose a mode
        SPI_FULL_DUBLEX                   
        SPI_UNI_DIRCTION_RESEIVE_ONLY     
        SPI_BIDIRCTIONAL_TX               
        SPI_BIDIRCTIONAL_RX               
*/
void SPI_voidCommunicationProtocol(void);
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++







//+++++++++++++++++++++++++++++++++++SLAVE++++++++++++++++++++++++++++++++
/*
* Function to set the Slave managment mode (HW or SW mode)
* Paramters :
        Choose a mode in config
            SPI_HW_MODE   
            SPI_SW_MODE 
*/
void SPI_voidSlaveManagmentMode(void);


/*
* Function to set the controller as slave
*/
void SPI_voidEnableSlave(void);
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++








//+++++++++++++++++++++++++++++++++++MASTER++++++++++++++++++++++++++++++++
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
void SPI_voidBaudRateClk(void);



/*
* Function to set the Master managment mode (HW or SW mode)
* Paramters :
    SPI_BAUD_RATE
        Choose a mode in config
            SPI_MASTER_HW_MODE   
            SPI_MASTER_SW_MODE 
*/
void SPI_voidMasterManagmentMode(void);



/*
* Function to set the controller as master
*/
void SPI_voidEnableMaster(void);


/*
* Master Init Function
*/
void SPI_voidMasterInit(void);
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


#endif /* SPI_INTERFACE_H_ */
