#最低要求
cmake_minimum_required(VERSION 3.21)
#项目名称
project(Leetcode)

# 引入include文件夹
include_directories(BEFORE include)
# BEFORE 将 include 目录添加到搜索路径的最前面 不加就是放到最后面
# 比如说我自己写一个vector.h然后和标准库重名了，但是BEFORE引入的话我的优先级高，用的就是我的自定义库

#设置CMake变量
set(CMAKE_CXX_STANDARD 23)

# 先创建库，包含 src 中的所有实现
add_library(leetcode_lib STATIC)
file(GLOB_RECURSE SOURCE_FILES "src/*.cpp")
target_sources(leetcode_lib PRIVATE ${SOURCE_FILES})

# 主程序链接这个库
add_executable(Leetcode main.cpp)
target_link_libraries(Leetcode PRIVATE leetcode_lib)

#添加子目录
add_subdirectory(leetcode/editor/cn)
add_subdirectory(interestingQuestion)
