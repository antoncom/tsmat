/*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====
    Copyright (c) 2021 Neoway Technologies, Inc.
    All rights reserved.
    Confidential and Proprietary - Neoway Technologies, Inc.
    Author: ZhangYanhong
    Date: 2021/11/18
*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*/
#ifndef __NWY_DM_H__
#define __NWY_DM_H__

#include "nwy_error.h"
#include "nwy_log.h"
#include "stddef.h"
#ifdef __cplusplus
extern "C" {
#endif

/*------------------------------- Macro definition -------------------------------*/
#define NWY_FW_VER_MAX_LEN          (400)      //the same as at server define

/*-------------------------------- Type Definition -------------------------------*/
typedef enum {
    NWY_DM_OP_MODE_ONLINE = 0x00,               /**<  Online \n */
    NWY_DM_OP_MODE_LOW_POWER = 0x01,            /**<  Low power \n   */
    NWY_DM_OP_MODE_OTHER = 0x02                 /**<  Other mode(only used for get) \n  */
}nwy_dm_operating_mode_t; 

typedef enum {
    NWY_USB_RNDIS_MODE = 0x00,               /**<  rndis mode \n */
    NWY_USB_ECM_MODE   = 0x01,               /**<  ecm mode \n   */
    NWY_USB_MAX,
}nwy_usb_operating_mode_e; 

typedef enum {
    NWY_DM_MODEM_IND_ENABLE     = 0x00,               /**<  enable modem ind \n */
    NWY_DM_MODEM_IND_DISABLE  = 0x01,               /**<  disenable modem ind \n   */
}nwy_dm_modem_ind_e; 


/*----------------------------- variables definition -----------------------------*/


/*----------------------------- functions definition -----------------------------*/
int nwy_dm_get_dev_model(char* model_buf, size_t buf_len);
int nwy_dm_get_dev_op_mode(nwy_dm_operating_mode_t *op_mode);
int nwy_dm_set_dev_op_mode(nwy_dm_operating_mode_t op_mode);
int nwy_dm_get_imei(char* imei_buf, size_t buf_len);
int nwy_dm_get_fw_version(char* version_buf, size_t buf_len);
int nwy_dm_get_sdk_version(char* ver_buf, size_t buf_len);
int nwy_usb_switch_op_mode(nwy_usb_operating_mode_e usb_mode);
int nwy_dm_disable_modem_ind(nwy_dm_modem_ind_e state);


#ifdef __cplusplus
   }
#endif

#endif  

