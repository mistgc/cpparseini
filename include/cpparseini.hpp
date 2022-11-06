#ifndef __CPPARSEINI_HPP__
#define __CPPARSEINI_HPP__

#include <string>
#include <unordered_map>

class Section {
    using items = std::unordered_map<std::string, std::string>;
private: 
    items data;
public:
    Section();

    void addItem(std::string k, std::string v);

    void addItems(items kvs);

    void removeItem(std::string k);

    std::string getValue(std::string k);

    items getAll();
};

class InitFile {
    using items = std::unordered_map<std::string, std::string>;
private:
    std::unordered_map<std::string, Section> content;

    std::string                              path;

    static inline bool isSection(std::string line);

    static std::string parseSection(std::string line);

    static inline items parseItem(std::string line);

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
public:
    InitFile();

    InitFile(std::string path);

    void addSection(std::string name, items kvs);

    void removeSection(std::string name);

    Section& getSection(std::string name);

};
#endif //__CPPARSEINI_HPP__
