/*
 * NVIC_interface.h
 *
 *  Created on: Aug 8, 2022
 *      Author: dyab
 */

#ifndef NVIC_INTERFACE_H_
#define NVIC_INTERFACE_H_


//The IPRx registers provide a 4-bit priority field for each interrupt
//So we can assign the groups the hole 4 bits (16 groups) leaving no bits for sub-priorities 
//Or split the 4 bits between the groups and sub-priorities 

// #define		NVIC_GROUP_4_BITS		0       //and 0 bits for sub-priorities (16 group, 0 sub-priorities)
// #define		NVIC_GROUP_3_BITS		1       //and 1 bits for sub-priorities (8 group, 2 sub-priorities)
// #define		NVIC_GROUP_2_BITS		2       //and 2 bits for sub-priorities (4 group, 4 sub-priorities)
// #define		NVIC_GROUP_1_BITS		3       //and 3 bits for sub-priorities (2 group, 8 sub-priorities)
// #define		NVIC_GROUP_0_BITS		4       //and 4 bits for sub-priorities (0 group, 16 sub-priorities)

//Another Implementation//
#define		NVIC_GROUP_4_BITS		0x05FA0300
#define		NVIC_GROUP_3_BITS		0x05FA0400
#define		NVIC_GROUP_2_BITS		0x05FA0500
#define		NVIC_GROUP_1_BITS		0x05FA0600
#define		NVIC_GROUP_0_BITS		0x05FA0700




/*
 * NVIC_voidInit
 * Parameters: void
 * description: Sets the Priority Model for group & sub-priorities 
 * SCP Work
 */
void NVIC_voidInit(void);


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
