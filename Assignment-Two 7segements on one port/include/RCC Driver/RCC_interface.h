/*
 * RCC_interface.h
 *
 *  Created on: Aug 2, 2022
 *      Author: BluRay
 */

#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_ /// same exact name

// macro definitions
#define RCC_AHB			0
#define RCC_APB1		1
#define RCC_APB2		2

#define RCC_MCO_NO		(-2)
#define RCC_SYS_CLK		(-1)
#define RCC_HSI			0
#define RCC_HSE			1
#define RCC_PLL			2


#define RCC_AHB_PRE_NO	0
#define RCC_AHB_PRE_2	8
#define RCC_AHB_PRE_4	9
#define RCC_AHB_PRE_8	10
#define RCC_AHB_PRE_16	11
/*
typedef enum{
	NO,
	PRE2 = 8,
	PRE4,
	PRE8,
	PRE16,
}RCC_AHB_PRE;
*/
// we can't use enum in macros because it needs compiling and macros are preprocessor

typedef enum{  //new data type label int "peripheral name"
	    DMA1,
	    DMA2,
	    SRAM,
	    RES1,
	    FLITF,
	    RES2,
	    CRCE,
	    RES3,
	    FSMC,
	    RES4,
	    SDIO,
	    RES5,
	    RES6,
	    RES7,
	    RES8,
	    RES9,
	    RES10,
	    RES11,
	    RES12,
	    RES13,
	    RES14,
	    RES15,
	    RES16,
	    RES17,
	    RES18,
	    RES19,
	    RES20,
	    RES21,
	    RES22,
	    RES23,
	    RES24,
	    RES25,
	    TIM2,
	    TIM3,
	    TIM4,
	    TIM5,
	    TIM6,
	    TIM7,
	    TIM12,
	    TIM13,
	    TIM14,
	    RES26,
	    RES27,
	    WWDG,
	    RES28,
	    RES29,
	    SPI2,
	    SPI3,
	    RES30,
	    USART2,
	    USART3,
	    UART4,
	    UART5,
	    I2C1,
	    I2C2,
	    USB,
	    CAN,
	    BKP,
	    PWR,
	    DAC,
	    RES46,
	    RES31,
	    AFIO,
	    RES32,
	    GPIOA,
	    GPIOB,
	    GPIOC,
	    GPIOD,
	    GPIOE,
	    GPIOF,
	    GPIOG,
	    ADC1,
	    ADC2,
	    TIM1,
	    SPI1,
	    TIM8,
	    USART1,
	    ADC3,
	    RES33,
	    RES34,
	    RES35,
	    TIM9,
	    TIM10,
	    TIM11,
	    RES36,
	    RES37,
	    RES38,
	    RES39,
	    RES40,
	    RES41,
	    RES42,
	    RES43,
	    RES44,
	    RES45
}Peripherals_t;


// PUPLIVC FUNCTION DECLARATION


void RCC_voidInit (void);
//write it with pre build configuration



/*
 * NAME:RCC_voidPeripheralClockEnable
 * RETURN TYPE: VOID
 * ARGUMENTS: Copy_u8BusName:U8 , (AHB,APB1,ABP2)
 * 			  Copy_u8PerphiralName : Peripherals_t , (ENUM VALUES)
 * DESCRIPTION: ENABLES PREPHIRAL CLK FOR CERTAIN PREPHIRAL
 */
void RCC_voidPeripheralClockEnable(u8 Copy_u8BusName, Peripherals_t Copy_u8PerphiralName);

void RCC_voidPeripheralClockDisable(u8 Copy_u8BusName, Peripherals_t Copy_u8PerphiralName);


#endif /* RCC_INTERFACE_H_ */
