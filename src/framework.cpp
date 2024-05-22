#include "framework.h"
#include <Windows.h>

#include <vulkan/vulkan.h>

HMODULE lib;

void KomputeFramework::Init()
{
    lib = LoadLibrary("vulkan-1.dll");
    auto x = (PFN_vkGetInstanceProcAddr)GetProcAddress(lib, "vkGetInstanceProcAddr");
    auto vkCreateInstance = (PFN_vkCreateInstance)x(nullptr, "vkCreateInstance");
    VkInstanceCreateInfo ici{};
    ici.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    VkInstance inst;
    auto res = vkCreateInstance(&ici, nullptr, &inst);
    if (res == VK_SUCCESS)
    {
        
    }

}
