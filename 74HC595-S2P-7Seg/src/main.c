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

#include "GPIO/GPIO_interface.h"
#include "7Segment_interface.h"


// Change it's value after 8 clock cycles (DigitCount==8)
u8 Data8Bits = 0x6d; //5 for common cathod 7seg



void SendSerialData(){
    static u8 DigitIndex=0;

    S2P_voidTx(Data8Bits, DigitIndex);
    

    if(DigitIndex==8){
        //rising edge on latch
        S2P_voidLatchClock(1);

        DigitIndex=-1;
        //Data8Bits = new value


        //falling edge on latch
        S2P_voidLatchClock(0);
    }
    DigitIndex++;

}


void Clock(){
    static u8 flip=1;

    switch (flip){
        case 1:
            flip = 0;
            SendSerialData();
            S2P_voidShiftClock(0);

            break;

        case 0:
            flip = 1;
            S2P_voidShiftClock(1);

            break;
    }
    
}



int main(void){

    S2P_voidInit();
    //S2P_voidOutputEnable();
    
    //S2P_voidShiftReset(0);


    OS_voidCreateTask(0, 1, 0, Clock);
    OS_voidStartScheduler();

    return 0;
}