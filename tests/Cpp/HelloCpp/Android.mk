LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := cocos_hellocpp_common

LOCAL_MODULE_FILENAME := libhellocppcommon

LOCAL_SRC_FILES := \
Classes/AppDelegate.cpp \
Classes/HelloWorldScene.cpp

LOCAL_C_INCLUDES := $(LOCAL_PATH)/Classes


LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/Classes
            
include $(BUILD_STATIC_LIBRARY)

$(call import-module,2d)
