#include <cpparseini.hpp>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

//========================InitFile===========================

InitFile::InitFile() {
    // default path is 'config.ini' (默认路径为config.ini)
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
        if (isSection(line))
            parseSection(line);
        else
            parseItem(line);
    }
}

void InitFile::addSection(std::string name, Section::items kvs) {
    Section sec(kvs);
    std::pair<std::string, Section> p(name, sec);
    content.insert(p);
}

bool InitFile::removeSection(std::string name) {
    auto iter = content.find(name);
    if (iter != content.end()) {
        // clear data of the section first
        iter->second.clear();
        content.erase(name);
        return true;
    } else
        return false;
}

void InitFile::clear() {
    for (auto& sec : content) {
        removeSection(sec.first);
    }
}

Section& InitFile::getSection(std::string name) {
    auto iter = content.find(name);
    return iter->second;
}

void InitFile::display() {
    for (auto& i : content) {
        std::cout << "[" << i.first << "]" << std::endl;
        i.second.display();
    }
}

//========================Section============================

Section::Section() {
    data = Section::items();
}

Section::Section(Section::items data) {
    this->data = data;
}

void Section::addItem(std::string k, std::string v) {
    std::pair<std::string, std::string> item(k, v);
    data.insert(item);
}

void Section::addItems(const std::string& content) {
    char buf[512] = {0};
    std::istringstream iss(content);
    while (!iss.eof()) {
        iss.getline(buf, 512);
        std::string raw_line(buf);
        if (!InitFile::isValidLine(raw_line)) continue;
        std::string line = InitFile::normalize(raw_line);
#ifdef DEBUG
        std::cout << line << std::endl;
#endif
        size_t idx;
        size_t len = line.length();
        for (idx = 0; idx < len; idx++)
            if (line[idx] == '=') break;
        std::string k = line.substr(0, idx);
        std::string v = line.substr(idx+1, len);
#ifdef DEBUG
        std::cout << k << ":" << v << std::endl;
#endif
        addItem(k, v);
    }
}

void Section::addItems(Section::items kvs) {
    for (auto kv : kvs) {
        data.insert(kv);
    }
}

bool Section::removeItem(std::string k) {
    // query whether the key exists (查询key是否存在)
    if (data.find(k) != data.end()) {
        data.erase(k);
        return true;
    }
    else return false;
}

void Section::clear() {
    data.clear();
}

std::string Section::getValue(std::string k) {
    auto iter = data.find(k);
    if (iter != data.end())
        return iter->second;
    else 
        return NULL;
}

Section::items& Section::getAll() {
    return data;
}

void Section::display() {
    for (auto& item : data)
        std::cout << item.first << "=" << item.second << std::endl;
}
