/*
 * NVIC_private.h
 *
 *  Created on: Aug 8, 2022
 *      Author: dyab
 */

#ifndef NVIC_PRIVATE_H_
#define NVIC_PRIVATE_H_


#define NVIC_BASE_ADDRESS  0xE00E100


#define NVIC_ISER0	*((volatile u32 *)  (NVIC_BASE_ADDRESS + 0x000) )
#define NVIC_ISER1	*((volatile u32 *)  (NVIC_BASE_ADDRESS + 0x004) )
#define NVIC_ISER2	*((volatile u32 *)  (NVIC_BASE_ADDRESS + 0x008) )





#endif /* NVIC_PRIVATE_H_ */
