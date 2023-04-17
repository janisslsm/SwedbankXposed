#include <cstring>
#include <jni.h>
#include "core.hpp"

static HookFunType hook_func = nullptr;

int (*backup_system_property_get)(const char *name, char* value);

int fake_system_property_get(const char *name, char* value) {
    if (strcmp(name, "sys.oem_unlock_allowed") == 0)
    {
        strcpy(value, "0");
        return 1;
    }

    return backup_system_property_get(name, value);
}

extern "C" [[gnu::visibility("default")]] [[gnu::used]]
jint JNI_OnLoad(JavaVM *jvm, void*) {
    JNIEnv *env = nullptr;
    jvm->GetEnv((void **)&env, JNI_VERSION_1_6);
    return JNI_VERSION_1_6;
}

extern "C" [[gnu::visibility("default")]] [[gnu::used]]
NativeOnModuleLoaded native_init(const NativeAPIEntries *entries) {
    hook_func = entries->hook_func;
    // system hooks
    hook_func((void*)__system_property_get, (void*)fake_system_property_get, (void**)&backup_system_property_get);
    return nullptr;
}