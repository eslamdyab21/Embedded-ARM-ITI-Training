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

// Change it's value after 8 clock cycles (DigitCount==8)
u8 Data8Bits = 0;


void SendSerialData(){
    static u8 DigitIndex=0;

    S2P_voidTx(Data8Bits, DigitIndex);
    DigitIndex++;

    if(DigitIndex==8){
        DigitIndex=0;
        //Data8Bits = new value
    }

}


void Clock(){
    static u8 flip=0;

    switch (flip){
        case 1:
            flip = 0;
            S2P_voidShiftClock(0);
            S2P_voidLatchClock(0);
            SendSerialData();

            break;

        case 0:
            flip = 1;
            S2P_voidShiftClock(1);
            S2P_voidLatchClock(1);

            break;
    }
    
}

int main(void){

    S2P_voidInit();

    OS_voidCreateTask(0, 1, 0, Clock);

    return 0;
}