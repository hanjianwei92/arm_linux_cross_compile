# ini-file-project

该项目实现了INI文件的读写功能，并验证INI文件是否成功写入指定目录。

## 文件结构

```
ini-file-project
├── src
│   ├── main.cpp          // 程序入口点
│   ├── ini_reader_writer.cpp // INI文件读写实现
│   └── ini_reader_writer.h   // INI文件读写功能的头文件
├── CMakeLists.txt       // CMake构建配置
└── README.md            // 项目文档
```

## 编译和运行

1. 确保已安装CMake和C++编译器。
2. 在项目根目录下创建构建目录并进入该目录：

   ```bash
   mkdir build
   cd build
   ```

3. 运行CMake以生成Makefile：

   ```bash
   cmake ..
   ```

4. 编译项目：

   ```bash
   make
   ```

5. 运行生成的可执行文件：

   ```bash
   ./ini-file-project
   ```

## 功能说明

- `main.cpp`：程序入口，调用INI文件读写功能，并验证写入是否成功。
- `ini_reader_writer.cpp`和`ini_reader_writer.h`：实现INI文件的读取和写入逻辑。

## 依赖

- C++14或更高版本的编译器
- CMake 3.0或更高版本

## 许可证

本项目采用MIT许可证，详情请查看LICENSE文件。