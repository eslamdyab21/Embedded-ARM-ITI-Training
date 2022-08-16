/*
 * SYSTICK_interface.h
 *
 *  Created on: Aug 16, 2022
 *      Author: dyab
 */

#ifndef SYSTICK_INTERFACE_H_
#define SYSTICK_INTERFACE_H_

//Macros
#define SYSTICK_AHB_8 		0
#define SYSTICK_AHB 		1




/*
 * STK_voidInit
 * description: Selects the clock source of the SysTick (AHB, AHB/8)
 */
void STK_voidInit(u8 Copy_u8ClkSRC);



#endif /* SYSTICK_INTERFACE_H_ */
