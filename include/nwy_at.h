/*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====
    Copyright (c) 2018 Neoway Technologies, Inc.
    All rights reserved.
    Confidential and Proprietary - Neoway Technologies, Inc.
    Author: jitonghu
    Date: 2018/9
*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*/
#ifndef __NWY_AT_H__
#define __NWY_AT_H__

#include "nwy_common.h"
#include "nwy_error.h"

/*---------------------------Macro definition---------------------------*/

#ifdef __cplusplus
extern "C" {
#endif

#define NWY_AT_LEN_MAX              2048

#define NWY_AT_WAIT_NONE            (0)
#define NWY_AT_WAIT_FOREVER         (-1L)
#define NWY_AT_WAIT_DEFAULT         (5)   //5s

/*-----------------------------Type Definition---------------------------*/

typedef int (*nwy_at_urc_cb_func)(char *cmd, const char* urc_info, int len);

typedef struct
{
    char                name[64];
    nwy_at_urc_cb_func  func;
}nwy_at_urc_t;

/*---------------------------Variable Definition--------------------------*/

int nwy_at_port_init(char *name);
void nwy_at_port_deinit(void);

int nwy_at_send_cmd(char *cmd, char *resp, int timeout);

/* the at URC call back, such as "+CMT:;+CDS:;+CBM:;" */
int nwy_at_reg_urc_cb_func(nwy_at_urc_t *table, int len);
void nwy_at_unreg_urc_cb_func(void);

#ifdef __cplusplus
   }
#endif

#endif //__NWY_AT_H__