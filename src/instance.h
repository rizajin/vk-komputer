#ifndef INSTANCE_H
#define INSTANCE_H

#include <vulkan/vulkan.h>

class Instance
{
   public:
    Instance() = default;

    bool Create();
    VkInstance Get();
    void CleanUp();

   private:
    VkInstance inst;
};

#endif
