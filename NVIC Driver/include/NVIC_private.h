/*
 * NVIC_private.h
 *
 *  Created on: Aug 8, 2022
 *      Author: dyab
 */

#ifndef NVIC_PRIVATE_H_
#define NVIC_PRIVATE_H_


#define NVIC_BASE_ADDRESS  0xE00E100
#define SCB_BASE_ADDRESS   0xE000ED00


//Interrupt set-enable registers
#define NVIC_ISER0          *((volatile u32 *)  (NVIC_BASE_ADDRESS+0x000))
#define NVIC_ISER1	        *((volatile u32 *)  (NVIC_BASE_ADDRESS+0x004))


//Interrupt clear-enable registers
#define NVIC_ICER0          *((volatile u32 *) (NVIC_BASE_ADDRESS+0x080))
#define NVIC_ICER1	        *((volatile u32 *) (NVIC_BASE_ADDRESS+0x084))


//Interrupt set-pending registers
#define NVIC_ISPR0			*((volatile u32 *) (NVIC_BASE_ADDRESS+0x100))
#define NVIC_ISPR1			*((volatile u32 *) (NVIC_BASE_ADDRESS+0x104))


//Interrupt clear-pending registers
#define NVIC_ICPR0			*((volatile u32 *) (NVIC_BASE_ADDRESS+0x180))
#define NVIC_ICPR1			*((volatile u32 *) (NVIC_BASE_ADDRESS+0x184))


//Interrupt active bit registers
#define NVIC_IABR0			*((volatile u32 *) (NVIC_BASE_ADDRESS+0x200))
#define NVIC_IABR1			*((volatile u32 *) (NVIC_BASE_ADDRESS+0x204))

//Interrupt priority registers
//no * because we will use it as a pointer to access it array-like (NVIC_IPR[0],NVIC_IPR[1],...)
#define NVIC_IPR			((volatile u8 *) (NVIC_BASE_ADDRESS+0x300))

#define NVIC_STIR			*((volatile u32 *) (NVIC_BASE_ADDRESS+0xE00))


//System Control Block
//Application interrupt and reset control register (SCB_AIRCR)
//The AIRCR provides priority grouping control
#define SCB_AIRCR			*((volatile u32 *) (SCB_BASE_ADDRESS+0x0C))


#endif /* NVIC_PRIVATE_H_ */
