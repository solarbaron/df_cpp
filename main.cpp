#include <iostream>
#include <cstdlib>

#ifdef _WIN32
#include <curses.h>
#else
#include <ncurses.h>
#endif

#include "fancy_border.cpp"

class staticBaseCommands {
private:
    static void clearTerminal() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
    }
    static void helpMenu() {
        initscr();          // Initialize NCurses
        cbreak();           // Disable line buffering
        noecho();           // Don't echo the characters typed to the screen
        nodelay(stdscr, TRUE); // Non-blocking read

        clear();
        std::string helpMenu = "commands:\n\n look - makes observation of your surroundings\n clear - clears text in terminal\n quit - exits game \n\n";

        //printBorder(helpMenu);
        printw(helpMenu.c_str());
        printw("Press 'q' to exit help menu.\n");
        refresh();

        int ch;
        while((ch = getch()) != 'q') {
            if(ch != ERR) {
                // Process the input
                //printw("You pressed: %c\n", ch);
            }
        }
        endwin(); // End NCurses mode

    }

    friend class engine;
    friend class characterCreation;
};

class characterCreation {
public:
    void base() {
        name();
    }
private:
    void name() {
        std::string characterName;
        std::string characterInfo;
        std::string characterGender = "joe";
        std::cout << "welcome to character creation" << std::endl;
        std::cout << "Enter your character name: ";
        std::getline(std::cin, characterName);
        characterInfo = ("name: " + characterName + "\ngender: " + characterGender);
        staticBaseCommands::clearTerminal();
        printBorder(characterInfo);
    }
};


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
        }
        else if (command == "help") {
            staticBaseCommands::helpMenu();
        }
        else if (command == "clear") {
            staticBaseCommands::clearTerminal();
        }
        else if (command == "") {
        }
        else if (command == "quit") {
            exit();
        } else {
            std::cout << "unknown command" << std::endl;
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
    characterCreation characterCreation;
    characterCreation.base();
    engine engine;
    engine.run();
    return 0;
}

