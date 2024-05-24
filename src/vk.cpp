#include "vk.h"

#include <Windows.h>

// TODO: check if we can remain hidden.
namespace
{
VkInstance instance;
}

// clang-format off
PFN_vkGetInstanceProcAddr vkGetInstanceProcAddr{nullptr};
PFN_vkCreateInstance vkCreateInstance{nullptr};
// instance
PFN_vkGetDeviceProcAddr vkGetDeviceProcAddr{nullptr};
PFN_vkEnumeratePhysicalDevices vkEnumeratePhysicalDevices{nullptr};
PFN_vkGetPhysicalDeviceProperties vkGetPhysicalDeviceProperties{nullptr};
PFN_vkGetPhysicalDeviceFeatures vkGetPhysicalDeviceFeatures{nullptr};
PFN_vkGetPhysicalDeviceMemoryProperties vkGetPhysicalDeviceMemoryProperties{nullptr};
PFN_vkGetPhysicalDeviceQueueFamilyProperties vkGetPhysicalDeviceQueueFamilyProperties{nullptr};
PFN_vkDestroyInstance vkDestroyInstance{nullptr};
PFN_vkCreateDevice vkCreateDevice{nullptr};
// dev
PFN_vkAllocateCommandBuffers vkAllocateCommandBuffers{nullptr};
PFN_vkBeginCommandBuffer vkBeginCommandBuffer{nullptr};
PFN_vkCmdBindPipeline vkCmdBindPipeline{nullptr};
PFN_vkCmdBindDescriptorSets vkCmdBindDescriptorSets{nullptr};
PFN_vkCmdDispatch vkCmdDispatch{nullptr};
PFN_vkEndCommandBuffer vkEndCommandBuffer{nullptr};
PFN_vkCreateFence vkCreateFence{nullptr};
PFN_vkQueueSubmit vkQueueSubmit{nullptr};
PFN_vkWaitForFences vkWaitForFences{nullptr};
PFN_vkDestroyFence vkDestroyFence{nullptr};
PFN_vkAllocateDescriptorSets vkAllocateDescriptorSets{nullptr};
PFN_vkGetDeviceQueue vkGetDeviceQueue{nullptr};
PFN_vkCreateCommandPool vkCreateCommandPool{nullptr};
PFN_vkCreateDescriptorPool vkCreateDescriptorPool{nullptr};
PFN_vkDestroyCommandPool vkDestroyCommandPool{nullptr};
PFN_vkDestroyDescriptorPool vkDestroyDescriptorPool{nullptr};
PFN_vkDestroyDevice vkDestroyDevice{nullptr};
PFN_vkCreateBuffer vkCreateBuffer{nullptr};
PFN_vkGetBufferMemoryRequirements vkGetBufferMemoryRequirements{nullptr};
PFN_vkAllocateMemory vkAllocateMemory{nullptr};
PFN_vkBindBufferMemory vkBindBufferMemory{nullptr};
PFN_vkUpdateDescriptorSets vkUpdateDescriptorSets{nullptr};
PFN_vkDestroyBuffer vkDestroyBuffer{nullptr};
PFN_vkFreeMemory vkFreeMemory{nullptr};
PFN_vkMapMemory vkMapMemory{nullptr};
PFN_vkUnmapMemory vkUnmapMemory{nullptr};
PFN_vkCreateShaderModule vkCreateShaderModule{nullptr};
PFN_vkCreateDescriptorSetLayout vkCreateDescriptorSetLayout{nullptr};
PFN_vkCreatePipelineLayout vkCreatePipelineLayout{nullptr};
PFN_vkCreateComputePipelines vkCreateComputePipelines{nullptr};
PFN_vkDestroyPipelineLayout vkDestroyPipelineLayout{nullptr};
PFN_vkDestroyDescriptorSetLayout vkDestroyDescriptorSetLayout{nullptr};
PFN_vkDestroyPipeline vkDestroyPipeline{nullptr};
PFN_vkDestroyShaderModule vkDestroyShaderModule{nullptr};

// clang-format on

// TODO: make it log what failed? or just assume that the whole fn set is required anyway?
#define CHECKFORNULLPTR(ptr) \
    if (ptr == nullptr)      \
        return false;

bool InitFunctions(HMODULE lib)
{
    vkGetInstanceProcAddr =
        (PFN_vkGetInstanceProcAddr)GetProcAddress(lib, "vkGetInstanceProcAddr");
    vkCreateInstance = (PFN_vkCreateInstance)vkGetInstanceProcAddr(
        nullptr, "vkCreateInstance");

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

    if (vkCreateInstance(&instanceCreateInfo, nullptr, &instance) != VK_SUCCESS)
    {
        return false;
    }

    vkGetDeviceProcAddr = (PFN_vkGetDeviceProcAddr)vkGetInstanceProcAddr(
        instance, "vkGetDeviceProcAddr");
    CHECKFORNULLPTR(vkGetDeviceProcAddr);

    vkEnumeratePhysicalDevices =
        (PFN_vkEnumeratePhysicalDevices)vkGetInstanceProcAddr(
            instance, "vkEnumeratePhysicalDevices");
    CHECKFORNULLPTR(vkEnumeratePhysicalDevices);

    vkGetPhysicalDeviceProperties =
        (PFN_vkGetPhysicalDeviceProperties)vkGetInstanceProcAddr(
            instance, "vkGetPhysicalDeviceProperties");
    CHECKFORNULLPTR(vkGetPhysicalDeviceProperties);

    vkGetPhysicalDeviceFeatures =
        (PFN_vkGetPhysicalDeviceFeatures)vkGetInstanceProcAddr(
            instance, "vkGetPhysicalDeviceFeatures");
    CHECKFORNULLPTR(vkGetPhysicalDeviceFeatures);

    vkGetPhysicalDeviceMemoryProperties =
        (PFN_vkGetPhysicalDeviceMemoryProperties)vkGetInstanceProcAddr(
            instance, "vkGetPhysicalDeviceMemoryProperties");
    CHECKFORNULLPTR(vkGetPhysicalDeviceMemoryProperties);

    vkGetPhysicalDeviceQueueFamilyProperties =
        (PFN_vkGetPhysicalDeviceQueueFamilyProperties)vkGetInstanceProcAddr(
            instance, "vkGetPhysicalDeviceQueueFamilyProperties");
    CHECKFORNULLPTR(vkGetPhysicalDeviceQueueFamilyProperties);

    vkDestroyInstance = (PFN_vkDestroyInstance)vkGetInstanceProcAddr(
        instance, "vkDestroyInstance");
    CHECKFORNULLPTR(vkDestroyInstance);

    vkCreateDevice =
        (PFN_vkCreateDevice)vkGetInstanceProcAddr(instance, "vkCreateDevice");
    CHECKFORNULLPTR(vkCreateDevice);

    return true;
}

void CleanUpVk()
{
    vkGetInstanceProcAddr = nullptr;
    vkCreateInstance = nullptr;
    vkGetDeviceProcAddr = nullptr;
    vkEnumeratePhysicalDevices = nullptr;
    vkGetPhysicalDeviceProperties = nullptr;
    vkGetPhysicalDeviceFeatures = nullptr;
    vkGetPhysicalDeviceMemoryProperties = nullptr;
    vkGetPhysicalDeviceQueueFamilyProperties = nullptr ;
    vkCreateDevice = nullptr;

    vkDestroyInstance(instance, nullptr);
    instance = nullptr;
    vkDestroyInstance = nullptr;
}
