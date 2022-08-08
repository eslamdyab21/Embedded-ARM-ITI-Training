/*
 * NVIC_program.c
 *
 *  Created on: Aug 8, 2022
 *      Author: dyab
 */

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"


/*
 * NVIC_voidEnableInterrupt
 * parameters: index of interrupt
 * description: Sets the NVIC enable pin for a specific interrupt
 */
void NVIC_voidEnableInterrupt(u8 Copy_u8InterruptPotiotion){
    if(Copy_u8InterruptPotiotion < 32)
        NVIC_ISER0 = 1 << Copy_u8InterruptPotiotion;
    else if(Copy_u8InterruptPotiotion < 60)
        NVIC_ISER1 = 1 << (Copy_u8InterruptPotiotion - 32);
}


/*
 * NVIC_voidDisableInterrupt
 * parameters: index of interrupt
 * description: disable interrupts, and show which interrupts are enabled or disabled
 */
void NVIC_voidDisableInterrupt(u8 Copy_u8InterruptPotiotion){
    if(Copy_u8InterruptPotiotion < 32)
		NVIC_ICER0 = 1 << Copy_u8InterruptPotiotion;
    else if(Copy_u8InterruptPotiotion < 60)
		NVIC_ICER1 = 1 << (Copy_u8InterruptPotiotion - 32);
}


/*
 * NVIC_voidSetPendingFlag
 * parameters: index of interrupt
 * description: force interrupts into the pending state, and show which 
                interrupts are pending
 */
void NVIC_voidSetPendingFlag(u8 Copy_u8InterruptPotiotion){
    if(Copy_u8InterruptPotiotion < 32)
		NVIC_ISPR0 = 1 << Copy_u8InterruptPotiotion;
    else if(Copy_u8InterruptPotiotion < 60)
		NVIC_ISPR1 = 1 << (Copy_u8InterruptPotiotion - 32);
}


/*
 * NVIC_voidClearPendingFlag
 * parameters: index of interrupt
 * description: remove the pending state from interrupts, and show which
                interrupts are pending and which are not
 */
void NVIC_voidClearPendingFlag(u8 Copy_u8InterruptPotiotion){
    if(Copy_u8InterruptPotiotion < 32)
		NVIC_ICPR0 = 1 << Copy_u8InterruptPotiotion;
    else if(Copy_u8InterruptPotiotion < 60)
		NVIC_ICPR1 = 1 << (Copy_u8InterruptPotiotion - 32);
}


/*
 * NVIC_u8GetActiveFlag
 * parameters: index of interrupt
 * return value: 0: not active or 1: active
 * description: indicate which interrupts are active
 */
u8 NVIC_u8GetActiveFlag(u8 Copy_u8InterruptPotiotion);
