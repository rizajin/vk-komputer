#include "framework.h"
#include <Windows.h>

#include <vulkan/vulkan.h>
#include "vk.h"

namespace
{
    HMODULE lib;
}

KomputeFramework::~KomputeFramework()
{
    CleanUp();
}

bool KomputeFramework::Init()
{
    // TODO: unix
    lib = LoadLibrary("vulkan-1.dll");
    InitFunctions(lib);

    return true;
}

void KomputeFramework::CleanUp()
{
    CleanUpVk();
    FreeLibrary(lib);
}
