#include <cpparseini.hpp>
#include <fstream>
#include <iostream>

InitFile::InitFile() {
    InitFile(std::string("config.ini"));
}

InitFile::InitFile(std::string path) {
    this->path = path;
    char buf[512] = {0};
    // get config content (获取配置内容)
    std::fstream ctnt(path);
    std::string cur_section;
    while (!ctnt.eof()) {
        ctnt.getline(buf, 512);
        std::string raw_line(buf);
        if (!isValidLine(raw_line)) continue;
        std::string line = normalize(raw_line);
#ifdef DEBUG
        std::cout << line << std::endl;
#endif
    }
}
