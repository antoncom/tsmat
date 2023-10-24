/*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====
    Copyright (c) 2018 Neoway Technologies, Inc.
    All rights reserved.
    Confidential and Proprietary - Neoway Technologies, Inc.
    Author: WangLei
    Date: 2018/5
*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*/

#ifndef __NWY_NW_H__
#define __NWY_NW_H__

#include "nwy_common.h"

#ifdef __cplusplus
extern "C" {
#endif
/*---------------------------Macro definition---------------------------*/
#define NWY_NW_EONS_MAX_LEN  512
#define NWY_NW_MNC_MCC_LEN   3
#define NWY_NW_SCAN_LIST_MAX 40
#define NWY_NW_FPLMN_LIST_MAX 64
#define NWY_NW_SPN_LEN_MAX    32

#define NWY_NW_MODE_NONE     0x00
#define NWY_NW_MODE_CDMA     0x01
#define NWY_NW_MODE_EVDO     0x02
#define NWY_NW_MODE_GSM      0x04
#define NWY_NW_MODE_WCDMA    0x08
#define NWY_NW_MODE_LTE      0x10
#define NWY_NW_MODE_INVALUE      0xFF
#define NAS_3GPP_FORBIDDEN_NETWORKS_LIST_MAX_V01 64
/*-----------------------------Type Definition---------------------------*/
typedef uint8 nwy_nw_mode_type_t;
enum sys_mode_ {
	E_NO_SERVICE,
	E_2G_3G,
	E_LTE,
	E_LTEP
};
typedef struct {
    char mcc[NWY_NW_MNC_MCC_LEN + 1];
    char mnc[NWY_NW_MNC_MCC_LEN + 1];
}nwy_nw_plmn_item_t;
typedef struct {
    int num;
    nwy_nw_plmn_item_t fplmn_list[NWY_NW_FPLMN_LIST_MAX];
}nwy_nw_fplmn_list_t;

/*typedef enum {
	CM_NW_STATUS_23G,
	CM_NW_STATUS_LTE,
	CM_NW_STATUS_NOT_REGISTERED = 3,
}nwy_nw_service_type_t;*/

typedef enum {
    NWY_NW_SERVICE_NONE     = 0,
    NWY_NW_SERVICE_LIMITED  = 1,
    NWY_NW_SERVICE_FULL     = 2,
}nwy_nw_service_type_t;
typedef enum {
    NWY_NW_ROAM_STATE_OFF = 0,
    NWY_NW_ROAM_STATE_ON = 1,
}nwy_nw_roam_state_t;

/*typedef enum {
    NWY_NW_RADIO_TECH_UNKNOWN = 0,
    NWY_NW_RADIO_TECH_GPRS = 1,
    NWY_NW_RADIO_TECH_EDGE = 2,
    NWY_NW_RADIO_TECH_UMTS = 3,
    NWY_NW_RADIO_TECH_IS95A = 4,
    NWY_NW_RADIO_TECH_IS95B = 5,
    NWY_NW_RADIO_TECH_1xRTT =  6,
    NWY_NW_RADIO_TECH_EVDO_0 = 7,
    NWY_NW_RADIO_TECH_EVDO_A = 8,
    NWY_NW_RADIO_TECH_HSDPA = 9,
    NWY_NW_RADIO_TECH_HSUPA = 10,
    NWY_NW_RADIO_TECH_HSPA = 11,
    NWY_NW_RADIO_TECH_EVDO_B = 12,
    NWY_NW_RADIO_TECH_EHRPD = 13,
    NWY_NW_RADIO_TECH_LTE = 14,
    NWY_NW_RADIO_TECH_HSPAP = 15, // HSPA+
    NWY_NW_RADIO_TECH_GSM = 16, // Only supports voice
    NWY_NW_RADIO_TECH_TD_SCDMA = 17,
    NWY_NW_RADIO_TECH_IWLAN = 18,
    NWY_NW_RADIO_TECH_LTEP = 19,
    NWY_NW_RADIO_TECH_DC_HSPA = 20
}nwy_nw_radio_tech_type_t;*/
typedef enum {
    NWY_NW_RADIO_TECH_TD_SCDMA = 1,
    NWY_NW_RADIO_TECH_GSM = 2,      //GSM; only supports voice.
    NWY_NW_RADIO_TECH_HSPAP = 3,    //HSPA+.
    NWY_NW_RADIO_TECH_LTE = 4,      //LTE.
    NWY_NW_RADIO_TECH_EHRPD = 5,    //EHRPD.
    NWY_NW_RADIO_TECH_EVDO_B = 6,   //EVDO B.
    NWY_NW_RADIO_TECH_HSPA = 7,     //HSPA.
    NWY_NW_RADIO_TECH_HSUPA = 8,    //HSUPA.
    NWY_NW_RADIO_TECH_HSDPA = 9,    //HSDPA.
    NWY_NW_RADIO_TECH_EVDO_A = 10,  //EVDO A.
    NWY_NW_RADIO_TECH_EVDO_0 = 11,  //EVDO 0.
    NWY_NW_RADIO_TECH_1xRTT = 12,   //1xRTT.
    NWY_NW_RADIO_TECH_IS95B = 13,   //IS95B.
    NWY_NW_RADIO_TECH_IS95A = 14,   //IS95A.
    NWY_NW_RADIO_TECH_UMTS = 15,    //UMTS.
    NWY_NW_RADIO_TECH_EDGE = 16,    //EDGE.
    NWY_NW_RADIO_TECH_GPRS = 17,    //GPRS.
    NWY_NW_RADIO_TECH_NONE = 18,    //No technology selected.
    NWY_NW_RADIO_TECH_IWLAN = 19,
    NWY_NW_RADIO_TECH_LTEP = 20,
    NWY_NW_RADIO_TECH_DC_HSPA = 21
}nwy_nw_radio_tech_type_t;

/*typedef struct {
    nwy_nw_radio_tech_type_t radio_tech;    //Radio technology; see #NWY_nw_radio_tech_t
    nwy_nw_service_type_t regs_state;       //Registration state
    nwy_nw_roam_state_t roam_state;

}nwy_nw_common_regs_type_t;

typedef struct {
    nwy_nw_common_regs_type_t data_regs;  //Data registration
}nwy_nw_regs_info_type_t;*/
typedef enum {
    NWY_NW_SPN_ENC_GSM7    = 0x00,   /* 7bit code */
    NWY_NW_SPN_ENC_UCS2    = 0x01,   /* UCS2 code */
}nwy_nw_spn_enc_t;

typedef struct {
    char long_eons[NWY_NW_EONS_MAX_LEN + 1];
    char short_eons[NWY_NW_EONS_MAX_LEN + 1];
    char mcc[NWY_NW_MNC_MCC_LEN + 1];
    char mnc[NWY_NW_MNC_MCC_LEN + 1];
    char spn[NWY_NW_SPN_LEN_MAX + 1];
    nwy_nw_spn_enc_t spn_enc;
}nwy_nw_operator_name_t;
typedef enum {
  NWY_RADIO_IF_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  NWY_RADIO_IF_NO_SVC_V01 = 0x00, 
  NWY_RADIO_IF_CDMA_1X_V01 = 0x01, 
  NWY_RADIO_IF_CDMA_1XEVDO_V01 = 0x02, 
  NWY_RADIO_IF_AMPS_V01 = 0x03, 
  NWY_RADIO_IF_GSM_V01 = 0x04, 
  NWY_RADIO_IF_UMTS_V01 = 0x05, 
  NWY_RADIO_IF_WLAN_V01 = 0x06, 
  NWY_RADIO_IF_GPS_V01 = 0x07, 
  NWY_RADIO_IF_LTE_V01 = 0x08, 
  NWY_RADIO_IF_TDSCDMA_V01 = 0x09, 
  NWY_RADIO_IF_NO_CHANGE_V01 = -1, 
  NWY_RADIO_IF_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}nwy_radio_if_enum_v01;
typedef enum {
    NWY_BANDWIDTH_ENUM_TYPE_MIN_ENUM_VAL_V01 = -2147483647,
    NWY_LTE_BW_NRB_6_V01 = 0, /**<  LTE 1.4 MHz bandwidth \n  */
    NWY_LTE_BW_NRB_15_V01 = 1, /**<  LTE 3 MHz bandwidth \n  */
    NWY_LTE_BW_NRB_25_V01 = 2, /**<  LTE 5 MHz bandwidth \n  */
    NWY_LTE_BW_NRB_50_V01 = 3, /**<  LTE 10 MHz bandwidth \n  */
    NWY_LTE_BW_NRB_75_V01 = 4, /**<  LTE 15 MHz bandwidth \n  */
    NWY_LTE_BW_NRB_100_V01 = 5, /**<  LTE 20 MHz bandwidth \n */
    NWY_NR5G_BW_NRB_6_V01 = 6, /**<  NR5G 1.4 MHz bandwidth \n  */
    NWY_NR5G_BW_NRB_15_V01 = 7, /**<  NR5G 3 MHz bandwidth \n  */
    NWY_NR5G_BW_NRB_25_V01 = 8, /**<  NR5G 5 MHz bandwidth \n  */
    NWY_NR5G_BW_NRB_50_V01 = 9, /**<  NR5G 10 MHz bandwidth \n  */
    NWY_NR5G_BW_NRB_75_V01 = 10, /**<  NR5G 15 MHz bandwidth \n  */
    NWY_NR5G_BW_NRB_100_V01 = 11, /**<  NR5G 20 MHz bandwidth  */
    NWY_BANDWIDTH_ENUM_TYPE_MAX_ENUM_VAL_V01 = 2147483647
}nwy_bandwidth_enum_type_v01;
typedef struct {
nwy_radio_if_enum_v01 radio_if;
/**<   Radio interface currently in use. Values: \n
    - NAS_RADIO_IF_NO_SVC (0x00) --  None (no service) \n
    - NAS_RADIO_IF_CDMA_1X (0x01) --  cdma2000\textsuperscript{\textregistered} 1X \n
    - NAS_RADIO_IF_CDMA_1XEVDO (0x02) --  cdma2000\textsuperscript{\textregistered} HRPD (1xEV-DO) \n
    - NAS_RADIO_IF_AMPS (0x03) --  AMPS \n
    - NAS_RADIO_IF_GSM (0x04) --  GSM \n
    - NAS_RADIO_IF_UMTS (0x05) --  UMTS \n
    - NAS_RADIO_IF_WLAN (0x06) --  WLAN \n
    - NAS_RADIO_IF_GPS (0x07) --  GPS \n
    - NAS_RADIO_IF_LTE (0x08) --  LTE \n
    - NAS_RADIO_IF_TDSCDMA (0x09) --  TD-SCDMA \n
    - NAS_RADIO_IF_NR5G (0x0C) --  NR5G \n
    - NAS_RADIO_IF_NO_CHANGE (-1) --  No change
*/
nwy_bandwidth_enum_type_v01 bandwidth;
/**<   Bandwidth. Values: \n
    - NAS_LTE_BW_NRB_6 (0) --  LTE 1.4 MHz bandwidth \n
    - NAS_LTE_BW_NRB_15 (1) --  LTE 3 MHz bandwidth \n
    - NAS_LTE_BW_NRB_25 (2) --  LTE 5 MHz bandwidth \n
    - NAS_LTE_BW_NRB_50 (3) --  LTE 10 MHz bandwidth \n
    - NAS_LTE_BW_NRB_75 (4) --  LTE 15 MHz bandwidth \n
    - NAS_LTE_BW_NRB_100 (5) --  LTE 20 MHz bandwidth \n
    - NAS_NR5G_BW_NRB_6 (6) --  NR5G 1.4 MHz bandwidth \n
    - NAS_NR5G_BW_NRB_15 (7) --  NR5G 3 MHz bandwidth \n
    - NAS_NR5G_BW_NRB_25 (8) --  NR5G 5 MHz bandwidth \n
    - NAS_NR5G_BW_NRB_50 (9) --  NR5G 10 MHz bandwidth \n
    - NAS_NR5G_BW_NRB_75 (10) --  NR5G 15 MHz bandwidth \n
    - NAS_NR5G_BW_NRB_100 (11) --  NR5G 20 MHz bandwidth
*/
}nwy_rf_bandwidth_info_type;
typedef enum {
  NWY_ACTIVE_BAND_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  NWY_ACTIVE_BAND_BC_0_V01 = 0, 
  NWY_ACTIVE_BAND_BC_1_V01 = 1, 
  NWY_ACTIVE_BAND_BC_3_V01 = 3, 
  NWY_ACTIVE_BAND_BC_4_V01 = 4, 
  NWY_ACTIVE_BAND_BC_5_V01 = 5, 
  NWY_ACTIVE_BAND_BC_6_V01 = 6, 
  NWY_ACTIVE_BAND_BC_7_V01 = 7, 
  NWY_ACTIVE_BAND_BC_8_V01 = 8, 
  NWY_ACTIVE_BAND_BC_9_V01 = 9, 
  NWY_ACTIVE_BAND_BC_10_V01 = 10, 
  NWY_ACTIVE_BAND_BC_11_V01 = 11, 
  NWY_ACTIVE_BAND_BC_12_V01 = 12, 
  NWY_ACTIVE_BAND_BC_13_V01 = 13, 
  NWY_ACTIVE_BAND_BC_14_V01 = 14, 
  NWY_ACTIVE_BAND_BC_15_V01 = 15, 
  NWY_ACTIVE_BAND_BC_16_V01 = 16, 
  NWY_ACTIVE_BAND_BC_17_V01 = 17, 
  NWY_ACTIVE_BAND_BC_18_V01 = 18, 
  NWY_ACTIVE_BAND_BC_19_V01 = 19, 
  NWY_ACTIVE_BAND_GSM_450_V01 = 40, 
  NWY_ACTIVE_BAND_GSM_480_V01 = 41, 
  NWY_ACTIVE_BAND_GSM_750_V01 = 42, 
  NWY_ACTIVE_BAND_GSM_850_V01 = 43, 
  NWY_ACTIVE_BAND_GSM_900_EXTENDED_V01 = 44, 
  NWY_ACTIVE_BAND_GSM_900_PRIMARY_V01 = 45, 
  NWY_ACTIVE_BAND_GSM_900_RAILWAYS_V01 = 46, 
  NWY_ACTIVE_BAND_GSM_1800_V01 = 47, 
  NWY_ACTIVE_BAND_GSM_1900_V01 = 48, 
  NWY_ACTIVE_BAND_WCDMA_2100_V01 = 80, 
  NWY_ACTIVE_BAND_WCDMA_PCS_1900_V01 = 81, 
  NWY_ACTIVE_BAND_WCDMA_DCS_1800_V01 = 82, 
  NWY_ACTIVE_BAND_WCDMA_1700_US_V01 = 83, 
  NWY_ACTIVE_BAND_WCDMA_850_V01 = 84, 
  NWY_ACTIVE_BAND_WCDMA_800_V01 = 85, 
  NWY_ACTIVE_BAND_WCDMA_2600_V01 = 86, 
  NWY_ACTIVE_BAND_WCDMA_900_V01 = 87, 
  NWY_ACTIVE_BAND_WCDMA_1700_JAPAN_V01 = 88, 
  NWY_ACTIVE_BAND_WCDMA_1500_JAPAN_V01 = 90, 
  NWY_ACTIVE_BAND_WCDMA_850_JAPAN_V01 = 91, 
  NWY_ACTIVE_BAND_E_UTRA_OPERATING_BAND_1_V01 = 120, 
  NWY_ACTIVE_BAND_E_UTRA_OPERATING_BAND_2_V01 = 121, 
  NWY_ACTIVE_BAND_E_UTRA_OPERATING_BAND_3_V01 = 122, 
  NWY_ACTIVE_BAND_E_UTRA_OPERATING_BAND_4_V01 = 123, 
  NWY_ACTIVE_BAND_E_UTRA_OPERATING_BAND_5_V01 = 124, 
  NWY_ACTIVE_BAND_E_UTRA_OPERATING_BAND_6_V01 = 125, 
  NWY_ACTIVE_BAND_E_UTRA_OPERATING_BAND_7_V01 = 126, 
  NWY_ACTIVE_BAND_E_UTRA_OPERATING_BAND_8_V01 = 127, 
  NWY_ACTIVE_BAND_E_UTRA_OPERATING_BAND_9_V01 = 128, 
  NWY_ACTIVE_BAND_E_UTRA_OPERATING_BAND_10_V01 = 129, 
  NWY_ACTIVE_BAND_E_UTRA_OPERATING_BAND_11_V01 = 130, 
  NWY_ACTIVE_BAND_E_UTRA_OPERATING_BAND_12_V01 = 131, 
  NWY_ACTIVE_BAND_E_UTRA_OPERATING_BAND_13_V01 = 132, 
  NWY_ACTIVE_BAND_E_UTRA_OPERATING_BAND_14_V01 = 133, 
  NWY_ACTIVE_BAND_E_UTRA_OPERATING_BAND_17_V01 = 134, 
  NWY_ACTIVE_BAND_E_UTRA_OPERATING_BAND_33_V01 = 135, 
  NWY_ACTIVE_BAND_E_UTRA_OPERATING_BAND_34_V01 = 136, 
  NWY_ACTIVE_BAND_E_UTRA_OPERATING_BAND_35_V01 = 137, 
  NWY_ACTIVE_BAND_E_UTRA_OPERATING_BAND_36_V01 = 138, 
  NWY_ACTIVE_BAND_E_UTRA_OPERATING_BAND_37_V01 = 139, 
  NWY_ACTIVE_BAND_E_UTRA_OPERATING_BAND_38_V01 = 140, 
  NWY_ACTIVE_BAND_E_UTRA_OPERATING_BAND_39_V01 = 141, 
  NWY_ACTIVE_BAND_E_UTRA_OPERATING_BAND_40_V01 = 142, 
  NWY_ACTIVE_BAND_E_UTRA_OPERATING_BAND_18_V01 = 143, 
  NWY_ACTIVE_BAND_E_UTRA_OPERATING_BAND_19_V01 = 144, 
  NWY_ACTIVE_BAND_E_UTRA_OPERATING_BAND_20_V01 = 145, 
  NWY_ACTIVE_BAND_E_UTRA_OPERATING_BAND_21_V01 = 146, 
  NWY_ACTIVE_BAND_E_UTRA_OPERATING_BAND_24_V01 = 147, 
  NWY_ACTIVE_BAND_E_UTRA_OPERATING_BAND_25_V01 = 148, 
  NWY_ACTIVE_BAND_E_UTRA_OPERATING_BAND_41_V01 = 149, 
  NWY_ACTIVE_BAND_E_UTRA_OPERATING_BAND_42_V01 = 150, 
  NWY_ACTIVE_BAND_E_UTRA_OPERATING_BAND_43_V01 = 151, 
  NWY_ACTIVE_BAND_E_UTRA_OPERATING_BAND_23_V01 = 152, 
  NWY_ACTIVE_BAND_E_UTRA_OPERATING_BAND_26_V01 = 153, 
  NWY_ACTIVE_BAND_TDSCDMA_BAND_A_V01 = 200, 
  NWY_ACTIVE_BAND_TDSCDMA_BAND_B_V01 = 201, 
  NWY_ACTIVE_BAND_TDSCDMA_BAND_C_V01 = 202, 
  NWY_ACTIVE_BAND_TDSCDMA_BAND_D_V01 = 203, 
  NWY_ACTIVE_BAND_TDSCDMA_BAND_E_V01 = 204, 
  NWY_ACTIVE_BAND_TDSCDMA_BAND_F_V01 = 205, 
  NWY_ACTIVE_BAND_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}nwy_active_band_enum_v01;
//typedef enum {
  //NWY_RADIO_IF_ENUM_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  /*NWY_RADIO_IF_NO_SVC_V01 = 0x00, 
  NWY_RADIO_IF_CDMA_1X_V01 = 0x01, 
  NWY_RADIO_IF_CDMA_1XEVDO_V01 = 0x02, 
  NWY_RADIO_IF_AMPS_V01 = 0x03, 
  NWY_RADIO_IF_GSM_V01 = 0x04, 
  NWY_RADIO_IF_UMTS_V01 = 0x05, 
  NWY_RADIO_IF_WLAN_V01 = 0x06, 
  NWY_RADIO_IF_GPS_V01 = 0x07, 
  NWY_RADIO_IF_LTE_V01 = 0x08, 
  NWY_RADIO_IF_TDSCDMA_V01 = 0x09, 
  NWY_RADIO_IF_NO_CHANGE_V01 = -1, 
  NWY_RADIO_IF_ENUM_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
//}nwy_radio_if_enum_v01;
typedef struct {
    uint8 regs_reject_info_valid;
    uint8 regs_rej_cause;
    int rej_srv_domain; 
    /*- 0x00 -- SYS_SRV_DOMAIN_NO_SRV  -- No service \n
      - 0x01 -- SYS_SRV_DOMAIN_CS_ONLY -- Circuit-switched only \n
      - 0x02 -- SYS_SRV_DOMAIN_PS_ONLY -- Packet-switched only \n
      - 0x03 -- SYS_SRV_DOMAIN_CS_PS   -- Circuit-switched and packet-switched \n
      - 0x04 -- SYS_SRV_DOMAIN_CAMPED  -- Camped*/
}nwy_nw_res_reject_info;
typedef struct {
  nwy_radio_if_enum_v01 radio_if;
  /**<   Radio interface currently in use. Values:  \n
       - 0x01 -- cdma2000\textsuperscript{\textregistered} 1X             \n
       - 0x02 -- cdma2000\textsuperscript{\textregistered} HRPD (1xEV-DO) \n
       - 0x03 -- AMPS \n
       - 0x04 -- GSM \n
       - 0x05 -- UMTS \n
       - 0x08 -- LTE \n
       - 0x09 -- TD-SCDMA
  */

  nwy_active_band_enum_v01 active_band;
  /**<   Active band class (see Table @latexonly\ref{tbl:bandClass}@endlatexonly 
      for details). Values: \n
      - 00 to 39   -- CDMA band classes  \n
      - 40 to 79   -- GSM band classes   \n
      - 80 to 91   -- WCDMA band classes \n
      - 120 to 153 -- LTE band classes   \n
      - 200 to 205 -- TD-SCDMA band classes
  */

  uint16_t active_channel;
  /**<   Active channel. If the channel is not relevant to the
      technology, a value of 0 will be returned.
 */
}nwy_rf_band_info_type;  /* Type */
typedef enum {
    NWY_NW_TECH_DOMAIN_NONE  = 0, //  None
    NWY_NW_TECH_DOMAIN_3GPP  = 1, //  3GPP
    NWY_NW_TECH_DOMAIN_3GPP2 = 2, //  3GPP2
}nwy_nw_tech_domain_type_t;
typedef struct {
    nwy_nw_tech_domain_type_t tech_domain;  //Technology, used to determine the structure type
    nwy_nw_radio_tech_type_t radio_tech;    //Radio technology; see #NWY_nw_radio_tech_t
    nwy_nw_service_type_t regs_state;       //Registration state
    nwy_nw_roam_state_t roam_state;
    nwy_nw_res_reject_info reject_info;
    nwy_rf_band_info_type rf_band_info;
    uint8 rf_bandwidth_info_valid;
    nwy_rf_bandwidth_info_type rf_bandwidth_info;
}nwy_nw_common_regs_type_t;

typedef struct {
    uint8 voice_regs_valid;
    nwy_nw_common_regs_type_t voice_regs; //Voice registration
    uint8 data_regs_valid;
    nwy_nw_common_regs_type_t data_regs;  //Data registration
    nwy_nw_res_reject_info reject_info;
}nwy_nw_regs_info_type_t;

typedef enum {
    NWY_NW_NET_STAT_UNKNOWN    = 0,   /* Network state unknown */
    NWY_NW_NET_STAT_AVAILABLE,        /* Network is available for registration */
    NWY_NW_NET_STAT_CURRENT,          /* Network currently registered */
    NWY_NW_NET_STAT_FORBIDDEN,        /* Network forbidden registraiton */
}nwy_nw_net_status_t;

typedef enum {
    NWY_NW_NET_RAT_UNKNOWN, 
    NWY_NW_NET_RAT_GERAN,
    NWY_NW_NET_RAT_UMTS,
    NWY_NW_NET_RAT_LTE,
    NWY_NW_NET_RAT_TDS,
/*Begin:Add by huangweigang for support NR5G in 2021.8.21*/
    NWY_NW_NET_RAT_NR5G,
/*Begin:Add by huangweigang for support NR5G in 2021.8.21*/
}nwy_nw_net_rat_t;

typedef struct {
    nwy_nw_net_status_t net_status;
    nwy_nw_net_rat_t net_rat;
    nwy_nw_operator_name_t net_name;
}nwy_nw_net_scan_item_t;

typedef struct {
    int result;
    int net_num;
    nwy_nw_net_scan_item_t net_list[NWY_NW_SCAN_LIST_MAX];
}nwy_nw_net_scan_rsp_list_t;
typedef struct {
    char mcc[NWY_NW_MNC_MCC_LEN + 1];
    char mnc[NWY_NW_MNC_MCC_LEN + 1];
    nwy_nw_net_rat_t net_rat;
}nwy_nw_net_select_param_t;

typedef void (*nwy_nw_net_scan_cb_func) 
(
    nwy_nw_net_scan_rsp_list_t *net_list
);
typedef enum {
    NWY_NW_REGS_NONE = -1,
    NWY_NW_REGS_DATA_IND = 0,   // data register state event
    NWY_NW_REGS_VOICE_IND = 1,  // voice register state event
}nwy_nw_regs_ind_type_t;
typedef void (*nwy_nw_cb_func)
(
    nwy_nw_regs_ind_type_t ind_type,
    void *ind_struct
);
/*---------------------------Function Definition--------------------------*/
int nwy_nw_get_register_info(nwy_nw_regs_info_type_t *regs_info);
int nwy_nw_get_operator_name(nwy_nw_operator_name_t *opt_name);
int nwy_nw_get_signal_csq(int *csq_val);
int nwy_nw_get_network_mode(nwy_nw_mode_type_t *p_nw_mode);
int nwy_nw_set_network_mode(nwy_nw_mode_type_t nw_mode);
int nwy_nw_get_signal_rssi(int *rssi_val);
int nwy_nw_get_forbidden_plmn(nwy_nw_fplmn_list_t *fplmn_list);
int nwy_nw_manual_network_select(nwy_nw_net_select_param_t *net_select);
int nwy_nw_manual_network_scan(nwy_nw_net_scan_cb_func scan_cb);
int nwy_nw_register_callback_func(nwy_nw_cb_func cb);
int nwy_nw_unregister_callback_func();
#ifdef __cplusplus
   }
#endif

#endif //__NWY_NW_H__