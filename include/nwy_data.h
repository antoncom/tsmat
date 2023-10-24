/*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====
    Copyright (c) 2022 Neoway Technologies, Inc.
    All rights reserved.
    Confidential and Proprietary - Neoway Technologies, Inc.
    Author: LiuFeifan
    Date: 2022/01/17
*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*/
#ifndef __NWY_DATA_H__
#define __NWY_DATA_H__

#include "nwy_error.h"
#include "nwy_log.h"
#include "nwy_common.h"


#ifdef __cplusplus
extern "C" {
#endif

/*------------------------------- Macro definition -------------------------------*/
#define NWY_APN_MAX_LEN 50
#define NWY_PDP_ADDR_MAX_LEN 21
#define NWY_APN_USER_MAX_LEN 21
#define NWY_APN_PWD_MAX_LEN 20
#define NWY_DATA_AUTO_CONNECT_MAX_SECT_NUM 5

/*-------------------------------- Type Definition -------------------------------*/
typedef enum 
{
  	NWY_DATA_CALL_INVALID = 0x0,
  	NWY_DATA_CALL_CONNECTED,                     //data call is connected
  	NWY_DATA_CALL_DISCONNECTED,                  //data call is disconnected
} nwy_data_call_state_t;

typedef enum 
{
  	NWY_DATA_PROFILE_3GPP = 0,                   //UMTS profile
  	NWY_DATA_PROFILE_3GPP2                       //CDMA profile
} nwy_data_profile_type_t;

typedef enum
{
  	NWY_DATA_PDP_TYPE_IPV4 = 0,                  //IPv4 dial
    NWY_DATA_PDP_TYPE_PPP,                       //PPP dial
    NWY_DATA_PDP_TYPE_IPV6,                      //IPv6 dial
    NWY_DATA_PDP_TYPE_IPV4V6,                    //IPv4/v6 dial
} nwy_data_pdp_type_t;

typedef enum
{
  	NWY_DATA_AUTH_PROTO_NONE=0,                    //none
  	NWY_DATA_AUTH_PROTO_PAP,                     //PAP
  	NWY_DATA_AUTH_PROTO_CHAP,                    //CHAP
} nwy_data_auth_proto_t;

typedef struct
{
    char valid_addr;                             //Indicates whether a valid address is available
    struct sockaddr_storage addr;                //Stores the IP address
}nwy_data_addr_t;

typedef struct
{
    nwy_data_addr_t iface_addr_s;                //Network interface address
    uint32_t iface_mask;                         //Subnet mask
    nwy_data_addr_t gtwy_addr_s;                 //Gateway server address
    uint32_t gtwy_mask;                          //Gateway mask
    nwy_data_addr_t dnsp_addr_s;                 //Primary DNS server address
    nwy_data_addr_t dnss_addr_s;                 //Secondary DNS server address
}nwy_data_addr_t_info;

typedef struct 
{
  nwy_data_pdp_type_t pdp_type;                //PPP,IPv4,
  char apn[NWY_APN_MAX_LEN+1];                 //Access Point Name
  nwy_data_auth_proto_t auth_proto;            //authentication protocol
  char user_name[NWY_APN_USER_MAX_LEN+1];      //user name
  char pwd[NWY_APN_PWD_MAX_LEN+1];            //password
  uint8 clat_enabled; 
} nwy_data_profile_info_t;

typedef void (*nwy_data_cb_func)
(   
  	int hndl,
  	nwy_data_call_state_t ind_state,
  	void *ind_struct
);

typedef struct
{
  	int profile_idx;
  	int ip_version;
    uint8 auto_connect;
}nwy_data_start_call_v02_t;

typedef struct
{
    uint8 sect_num;
    uint8 sect_retry_time;
    uint8 timer_vals[NWY_DATA_AUTO_CONNECT_MAX_SECT_NUM];
}nwy_data_auto_connect_cfg_t;

/*----------------------------- variables definition -----------------------------*/


/*----------------------------- functions definition -----------------------------*/

/*
 *****************************************************************************
 * Prototype	 : nwy_data_get_srv_handle
 * Description	 : release handle
 * Input		 : cb_func, callback function
 * Output		 : NULL
 * Return Value  : handle id
 * Author		 : LiuFeifan
 *****************************************************************************
 */
int nwy_data_get_srv_handle(nwy_data_cb_func cb_func);

/*
 *****************************************************************************
 * Prototype	 : nwy_data_release_srv_handle
 * Description	 : release handle
 * Input		 : hndl, handle id
 * Output		 : NULL
 * Return Value  : NULL
 * Author		 : LiuFeifan
 *****************************************************************************
 */
void nwy_data_release_srv_handle(int hndl);

/*
 *****************************************************************************
 * Prototype	 : nwy_data_set_profile
 * Description	 : Get profile info
 * Input		 : hndl, handle id
 * Input		 : profile_type, the profile type to set
 * Input		 : profile_info, profile info
 * Output		 : NULL
 * Return Value  : error code
 * Author		 : LiuFeifan
 *****************************************************************************
 */
int nwy_data_set_profile(int profile_idx, nwy_data_profile_type_t profile_type,
                         	nwy_data_profile_info_t *profile_info);

/*
 *****************************************************************************
 * Prototype	 : nwy_data_get_profile
 * Description	 : Get profile info
 * Input		 : hndl, handle id
 * Input		 : profile_type, the profile type to obtain
 * Output		 : profile_info, profile info
 * Return Value  : error code
 * Author		 : LiuFeifan
 *****************************************************************************
 */
int nwy_data_get_profile(int profile_idx, nwy_data_profile_type_t profile_type,
							nwy_data_profile_info_t *profile_info);

/*
 *****************************************************************************
 * Prototype	: nwy_data_start_call
 * Description	: Stop the data call
 * Input		: hndl, handle id
 * Input		: param, Control parameters for data call
 * Output		: NULL
 * Return Value : error code
 * Author		: LiuFeifan
 *****************************************************************************
 */
int nwy_data_start_call(int hndl, nwy_data_start_call_v02_t* param);

/*
 *****************************************************************************
 * Prototype	: nwy_data_stop_call
 * Description	: Stop the data call
 * Input		: hndl, handle id
 * Output	 	: NULL
 * Return Value	: error code
 * Author	 	: LiuFeifan
 *****************************************************************************
 */
int nwy_data_stop_call(int hndl);

/*
 *****************************************************************************
 * Prototype	: nwy_data_get_ip_addr
 * Description	: Converts the ipv4 address to a string
 * Input		: hndl, handle id
 * Output	 	: info_ptr, Network information
 * Output       : len, The number of addresses returned
 * Return Value	: error code
 * Author	 	: LiuFeifan
 *****************************************************************************
 */
int nwy_data_get_ip_addr(int hndl, nwy_data_addr_t_info *info_ptr, int *len);

/*
 *****************************************************************************
 * Prototype	: nwy_data_set_auto_connect_cfg
 * Description	: set auto connect info
 * Input		: cfg, auto connect info
 * Return Value	: error code
 * Author	 	: LiuFeifan
 *****************************************************************************
 */
int nwy_data_set_auto_connect_cfg(nwy_data_auto_connect_cfg_t *cfg);

/*
 *****************************************************************************
 * Prototype	: nwy_data_get_device_name
 * Description	: get device name
 * Input		: hndl, handle id
 * Input		 : len, buf length
 * Output		 : buf, device name
 * Return Value	: error code
 * Author	 	: LiuFeifan
 *****************************************************************************
 */
int nwy_data_get_device_name(int hndl, char * buf, int len);

void nwy_data_release_all_handle(void);

#ifdef __cplusplus
   }
#endif

#endif  

