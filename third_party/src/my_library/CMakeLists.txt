cmake_minimum_required(VERSION 3.10)
project(MyLibrary)

set(CMAKE_CXX_STANDARD 14)

# 添加静态库
add_library(my_library_static STATIC src/my_library.cpp)
set_target_properties(my_library_static PROPERTIES 
    OUTPUT_NAME my_library
    CLEAN_DIRECT_OUTPUT 1)

# 添加动态库
add_library(my_library_shared SHARED src/my_library.cpp)
set_target_properties(my_library_shared PROPERTIES 
    OUTPUT_NAME my_library
    CLEAN_DIRECT_OUTPUT 1)

# 包含库头文件
target_include_directories(my_library_static PUBLIC include)
target_include_directories(my_library_shared PUBLIC include)

# 安装库，将库文件安装到CMAKE_INSTALL_PREFIX指定的目录中的lib目录下
install(TARGETS my_library_static my_library_shared DESTINATION lib)

# 安装头文件，将头文件安装到CMAKE_INSTALL_PREFIX指定的目录中的include目录下
install(DIRECTORY include/ DESTINATION include)