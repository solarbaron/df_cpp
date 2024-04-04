//
// Created by solarbaron on 2.4.24.
//

#include "fancy_border.h"

void printBorder(const std::string& text) {
    // UTF-8 characters for the border
    const char* topLeft = "\u250C"; // ┌
    const char* topRight = "\u2510"; // ┐
    const char* bottomLeft = "\u2514"; // └
    const char* bottomRight = "\u2518"; // ┘
    const char* horizontal = "\u2500"; // ─
    const char* vertical = "\u2502"; // │

    std::istringstream stream(text);
    std::string line;
    std::vector<std::string> lines;
    size_t maxLength = 0;
    while (std::getline(stream, line)) {
        lines.push_back(line);
        if (line.length() > maxLength) {
            maxLength = line.length();
        }
    }

    // Calculate the width for the border based on the text length
    int width = maxLength + 2; // Adding space for padding

    // Print top border
    std::cout << topLeft;
    for (size_t i = 0; i < width; i++) std::cout << horizontal;
    std::cout << topRight << std::endl;

    //rewrite

    //printw(topLeft"\n");
    //for (size_t i = 0; i < width; i++) printw(horizontal,"\n");;
    //printw(topRight,"\n");

    for (const auto& l : lines) {
        std::cout << vertical << " " << l;
        // Print spaces if the line is shorter than the longest line
        for (size_t i = l.length(); i < maxLength; i++) {
            std::cout << " ";
        }
        std::cout << " " << vertical << std::endl;
    }

    // Print bottom border
    std::cout << bottomLeft;
    for (size_t i = 0; i < width; i++) std::cout << horizontal;
    std::cout << bottomRight << std::endl;
}
