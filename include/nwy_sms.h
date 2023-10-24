/*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====
    Copyright (c) 2021 Neoway Technologies, Inc. All rights reserved.
    Confidential and Proprietary - Neoway Technologies, Inc.
    
    Author: wangchen
    Date: 2022/2/11
    Description: nwy_sms.h include SMS API.
*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*/
#ifndef __NWY_SMS_H__
#define __NWY_SMS_H__

#include <stdint.h>
#include "nwy_error.h"
#include "nwy_log.h"


#ifdef __cplusplus
extern "C" {
#endif

/*---------------------------Macro definition---------------------------*/
#define NWY_SMS_MAX_ADDR_LENGTH 21
#define NWY_SMS_MAX_MO_MSG_LENGTH 5*160
#define NWY_SMS_MAX_PDU_LENGTH 512
#define NWY_SMS_MAX_MT_MSG_LENGTH 160
#define NWY_SMS_MAX_DATE_LENGTH 40
#define NWY_MAX_MSG_LIST_LEN 255


typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;


/*-----------------------------Type Definition-------------------------*/
typedef struct {
    char sca[NWY_SMS_MAX_ADDR_LENGTH + 1];
} nwy_sms_sca_t;

typedef enum {
    NWY_SMS_MODE_CDMA = 0,
    NWY_SMS_MODE_GW   = 1,
} nwy_nw_mode_t;      //not support

typedef enum nwy_mt_sms_event{
    NWY_SMS_PP_IND      = 0,// PP msg
    NWY_SMS_PP_IND_EXT,
}nwy_mt_sms_event_t;

typedef enum nwy_sms_msg_format_type{
    NWY_SMS_MSG_GSM7_DCS = 0,
    NWY_SMS_MSG_8BIT_DCS = 1,
    NWY_SMS_MSG_UCS2_DCS = 2,
    NWY_SMS_MSG_UNKONWN_DCS,
}nwy_sms_msg_format_type_e;

typedef struct nwy_sms_info_type{
    char phone_num[NWY_SMS_MAX_ADDR_LENGTH];
    uint32_t msg_context_len;
    char msg_context[NWY_SMS_MAX_MO_MSG_LENGTH + 1];
    nwy_sms_msg_format_type_e msg_format;
}nwy_sms_info_type_t;

typedef enum nwy_sms_storage_type
{
    NWY_SMS_STORAGE_TYPE_NONE = 0x00,  //not support
    NWY_SMS_STORAGE_TYPE_ME = 0x01,  //not support
    NWY_SMS_STORAGE_TYPE_SM = 0x02,
    NWY_SMS_STORAGE_TYPE_MAX,
}nwy_sms_storage_type_e;

typedef struct nwy_sms_time_stamp
{
    uint16_t uYear;
    uint8_t uMonth;
    uint8_t uDay;
    uint8_t uHour;
    uint8_t uMinute;
    uint8_t uSecond;
    int8_t iZone;
}nwy_sms_time_stamp_t;

typedef struct nwy_sms_recv_info_type
{
  char oa[NWY_SMS_MAX_ADDR_LENGTH + 1];
  uint8_t oa_size;
  nwy_sms_time_stamp_t scts;
  nwy_sms_msg_format_type_e dcs;
  uint16_t nStorageId;
  uint16_t nIndex;
  uint16_t nDataLen;
  char pData[NWY_SMS_MAX_PDU_LENGTH];
  uint8_t cnmi_mt;
}nwy_sms_recv_info_type_t;

typedef enum {
    NWY_SMS_ENCODING_NONE = 0,
    NWY_SMS_ENCODING_GBK = 1,
} nwy_sms_context_decode_type;

typedef struct nwy_sms_pp_info_type{
    uint8_t is_empty;  //not support
    nwy_sms_msg_format_type_e msg_format; // Message format.
    uint32_t concat_sms_total;  //not support
    uint32_t concat_sms_cur;  //not support
    uint32_t concat_sms_id;  //not support
    uint32_t msg_content_len;
    uint8_t msg_pdu[NWY_SMS_MAX_PDU_LENGTH + 1];
    uint8_t msg_content[NWY_SMS_MAX_MT_MSG_LENGTH + 1];
    char source_phone_num[NWY_SMS_MAX_ADDR_LENGTH + 1]; // Source address.
    char date[NWY_SMS_MAX_DATE_LENGTH];
    nwy_sms_context_decode_type context_decode_type;  //not support
    uint8_t msg_decoded_content[NWY_SMS_MAX_MT_MSG_LENGTH + 1];  //not support
} nwy_sms_pp_info_type_t;  /* Message */

typedef void (*nwy_sms_evt_handler)
(
    nwy_mt_sms_event_t ind_type,
    void *ind_struct
);

typedef struct {
    uint8_t len;
    int indices[NWY_MAX_MSG_LIST_LEN];
}nwy_sms_indices_t; 



/*
 *****************************************************************************
 * Prototype	: nwy_sms_get_sca
 * Description	: get SMSC
 * Input		: NULL
 * Output	 	: SMSC value.
 * Return Value	: int
 * Author	 	: wangchen
 *****************************************************************************
 */
int nwy_sms_get_sca(nwy_sms_sca_t *sca);

/*
 *****************************************************************************
 * Prototype	: nwy_sms_set_sca
 * Description	: set SMSC
 * Input		: smsc
 * Output	 	: NULL
 * Return Value	: int
 * Author	 	: wangchen
 *****************************************************************************
 */
int nwy_sms_set_sca(nwy_sms_sca_t *sca);

/*
 *****************************************************************************
 * Prototype	: nwy_sms_send_sms
 * Description	: send sms
 * Input		: NULL
 * Output	 	: SMSC value.
 * Return Value	: int
 * Author	 	: wangchen
 *****************************************************************************
 */
int nwy_sms_send_message(nwy_sms_info_type_t *p_sms_data);

/*
 *****************************************************************************
 * Prototype	: nwy_set_report_option
 * Description	: set sms report
 * Input		: uint8_t mode, uint8_t mt, uint8_t bm, uint8_t ds, uint8_t bfr
 * Output	 	: NULL.
 * Return Value	: int
 * Author	 	: wangchen
 *****************************************************************************
 */
int nwy_set_report_option(uint8_t mode, uint8_t mt, uint8_t bm, uint8_t ds, uint8_t bfr);

/*
 *****************************************************************************
 * Prototype	: nwy_sms_set_storage
 * Description	: set sms storage
 * Input		: nwy_sms_storage_type_e sms_storage
 * Output	 	: NULL.
 * Return Value	: int
 * Author	 	: wangchen
 *****************************************************************************
 */
int nwy_sms_set_storage(nwy_sms_storage_type_e sms_storage);

/*
 *****************************************************************************
 * Prototype	: nwy_sms_get_storage
 * Description	: get sms storage
 * Input		: NULL
 * Output	 	: NULL.
 * Return Value	: nwy_sms_storage_type_e
 * Author	 	: wangchen
 *****************************************************************************
 */
nwy_sms_storage_type_e nwy_sms_get_storage(void);

/*
 *****************************************************************************
 * Prototype	: nwy_sms_delete_message
 * Description	: delete sms by index
 * Input		: uint8_t index
 * Output	 	: NULL.
 * Return Value	: int
 * Author	 	: wangchen
 *****************************************************************************
 */
int nwy_sms_delete_message (nwy_sms_storage_type_e storage, uint8_t index, nwy_nw_mode_t mode);

/*
 *****************************************************************************
 * Prototype	: nwy_sms_read_msg
 * Description	: get sms
 * Input		: uint8_t index nwy_sms_storage_type_e mem_store(not support mem_store)
 * Output	 	: nwy_sms_pp_info_type_t *sms_pp
 * Return Value	: int
 * Author	 	: wangchen
 *****************************************************************************
 */
int nwy_sms_read_msg(nwy_sms_storage_type_e mem_store, uint8_t index, nwy_sms_pp_info_type_t *sms_pp);

/*
 *****************************************************************************
 * Prototype	: nwy_sms_add_mtmessage_handler
 * Description	: reg sms ind
 * Input		: nwy_sms_evt_handler evt_handler void *contextPtr
 * Output	 	: NULL
 * Return Value	: int
 * Author	 	: wangchen
 *****************************************************************************
 */
int nwy_sms_add_mtmessage_handler (nwy_sms_evt_handler evt_handler, void *contextPtr);

/*
 *****************************************************************************
 * Prototype	: nwy_sms_unsol_sms_event
 * Description	: register sms ind then runloop to recv and process ind
 * Input		: void
 * Output	 	: void
 * Return Value	: int
 * Author	 	: wangchen
 *****************************************************************************
 */
int nwy_sms_unsol_sms_event(void);

/*
 *****************************************************************************
 * Prototype	: nwy_sms_get_indices
 * Description	: get sms index list
 * Input		: nwy_sms_storage_type_e mem_store(not support)
 * Output	 	: nwy_sms_indices_t *p_list
 * Return Value	: int
 * Author	 	: wangchen
 *****************************************************************************
 */
int nwy_sms_get_indices(nwy_sms_storage_type_e mem_store, nwy_sms_indices_t *p_list);


#ifdef __cplusplus
   }
#endif

#endif
