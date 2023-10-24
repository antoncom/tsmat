#ifndef __NWY_TTS_EXT_H__
#define __NWY_TTS_EXT_H__

#include "nwy_common.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    TTS_NONE,
	TTS_PLAY,
	TTS_STOP
}nwy_tts_play_state_t;

typedef enum
{
	ENCODE_ASCII          = 437,
	ENCODE_GBK            = 936,
	ENCODE_BIG5           = 950,
	ENCODE_UTF16LE        = 1200,
	ENCODE_UTF16BE        = 1201,
	ENCODE_UTF7           = 65000,
	ENCODE_UTF8           = 65001,
	ENCODE_PHONETIC_PLAIN = 23456
}nwy_tts_encode_t;

typedef enum neoway_result
{
    NEOWAY_PLAY_ERROR,
    NEOWAY_INIT_ERROR,  
    NEOWAY_PARAM_ERROR,
    NEOWAY_SET_PARAM_ERROR,
    NEOWAY_PLAY_END,  
    NEOWAY_SYNTHESIZETEXT_ERROR,
    NEOWAY_TTS_TERMINATED,
    NEOWAY_TTS_TIMEOUT,
}nwy_neoway_result_t;

typedef void (*tts_play_cb)(int result);

/*---------------------------Function Definition--------------------------*/
int nwy_tts_init(void);
int nwy_tts_stop_play(void);
void nwy_tts_playbuf(byte * buf, nwy_tts_encode_t type, tts_play_cb cb);
int nwy_tts_configure(int volume_level, int speed_level, int pitch_level);
nwy_tts_play_state_t nwy_tts_state(void);
void nwy_tts_setparams(long	nParamID,long nParamValue);


#ifdef __cplusplus
   }
#endif

#endif //__NWY_TTS_EXT_H__

