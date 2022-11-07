#ifndef __CPPARSEINI_HPP__
#define __CPPARSEINI_HPP__

#include <iostream>
#include <string>
#include <unordered_map>

class Section {
public:
    using items = std::unordered_map<std::string, std::string>;

    Section();

    Section(items data);

    Section(std::string name);

    Section(const char* name);

    Section(std::string name, items data);
    
    Section(const char* name, items data);

    void addItem(std::string k, std::string v);

    void addItem(const char* k, const char* v);

    void addItems(const std::string& content);

    void addItems(items kvs);

    bool removeItem(std::string k);

    void clear();

    std::string getName();

    std::string getValue(std::string k);

    void setValue(std::string k, std::string v);

    void setValue(const char* k, const char* v);

    items& getAll();

    void display();
private: 
    std::string                              name;

    items                                    data;
};

class InitFile {
public:
    using items = std::unordered_map<std::string, std::string>;

    friend class Section;

    InitFile();

    InitFile(std::string path);

    InitFile(const char* path);

    void addSection(std::string name, items kvs);

    void addSection(Section sec);

    bool removeSection(std::string name);

    void clear();

    Section* getSection(std::string name);

    Section* getSection(const char* name);

    void display();

private:
    /* initialization file content after parsed (解析后配置文件内容) */
    std::unordered_map<std::string, Section> content;

    /* current section (当前Section) */
    std::string                              cur_sec;

    /* path of config file loaded (加载配置文件的路径) */
    std::string                              path;

    void parseSection(std::string line) {
        std::string k = line.substr(1, line.length()-2);
        cur_sec = k;
#ifdef DEBUG
        std::cout << k << std::endl;
#endif
        Section v;
        std::pair<std::string, Section> sec(k, v);
        content.insert(sec);
    }

    inline void parseItem(std::string line) {
        size_t idx;
        size_t len = line.length();
        for (idx = 0; idx < len; idx++)
            if (line[idx] == '=') break;
        std::string k = line.substr(0, idx);
        std::string v = line.substr(idx+1);
#ifdef DEBUG
        std::cout << k << "=" << v << std::endl;
#endif
        content[cur_sec].addItem(k, v);
    }

    static inline bool isSection(std::string line) {
        if (line[0] == '[' && line[line.length()-1] == ']') {
            return true;
        } else return false;
    }

    static inline bool isValidLine(const std::string &line) {
        if (line.length() == 0 || line[0] == '\t' || line[0] == '\r' || line[0] == '\n') return false;
        else return true;
    }

    static inline bool isWitheSpace(const char c) {
        if (c == '\r' || c == '\t' || c == ' ') return true;
        else return false;
    }

    static inline std::string normalize(const std::string &line) {
        std::string res;
        for (auto &c : line) {
            if (isWitheSpace(c)) continue;
            res.push_back(c);
        }
        return res;
    }
};
#endif //__CPPARSEINI_HPP__
