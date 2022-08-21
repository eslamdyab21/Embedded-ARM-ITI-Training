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
* function to enable sending data
*/
void USART_voidInitTx(void);

/*
* function to enable receving data
*/
void USART_voidInitRx(void);

/*
* function to send data
*/
void USART_voidTx(u8 Copy_u8DataByte);

/*
* function to read recived data
*/
u8 USART_u8Rx();


#endif /* USART_INTERFACE_H_ */
