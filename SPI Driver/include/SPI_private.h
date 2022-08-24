/*
 * SPI_private.h
 *
 *  Created on: Aug 24, 2022
 *      Author: dyab
 */

#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_


typedef struct{
    volatile u32 CR1_REG;
    volatile u32 CR2_REG;
    volatile u32 SR_REG;
    volatile u32 DR_REG;
    volatile u32 CRCPR_REG;
    volatile u32 RXCRCR_REG;
    volatile u32 TXCRCR_REG;
    volatile u32 I2SCFGR_REG;
    volatile u32 I2SPR_REG;

}SPI_t;

// SPI1 base address: 0x40013000
#define SPI1_PERIPHERAL				((volatile SPI_t*) 0x40013000)




#endif /* SPI_PRIVATE_H_ */
