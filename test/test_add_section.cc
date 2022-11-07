#include <cpparseini.hpp>
#include <iostream>
#include <string>

int main() {
    InitFile* init = new InitFile(std::string("test/fixtures/config.ini"));
    Section::items i;
    i.insert(std::pair<std::string, std::string>(std::string("Hello"), std::string("1111")));
    i.insert(std::pair<std::string, std::string>(std::string("World"), std::string("2222")));
    init->addSection(std::string("Greet"), i);
    std::cout << std::endl;
    init->display();
    return 0;
}
