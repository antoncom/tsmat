/*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====
    Copyright (c) 2018 Neoway Technologies, Inc.
    All rights reserved.
    Confidential and Proprietary - Neoway Technologies, Inc.
    Author: Shi.Shaogang
    Date: 2018.06
*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*/

#ifndef __NWY_SPI_H__
#define __NWY_SPI_H__

#ifdef __cplusplus
extern "C" {
#endif
/*----------------------------Type Definition-----------------------------*/
typedef enum {
    S_P96  =   960000,
    S_4P8  =   4800000,
    S_9P6  =   9600000,
    S_16   =   16000000,
    S_19P2 =   19200000,
    S_25   =   25000000,
    S_50   =   50000000
}nwy_speed_t;

/*---------------------------Function Definition--------------------------*/
int nwy_spi_init(char* spidev, uint8_t mode, uint32_t speed, uint8_t bits);
int nwy_spi_transfer(int fd, uint8_t* tx, uint32_t tx_size, uint8_t* rx,
                     uint32_t speed, uint8_t bits, uint16_t delay);
void nwy_spi_deinit(int fd);


#ifdef __cplusplus
   }
#endif

#endif 
