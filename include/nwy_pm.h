/*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====
    Copyright (c) 2018 Neoway Technologies, Inc.
    All rights reserved.
    Confidential and Proprietary - Neoway Technologies, Inc.
    Author: Shi.Shaogang
    Date: 2018.06
*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*/

#ifndef __NWY_PM_H__
#define __NWY_PM_H__

#ifdef __cplusplus
extern "C" {
#endif

/*----------------------------Type Definition-----------------------------*/

typedef enum {
    NWY_QUICK_POWER_OFF  = 0,
    NWY_NORMAL_POWER_OFF = 1
}nwy_power_off_t;

typedef enum {
    NWY_WAKEUP = 0,
    NWY_ENTRY_SLEEP
}nwy_pm_set_t;

typedef enum {
    NWY_PM_WAKE_UNLOCK = 0,
    NWY_PM_WAKE_LOCK = 1
}nwy_pm_set_wakelock_t;

/*---------------------------Function Definition--------------------------*/
int nwy_pm_state_set(int mode);
int nwy_pm_state_get(void);
int nwy_pm_set_wakelock(nwy_pm_set_wakelock_t mode, char *name);

#ifdef __cplusplus
   }
#endif

#endif //__NWY_PM_H__
