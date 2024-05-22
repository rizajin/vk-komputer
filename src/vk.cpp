#include "vk.h"

#include <Windows.h>

PFN_vkGetInstanceProcAddr vkGetInstanceProcAddr{nullptr};
PFN_vkCreateInstance vkCreateInstance{nullptr};

bool InitFunctions(HMODULE lib)
{
    vkGetInstanceProcAddr =
        (PFN_vkGetInstanceProcAddr)GetProcAddress(lib, "vkGetInstanceProcAddr");
    vkCreateInstance = (PFN_vkCreateInstance)vkGetInstanceProcAddr(
        nullptr, "vkCreateInstance");

    return true;
}

void CleanUpVk()
{
    if (vkGetInstanceProcAddr)
    {
        vkGetInstanceProcAddr = nullptr;
    }
    if (vkCreateInstance)
    {
        vkCreateInstance = nullptr;
    }
}
