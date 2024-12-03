#ifndef INI_READER_WRITER_H
#define INI_READER_WRITER_H

#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include <iostream>
#include <sstream>
#include <map>

using iniData = std::map<std::string, std::map<std::string, std::string>>;
class IniReaderWriter {
    public:
        IniReaderWriter(const std::string& filePath);
        ~IniReaderWriter();
        auto filePath() const { return _filePath; }
        bool writeIni();
        bool readIni();
        iniData data = {};

    private:
        const std::string _filePath;
        std::fstream _iniFile_stream;
};

#endif // INI_READER_WRITER_H