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


void (*CallBack)(void) = (void *) 0;


/*
 * STK_voidInit
 * description: Selects the clock source of the SysTick (AHB, AHB/8)
 */
void STK_voidInit(u8 Copy_u8ClkSRC){
    switch (Copy_u8ClkSRC)
    {
    case SYSTICK_AHB_8:
        //CLKSOURCE: Clock source selection (bit-2)
        CLR_BIT(SYSTICK->CTRL,2);
        break;

    case SYSTICK_AHB:
        SET_BIT(SYSTICK->CTRL,2);
        break;
    }
}


/*
 * STK_voidSetBusyWait
 * description: Starts a synchronous wait (delay)
 */
void STK_voidSetBusyWait(u32 Copy_u32TickCount){
    /* Disable the systick interrupt
	 * Set LOAD value
	 * start the timer
	 * empty loop until the flag is raised
	 * reset the flag
	 * Reset the LOAD register
	 * stop the timer
	 */

    //Disable the systick interrupt(incase it was already in use brfore)
    //TICKINT: SysTick exception request enable
    //0: Counting down to zero does not assert the SysTick exception request
    //1: Counting down to zero to asserts the SysTick exception request.

    //we don't need to assert the SysTick exception request because this function
    //only do busy wait, no functions to call 
	CLR_BIT(SYSTICK->CTRL, 1);

    //Set LOAD value
    //Note anded with 0x00FFFFFF because the SysTick can count up to 24-bits only
	SYSTICK->LOAD = (Copy_u32TickCount - 1) & 0x00FFFFFF;

    //clear the val regitser to start from zero
	SYSTICK->VAL = 0;

    //start the timer
	SET_BIT(SYSTICK->CTRL, 0);

    //empty loop until the flag is raised (bit-16 is the COUNT FLAG)
    //__asm("NOP") is no operation in assembly
	while(!(GET_BIT(SYSTICK->CTRL, 16))){
		__asm("NOP");
	}

    //disable the timer
	CLR_BIT(SYSTICK->CTRL, 0);

    //stop the timer
	SYSTICK->VAL = 0;
}



/*
 * STK_voidSetPeriodicInterval
 * description: Starts a periodic interval asynchronous wait
 *              takes a callback function to call every period
 * paramters: Copy_u32TickCount
 *            void (*ptr)(void): pointer to a function to call after every period
 */
void STK_voidSetPeriodicInterval(u32 Copy_u32TickCount, void (*ptr)(void)){
    //Set LOAD value
	SYSTICK->LOAD = (Copy_u32TickCount - 1) & 0x00FFFFFF;

    //clear the val regitser to start from zero
	SYSTICK->VAL = 0;
    
    //assign the callback function to the handler
	CallBack = ptr;

    //Enable the systick interrupt (TICKINT: SysTick exception request enable)
	SET_BIT(SYSTICK->CTRL, 1);

    //Enable the timer (ENABLE: Counter enable)
	SET_BIT(SYSTICK->CTRL, 0);
}





/*
 * STK_voidSetSingleInterval
 * description: Starts a single interval asynchronous wait
 *              takes a callback function to call one time
 */
void STK_voidSetSingleInterval(u32 Copy_u32TickCount, void (*ptr)(void)){
    //Set LOAD value
	SYSTICK->LOAD = (Copy_u32TickCount - 1) & 0x00FFFFFF;

    //clear the val regitser to start from zero
	SYSTICK->VAL = 0;
    
    //assign the callback function to the handler
	CallBack = ptr;

    //Enable the systick interrupt (TICKINT: SysTick exception request enable)
	SET_BIT(SYSTICK->CTRL, 1);

    //Enable the timer (ENABLE: Counter enable)
	SET_BIT(SYSTICK->CTRL, 0);
}





void SysTick_Handler(void){
    // Call the callback function to do the periodic task
	CallBack();

    /*
    *A write of any value clears the field to 0, and also clears the COUNTFLAG bit 
    *in the STK_CTRL register to 0.
    */
	SYSTICK->VAL = 0;
}