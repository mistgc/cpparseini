#include <cpparseini.hpp>
#include <iostream>
#include <string>

int main() {
    InitFile* init = new InitFile(std::string("test/fixtures/config.ini"));
    std::cout << std::endl;
    init->display();
    return 0;
}
