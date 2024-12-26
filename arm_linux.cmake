set(CMAKE_SYSTEM_NAME Linux)

set(CMAKE_SYSTEM_PROCESSOR arm)

# 设置交叉编译工具链的C语言编译器路径，注意应为完整路径
set(CMAKE_C_COMPILER gnu/aarch32/lin/gcc-arm-linux-gnueabi/bin/arm-linux-gnueabihf-gcc)

# 设置交叉编译工具链的C++语言编译器路径，注意应为完整路径
set(CMAKE_CXX_COMPILER gnu/aarch32/lin/gcc-arm-linux-gnueabi/bin/arm-linux-gnueabihf-g++)

# 有第三方依赖库的情况下，需要设置，其中third_party/install为第三方库的安装路径，注意应为完整路径

# 设置含有库的目录到CMAKE_PREFIX_PATH，CMAKE会通过find_package()在此目录下查找第三方库，
# 库必须具有<Library>Config.cmake文件或Find<Library>.cmake文件，否则find_package()无法找到库。
set(CMAKE_PREFIX_PATH  ${CMAKE_PREFIX_PATH} third_party/install)

# 设置含有头文件的目录到CMAKE_INCLUDE_PATH，CMAKE会通过find_path()在此目录下查找第三方头文件
set(CMAKE_INCLUDE_PATH ${CMAKE_INCLUDE_PATH} third_party/install/include)

# 设置含有库的目录到CMAKE_LIBRARY_PATH，CMAKE会通过find_library()在此目录下查找第三方库，
# 无需提供<Library>Config.cmake文件或Find<Library>.cmake文件，只需提供库文件即可。
set(CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} third_party/install/lib)

# 将第三方库的头文件目录添加到头文件搜索路径中，对所有引用此工具链配置文件的CMakeLists.txt文件有效
include_directories(${CMAKE_INCLUDE_PATH})
