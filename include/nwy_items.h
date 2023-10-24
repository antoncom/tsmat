/*====*====*====*====*====*====*====*====*====*====*====*====*====*====*
   Copyright (c) 2018 Neoway Technologies, Inc.
   All rights reserved.
   Confidential and Proprietary - Neoway Technologies, Inc.
   Author: wangjie@neoway.com
   Date: 2018.06
*====*====*====*====*====*====*====*====*====*====*====*====*====*====*/

#ifndef NWY_DATA_H
#define NWY_DATA_H

#ifdef __cplusplus
extern "C" {
#endif
/*--------------------------Function Declaration-----------------------*/
int nwy_item_read(unsigned int id, void *data);
int nwy_item_write(unsigned int id, void *data, unsigned int len, int mode);
int nwy_item_delete(unsigned int id, int mode);
int nwy_backup_config_file(unsigned int id, char *file_path);
int nwy_restore_config_file(unsigned int id, char *file_path);
int nwy_check_config_file(unsigned int id, char *file_path);
void nwy_free_data_cache(void);
int nwy_item_sync(void);

#ifdef __cplusplus
   }
#endif

#endif

