/*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====
    Copyright (c) 2018 Neoway Technologies, Inc.
    All rights reserved.
    Confidential and Proprietary - Neoway Technologies, Inc.
    Author: wangxiaobo
    Date: 2018/7/6
*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*/

#ifndef __nwy_AUDIO_H__
#define __nwy_AUDIO_H__

#include "nwy_error.h"
#include <stdint.h>
#include <sys/types.h>

#ifdef __cplusplus
extern "C" {
#endif
/*---------------------- Macro definition ---------------------------------*/
#define ID_RIFF 0x46464952
#define ID_WAVE 0x45564157
#define ID_FMT  0x20746d66
#define ID_DATA 0x61746164
#define FORMAT_PCM 1

/*---------------------- type definition ---------------------------------*/
typedef int(*play_event_handler)(int event);
typedef int(*record_event_handler)(uint8_t *pData, uint32_t len);

/*---------------------- functions definition ---------------------------------*/
int nwy_audio_playback_open(int dev, play_event_handler handler);//1:audio;2:voice;3:volte;4:remote.
int nwy_audio_is_sec_i2s(int value);

void nwy_audio_player_close();
int nwy_audio_player_play(uint8_t *pdata, uint32_t len);
int nwy_audio_player_play_file(char *filename);
int nwy_audio_player_stop();
int nwy_audio_player_pause();
int nwy_audio_player_resume();

int nwy_audio_capture_open(int dev, record_event_handler handler);//1:audio;2.voice;3:volte;
void nwy_audio_recorder_close(); 
int nwy_audio_recorder_start();
int nwy_audio_recorder_stop();
int nwy_audio_recorder_pause();
int nwy_audio_recorder_resume();

int nwy_audio_tone_open(char *device, play_event_handler handler); 
void nwy_audio_tone_close();
int nwy_audio_tone_start(int fd);
int nwy_audio_tone_stop();

void nwy_audio_mix(char *cmd, char argc, char *argv);
void nwy_audio_set_mic_vol(const int step);//step(0~5)
void nwy_audio_set_handset_vol(const int step);
void nwy_change_output_channel( int device);//device0:handset  device1:speaker
void nwy_change_input_channel( int device);//mic0:handset mic mic1:headset mic
void nwy_output_device_mute(void);
void nwy_input_device_mute(void);
void nwy_audio_tone_play(int fre1, int fre2, int timeout, int volume);
void nwy_remaudio_open(int status);

/****************Begin: add for loopback test*******************/
void nwy_audio_loopback_init(void);
void nwy_loopback_test_start(void);
void nwy_loopback_test_stop(void);
/****************End: add for loopback test*******************/
int nwy_get_es8311_init_status(void);
void nwy_set_es8311_init(void);
void nwy_set_nau88c10_init(void);
void nwy_reset_codec(void);
int nwy_audio_get_playStatus(void);
void nwy_set_aic3104_init(void);

size_t g_strlcat(char *dst, const char *src, size_t size);
size_t g_strlcpy(char *dst, const char *src, size_t size);

#ifdef __cplusplus
   }
#endif

#endif // __nwy_AUDIO_H__ 

