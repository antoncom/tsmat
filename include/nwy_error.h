/*====*====*====*====*====*====*====*====*====*====*====*====
  Copyright (c) 2021 Neoway Technologies, Inc.
  All rights reserved.
  Confidential and Proprietary - Neoway Technologies, Inc.
  Author: ZhanYanhong
  Date: 2021/11/8
 *====*====*====*====*====*====*====*====*====*====*====*====*/

#ifndef __NWY_ERROR_H__
#define __NWY_ERROR_H__

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    NWY_RES_OK                     = 0,

    NWY_GEN_E_UNKNOWN              = -1,
    NWY_GEN_E_INVALID_PARA         = -2,
    NWY_GEN_E_OUT_MEMORY           = -3,
    NWY_GEN_E_UBUS_CON_FAIL		   = -4,
    NWY_GEN_E_UBUS_SRV_INVALID = -5,
    NWY_GEN_E_UBUS_METHOD_INVALID = -6,
    NWY_GEN_E_UBUS_REQUEST_FAIL= -7,
    NWY_GEN_E_BLOBMSG_PARSE_FAIL=-8,
    NWY_GEN_E_GPRS_NOT_ACT = -9,
    NWY_GEN_E_AREADY_CONNECT = -10,
    NWY_GEN_E_NOT_IMPLEMENTED      = -11,
    NWY_GEN_E_UBUS_INIT_FAIL = -12,
    NWY_GEN_E_UBUS_SUBSCRIBE_FAIL = -13,
	NWY_GEN_E_UBUS_PM_SLEPP = -14,
	NWY_GEN_E_UBUS_INVALID_COMMAND = -15,
	NWY_GEN_E_UBUS_INVALID_ARGUMENT = -16,
	NWY_GEN_E_UBUS_METHOD_NOT_FOUND = -17,
	NWY_GEN_E_UBUS_NOT_FOUND = -18,
	NWY_GEN_E_UBUS_NO_DATA = -19,
	NWY_GEN_E_UBUS_PERMISSION_DENIED = -20,
	NWY_GEN_E_UBUS_TIMEOUT = -21,
	NWY_GEN_E_UBUS_NOT_SUPPORTED = -22,
	NWY_GEN_E_UBUS_UNKNOWN_ERROR = -23,
	NWY_GEN_E_UBUS_CONNECTION_FAILED = -24,

    NWY_SMS_E_UNKNOWN              = -100,
    NWY_SMS_E_QMI                  = NWY_SMS_E_UNKNOWN - 1,
    NWY_SMS_E_MCM                  = NWY_SMS_E_UNKNOWN - 2,
    NWY_SMS_E_DEVICE_NOT_READY     = NWY_SMS_E_UNKNOWN - 3,
    NWY_SMS_E_INVALID_INDEX        = NWY_SMS_E_UNKNOWN - 4,
    NWY_SMS_E_NO_ENTRY             = NWY_SMS_E_UNKNOWN - 5,
    NWY_SMS_E_BUSY                 = NWY_SMS_E_UNKNOWN - 6,
    NWY_SMS_E_TIMEOUT              = NWY_SMS_E_UNKNOWN - 7,

    NWY_DATA_E_UNKNOWN             = -200,
    NWY_DATA_E_PROFILE_ID_INVALID  = NWY_DATA_E_UNKNOWN-1,
	NWY_DATA_E_IA_PROFILE_OK_PS_FAIL  = NWY_DATA_E_UNKNOWN-2,

    NWY_SIM_E_UNKNOWN              = -300,
    NWY_SIM_E_INCORRECT_PWD        = -301,
    NWY_SIM_E_PUK_REQUIRED         = -302,
    NWY_SIM_E_PERM_BLOCKED         = -303,

    NWY_WIFI_E_UNKNOWN             = -400,
    NWY_WIFI_E_CREAT_CFG_FAIL      = -401,
    NWY_WIFI_E_WIFI_DISABLED       = -402,
    NWY_WIFI_E_WIFI_ENABLED        = -403,
    NWY_WIFI_E_OPRT_NOT_ALLOWED    = -404,

    NWY_VOICE_E_UNKNOWN            = -500,
    NWY_VOICE_E_QMI                = NWY_VOICE_E_UNKNOWN - 1,
    NWY_VOICE_E_MCM                = NWY_VOICE_E_UNKNOWN - 2,

    NWY_AUDIO_E_UNKNOWN            = -600,
    NWY_AUDIO_E_PCM                = NWY_AUDIO_E_UNKNOWN - 1,
    NWY_AUDIO_E_NO_SPACE           = NWY_AUDIO_E_UNKNOWN - 2,

    NWY_LOC_E_UNKNOWN              = -700,
    NWY_LOC_E_MCM                  = NWY_LOC_E_UNKNOWN - 1,
    NWY_LOC_E_QMI                  = NWY_LOC_E_UNKNOWN - 2,
    NWY_LOC_E_TIMEOUT              = NWY_LOC_E_UNKNOWN - 3,
    NWY_LOC_E_INIT                 = NWY_LOC_E_UNKNOWN - 4,

    NWY_AT_E_UNKNOWN              = -800,
	NWY_AT_E_UNREG_UNSOCLICITD	  = NWY_AT_E_UNKNOWN-1,
	NWY_AT_E_SEND_FAILED		  = NWY_AT_E_UNKNOWN-2,
	NWY_AT_E_AT_RESP_FAILED		  = NWY_AT_E_UNKNOWN-3,
	NWY_AT_E_INVALID_AT		      = NWY_AT_E_UNKNOWN-4,
	NWY_AT_E_TIMEOUT              = NWY_AT_E_UNKNOWN-5,
	
    NWY_ETH_E_UNKNOWN             = -900,
	
	NWY_GPIO_E_UNKNOWN			  = -1000,

	NWY_PM_E_UNKNOWN                = -1100,
	NWY_PM_E_NOT_SUPPORT            = -1101,
	NWY_PM_E_OPEN_FAILED            = -1102,
	NWY_PM_E_WRITE_FAILED           = -1103,
	NWY_PM_E_READ_FAILED            = -1104,
    
	NWY_FOTA_E_UNKNOWN			  = -1200,			

	NWY_ITEMS_E_UNKNOWN			  = -1300,
	
	NWY_WWAN_E_UNKNOWN			  = -1400,


	NWY_UART_RECV_FAILED          = -1450,
	NWY_UART_SEND_FAILED          = -1451,

} nwy_error_e;



#ifdef __cplusplus
   }
#endif

#endif //__NWY_ERROR_H__
