#--------------------------------------------------------------
#               Neoway OpenWrt
#   
#--------------------------------------------------------------
APP_NAME = tsmat

#GCC_VERSION=0.1

#--------------------------------------------------------------
# Include definition
#--------------------------------------------------------------
#COMMON_USR_DIR=../../tool/toolchain-arm_cortex-a7+neon-vfpv4_gcc-4.8-linaro_uClibc-1.0.25_eabi/linux64/usr
INC_DIR=  -I ./include
USR_INC_DIR = -I$(COMMON_USR_DIR)/include

#--------------------------------------------------------------
# LIB
#--------------------------------------------------------------
STD_LIB_FILES =	-ldl -lpthread -lm -lrilutil -llog -lprop2uci -luci -lubox -lubus -lblobmsg_json -ljson_script -ljson-c
USR_LIB_FILES = -lnwy_service -lnwy_common
LDFLAGS += -L$(COMMON_USR_DIR)/lib
LDFLAGS += -L./libs

#--------------------------------------------------------------
# Source code files
#--------------------------------------------------------------
DIRS = $(shell find . -maxdepth 3 -type d)
#LOCAL_SRC_FILES = $(foreach dir, $(DIRS), $(wildcard $(dir)/*.c)) 
LOCAL_SRC_FILES = tsmat.c
LOCAL_OBJECTS = $(notdir $(patsubst %.c, %.o,$(LOCAL_SRC_FILES)))
		
#--------------------------------------------------------------
# Compilation options
#--------------------------------------------------------------
#set CFLAGS
LOCAL_CFLAGS = -Werror -march=armv7-a -mfpu=neon-vfpv4 -mfloat-abi=hard

.PHONY: $(APP_NAME)

$(APP_NAME) : $(LOCAL_SRC_FILES)
	$(CC) $(LOCAL_CFLAGS) $(LOCAL_INC_DIR) $(INC_DIR) $(USR_INC_DIR) $(LOCAL_SRC_FILES) $(STD_LIB_FILES) $(USR_LIB_FILES) $(LDFLAGS)  -o $@
	rm -rf  *.o *.a
	@echo ---- finished ----

.PHONY: clean
clean:
	rm -rf $(APP_NAME)
	rm -rf  *.o *.a

