/*
 * S2P_interface.h
 *
 *  Created on: Aug 18, 2022
 *      Author: dyab
 */

#ifndef S2P_INTERFACE_H_
#define S2P_INTERFACE_H_

//Macros

//Input (PORTB)
#define S2P_A_PIN                    3       //Serial Data Input
#define S2P_SHIFT_CLK_PIN            4
#define S2P_RESET_PIN                5
#define S2P_LATCH_CLK_PIN            6
#define S2P_OUTPUT_ENABLE_PIN        7



//Output (PORTA)
#define S2P_QA  0
#define S2P_QB  1
#define S2P_QC  2
#define S2P_QD  3
#define S2P_QE  4
#define S2P_QF  5
#define S2P_QG  6
#define S2P_QH  7



/*
* Function to set the clock speed for the latch and the shift register
* Paramters: Copy_u8ShiftClkSpeed and Copy_u8LatchClkSpeed
*            in ms
*/
void S2P_voidInit(u8 Copy_u8ShiftClkSpeed, u8 Copy_u8LatchClkSpeed);

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
