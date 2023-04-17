//
// Created by Janis on 17.04.2023.
//

#ifndef SWEDBANKXPOSED_CORE_HPP
#define SWEDBANKXPOSED_CORE_HPP
#include <cstdint>

typedef int (*HookFunType)(void *func, void *replace, void **backup);

typedef int (*UnhookFunType)(void *func);

typedef void (*NativeOnModuleLoaded)(const char *name, void *handle);

typedef struct {
    uint32_t version;
    HookFunType hook_func;
    UnhookFunType unhook_func;
} NativeAPIEntries;

typedef NativeOnModuleLoaded (*NativeInit)(const NativeAPIEntries *entries);
#endif //SWEDBANKXPOSED_CORE_HPP
