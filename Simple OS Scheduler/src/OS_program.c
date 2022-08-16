/*
 * OS_program.c
 *
 *  Created on: Aug 16, 2022
 *      Author: dyab
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "OS_interface.h"
#include "OS_private.h"
#include "OS_config.h"


Task OS_Tasks[OS_NUMBER_OF_TASKS];


/*
* function to handle the scheduling based on the InitialDelay value of every task
*/
void Scheduler(void){

	for(u8 i = 0; i < OS_NUMBER_OF_TASKS; i++){
		if(((OS_Tasks[i].State == OS_TASK_READY)||(OS_Tasks[i].State == OS_TASK_SUSPENDED))){
			if(OS_Tasks[i].InitialDelay == 0){
				OS_Tasks[i].InitialDelay = OS_Tasks[i].Periodicity-1;
				OS_Tasks[i].Fptr();
				if(OS_Tasks[i].State == OS_TASK_SUSPENDED)
					OS_Tasks[i].State = OS_TASK_READY;
			}
            else
				OS_Tasks[i].InitialDelay--;
			
		}
	}

}