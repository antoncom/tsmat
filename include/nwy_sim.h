/*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====
    Copyright (c) 2021 Neoway Technologies, Inc.
    All rights reserved.
    Confidential and Proprietary - Neoway Technologies, Inc.
    Author: gaohe
    Date: 2022/2/14
*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*/
#ifndef __NWY_SIM_H__
#define __NWY_SIM_H__

#include "nwy_error.h"
#include "nwy_log.h"

#ifdef __cplusplus
extern "C" {
#endif
/*---------------------------Macro definition---------------------------*/
#define size_t long long unsigned int
#define uint8 unsigned char



/*-----------------------------Type Definition---------------------------*/
typedef enum
{
    NWY_SIM_NOT_INSERTED,
    NWY_SIM_READY,
    NWY_SIM_PIN_REQ,
    NWY_SIM_PUK_REQ,
    NWY_SIM_BUSY,
    NWY_SIM_BLOCKED,
    NWY_SIM_UNKNOWN
}nwy_sim_status_t;

typedef enum
{
    NWY_SIM_ID_SLOT_1,
    NWY_SIM_ID_SLOT_2,
    NWY_SIM_ID_MAX
}nwy_sim_id_t;

typedef enum
{
    NWY_SIM_PIN_MODE_ENABLED,
    NWY_SIM_PIN_MODE_DISABLED,
    NWY_SIM_PIN_MODE_UNKOWN
}nwy_sim_pin_mode_t;

typedef struct {
    char mcc[4];
    char mnc[4];
    int  mnc_len;
}nwy_sim_plmn_t;

/*---------------------------Function Definition--------------------------*/
nwy_sim_status_t nwy_sim_get_card_status(nwy_sim_id_t sim_id);
int nwy_sim_verify_pin(nwy_sim_id_t sim_id, const char* pin);
int nwy_sim_enable_pin(nwy_sim_id_t sim_id, const char* pin);
int nwy_sim_disable_pin(nwy_sim_id_t sim_id, const char* pin);
nwy_sim_pin_mode_t nwy_sim_get_pin_mode(nwy_sim_id_t sim_id);
int nwy_sim_unblock
(
    nwy_sim_id_t sim_id, 
    const char*  puk, 
    const char*  new_pin
);
int nwy_sim_change_pin
(
    nwy_sim_id_t sim_id, 
    const char*  old_pin, 
    const char*  new_pin
);
int nwy_sim_get_pin_puk_retry_times
(
    nwy_sim_id_t sim_id, 
    uint8*       pin_times, 
    uint8*       puk_times
);
int nwy_sim_get_iccid
(
    nwy_sim_id_t sim_id,
    char*        iccid_buf,
    size_t       buf_len
);
int nwy_sim_get_imsi
(
    nwy_sim_id_t sim_id,
    char*        imsi_buf,
    size_t       buf_len
);

int nwy_sim_get_msisdn
(
    nwy_sim_id_t sim_id,
    char*        msisdn_buf,
    size_t       buf_len
);

int nwy_sim_set_msisdn
(
    nwy_sim_id_t sim_id,
    char*        msisdn_buf,
    int          number_len
);

int nwy_sim_get_mcc_mnc
(
    nwy_sim_id_t     sim_id,
    nwy_sim_plmn_t*  plmn
);

int nwy_sim_check_app_info
(
	nwy_sim_id_t sim_id
);

int nwy_sim_switch_slot(nwy_sim_id_t sim_id);


#ifdef __cplusplus
   }
#endif

#endif  

