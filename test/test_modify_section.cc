#include <cpparseini.hpp>
#include <iostream>
#include <string>

int main() {
    std::cout << "\x1b[0;32mtest_modify_section case 1:\x1b[0m" << std::endl;
    InitFile* init1 = new InitFile(std::string("test/fixtures/config.ini"));
    auto sec_cache = init1->getSection(std::string("Cache"));
    std::cout << sec_cache << std::endl;
    sec_cache->setValue("ip", "127.0.0.1");
    sec_cache->setValue("domain", "localhost");
    init1->display();

    std::cout << "\x1b[0;32mtest_modify_section case 2:\x1b[0m" << std::endl;
    InitFile* init2 = new InitFile("test/fixtures/config.ini");
    Section* sec_db = init2->getSection(std::string("Database"));
    sec_db->setValue("user", "linux");
    sec_db->removeItem(std::string("password"));
    sec_db->addItem("passwd", "123");
    sec_db->display();
    
    return 0;
}
