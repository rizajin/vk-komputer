cmake_minimum_required(VERSION 3.21)
project(vkKomputer)

find_package(Vulkan REQUIRED COMPONENTS glslang shaderc_combined)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(vkKompute STATIC 
    src/framework.cpp
    inc/framework.h
    src/vk.cpp
    src/vk.h

    src/command_manager.cpp
    src/command_manager.h
    src/device.cpp
    src/device.h
    src/instance.cpp
    src/instance.h
    src/pipeline.cpp
    src/pipeline.h
)
target_compile_definitions(vkKompute PRIVATE -DVK_NO_PROTOTYPES)
target_link_libraries(vkKompute PRIVATE Vulkan::Headers)
target_include_directories(vkKompute SYSTEM INTERFACE inc)
target_include_directories(vkKompute PRIVATE inc)

add_executable(Sample main.cpp)
target_link_libraries(Sample vkKompute)
