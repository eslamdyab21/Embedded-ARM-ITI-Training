/*
 * GPIO_private.h
 *
 *  Created on: Aug 4, 2022
 *      Author: Eslam Dyab
 */

#ifndef GPIO_PRIVATE_H_
#define GPIO_PRIVATE_H_


typedef struct{
	volatile u32 CRL;
	volatile u32 CRH;
	volatile u32 IDR;
	volatile u32 ODR;
	volatile u32 BSRR;
	volatile u32 BRR;
	volatile u32 LCKR;
}GPIO_Port_t;

// PORTA base address: 0x40010800
#define REG_GPIO_PORTA				((volatile GPIO_Port_t*) 0x40010800)
// PORTB base address: 0x40010C00
#define REG_GPIO_PORTB				((volatile GPIO_Port_t*) 0x40010C00)
// PORTC base address: 0x40011000
#define REG_GPIO_PORTC				((volatile GPIO_Port_t*) 0x40011000)



#endif /* GPIO_PRIVATE_H_ */
