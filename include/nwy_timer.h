/*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====
    Copyright (c) 2018 Neoway Technologies, Inc.
    All rights reserved.
    Confidential and Proprietary - Neoway Technologies, Inc.
    Author: Shi.Shaogang
    Date: 2018.06
*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*/

#ifndef __NWY_TIMER_H__
#define __NWY_TIMER_H__

#ifdef __cplusplus
extern "C" {
#endif
/*---------------------------Function Definition--------------------------*/
int nwy_timer_init(void);
void nwy_timer_deinit(void);
int nwy_start_timer(unsigned long second, int mode, void (*callback)(int));
int nwy_stop_timer(void);


#ifdef __cplusplus
   }
#endif

#endif 
