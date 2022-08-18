/*
 * S2P_program.c
 *
 *  Created on: Aug 18, 2022
 *      Author: dyab
 */

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "S2P_interface.h"
#include "SYSTICK Driver/SYSTICK_interface.h"
#include "Simple OS Scheduler/OS_interface.h"

void Clock(){
    static u8 flip=0;

    switch (flip){
        case 1:
            flip = 0;
            break;

        case 0:
            flip = 1;
            break;
    }
    
}

int main(void){

    S2P_voidInit();
    OS_voidCreateTask(0, 1, 0, Clock);

    return 0;
}