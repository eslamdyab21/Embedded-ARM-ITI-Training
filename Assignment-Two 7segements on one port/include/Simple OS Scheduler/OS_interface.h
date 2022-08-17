/*
 * OS_interface.h
 *
 *  Created on: Aug 16, 2022
 *      Author: dyab
 */

#ifndef OS_INTERFACE_H_
#define OS_INTERFACE_H_

//Macros
#define OS_TASK_DELETED			2
#define OS_TASK_READY			1
#define OS_TASK_SUSPENDED		0


/*
 * OS_voidCreateTask
 * Paramters:
 *      Copy_u8ID:           Task unique ID
 *      Copy_u8Periodicity:  Periodcity of the task
 *      Copy_u8InitialDelay: Initial delay for the task so that each task can have
 *                           a time slot of the cpu time
 *      ptr:                 pointer to a callback function
 */
void OS_voidCreateTask(u8 Copy_u8ID, u16 Copy_u8Periodicity, u8 Copy_u8InitialDelay, void (*ptr)(void));


/*
 * OS_voidDeleteTask
 */
void OS_voidDeleteTask(u8 Copy_u8ID);


/*
 * OS_voidSuspendTask
 */
void OS_voidSuspendTask(u8 Copy_u8ID, u8 Copy_u8SuspendTime);


/*
 * OS_voidStartScheduler
 */
void OS_voidStartScheduler(void);


/*
 * OS_voidResumeTask
 */
void OS_voidResumeTask(u8 Copy_u8ID);


/*
 * OS_u8GetTaskState
 */
u8 OS_u8GetTaskState(u8 Copy_u8ID);


#endif /* OS_INTERFACE_H_ */
