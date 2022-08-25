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

    SPI1_PERIPHERAL->CR1_REG |= SPI_BAUD_RATE<<3;
    
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
    NSS pin is in output mode
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
    switch (SPI_MASTER_CNTRL_MODE)
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




/*
* Function to set the controller as master
*/
void SPI_voidEnableMaster(void){
    //6.The MSTR and SPE bits must be set (they remain set only if the NSS pin 
    //is connected to a high-level signal).

    /*
    Bit 2 MSTR: Master selection
        0: Slave configuration
        1: Master configuration
    */

    SET_BIT(SPI1_PERIPHERAL->CR1_REG,2);
}


/*
* Function to enable SPI
*/
void SPI_voidEnableSPI(void){
    /*
    Bit 6 SPE: SPI enable
    0: Peripheral disabled
    1: Peripheral enabled
    */

    SET_BIT(SPI1_PERIPHERAL->CR1_REG,6);
}


/*
* Function to disable SPI
*/
void SPI_voidDisableSPI(void){
    /*
    Bit 6 SPE: SPI enable
    0: Peripheral disabled
    1: Peripheral enabled
    */

    CLR_BIT(SPI1_PERIPHERAL->CR1_REG,6);
}


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


    
    
    //Transmit sequence: 
    //Enable TXE interrupt (Tx Frame Complete)
    SPI_voidTxeInt();

    //Enable RXNE interrupt (Rx Frame Complete)
    SPI_voidRxeInt();

    //6.The MSTR and SPE bits must be set (they remain set only if the NSS pin 
    //is connected to a high-level signal).
    SPI_voidEnableMaster();

    //7. enable SPI
    SPI_voidEnableSPI();


    

}


/*
* Function to Transmit data
*/
void SPI_voidTx(u16 Copy_u16TxData){
    SPI1_PERIPHERAL->DR_REG = Copy_u16TxData;
}


/*
* Function to Receive data
*/
u16 SPI_16Rx(void){
    return SPI1_PERIPHERAL->DR_REG;
}






/*
* Function to Enable/Disale TXE interrupt (Tx Frame Complete)
* Paramters :
    SPI_TXE_INT
        Choose a state in config
            SPI_ENABLE_INT 
            SPI_DISABLE_INT 
*/
void SPI_voidTxeInt(void){
    /*
    Bit 7 TXEIE: Tx buffer empty interrupt enable(CR2)
        0: TXE interrupt masked
        1: TXE interrupt not masked. Used to generate an interrupt 
            request when the TXE flag is set.
        */
    SET_BIT(SPI1_PERIPHERAL->CR2_REG,7);
}





/*
* Function to check if frame is transmited (Enable TXE first)
* Returns :
    1: frame is transferd so you can send a new frame
    0: frame is not transferd yet so you need to wait before sending a new frame
*/
u8 SPI_boolIsTxFrameComplete(void){
    /*
    Bit 1 TXE: Transmit buffer empty(SR)
        0: Tx buffer not empty
        1: Tx buffer empty
    */

    return GET_BIT(SPI1_PERIPHERAL->SR_REG,1);
}




/*
* Function to Enable/Disale RXNE interrupt (Rx Frame Complete)
* Paramters :
    SPI_RXNE_INT
        Choose a state in config
            SPI_ENABLE_INT 
            SPI_DISABLE_INT 
*/
void SPI_voidRxeInt(void){

    /*
    Bit 6 RXNEIE: RX buffer not empty interrupt enable
        0: RXNE interrupt masked
        1: RXNE interrupt not masked. Used to generate an interrupt 
           request when the RXNE flag is set.
    */

    SET_BIT(SPI1_PERIPHERAL->CR2_REG,6);
}




/*
* Function to check if frame is recived (Enable RXNE first)
* Returns :
    1: frame is recived so you can recive a new frame
    0: frame is not recived yet so you need to wait before reciving a new frame
*/
u8 SPI_boolIsRxFrameComplete(void){
    /*
    Bit 0 RXNE: Receive buffer not empty
        0: Rx buffer empty
        1: Rx buffer not empty
    */

    return GET_BIT(SPI1_PERIPHERAL->SR_REG,0);
}





/*
* Function to set the Communication Protocol
* Paramters :
    Choose a mode
    SPI_COMMUNICATION_PROTCOL
        SPI_FULL_DUBLEX                   
        SPI_UNI_DIRCTION_RESEIVE_ONLY     
        SPI_BIDIRCTIONAL_TX               
        SPI_BIDIRCTIONAL_RX               
*/
void SPI_voidCommunicationProtocol(void){

    //(BIDIMODE and RXONLY)
    /*
    Bit 15 BIDIMODE: Bidirectional data mode enable
        0: 2-line unidirectional data mode selected
        1: 1-line bidirectional data mode selected
    */

    /*
    Bit 10 RXONLY: Receive only
        This bit combined with the BIDImode bit selects the direction of 
        transfer in 2-line unidirectional mode. This bit is also useful in 
        a multislave system in which this particular slave is not accessed, 
        the output from the accessed slave is not corrupted.
            0: Full duplex (Transmit and receive)
            1: Output disabled (Receive-only mode)
    */


    CLR_BIT(SPI1_PERIPHERAL->CR1_REG,10);
    CLR_BIT(SPI1_PERIPHERAL->CR1_REG,15);


    switch (SPI_COMMUNICATION_PROTCOL)
    {
    case SPI_FULL_DUBLEX:
        CLR_BIT(SPI1_PERIPHERAL->CR1_REG,10);
        CLR_BIT(SPI1_PERIPHERAL->CR1_REG,15);
        break;

    case SPI_UNI_DIRCTION_RESEIVE_ONLY:
        CLR_BIT(SPI1_PERIPHERAL->CR1_REG,15);
        SET_BIT(SPI1_PERIPHERAL->CR1_REG,10);
        break;
    
    case SPI_BIDIRCTIONAL_TX:
        SET_BIT(SPI1_PERIPHERAL->CR1_REG,15);
        SET_BIT(SPI1_PERIPHERAL->CR1_REG,10);
        break;
    
    case SPI_BIDIRCTIONAL_RX:
        SET_BIT(SPI1_PERIPHERAL->CR1_REG,15);
        CLR_BIT(SPI1_PERIPHERAL->CR1_REG,10);
        break;
    }
}