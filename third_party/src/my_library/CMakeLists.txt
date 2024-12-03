cmake_minimum_required(VERSION 3.10)
project(MyLibrary)

set(CMAKE_CXX_STANDARD 14)

# 添加库源文件
add_library(my_library src/my_library.cpp)

# 包含库头文件
target_include_directories(my_library PUBLIC include)

# 安装库
install(TARGETS my_library DESTINATION lib)

# 安装头文件
install(DIRECTORY include/ DESTINATION include)