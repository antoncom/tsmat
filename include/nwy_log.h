/*====*====*====*====*====*====*====*====*====*====*====*====
   Copyright (c) 2021 Neoway Technologies, Inc.
   All rights reserved.
   Confidential and Proprietary - Neoway Technologies, Inc.
   Author: zhangyanhong
   Date: 2021.11.15
*====*====*====*====*====*====*====*====*====*====*====*====*/
#ifndef __NWY_LOG_H__
#define __NWY_LOG_H__

/*----------------------------Log System--------------------------------------------*/
/* LOG FORMAT */
#define LOG_SIMPLE       0           /* logging without line, function and file name*/
#define LOG_COMPLEX      1           /* logging with line, function and file name*/
#define LOG_FORMAT_MAX 1             /*maximum value for log format*/

/* LOG LEVERL DEFINITION */
#define LOG_EMERG        0           /* systemis unusable */
#define LOG_ALERT        1           /* actionmust bet taken immediately */
#define LOG_CRIT         2           /* critical conditions */
#define LOG_ERR          3           /* error conditions */
#define LOG_WARNING      4           /* warning conditions */
#define LOG_NOTICE       5           /* normalbut significant */
#define LOG_INFO         6           /* informational  */
#define LOG_DEBUG        7           /* debug-level messages */

/* LOG DIRECTION DEFINITION */
#define LOG_MASK_ADB     0x02         /* adb */
#define LOG_MASK_STD     0x04         /* stderr */

#define LOG_DEFAULT_LEVEL   7

#define LOG_OPEN_PREF "NWYSDK-"

#ifndef LOG_FORMAT
#define LOG_FORMAT     LOG_COMPLEX      /*spcify log format*/
#endif

#ifndef LOG_MSG_TAG
#define LOG_MSG_TAG     "NULL"          /*specify module tag, default empty*/
#endif

#ifndef LOG_MSG_LEVEL
#define LOG_MSG_LEVEL   LOG_DEBUG       /*specify log level, default LOG_DEBUG(7)*/
#endif

#ifndef LOG_MSG_MASK
#define LOG_MSG_MASK    LOG_MASK_ADB    /*specify log direction, default adb*/
#endif

typedef enum
{
	LOG_ENABLE,
	LOG_DISABLE,
}nwy_log_status;

void nwy_set_log_status(nwy_log_status log_status);
void nwy_set_log_print_direction(int mask);

/* set log enable or disable */
#define SETLOGSTATUS(status)    \
        nwy_set_log_status(status)

/* set log printf direction for  LOG_MASK_ADB or LOG_MASK_STD or LOG_MASK_QXDM or all*/
#define SETLOGDIRECTION(direction)    \
		nwy_set_log_print_direction(direction)

void nwy_diag_msg_log(int format, const char *tag,
                     int level, int level_max, int mask, 
                     const char *file, int line, 
                     const char *func, const char *fmt, ...);

#define NWYLOG(format, tag, lvl, lvl_max, msk, file, line, func, fmt, ...)    \
        nwy_diag_msg_log(format, tag, lvl, lvl_max, msk, file, line, func, fmt, ##__VA_ARGS__)

#ifdef LOGV
#undef LOGV
#endif
#define LOGV(lvl, fmt, ...)  \
        NWYLOG(LOG_FORMAT, LOG_OPEN_PREF LOG_MSG_TAG,\
                    lvl, LOG_MSG_LEVEL, LOG_MSG_MASK,   \
                    __FILE__, __LINE__, __func__, fmt, ##__VA_ARGS__)

#ifdef LOGE
#undef LOGE
#endif
#define LOGE(fmt, ...)  \
        NWYLOG(LOG_FORMAT, LOG_OPEN_PREF LOG_MSG_TAG,\
                    LOG_ERR, LOG_MSG_LEVEL, LOG_MSG_MASK,   \
                    __FILE__, __LINE__, __func__, fmt, ##__VA_ARGS__)

#ifdef LOGI
#undef LOGI
#endif
#define LOGI(fmt, ...)  \
        NWYLOG(LOG_FORMAT, LOG_OPEN_PREF LOG_MSG_TAG,\
                    LOG_NOTICE, LOG_MSG_LEVEL, LOG_MSG_MASK,    \
                    __FILE__, __LINE__, __func__, fmt, ##__VA_ARGS__)

#ifdef LOGD
#undef LOGD
#endif
#define LOGD(fmt, ...)  \
        NWYLOG(LOG_FORMAT, LOG_OPEN_PREF LOG_MSG_TAG,\
                    LOG_DEBUG, LOG_MSG_LEVEL, LOG_MSG_MASK,     \
                    __FILE__, __LINE__, __func__, fmt, ##__VA_ARGS__)



#endif //__NWY_LOG_H__

