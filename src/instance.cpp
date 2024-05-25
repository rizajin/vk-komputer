#include "instance.h"

#include "vk.h"

bool Instance::Create()
{
    VkApplicationInfo appInfo{VK_STRUCTURE_TYPE_APPLICATION_INFO,
                              nullptr,
                              "",
                              {},
                              "Kompute",
                              0,
                              VK_API_VERSION_1_0};

    VkInstanceCreateInfo instanceCreateInfo{};
    instanceCreateInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    instanceCreateInfo.enabledExtensionCount = 0;
    instanceCreateInfo.enabledLayerCount = 0;
    instanceCreateInfo.flags = 0;
    instanceCreateInfo.pNext = nullptr;
    instanceCreateInfo.ppEnabledExtensionNames = nullptr;
    instanceCreateInfo.ppEnabledLayerNames = nullptr;
    instanceCreateInfo.pApplicationInfo = &appInfo;

    if (vkCreateInstance(&instanceCreateInfo, nullptr, &inst) != VK_SUCCESS)
    {
        return false;
    }

    return true;
}

VkInstance Instance::Get()
{
    return inst;
}

void Instance::CleanUp()
{
    vkDestroyInstance(inst, nullptr);
}
