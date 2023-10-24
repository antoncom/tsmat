/*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====
    Copyright (c) 2022 Neoway Technologies, Inc.
    All rights reserved.
    Confidential and Proprietary - Neoway Technologies, Inc.
    Author: dong.nengxiang
    Date: 2022.02
*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*/

#ifndef __NWY_LOC_H__
#define __NWY_LOC_H__

#include <termios.h>


#ifdef __cplusplus
extern "C" {
#endif
/*----------------------------Type Definition-----------------------------*/


#define NWY_GNSS_CONNECT_UART "/dev/ttyS2"
#define NWY_GNSS_DEFAULT_BAUDRATE   115200
#define NWY_GNSS_GPIO_PWR       34
//#define NWY_GNSS_GPIO_RST     35

#define CLOCK_MONOTONIC         1
#define NWY_CIRCLE_CMD_CNT      2

#define NWY_GNSS_RECV_BUF_SIZE   2048
#define MAX_WR_SIZE   256
#define UART_INTERACT_TIMEOUT   300
#define PKT_END   "\r\n"
#define NMEA_END_CHAR  '\n'

typedef enum
{
  NWY_GPGGA,
  NWY_GPGSA,
  NWY_GPGSV,
  NWY_GPRMC,
  NWY_GPVTG,
  NWY_GPGLL
}nwy_gps_info_type;

typedef enum
{
  NWY_GPS_MODE = 0,
  NWY_BD_MODE = 1,
  NWY_GPS_BD_MODE =2,

  NWY_GNSS_MODE_CNT,
}nwy_gnss_mode;

typedef enum{
  NWY_GNSS_LINK_GPIO_CLOSE,
  NWY_GNSS_LINK_GPIO_OPEN,
  NWY_GNSS_LINK_GPIO_RESET
}nwy_gnss_link_gpio_cmd_t;

typedef enum
{
    NWY_GNSS_FORMAT_NULL        = 0,    
    NWY_GNSS_FORMAT_QCOM    = 1,    //qualcomm
    NWY_GNSS_FORMAT_UNICORE     = 2,    //Unicore

    NWY_GNSS_FORMAT_MAX
}nwy_gnss_format_chips;

typedef unsigned int nwy_loc_nmea_mask_t;
#define NWY_LOC_NMEA_MASK_GGA ((nwy_loc_nmea_mask_t)0x00000001) /**<  Enable GGA type  */
#define NWY_LOC_NMEA_MASK_GLL ((nwy_loc_nmea_mask_t)0x00000002) /**<  Enable GLL type  */
#define NWY_LOC_NMEA_MASK_GSA ((nwy_loc_nmea_mask_t)0x00000004) /**<  Enable GSA type  */
#define NWY_LOC_NMEA_MASK_GSV ((nwy_loc_nmea_mask_t)0x00000008) /**<  Enable GSV type  */
#define NWY_LOC_NMEA_MASK_RMC ((nwy_loc_nmea_mask_t)0x00000010) /**<  Enable RMC type  */
#define NWY_LOC_NMEA_MASK_VTG ((nwy_loc_nmea_mask_t)0x00000020) /**<  Enable VTG type  */
#define NWY_LOC_NMEA_MASK_ZDA ((nwy_loc_nmea_mask_t)0x00000040) /**<  Enable ZDA type  */
#define NWY_LOC_NMEA_MASK_GST ((nwy_loc_nmea_mask_t)0x00000080) /**<  Enable GST type  */


typedef struct {
    char nmea[NWY_GNSS_RECV_BUF_SIZE + 1];
    int length;
} nwy_loc_nmea_info_ind_msg_t;  


/******************AGPS Begin******************/
//typedef unsigned int  uint32;
//typedef unsigned long long uint64;

#define NWY_AGPS_TIMEOUT  10000
#define NWY_AGPS_PKT_SIZE 8192   //8K
#define NWY_AGPS_DATA_MAX 7168   //7K


typedef enum{
    NWY_HEXINXINGTONG,

    NWY_ZHONGKEWEI,
}nwy_agnss_mode_t;


typedef struct
{
    int set_flag;
    int data_type;
    char url[521+1];
    char user[128];
    char pass[128];
    char mid[64];
    int port;

    double lat;
    double lng;
    double alt;
}nwy_setserver_para_t;
/******************AGPS End******************/


typedef void (*nwy_loc_ind_event_func)(nwy_loc_nmea_info_ind_msg_t *ind_msg);

/*---------------------------Function Definition--------------------------*/

void nwy_loc_init(void);
int nwy_loc_add_event_handler( nwy_loc_ind_event_func ind_handler);
int nwy_loc_del_event_handler(void);
int nwy_loc_set_gnss_sys(int mode);
int nwy_loc_open(void);
int nwy_loc_close(void);
int nwy_loc_cold_start(void);
int nwy_loc_start_navigation(void);
int nwy_loc_stop_navigation(void);
int nwy_loc_cfg_nmea_type(unsigned int nmea_type);

int nwy_gnss_reg_write(char *val_ptr, int val_len);

int nwy_loc_get_agps_info(char *out_sentence);
int nwy_loc_nmea_output_format(nwy_gnss_format_chips chips);

int nwy_loc_output_frequency(int gnss_rate);
int nwy_loc_navigation_cutoff_pitch_angle(int cutoff_angle);
int nwy_loc_coordinate_system(int gnss_coordinate_system);


int nwy_agps_dev_open(void);
int nwy_agps_data_write_to_gnss(char *data, int len);
int nwy_agps_buildReqPkt(char* sendbuf, nwy_setserver_para_t *server_info);

int nwy_agps_get_data(char *in_data, int in_len,int* rcv_data_len, char *out_data);
int nwy_agps_send_data(int soc_id, char *tmp_buf, int recv_len);

int nwy_agps_tcp_establish(char *host_url, int port);
int nwy_agps_tcp_close(int fd);
int nwy_agps_tcp_send(int fd, const char *buf, int len);
int nwy_agps_tcp_recv(int fd, char *buf, int len);
int nwy_start_AGPS(nwy_setserver_para_t *server_info);


#ifdef __cplusplus
   }
#endif

#endif 
