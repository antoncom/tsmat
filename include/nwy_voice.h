/*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====
    Copyright (c) 2021 Neoway Technologies, Inc.
    All rights reserved.
    Confidential and Proprietary - Neoway Technologies, Inc.
    Author: gaohe
    Date: 2022/2/14
*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*/
#ifndef __NWY_VOICE_H__
#define __NWY_VOICE_H__
#include <stdint.h>
#include "nwy_error.h"
#include "nwy_log.h"
#include "libubus.h"

#ifdef __cplusplus
extern "C" {
#endif
/*---------------------------Macro definition---------------------------*/

#define NWY_MAX_VOICE_CALLS             8   // GSM provides up to 8 calls; 3GPP2 provides 2.
#define NWY_MAX_PHONE_NUMBER            82  // Maximum length for a phone number or SIP URI (81 + NULL).
#define NWY_MAX_DTMF_LENGTH             20  // Maximum DTMF length.
#define NWY_MAX_PASSWORD_LENGTH         4   // Maximum password length.
#define NWY_MAX_CALL_FORWARDING_INFO    13  // Maximum call forwarding information.
#define NWY_MAX_ECALL_PARA_LEN      300
#define NWY_MAX_AT_STRLEN       128
#define NWY_MAX_ECALLMSD_STR_LEN        280
#define NWY_MAX_ECALL_MSD               140 // Maximum size of the MSD sent to the network with an eCall
#define NWY_ECALL_SIZEOF_VIN			(20)
#define NWY_ECALL_MSD_LENGTH_FOR_V_2	(31)
#define uint8  unsigned char
typedef signed long int  int32;

/*---------------------- Type Definition ---------------------------------*/
typedef  unsigned long  dword;        /* Unsigned 32 bit value type. */
typedef  uint16_t      	word;        /* Unsigned 16 bit value type. */
typedef  uint8 		boolean;
typedef char nwy_ecall_vehicle_id_number[NWY_ECALL_SIZEOF_VIN + 1];
typedef dword nwy_ecall_timestamp_type;
typedef int32 nwy_ecall_pos_type;
typedef uint8 nwy_ecall_msd_array_type[NWY_MAX_ECALL_MSD];

#define NWY_ECALL_SIZEOF_TIMESTAMP		(sizeof(nwy_ecall_timestamp_type))
#define NWY_ECALL_SIZEOF_POS_MILLIARCSEC	(sizeof(nwy_ecall_pos_type))

typedef enum {
    NWY_VOICE_CALL_IND = 0, // Voice call msg
    NWY_VOICE_MUTE_IND = 1, // Voice mute msg
    NWY_VOICE_DTMF_IND = 2, // Voice dtmf msg
}nwy_voice_ind_type_t;

typedef enum {
    NWY_VOICE_CALL_MOBILE_ORIGINATED_V01 = 1, // Mobile-originated.
    NWY_VOICE_CALL_MOBILE_TERMINATED_V01 = 2, // Mobile-terminated.
}nwy_voice_call_direction_type_t;

typedef enum {
    NWY_VOICE_CALL_STATE_INCOMING      = 0x0000, /**< MT incoming; CC setup. */
    NWY_VOICE_CALL_STATE_DIALING       = 0x0001, /**< Dialing state. */
    NWY_VOICE_CALL_STATE_ALERTING      = 0x0002, /**< MT call waiting; MO alterting. */
    NWY_VOICE_CALL_STATE_ACTIVE        = 0x0003, /**< Call is active. */
    NWY_VOICE_CALL_STATE_HOLDING       = 0x0004, /**< Call is on hold. */
    NWY_VOICE_CALL_STATE_END           = 0x0005, /**< Call is disconnected. */
    NWY_VOICE_CALL_STATE_WAITING       = 0x0006, /**< Call is waiting. */
} nwy_vc_call_state_t;/* ----------  end of enum nwy_vc_call_state_e  ---------- */


typedef enum {
  NWY_CALL_MODE_NO_SRV = 0x00, /**<  No service \n  */
  NWY_CALL_MODE_CDMA = 0x01, /**<  CDMA \n  */
  NWY_CALL_MODE_GSM = 0x02, /**<  GSM \n  */
  NWY_CALL_MODE_UMTS = 0x03, /**<  UMTS \n  */
  NWY_CALL_MODE_LTE = 0x04, /**<  LTE \n  */
  NWY_CALL_MODE_TDS = 0x05, /**<  TD-SCDMA \n  */
  NWY_CALL_MODE_UNKNOWN = 0x06, /**<  Unknown \n  */
  NWY_CALL_MODE_WLAN = 0x07, /**<  WLAN  */
} nwy_call_mode_e;

typedef enum {
  NWY_CALL_TYPE_VOICE = 0x00, /**<  Voice \n  */
  NWY_CALL_TYPE_VOICE_FORCED = 0x01, /**<  Avoid modem call classification \n  */
  NWY_CALL_TYPE_VOICE_IP = 0x02, /**<  Voice over IP  \n  */
  NWY_CALL_TYPE_VT = 0x03, /**<  Videotelephony call over IP \n  */
  NWY_CALL_TYPE_VIDEOSHARE = 0x04, /**<  Videoshare \n  */
  NWY_CALL_TYPE_TEST = 0x05, /**<  Test call type \n  */
  NWY_CALL_TYPE_OTAPA = 0x06, /**<  OTAPA \n  */
  NWY_CALL_TYPE_STD_OTASP = 0x07, /**<  Standard OTASP \n  */
  NWY_CALL_TYPE_NON_STD_OTASP = 0x08, /**<  Nonstandard OTASP \n  */
  NWY_CALL_TYPE_EMERGENCY = 0x09, /**<  Emergency \n  */
  NWY_CALL_TYPE_SUPS = 0x0A, /**<  Supplementary service \n  */
  NWY_CALL_TYPE_EMERGENCY_IP = 0x0B, /**<  Emergency VoIP \n  */
  NWY_CALL_TYPE_ECALL = 0x0C, /**<  eCall \n  */
  NWY_CALL_TYPE_EMERGENCY_VT = 0x0D, /**<  Emergency videotelephony call over IP  */
} nwy_call_type_e;

typedef enum
{
	AL_ACK_signal_received = 0,
	eIM_lost_synchronization_with_PSAP = 1,
	NACK_signal_received = 2,
	eIM_is_terminated_fatal_error = 6,
	eIM_is_terminated_call_drop = 7,
	Generic_error = 8,
	Request_MSD = 9,
	Start_Send_MSD = 10,
	eIM_starts_sending = 11,
	Send_MSD_signal_received = 12,
	Send_MSD_signal_received_too_often = 13,
	IVS_eIM_is_synced_with_PSAP = 14,
	IVS_eIM_is_synced_with_PSAP_eIM = 15,
	Link_layer_ACK_received = 16,
	Higher_Layer_ACK_received = 17,
	eIM_transmitter_idles_after_reset = 18,
	eIM_transmitter_idles_after_transmission = 19,
	MSD_update_request_is_received  = 20,
	MSD_update_is_done = 21,
	MSD_update_request_cannot_processed = 22,
	T3_expired = 23,
	T5_expired = 24,
	T6_expired= 25,
	T7_expired= 26,
	Reserved
}nwy_ecall_data_state;


typedef struct {
    uint32_t call_id;                            // Call ID associated with this call.
    nwy_vc_call_state_t state;         // Current call state (mcm_voice_call_state).
    char number[NWY_MAX_PHONE_NUMBER + 1];     // Phone number.
    nwy_voice_call_direction_type_t direction; // Voice call direction.
    nwy_call_mode_e call_mode;
    nwy_call_type_e call_type;
    nwy_ecall_data_state  ecall_data;
}nwy_voice_call_record_type_t;

/* call record */
typedef struct {
    uint32_t calls_num;  // connect call number.
    nwy_voice_call_record_type_t calls[NWY_MAX_VOICE_CALLS]; // Calls.
}nwy_voice_call_info_type_t;

typedef struct {
    uint8_t is_mute;  // Indicates whether a call is muted. */
}nwy_voice_mute_info_type_t;

typedef enum {
    NWY_VOICE_DTMF_EVENT_BURST = 0,      // Burst DTMF.
    NWY_VOICE_DTMF_EVENT_START_CONT = 1, // Continuous DTMF start.
    NWY_VOICE_DTMF_EVENT_STOP_CONT = 2,  // Continuous DTMF stop.
}nwy_voice_dtmf_event_type_t;

// DTMF information.
typedef struct {
    uint32_t call_id;    // Call ID associated with this DTMF event.
    nwy_voice_dtmf_event_type_t dtmf_event;   // DTMF event type.
    uint32_t digit_len;  // Must be set to the number of elements in digit.
    char digit[NWY_MAX_DTMF_LENGTH];
}nwy_voice_dtmf_info_type_t;

typedef uint32_t  nwy_voice_client_t;

typedef struct {
    uint8_t is_valid;
  uint8_t call_id;
  /**<   Unique call identifier for the call.
  */

  uint8_t call_state;
  /**<   Call state. Values: \n
       - 0x01 -- CALL_STATE_ORIGINATION    -- Origination \n
       - 0x02 -- CALL_STATE_INCOMING       -- Incoming \n
       - 0x03 -- CALL_STATE_CONVERSATION   -- Conversation \n
       - 0x04 -- CALL_STATE_CC_IN_PROGRESS -- Call is originating but waiting \n
                                              for call control to complete \n
       - 0x05 -- CALL_STATE_ALERTING       -- Alerting \n
       - 0x06 -- CALL_STATE_HOLD           -- Hold \n
       - 0x07 -- CALL_STATE_WAITING        -- Waiting \n
       - 0x08 -- CALL_STATE_DISCONNECTING  -- Disconnecting \n
       - 0x09 -- CALL_STATE_END            -- End \n
       - 0x0A -- CALL_STATE_SETUP          -- MT call is in Setup state in 3GPP
  */

  uint8_t call_type;
  /**<   Call type. Values: \n
       - 0x00 -- CALL_TYPE_VOICE         -- Voice \n
       - 0x02 -- CALL_TYPE_VOICE_IP      -- Voice over IP \n
       - 0x03 -- CALL_TYPE_VT            -- Videotelephony call over IP \n
       - 0x04 -- CALL_TYPE_VIDEOSHARE    -- Videoshare \n
       - 0x05 -- CALL_TYPE_TEST          -- Test call type \n       
       - 0x06 -- CALL_TYPE_OTAPA         -- OTAPA \n
       - 0x07 -- CALL_TYPE_STD_OTASP     -- Standard OTASP \n
       - 0x08 -- CALL_TYPE_NON_STD_OTASP -- Nonstandard OTASP \n
       - 0x09 -- CALL_TYPE_EMERGENCY     -- Emergency \n
       - 0x0A -- CALL_TYPE_SUPS          -- Supplementary service \n
       - 0x0B -- CALL_TYPE_EMERGENCY_IP  -- Emergency VoIP \n
       - 0x0D -- CALL_TYPE_EMERGENCY_VT  -- Emergency videotelephony call over IP
  */

  uint8_t direction;
  /**<   Direction. Values: \n
       - 0x01 -- CALL_DIRECTION_MO -- MO call \n
       - 0x02 -- CALL_DIRECTION_MT -- MT call
  */

  uint8_t mode;
  /**<   Mode. Values: \n
      - CALL_MODE_NO_SRV (0x00) --  No service \n 
      - CALL_MODE_CDMA (0x01) --  CDMA \n 
      - CALL_MODE_GSM (0x02) --  GSM \n 
      - CALL_MODE_UMTS (0x03) --  UMTS \n 
      - CALL_MODE_LTE (0x04) --  LTE \n 
      - CALL_MODE_TDS (0x05) --  TD-SCDMA \n 
      - CALL_MODE_UNKNOWN (0x06) --  Unknown \n 
      - CALL_MODE_WLAN (0x07) --  WLAN 
 */

  uint8_t is_mpty;
  /**<   Multiparty indicator. Values: \n
       - 0x00 -- FALSE \n
       - 0x01 -- TRUE
  */

  uint8_t als;
  /**<   ALS line indicator. Values: \n
       - 0x00 -- ALS_LINE1 -- Line 1 (default) \n
       - 0x01 -- ALS_LINE2 -- Line 2
  */
} nwy_call_info;
/* ----------  end of struct nwy_call_all_info  ---------- */



typedef void (*nwy_voice_statehandlerfunc)
(
    int                     call_id,
    char*                   phone_num,
    nwy_vc_call_state_t     state,
    void                    *contextPtr
);

typedef enum
{
	ECALL_MANUAL_INITIATED = 0,
	ECALL_AUTOMATIC_INITIATED
}nwy_ecall_activation_type;

typedef enum
{
	ECALL_EMERGENCY= 0,
	ECALL_TEST 	
}nwy_ecall_type_of_call;

typedef enum
{
	ecall_test = 0,
        ecall_reconfiguration,
        ecall_manually_initiated,
        ecall_automatically_initiated,
        ecall_not_activated,
        ecall_release 
}nwy_ecall_option;

typedef enum
{
	Low_confidence_in_position= 0,
	Position_can_be_trusted	
}nwy_ecall_position_trusted;

typedef enum
{
	passengerVehicleClassM1 = 1,
	busesAndCoachesClassM2,
	busesAndCoachesClassM3,
	lightCommercialVehiclesClassN1,
	heavyDutyVehiclesClassN2,
	heavyDutyVehiclesClassN3,
	motorcyclesClassL1e,
	motorcyclesClassL2e,
	motorcyclesClassL3e,
	motorcyclesClassL4e,
	motorcyclesClassL5e,
	motorcyclesClassL6e,
	motorcyclesClassL7e	
}nwy_ecall_vehicle_e_type;

typedef struct
{
	nwy_ecall_activation_type activation; /* manualActivation (0) / automaticActivation (1) */
	nwy_ecall_type_of_call callType;		
	nwy_ecall_position_trusted positionconfidence;
	nwy_ecall_vehicle_e_type ecall_vehicletype;
}nwy_ecall_control_info_s_type;

typedef struct
{
	boolean gasolineTankPresent;
	boolean dieselTankPresent;
	boolean compressedNaturalGas;
	boolean liquidPropaneGas;
	boolean electricEnergyStorage;
	boolean hydrogenStorage;
	boolean otherStorage;
}nwy_ecall_vehicle_propulsionstorage_s_type;

typedef struct
{
	nwy_ecall_pos_type positionlatitude;
	nwy_ecall_pos_type positionlongitude;
}nwy_ecall_vehicle_location_s_type;

typedef struct
{
    int latitudeDelta;
    int longitudeDelta;
}nwy_ecall_vehiclelocationN1delta_s_type;

typedef struct
{
    int latitudeDelta;
    int longitudeDelta;
}nwy_ecall_vehiclelocationN2delta_s_type;

typedef struct
{
	uint8 ecall_messageI_dentifier_valid;
	uint8 ecall_messageidentifier;
	
	uint8 ecall_control_info_valid;	
	nwy_ecall_control_info_s_type ecall_control_info;

	uint8 ecall_vin_valid;
	nwy_ecall_vehicle_id_number ecall_vin;
	
	uint8 ecall_vehicle_propulsionstorage_valid;
	nwy_ecall_vehicle_propulsionstorage_s_type ecall_vehicle_propulsionstorage;

	uint8 ecall_timestamp_valid;
	nwy_ecall_timestamp_type ecall_timestamp;

	uint8 ecall_vehicle_location_valid;
	nwy_ecall_vehicle_location_s_type ecall_vehicle_location;

	uint8 ecall_vehicledirection_valid;;         
	uint8 ecall_vehicledirection;

	uint8 ecall_vehiclelocationN1delta_valid;
    nwy_ecall_vehiclelocationN1delta_s_type ecall_vehiclelocationN1delta;

	uint8 ecall_vehiclelocationN2delta_valid;
    nwy_ecall_vehiclelocationN2delta_s_type ecall_vehiclelocationN2delta;

	uint8 ecall_numberofpassengers_valid;
	int ecall_numberofpassengers;

	uint8 ecall_additionaldata_valid;
	char ecall_additionaldata[512];
}nwy_ecall_msd_structure_s_type;

/*---------------------- Functions Definition ---------------------------------*/
int nwy_voice_add_statehandler(nwy_voice_statehandlerfunc state_handle);
int nwy_voice_remove_statehandler();
int nwy_voice_call_start(uint8_t sim_id, char *phone_num, int *call_id);
int nwy_voice_call_end(uint32_t call_id); 
int nwy_voice_call_answer(uint32_t call_id);
int nwy_voice_call_hold(uint32_t call_id);
int nwy_voice_call_unhold(uint32_t call_id);
int nwy_voice_call_conf(uint32_t call_id);
int nwy_voice_call_endconf(uint32_t call_id);
int nwy_voice_call_autoanswer(uint8_t answer_type, uint32_t answer_time);
int nwy_voice_notify_proc_cb(struct ubus_context *ctx, struct ubus_object *obj, struct ubus_request_data *req, const char *method, struct blob_attr *msg );
void nwy_voice_notify_rm_cb(struct ubus_context *ctx, struct ubus_subscriber *obj, uint32_t id);
int nwy_voice_send_dtmf(uint8_t sim_id, uint8_t dtmf, uint8_t call_id, uint32_t time_ms);

int nwy_voice_ecall_open(nwy_ecall_option  ecall_type);
int nwy_voice_ecall_push(void);
int nwy_voice_ecall_only(int active, char *number);
int nwy_voice_ecall_msdgen(void);
int nwy_voice_ecall_msdcfg(nwy_ecall_msd_structure_s_type *msd, bool persistent);
int nwy_voice_ecall_mode(int ecall_mode);
int nwy_voice_ecall_msd(char *msd);
int nwy_voice_ecall_smsdirnum(char *number);

#if 0
int nwy_voice_ecall(int sim_id, char *phone_num, char *ecall_msd, uint32 msd_len,
                    int manual, nwy_ecall_type_of_call ecall_type, int *call_id);
int nwy_voice_ecall_updatemsd(char *hex_msd, uint32 msd_len);
#endif

#ifdef __cplusplus
   }
#endif

#endif  

