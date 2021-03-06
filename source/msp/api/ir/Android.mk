LOCAL_PATH := $(call my-dir)

############ shared lib
include $(CLEAR_VARS)

include $(SDK_DIR)/Android.def

LOCAL_PRELINK_MODULE := false

LOCAL_MODULE := libhi_ir
ALL_DEFAULT_INSTALLED_MODULES += $(LOCAL_MODULE)

LOCAL_MODULE_TAGS := optional

LOCAL_CFLAGS := $(CFG_HI_CFLAGS)
LOCAL_CFLAGS += -DLOG_TAG=\"$(LOCAL_MODULE)\"

#LOCAL_SRC_FILES := $(sort $(call all-c-files-under, ./))

ifeq ($(CFG_HI_IR_TYPE_STD), y)
LOCAL_SRC_FILES := unf_ir_std.c
endif

ifeq ($(CFG_HI_IR_TYPE_S2), y)
LOCAL_SRC_FILES := unf_ir.c
endif

LOCAL_C_INCLUDES := $(COMMON_UNF_INCLUDE)
LOCAL_C_INCLUDES += $(COMMON_DRV_INCLUDE)
LOCAL_C_INCLUDES += $(COMMON_API_INCLUDE)
LOCAL_C_INCLUDES += $(MSP_UNF_INCLUDE)
LOCAL_C_INCLUDES += $(MSP_DRV_INCLUDE)
LOCAL_C_INCLUDES += $(MSP_API_INCLUDE)

LOCAL_SHARED_LIBRARIES := libhi_common libcutils libutils

include $(BUILD_SHARED_LIBRARY)


############ static lib
include $(CLEAR_VARS)

include $(SDK_DIR)/Android.def

LOCAL_PRELINK_MODULE := false

LOCAL_MODULE := libhi_ir
ALL_DEFAULT_INSTALLED_MODULES += $(LOCAL_MODULE)

LOCAL_MODULE_TAGS := optional

LOCAL_CFLAGS := $(CFG_HI_CFLAGS)
LOCAL_CFLAGS += -DLOG_TAG=\"$(LOCAL_MODULE)\"

#LOCAL_SRC_FILES := $(sort $(call all-c-files-under, ./))

ifeq ($(CFG_HI_IR_TYPE_STD), y)
LOCAL_SRC_FILES := unf_ir_std.c
endif

ifeq ($(CFG_HI_IR_TYPE_S2), y)
LOCAL_SRC_FILES := unf_ir.c
endif

LOCAL_C_INCLUDES := $(COMMON_UNF_INCLUDE)
LOCAL_C_INCLUDES += $(COMMON_DRV_INCLUDE)
LOCAL_C_INCLUDES += $(COMMON_API_INCLUDE)
LOCAL_C_INCLUDES += $(MSP_UNF_INCLUDE)
LOCAL_C_INCLUDES += $(MSP_DRV_INCLUDE)
LOCAL_C_INCLUDES += $(MSP_API_INCLUDE)

LOCAL_SHARED_LIBRARIES := libhi_common libcutils libutils

include $(BUILD_STATIC_LIBRARY)
