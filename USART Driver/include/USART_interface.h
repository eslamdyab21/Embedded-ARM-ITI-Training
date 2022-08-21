/*
 * USART_interface.h
 *
 *  Created on: Aug 21, 2022
 *      Author: dyab
 */

#ifndef USART_INTERFACE_H_
#define USART_INTERFACE_H_


/*
Interrupt event                  Event flag      Enable Control bit
-----------------------------------------------------------------------
Transmit data register empty        TXE               TXEIE
Transmission complete               TC                TCIE
*/




/*
* Init Function
*/
void USART_voidInit(void);


/*
* function to send data
*/
void USART_voidTx(u8 Copy_u8DataByte);

/*
* function to check if last frame is sent before disableing USART
* return : 0 --> Transmission is not complete
           1 --> Transmission is complete
*/
u8 USART_u8TransmissionStatus(void);


/*
* function to read recived data
*/
u8 USART_u8Rx();


#endif /* USART_INTERFACE_H_ */
