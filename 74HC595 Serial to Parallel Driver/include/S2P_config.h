/*
 * S2P_config.h
 *
 *  Created on: Aug 18, 2022
 *      Author: dyab
 */

#ifndef S2P_CONFIG_H_
#define S2P_CONFIG_H_


//Macros
//Choose one
// PortA
// PortB
// PortC
#define S2P_PORT                     PORTA


//Pins 
#define S2P_A_PIN                    0       //Serial Data Input
#define S2P_SHIFT_CLK_PIN            1
#define S2P_RESET_PIN                2
#define S2P_LATCH_CLK_PIN            3
#define S2P_OUTPUT_ENABLE_PIN        4


#endif /* S2P_CONFIG_H_ */
