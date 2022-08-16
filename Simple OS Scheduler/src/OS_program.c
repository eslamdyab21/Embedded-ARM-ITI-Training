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



/*
 * OS_voidCreateTask
 * Paramters:
 *      Copy_u8ID:           Task unique ID
 *      Copy_u8Periodicity:  Periodcity of the task
 *      Copy_u8InitialDelay: Initial delay for the task so that each task can have
 *                           a time slot of the cpu time
 *      ptr:                 pointer to a callback function
 */
void OS_voidCreateTask(u8 Copy_u8ID, u8 Copy_u8Periodicity, u8 Copy_u8InitialDelay, void (*ptr)(void)){
    OS_Tasks[Copy_u8ID].Fptr = ptr;
	OS_Tasks[Copy_u8ID].InitialDelay = Copy_u8InitialDelay;
	OS_Tasks[Copy_u8ID].Periodicity = Copy_u8Periodicity;
	OS_Tasks[Copy_u8ID].State = OS_TASK_READY;
}




/*
 * OS_voidDeleteTask
 */
void OS_voidDeleteTask(u8 Copy_u8ID){
    OS_Tasks[Copy_u8ID].State = OS_TASK_DELETED;
}


/*
 * OS_voidSuspendTask
 */
void OS_voidSuspendTask(u8 Copy_u8ID, u8 Copy_u8SuspendTime){
    OS_Tasks[Copy_u8ID].State = OS_TASK_SUSPENDED;
    OS_Tasks[Copy_u8ID].SuspendTime = Copy_u8SuspendTime;
    OS_Tasks[Copy_u8ID].InitialDelay += Copy_u8SuspendTime;
}

