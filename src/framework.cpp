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

    VkInstanceCreateInfo ici{};
    ici.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    VkInstance inst;
    auto res = vkCreateInstance(&ici, nullptr, &inst);
    if (res != VK_SUCCESS)
    {
        // TODO: error messages
        CleanUp();
        return false;
    }

    return true;
}

void KomputeFramework::CleanUp()
{
    FreeLibrary(lib);
    CleanUpVk();
}
