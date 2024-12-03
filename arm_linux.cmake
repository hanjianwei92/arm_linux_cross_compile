set(CMAKE_SYSTEM_NAME Linux)

set(CMAKE_SYSTEM_PROCESSOR arm)

set(CMAKE_C_COMPILER gnu/aarch32/lin/gcc-arm-linux-gnueabi/bin/arm-linux-gnueabihf-gcc)

set(CMAKE_CXX_COMPILER gnu/aarch32/lin/gcc-arm-linux-gnueabi/bin/arm-linux-gnueabihf-g++)

# 有第三方依赖库的情况下，需要设置，其中third_party/install为第三方库的安装路径
# set(CMAKE_PREFIX_PATH  ${CMAKE_PREFIX_PATH} third_party/install)

# set(CMAKE_INCLUDE_PATH ${CMAKE_INCLUDE_PATH} third_party/install/include)

# set(CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} third_party/install/lib)

# include_directories(${CMAKE_INCLUDE_PATH})
