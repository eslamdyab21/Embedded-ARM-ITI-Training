/*
 * SYSTICK_program.c
 *
 *  Created on: Aug 16, 2022
 *      Author: dyab
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SYSTICK_interface.h"
#include "SYSTICK_config.h"
#include "SYSTICK_private.h"


/*
 * STK_voidInit
 * description: Selects the clock source of the SysTick (AHB, AHB/8)
 */
void STK_voidInit(u8 Copy_u8ClkSRC){
    switch (Copy_u8ClkSRC)
    {
    case SYSTICK_AHB_8:
        CLR_BIT(SYSTICK->CTRL,2);
        break;

    case SYSTICK_AHB:
        SET_BIT(SYSTICK->CTRL,2);
        break;
    }
}