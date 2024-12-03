#!/bin/bash

# 进入源目录
cd $(dirname $0)

# 设置源目录、构建目录和安装目录
SRC_DIR=$(pwd)/src
BUILD_DIR=$(pwd)/build
INSTALL_DIR=$(pwd)/install

# 判断 build 和 install 目录是否存在，不存在则创建
if [ ! -d $BUILD_DIR ]; then
    mkdir $BUILD_DIR
fi

if [ ! -d $INSTALL_DIR ]; then
    mkdir $INSTALL_DIR
fi

# 递归扫描src目录下的所有子目录
for dir in $(find $SRC_DIR -name CMakeLists.txt -exec dirname {} \;); do
    # 获取包名
    pkg_name=$(basename $dir)
    
    # 创建包的构建目录
    pkg_build_dir=$BUILD_DIR/$pkg_name
    mkdir -p $pkg_build_dir
    
    # 进入构建目录并运行cmake和make
    cd $pkg_build_dir
    cmake $dir -DCMAKE_INSTALL_PREFIX=$INSTALL_DIR -DCMAKE_TOOLCHAIN_FILE=/home/han/.config/arm_linux.cmake -DCMAKE_BUILD_TYPE=Release
    make
    make install
done

# 返回初始目录
cd $(pwd)
