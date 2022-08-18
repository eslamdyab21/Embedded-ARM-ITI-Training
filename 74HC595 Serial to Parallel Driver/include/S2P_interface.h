/*
 * S2P_interface.h
 *
 *  Created on: Aug 18, 2022
 *      Author: dyab
 */

#ifndef S2P_INTERFACE_H_
#define S2P_INTERFACE_H_


//Macros
#define PORTA   0
#define PORTB   1
#define PORTC   2

/*
* Function to intialize the pins as output
*/
void S2P_voidInit();


/*
* Function to send serial data
* Paramters: Copy_u8SerialData 8-bits
*/
void S2P_voidTx(u8 Copy_u8SerialData);


/*
* Function to Enable output
*/
void S2P_voidOutputEnable();


/*
* Function to Disable output
*/
void S2P_voidOutputDisable();


#endif /* S2P_INTERFACE_H_ */
