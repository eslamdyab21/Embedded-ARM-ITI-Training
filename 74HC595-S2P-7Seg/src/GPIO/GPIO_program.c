/*
 * GPIO_program.c
 *
 *  Created on: Aug 4, 2022
 *      Author: Eslam Dyab
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include <GPIO/GPIO_config.h>
#include <GPIO/GPIO_interface.h>
#include <GPIO/GPIO_private.h>





/*
 * function to set mode of a certain pin
 */
void GPIO_voidSetPinMode(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8PinMode){
	switch(Copy_u8Port){
	      case GPIO_PORTA:
		      if(Copy_u8Pin <= 7){
			      REG_GPIO_PORTA->CRL &= (~(0b1111<<(4*Copy_u8Pin)));
			      REG_GPIO_PORTA->CRL |= (Copy_u8PinMode << (4*Copy_u8Pin));
		      }else if(Copy_u8Pin <= 16){
			      REG_GPIO_PORTA->CRH &= (~(0b1111<<(4*(Copy_u8Pin-8))));
			      REG_GPIO_PORTA->CRH |= (Copy_u8PinMode << (4*(Copy_u8Pin-8)));
		      }
		      break;


	      case GPIO_PORTB:
		      if(Copy_u8Pin <= 7){
			      REG_GPIO_PORTB->CRL &= (~(0b1111<<(4*Copy_u8Pin)));
			      REG_GPIO_PORTB->CRL |= (Copy_u8PinMode << (4*Copy_u8Pin));
		      }else if(Copy_u8Pin <= 16){
			      REG_GPIO_PORTB->CRH &= (~(0b1111<<(4*(Copy_u8Pin-8))));
			      REG_GPIO_PORTB->CRH |= (Copy_u8PinMode << (4*(Copy_u8Pin-8)));
		      }
		      break;


	      case GPIO_PORTC:
		      if(Copy_u8Pin <= 7){
			      REG_GPIO_PORTC->CRL &= (~(0b1111<<(4*Copy_u8Pin)));
			      REG_GPIO_PORTC->CRL |= (Copy_u8PinMode << (4*Copy_u8Pin));
		      }else if(Copy_u8Pin <= 16){
			      REG_GPIO_PORTC->CRH &= (~(0b1111<<(4*(Copy_u8Pin-8))));
			      REG_GPIO_PORTC->CRH |= (Copy_u8PinMode << (4*(Copy_u8Pin-8)));
		      }
		      break;
	      }
}


/*
 * function to get input value of a certain pin
 */
u8 GPIO_u8GetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin){
	u8 temp_u8ReturnVal = 0 ;
	switch(Copy_u8Port){
	      case GPIO_PORTA:
		      temp_u8ReturnVal = GET_BIT(REG_GPIO_PORTA->IDR,Copy_u8Pin);
		      break;

	      case GPIO_PORTB:
		      temp_u8ReturnVal = GET_BIT(REG_GPIO_PORTB->IDR,Copy_u8Pin);
		      break;

	      case GPIO_PORTC:
		      return GET_BIT(REG_GPIO_PORTC->IDR,Copy_u8Pin);
		      break;
	      }
	return temp_u8ReturnVal;
}


/*
 * function to set output value of a certain pin
 */
void GPIO_voidSetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8PinValue){

	switch(Copy_u8Port){
	      case GPIO_PORTA:
		      if(Copy_u8PinValue){
			      //SET_BIT(REG_GPIO_PORTA->ODR,Copy_u8Pin);	// non-atomic access
			      REG_GPIO_PORTA->BSRR = 0x0001<<Copy_u8Pin;		// atomic access
		      }else{
			      //CLR_BIT(REG_GPIO_PORTA->ODR,Copy_u8Pin);
			      REG_GPIO_PORTA->BRR = 0x0001<<Copy_u8Pin;		// atomic access
		      }


		      break;


	      case GPIO_PORTB:
		      if(Copy_u8PinValue){
			      //SET_BIT(REG_GPIO_PORTB->ODR,Copy_u8Pin);
			      REG_GPIO_PORTB->BSRR = 0x0001<<Copy_u8Pin;		// atomic access
		      }
		      else{
			      //CLR_BIT(REG_GPIO_PORTB->ODR,Copy_u8Pin);
			      REG_GPIO_PORTB->BRR = 0x0001<<Copy_u8Pin;		// atomic access
		      }

		      break;


	      case GPIO_PORTC:
		      if(Copy_u8PinValue){
			      //SET_BIT(REG_GPIO_PORTC->ODR,Copy_u8Pin);
			      REG_GPIO_PORTC->BRR = 0x0001<<Copy_u8Pin;		// atomic access
		      }
		      else{
			      //CLR_BIT(REG_GPIO_PORTC->ODR,Copy_u8Pin);
			      REG_GPIO_PORTC->BRR = 0x0001<<Copy_u8Pin;		// atomic access

		      }

		      break;
	      }

}
