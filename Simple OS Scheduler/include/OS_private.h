/*
 * OS_private.h
 *
 *  Created on: Aug 16, 2022
 *      Author: dyab
 */

#ifndef OS_PRIVATE_H_
#define OS_PRIVATE_H_


typedef struct{
	u8 Periodicity;
	u8 InitialDelay;
	u8 State;
	u8 SuspendTime;
	void (*Fptr)(void);
}Task;

void Scheduler(void);



#endif /* OS_PRIVATE_H_ */
