/*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====
    Copyright (c) 2021 Neoway Technologies, Inc.
    All rights reserved.
    Confidential and Proprietary - Neoway Technologies, Inc.
    Author: ZhangYanhong
    Date: 2021/11/8
*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*/
#ifndef __NWY_TEST_H__
#define __NWY_TEST_H__

#include <libubus.h>

#include "nwy_error.h"
#include "nwy_log.h"

#ifdef __cplusplus
extern "C" {
#endif

/*---------------------------Macro definition---------------------------*/
enum {
	TEST_ID,
	TEST_DATA,
	TEST_MSG,
	_TEST_MAX,
};


/*---------------------------Variable Definition--------------------------*/
extern int pin_status;

static const struct blobmsg_policy test_policy[] = 
{
	[TEST_ID] = { .name="id",  .type=BLOBMSG_TYPE_INT32 },
	[TEST_DATA] = { .name="data",  .type=BLOBMSG_TYPE_INT32 },
	[TEST_MSG] = { .name="msg",  .type=BLOBMSG_TYPE_STRING },
};


/*-----------------------------Type Definition---------------------------*/


/*---------------------------Function Definition--------------------------*/

/*
 *****************************************************************************
 * Prototype	: nwy_test_get_sim_status
 * Description	: get sim card state
 * Input		: NULL
 * Output	 	: pinstate, it stores the obtained PIN value.
 * Return Value	: NULL
 * Author	 	: ZhangYanhong
 *****************************************************************************
 */
int nwy_test_get_sim_status(int *pinstate);

struct ubus_context *nwy_test_get_ubx_ctx(void);

int nwy_test_snd_req_to_ttsrv();

int nwy_test_notify_proc_cb(struct ubus_context *ctx, struct ubus_object *obj, struct ubus_request_data *req, 
			const char *method, struct blob_attr *msg );
void nwy_test_notify_rm_cb(struct ubus_context *ctx, struct ubus_subscriber *obj, uint32_t id);



#ifdef __cplusplus
   }
#endif

#endif  
