#include <iostream>
#include <cstdlib>

#include "fancy_border.cpp"
int clear_term() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
    return 0
}

void character_creation() {
    std::string c_name;
    std::cout << "welcome to character creation" << std::endl;
    std::cout << "Enter your character name: ";
    std::cin >> c_name;
    std::string name_tmp1 = "name: ";
    name_tmp1 += c_name;
    clear_term();
    printBorder(name_tmp1);
}


int main() {
    character_creation();
    return 0;
}

