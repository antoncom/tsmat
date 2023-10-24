/*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====
    Copyright (c) 2021 Neoway Technologies, Inc.
    All rights reserved.
    Confidential and Proprietary - Neoway Technologies, Inc.
    Author: ZhangYanhong
    Date: 2021/11/18
*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*/
#ifndef __NWY_FOTA_H__
#define __NWY_FOTA_H__

#include "nwy_error.h"
#include "nwy_log.h"
#include "stddef.h"
#ifdef __cplusplus
extern "C" {
#endif

/*------------------------------- Macro definition -------------------------------*/


/*-------------------------------- Type Definition -------------------------------*/
typedef enum fota_dl_result {
    FOTA_DOWNLOAD_SUCCESS = 0,
    FOTA_DOWNLOAD_FAIL = 1,
    FOTA_DOWNLOAD_NULL = 2,
} nwy_fota_dl_result_t;

typedef enum fota_up_result {
    FOTA_UPDATE_SUCCESS = 0,
    FOTA_UPDATE_FAIL = 1,
    FOTA_UPDATE_NULL = 2,
} nwy_fota_up_result_t;

/*----------------------------- variables definition -----------------------------*/


/*----------------------------- functions definition -----------------------------*/

/*
 *****************************************************************************
 * Prototype	: nwy_fota_ua
 * Description	: fota upgrade ,send a ubus request to corresponding service object, 
 				  and it will wait response back, then run callback function.
 * Input		:
 * Output		: NULL
 * Return Value	: success:0 
 * Author		: xietianbao
 *****************************************************************************
 */
int nwy_fota_ua(char *fota_package_path);


int nwy_get_fota_result(void);




#ifdef __cplusplus
   }
#endif

#endif  //__NWY_FOTA_H__

