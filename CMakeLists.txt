cmake_minimum_required(VERSION 3.21)
project(vkKomputer)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

#add_library(x SHARED src/x.cpp)

add_executable(Sample main.cpp)
#target_link_libraries(Sample x)