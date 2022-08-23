/*
 * DMA_private.h
 *
 *  Created on: Aug 23, 2022
 *      Author: dyab
 */

#ifndef DMA_PRIVATE_H_
#define DMA_PRIVATE_H_


typedef struct{
    volatile u32 CCR;
    volatile u32 CNDTR;
    volatile u32 CPAR;
    volatile u32 CMAR;
    volatile u32 RES;

}DMA_CHANNEL_t;


typedef struct{
    volatile u32 ISR;
    volatile u32 IFCR;

    volatile DMA_CHANNEL_t CHANNEL[7];

}DMA_REG_t;


// DMA1 base address: 0x40020000
#define DMA1_REG	((volatile DMA_REG_t*) 0x40020000)


#endif /* DMA_PRIVATE_H_ */
