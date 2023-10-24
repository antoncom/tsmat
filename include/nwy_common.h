/*====*====*====*====*====*====*====*====*====*====*====*====
   Copyright (c) 2017 Neoway Technologies, Inc.
   All rights reserved.
   Confidential and Proprietary - Neoway Technologies, Inc.
Author: lisheng
   Date: 2018.05
*====*====*====*====*====*====*====*====*====*====*====*====*/
#ifndef __NWY_COMMON_H__
#define __NWY_COMMON_H__


#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <errno.h>
#include <stdarg.h>
#include <sys/syslog.h>
#include <pthread.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/stat.h>
//#include <sys/un.h>
#include <unistd.h>
#include <stdbool.h>

#include "nwy_log.h"

#ifdef __cplusplus
extern "C" {
#endif
#define NWY_SUCCESS  0
#define NWY_ERROR   -1

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

/* std types */
#ifndef byte
typedef unsigned char byte;
#endif

#ifndef int8
typedef int8_t int8;
#endif

#ifndef uint8
typedef uint8_t uint8;
#endif

#ifndef int16
typedef int16_t int16;
#endif

#ifndef uint16
typedef uint16_t uint16;
#endif

#ifndef int32
typedef signed long int int32;
#endif

#ifndef uint32
typedef unsigned long int uint32;
#endif

#ifndef int64
typedef int64_t int64;
#endif

#ifndef uint64
typedef uint64_t uint64;
#endif

typedef struct 
{
	char **p_evt;
	int num;
}SUB_EVENT;

typedef struct
{	
	struct ubus_subscriber *subobj;
	SUB_EVENT *subevts;
}NWY_UBUS_SUBSCRIBE;


/*
 *****************************************************************************
 * Prototype	: nwy_ubus_init
 * Description	: Create ubus objects of request and subscriber, and create a thread for 
 				 process ubus msg which send ubus msg to ubus service or subscribe info 
 				 from ubus service.
 * Input		: NULL
 * Output	 	: NULL
 * Return Value	: nwy_error_t
 * Author	 	: ZhangYanhong
 *****************************************************************************
 */
int nwy_sdk_init(void);


/*
 *****************************************************************************
 * Prototype	: nwy_sdk_deinit
 * Description	: free some object via nwy sdk init create
 * Input		: NULL
 * Output	 	: NULL
 * Return Value	: NULL
 * Author	 	: ZhangYanhong
 *****************************************************************************
 */
void nwy_sdk_deinit(void);

/*
 *****************************************************************************
 * Prototype	: nwy_ubus_subscribe_fun
 * Description	: register subscriber object and event to ubus
 * Input		: parms, struct NWY_UBUS_SUBSCRIBE object for subscribe info
 * Output	 	: NULL
 * Return Value	: nwy_error_t
 * Author	 	: ZhangYanhong
 *****************************************************************************
 */
int nwy_ubus_subscribe_fun(void *parms);

/*
 *****************************************************************************
 * Prototype	: nwy_ubus_unsubscribe_fun
 * Description	: unregister subscriber object and event from ubus for release system resource.
 * Input		: parms, struct NWY_UBUS_SUBSCRIBE object for unsubscribe info
 * Output	 	: NULL
 * Return Value	: nwy_error_t
 * Author	 	: ZhangYanhong
 *****************************************************************************
 */
void nwy_ubus_unsubscribe_fun(void *parms);


#ifdef __cplusplus
   }
#endif

#endif //__NWY_COMMON_H__
