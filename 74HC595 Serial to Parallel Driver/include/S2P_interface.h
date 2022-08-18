/*
 * S2P_interface.h
 *
 *  Created on: Aug 18, 2022
 *      Author: dyab
 */

#ifndef S2P_INTERFACE_H_
#define S2P_INTERFACE_H_

//Macros

//Input (PORTA)
#define S2P_A_PIN                    0       //Serial Data Input
#define S2P_SHIFT_CLK_PIN            1
#define S2P_RESET_PIN                2
#define S2P_LATCH_CLK_PIN            3
#define S2P_OUTPUT_ENABLE_PIN        4




/*
* Function to send serial data
* Paramters: Copy_u8SerialData 8-bits
*/
void S2P_voidTx(u8 Copy_u8SerialData);


/*
* Function to Enable/Disable output
* Paramters: Copy_u8Status, 0 for Disable
*                           1 for Enable
*/
void S2P_voidOutputEnaleOrDisable(u8 Copy_u8Status);




#endif /* S2P_INTERFACE_H_ */
