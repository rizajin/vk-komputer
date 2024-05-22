#ifndef VK_INC
#define VK_INC

#include <Windows.h>
#include <vulkan/vulkan.h>

extern PFN_vkGetInstanceProcAddr vkGetInstanceProcAddr;
extern PFN_vkCreateInstance vkCreateInstance;

bool InitFunctions(HMODULE);
void CleanUpVk();

#endif
