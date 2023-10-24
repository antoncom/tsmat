/*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====
    Copyright (c) 2018 Neoway Technologies, Inc.
    All rights reserved.
    Confidential and Proprietary - Neoway Technologies, Inc.
    Author: Shi.Shaogang
    Date: 2018.06
*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*/

#ifndef __NWY_I2C_H__
#define __NWY_I2C_H__

#ifdef __cplusplus
extern "C" {
#endif
/*---------------------------Function Definition--------------------------*/
int nwy_i2c_init(const char* i2cDev, unsigned char slaveAddr);
int nwy_i2c_deinit(int fd);
int nwy_i2c_read(int fd, unsigned char slaveAddr, unsigned char ofstAddr,
                 unsigned char* ptrBuff, unsigned short length);
int nwy_i2c_write(int fd, unsigned char slaveAddr, unsigned char ofstAddr,
                  unsigned char* ptrData, unsigned short length);


#ifdef __cplusplus
   }
#endif

#endif //__NWY_I2C_H__