LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := cocos2dxandroid_static

LOCAL_MODULE_FILENAME := libcocos2dandroid

LOCAL_SRC_FILES := \
CCApplication.cpp \
CCCommon.cpp \
CCDevice.cpp \
CCGLView.cpp \
CCFileUtilsAndroid.cpp \
CCImage.cpp \
nativeactivity.cpp \
jni/DPIJni.cpp \
jni/IMEJni.cpp \
jni/Java_org_cocos2dx_lib_Cocos2dxBitmap.cpp \
jni/Java_org_cocos2dx_lib_Cocos2dxHelper.cpp \
jni/JniHelper.cpp

LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)

LOCAL_C_INCLUDES := $(LOCAL_PATH) \
                    $(LOCAL_PATH)/../.. \
                    $(LOCAL_PATH)/../../../base \
                    $(LOCAL_PATH)/../../../math/kazmath/include \
                    $(LOCAL_PATH)/../../../physics \
                    $(LOCAL_PATH)/../../../../external/tiff/include/android \
                    $(LOCAL_PATH)/../../../../external/webp/include/android \
                    $(LOCAL_PATH)/../../../../external/jpeg/include/android

LOCAL_LDLIBS := -lGLESv1_CM \
                -lGLESv2 \
                -lEGL \
                -llog \
                -lz \
                -landroid

LOCAL_EXPORT_LDLIBS := -lGLESv1_CM \
                       -lGLESv2 \
                       -lEGL \
                       -llog \
                       -lz \
                       -landroid

LOCAL_WHOLE_STATIC_LIBRARIES	:= android_native_app_glue cocos_png_static


include $(BUILD_STATIC_LIBRARY)

$(call import-module,png/prebuilt/android)
$(call import-module,android/native_app_glue)
