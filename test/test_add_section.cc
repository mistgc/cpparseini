#include <cpparseini.hpp>
#include <iostream>
#include <string>

int main() {
    InitFile* init1 = new InitFile(std::string("test/fixtures/config.ini"));
    std::cout << "\x1b[0;32mtest_add_section case 1:\x1b[0m" << std::endl;
    Section::items i;
    i.insert(std::pair<std::string, std::string>(std::string("Hello"), std::string("1111")));
    i.insert(std::pair<std::string, std::string>(std::string("World"), std::string("2222")));
    init1->addSection(std::string("Greet"), i);
    init1->display();

    std::cout << "\x1b[0;32mtest_add_section case 2:\x1b[0m" << std::endl;
    InitFile* init2 = new InitFile("test/fixtures/config.ini");
    Section sec("Language");
    sec.addItem("C#", "C++++");
    init2->addSection(sec);
    init2->display();
    return 0;
}
