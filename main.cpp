#include <iostream>
#include <cstdlib>

#include "fancy_border.cpp"
int clear_term() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
    return 0;
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

class engine {
public:
    void run() {
        while (!gameEnd) {
            input();
            gameUpdate();
            render();
        }
    }
private:
    bool gameEnd = false;

    void input() {
        std::string command;
        std::cout << ">";
        std::getline(std::cin, command);

        if (command == "look") {
            std::cout << "you are blind" << std::endl;
        } else if (command == "quit") {
            exit();
        } else {
            std::cout << "unknown command";
        }
    }

    void gameUpdate() {

    }

    void render() {

    }

    static void exit() {
        ::exit(0);
    }
};

int main() {
    //character_creation();
    engine engine;
    engine.run();
    return 0;
}

