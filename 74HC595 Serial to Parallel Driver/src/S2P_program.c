/*
 * S2P_program.c
 *
 *  Created on: Aug 18, 2022
 *      Author: dyab
 */


#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "S2P_interface.h"
#include "S2P_private.h"
#include "S2P_config.h"

#include "GPIO/GPIO_interface.h"
#include "RCC Driver/RCC_interface.h"



/*
* Function to intialize the pins as output
*/
void S2P_voidInit(){
    RCC_voidInit();
    switch (S2P_PORT){
        case PORTA:
            RCC_voidPeripheralClockEnable(RCC_APB2, GPIOA);
            GPIO_voidSetPinMode(GPIO_PORTA, S2P_A_PIN, GPIO_PIN_MODE_GP_PP_10MHZ);
            GPIO_voidSetPinMode(GPIO_PORTA, S2P_SHIFT_CLK_PIN, GPIO_PIN_MODE_GP_PP_10MHZ);
            GPIO_voidSetPinMode(GPIO_PORTA, S2P_RESET_PIN, GPIO_PIN_MODE_GP_PP_10MHZ);
            GPIO_voidSetPinMode(GPIO_PORTA, S2P_LATCH_CLK_PIN, GPIO_PIN_MODE_GP_PP_10MHZ);
            GPIO_voidSetPinMode(GPIO_PORTA, S2P_OUTPUT_ENABLE_PIN, GPIO_PIN_MODE_GP_PP_10MHZ);

            break;

        case PORTB:
            RCC_voidPeripheralClockEnable(RCC_APB2, GPIOB);
            GPIO_voidSetPinMode(GPIO_PORTB, S2P_A_PIN, GPIO_PIN_MODE_GP_PP_10MHZ);
            GPIO_voidSetPinMode(GPIO_PORTB, S2P_SHIFT_CLK_PIN, GPIO_PIN_MODE_GP_PP_10MHZ);
            GPIO_voidSetPinMode(GPIO_PORTB, S2P_RESET_PIN, GPIO_PIN_MODE_GP_PP_10MHZ);
            GPIO_voidSetPinMode(GPIO_PORTB, S2P_LATCH_CLK_PIN, GPIO_PIN_MODE_GP_PP_10MHZ);
            GPIO_voidSetPinMode(GPIO_PORTB, S2P_OUTPUT_ENABLE_PIN, GPIO_PIN_MODE_GP_PP_10MHZ);

            break;

        case PORTC:
            RCC_voidPeripheralClockEnable(RCC_APB2, GPIOC);
            GPIO_voidSetPinMode(GPIO_PORTC, S2P_A_PIN, GPIO_PIN_MODE_GP_PP_10MHZ);
            GPIO_voidSetPinMode(GPIO_PORTC, S2P_SHIFT_CLK_PIN, GPIO_PIN_MODE_GP_PP_10MHZ);
            GPIO_voidSetPinMode(GPIO_PORTC, S2P_RESET_PIN, GPIO_PIN_MODE_GP_PP_10MHZ);
            GPIO_voidSetPinMode(GPIO_PORTC, S2P_LATCH_CLK_PIN, GPIO_PIN_MODE_GP_PP_10MHZ);
            GPIO_voidSetPinMode(GPIO_PORTC, S2P_OUTPUT_ENABLE_PIN, GPIO_PIN_MODE_GP_PP_10MHZ);
            break;

    }

}



/*
* Function to Enable output
*/
void S2P_voidOutputEnable(){
    switch (S2P_PORT){
        case PORTA:
            GPIO_voidSetPinValue(GPIO_PORTA, S2P_OUTPUT_ENABLE_PIN, GPIO_LOW);
            break;

        case PORTB:
            GPIO_voidSetPinValue(GPIO_PORTB, S2P_OUTPUT_ENABLE_PIN, GPIO_LOW);
            break;

        case PORTC:
            GPIO_voidSetPinValue(GPIO_PORTC, S2P_OUTPUT_ENABLE_PIN, GPIO_LOW);
            break;

    }
}



/*
* Function to Disable output
*/
void S2P_voidOutputDisable(){
    switch (S2P_PORT){
        case PORTA:
            GPIO_voidSetPinValue(GPIO_PORTA, S2P_OUTPUT_ENABLE_PIN, GPIO_HIGH);
            break;

        case PORTB:
            GPIO_voidSetPinValue(GPIO_PORTB, S2P_OUTPUT_ENABLE_PIN, GPIO_HIGH);
            break;

        case PORTC:
            GPIO_voidSetPinValue(GPIO_PORTC, S2P_OUTPUT_ENABLE_PIN, GPIO_HIGH);
            break;

    }
}