cmake_minimum_required(VERSION 3.10) # 设置CMake的最低版本要求
project(pmn3 VERSION 0.1.0) # 定义项目名称和版本

set(CMAKE_CXX_STANDARD 14) # 设置C++标准为C++14

# 设置编译器标志，-Wall表示开启所有警告，-Wextra表示开启额外警告，-Wpedantic表示开启严格警告
if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    add_compile_options(-Wall -Wextra -Wpedantic)
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    add_compile_options(/W4)
endif()

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin) # 设置可执行文件的输出路径

# 设置链接器标志, 静态链接gcc和stdc++库，否则在其他机器上运行时可能会提示缺少libstdc++.so.6，
# -static-libxxx表示静态链接指定的库, -static表示静态链接所有库
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")

# 设置Release模式下的编译选项，需在编译时通过命令行、代码或IDE方式指定编译模式为Release模式，
# -O3表示最高优化级别，-DNDEBUG表示关闭断言
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG")

# 设置查找库时的后缀，通过此方式可以控制CMAKE优先使用动态库还是静态库，会先查找.a文件，再查找.so文件。
set(CMAKE_FIND_LIBRARY_SUFFIXES .a .so)

# find_package() 只适用于查找安装在系统目录或包含在CMAKE_PREFIX_PATH的目录，且提供了CMake模块文件的库。
# 注意，如果是系统内置标准库，可以直接使用库名去链接，不需要使用find_package()或find_library()查找。
find_package(Threads REQUIRED) # 查找线程库

# find_library()用于查找指定的库，第一个参数是变量名，第二个参数是库名（库名不需要指定前缀lib和后缀.so），第三个参数是库的路径；
# 第三个参数库的路径可以不指定，CMAKE默认从系统目录或CMAKE_LIBRARY_PATH和CMAKE_PREFIX_PATH中指定的目录中查找。
find_library(zmqlib zmq REQUIRED)
find_library(zmqpplib zmqpp REQUIRED)
find_library(boost_filesystemlib boost_filesystem REQUIRED)
find_library(ssllib ssl REQUIRED)
find_library(cryptolib crypto REQUIRED)

# include_directories()会在编译时将指定的目录添加到头文件搜索路径中，且对其子目录有效，
# 注意，在include子目录头文件时，需要通过 include"子目录/xxx.h"，而不是include"xxx.h"，
# 要想使用include"xxx.h"的方式，需要在include_directories()中添加子目录路径。
include_directories("/home/han/third_party/install/include/zmqpp")
include_directories(src) # 包含src目录, 以便在源文件中使用#include "xxx.h"的方式包含头文件

file(GLOB_RECURSE DIR_SRCS # 递归获取src目录下的所有.cpp文件
    ${PROJECT_SOURCE_DIR}/src/**.cpp
)

add_executable(pmn3.elf ${DIR_SRCS}) # 定义可执行文件并添加源文件

# target_link_libraries()用于链接第三方库到可执行文件，第一个参数是可执行文件名，后面的参数是要链接的库名，多个库用空格或换行隔开，
# 如果是系统内置标准库，可以直接使用库名去链接；如果时通过find_library()查找的库，需要使用${变量名}的方式去链接。
# 如果是通过find_package()查找的库，可以使用库名::库名的方式去链接。
# 对于所有的库，都可直接使用其绝对路径去链接，如：/usr/lib/x86_64-linux-gnu/libzmq.so，但注意动态库需要在运行时将其路径添加到LD_LIBRARY_PATH中。
target_link_libraries(pmn3.elf 
                      dl                # 链接系统内置标准库, 无需使用find_library()查找, 直接使用库名
                      Threads::Threads  # 链接通过find_package()查找的库, 使用库名::库名的方式
                      ${zmqlib} ${zmqpplib} ${boost_filesystemlib} ${ssllib} ${cryptolib}  # 链接通过find_library()查找的库, 使用${变量名}的方式
)               