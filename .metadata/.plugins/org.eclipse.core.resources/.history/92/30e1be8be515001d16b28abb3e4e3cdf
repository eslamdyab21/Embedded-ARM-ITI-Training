/*
 * GPIO_interface.h
 *
 *  Created on: Aug 4, 2022
 *      Author: Omar Gamal
 */

#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_


// Macro definitions
#define GPIO_PORTA		0
#define GPIO_PORTB		1
#define GPIO_PORTC		2

#define GPIO_HIGH		1
#define GPIO_LOW		0

// Pin modes MACROs
#define GPIO_PIN_MODE_ANALOG_INPUT		0b0000
#define GPIO_PIN_MODE_FLOATING_INPUT	0b0100
#define GPIO_PIN_MODE_PULLING_INPUT		0b1000

#define GPIO_PIN_MODE_GP_PP_2MHZ		0b0010
#define GPIO_PIN_MODE_GP_PP_10MHZ		0b0001
#define GPIO_PIN_MODE_GP_PP_50MHZ		0b0011

#define GPIO_PIN_MODE_GP_OD_2MHZ		0b0110
#define GPIO_PIN_MODE_GP_OD_10MHZ		0b0101
#define GPIO_PIN_MODE_GP_OD_50MHZ		0b0111



// Public functions


/*
 * function to set mode of a certain pin
 */
void GPIO_voidSetPinMode(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8PinMode);


/*
 * function to get input value of a certain pin
 */
u8 GPIO_u8GetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin);


/*
 * function to set output value of a certain pin
 */
void GPIO_voidSetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8PinValue);


#endif /* GPIO_INTERFACE_H_ */
