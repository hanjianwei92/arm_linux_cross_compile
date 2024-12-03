#include "ini_reader_writer.h"
// #include "my_library.h"

int main() {
    const std::string filePath = "config.ini";
    IniReaderWriter iniFile(filePath);

    // 初始化INI文件数据
   iniFile.data = {
        {"Settings", {{"Volume", std::to_string(75)}, {"Brightness", "50"}}},
        {"Network", {{"IP", "192.168.1.23"}, {"Port", "8080"}}}
    };

    // 写入INI文件
   if (iniFile.writeIni()) {
        std::cout << "INI文件写入成功！" << std::endl;
    } else {
        std::cout << "INI文件写入失败！" << std::endl;
    }

    // 读取INI文件
    if (iniFile.readIni()) {
        std::cout << "INI文件读取成功！" << std::endl;
    } else {
        std::cout << "INI文件读取失败！" << std::endl;
    }

    // 验证INI参数是否写入成功
    if (iniFile.data.count("Settings") >= 1 && iniFile.data["Settings"].count("Volume") >= 1 &&
         std::stoi(iniFile.data["Settings"]["Volume"]) == 75) {
         std::cout << "验证INI文件写入成功！" << std::endl;
    } else {
        std::cout << "验证INI文件写入失败！" << std::endl;
    }

    // my_library_function();

    return 0;
}