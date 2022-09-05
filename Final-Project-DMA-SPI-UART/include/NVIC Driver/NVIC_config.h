/*
 * NVIC_config.h
 *
 *  Created on: Aug 8, 2022
 *      Author: dyab
 */

#ifndef NVIC_CONFIG_H_
#define NVIC_CONFIG_H_


//we can assign the groups the hole 4 bits (16 groups) leaving no bits for sub-priorities 
//Or split the 4 bits between the groups and sub-priorities 
//Your options:

/*NVIC_GROUP_4_BITS       //and 0 bits for sub-priorities (16 group, 0 sub-priorities)
  NVIC_GROUP_3_BITS       //and 1 bits for sub-priorities (8 group, 2 sub-priorities)
  NVIC_GROUP_2_BITS       //and 2 bits for sub-priorities (4 group, 4 sub-priorities)
  NVIC_GROUP_1_BITS	      //and 3 bits for sub-priorities (2 group, 8 sub-priorities)
  NVIC_GROUP_0_BITS       //and 4 bits for sub-priorities (0 group, 16 sub-priorities)
*/
#define 	NVIC_PRIORITY_DISTRIBUTION	    NVIC_GROUP_2_BITS

#endif /* NVIC_CONFIG_H_ */
