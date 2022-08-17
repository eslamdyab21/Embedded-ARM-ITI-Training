/*
 * RCC_private.h
 *
 *  Created on: Aug 2, 2022
 *      Author: BluRay
 */

#ifndef RCC_PRIVATE_H_
#define RCC_PRIVATE_H_

////in ARM

#define RCC_START_ADDRESS 0x40021000/////from memory mapping
#define RCC_CR            *((volatile u32*)(RCC_START_ADDRESS+0x00))
#define RCC_CFGR          *((volatile u32*)(RCC_START_ADDRESS+0x04))
#define RCC_CIR           *((volatile u32*)(RCC_START_ADDRESS+0x08))
#define RCC_APB2RSTR      *((volatile u32*)(RCC_START_ADDRESS+0x0c))
#define RCC_APB1RSTR      *((volatile u32*)(RCC_START_ADDRESS+0x10))
#define RCC_AHBENR        *((volatile u32*)(RCC_START_ADDRESS+0x14))
#define RCC_APB2ENR       *((volatile u32*)(RCC_START_ADDRESS+0x18))
#define RCC_APB1ENR       *((volatile u32*)(RCC_START_ADDRESS+0x1c))
#define RCC_BDCR          *((volatile u32*)(RCC_START_ADDRESS+0x20))
#define RCC_CSR           *((volatile u32*)(RCC_START_ADDRESS+0x24))


/*

/// in AVR
 *
 *
#define PORTA *((u8) 0x40)
#define PORTA *((volatile u8 *)0x19)

//Reg. is place in RAM
//hwa shaif rkm blnsbalo da int fhn3ml casting n2ol eno pointer
// derfrence of it by 1st *
// eh volatile de 3shan lw tlbto kter mi2lbosh const w y store it in flash i want it in ram so we write volatile elli hwa ro7 hatha mn el ram msh 3wzha bsor3a la
PORTA = 0b1011001;
*((u8 *)0x19) = 0b1011001; //correct

we use volatile :
volatile int x; // stored in cache
if not written volatile and i used it as read only then it will store x as const.
we write volatile to make sure that it can be changed [stored in ram]
*/
#endif /* RCC_PRIVATE_H_ */
