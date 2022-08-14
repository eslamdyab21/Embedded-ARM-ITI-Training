/*
 * NVIC_interface.h
 *
 *  Created on: Aug 8, 2022
 *      Author: dyab
 */

#ifndef NVIC_INTERFACE_H_
#define NVIC_INTERFACE_H_



/*
 * NVIC_voidEnableInterrupt
 * parameters: index of interrupt
 * description: Sets the NVIC enable pin for a specific interrupt
 */
void NVIC_voidEnableInterrupt(u8 Copy_u8InterruptPotiotion);


/*
 * NVIC_voidDisableInterrupt
 * parameters: index of interrupt
 * description: disable interrupts, and show which interrupts are enabled or disabled
 */
void NVIC_voidDisableInterrupt(u8 Copy_u8InterruptPotiotion);

/*
 * NVIC_voidSetPendingFlag
 * parameters: index of interrupt
 * description: force interrupts into the pending state, and show which 
                interrupts are pending
 */
void NVIC_voidSetPendingFlag(u8 Copy_u8InterruptPotiotion);


/*
 * NVIC_voidClearPendingFlag
 * parameters: index of interrupt
 * description: remove the pending state from interrupts, and show which
                interrupts are pending and which are not
 */
void NVIC_voidClearPendingFlag(u8 Copy_u8InterruptPotiotion);

/*
 * NVIC_u8GetActiveFlag
 * parameters: index of interrupt
 * return value: 0: not active or 1: active
 * description: indicate which interrupts are active
 */
u8 NVIC_u8GetActiveFlag(u8 Copy_u8InterruptPotiotion);


/*
 * NVIC_voidSetPriority
 * parameters: index of interrupt, GroupPriority and SubPriority
 * description: Sets the priority for a specific interrupt
 */
void NVIC_voidSetPriority(u8 Copy_u8InterruptPosition, u8 Copy_u8GroupPriority, u8 Copy_u8SubPriority);

#endif /* NVIC_INTERFACE_H_ */
