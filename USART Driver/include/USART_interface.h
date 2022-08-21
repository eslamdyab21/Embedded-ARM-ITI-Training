/*
 * USART_interface.h
 *
 *  Created on: Aug 21, 2022
 *      Author: dyab
 */

#ifndef USART_INTERFACE_H_
#define USART_INTERFACE_H_




void USART_voidInit(void);

void USART_voidTx(u8 Copy_u8DataByte);

u8 USART_u8Rx();


#endif /* USART_INTERFACE_H_ */
