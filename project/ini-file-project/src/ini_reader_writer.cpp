#include "ini_reader_writer.h"

IniReaderWriter::IniReaderWriter(const std::string& file_path) : _filePath(file_path) {
    std::ifstream infile(_filePath);
    if (infile.good()) {
        std::cout << "文件"<< _filePath <<"已存在" << std::endl;
        infile.close();
        _iniFile_stream.open(_filePath, std::ios::in | std::ios::out | std::ios::ate);
        readIni();
    } else {
        std::cout << "文件" << _filePath << "不存在, 创建"<< std::endl;
        infile.close();
        _iniFile_stream.open(_filePath, std::ios::in | std::ios::out | std::ios::trunc);
    }
    if (!_iniFile_stream.is_open()) {
        std::cerr << "无法打开文件进行读写: " << _filePath << std::endl;
    }
}

IniReaderWriter::~IniReaderWriter() {
    _iniFile_stream.close();
}

bool IniReaderWriter::writeIni() {
    _iniFile_stream.close();
    _iniFile_stream.open(_filePath, std::ios::in | std::ios::out | std::ios::trunc);
    if (!_iniFile_stream.is_open()) {
        std::cerr << "无法打开文件进行写入: " << _filePath << std::endl;
        return false;
    }
    for (const auto& section : data) {
        _iniFile_stream << "[" << section.first << "]" << std::endl;
        for (const auto& keyValue : section.second) {
            _iniFile_stream << keyValue.first << "=" << keyValue.second << std::endl;
        }
        _iniFile_stream << std::endl;
    }
    _iniFile_stream.flush();

    _iniFile_stream.seekg(0, std::ios::beg);
    std::cout << "写入文件:" << std::endl;
    std::string line;
    while (std::getline(_iniFile_stream, line)) {
        std::cout << line << std::endl;
    }

    return true;
}

bool IniReaderWriter::readIni() {
    if (!_iniFile_stream.is_open()) {
        std::cerr << "无法打开文件进行读取: " << _filePath << std::endl;
        return false;
    }
    _iniFile_stream.seekg(0, std::ios::beg);

    std::string line;
    std::string currentSection;

    std::cout << "读取文件: " << _filePath << std::endl;
    while (std::getline(_iniFile_stream, line)) {
        std::cout << line << std::endl;

        if (line.empty() || line[0] == ';') {
            continue; // 跳过空行和注释
        }

        if (line[0] == '[' && line.back() == ']') {
            currentSection = line.substr(1, line.size() - 2);
        } else {
            size_t pos = line.find('=');
            if (pos != std::string::npos) {
                std::string key = line.substr(0, pos);
                std::string value = line.substr(pos + 1);
                data[currentSection][key] = value;
            }
        }
    }
    return true;
}