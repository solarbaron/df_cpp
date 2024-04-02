//
// Created by solarbaron on 2.4.24.
//

#include "fancy_border.h"

#include <iostream>
#include <string>
#include <vector>

void printBorder(const std::string& text) {
    // UTF-8 characters for the border
    const char* topLeft = "\u250C"; // ┌
    const char* topRight = "\u2510"; // ┐
    const char* bottomLeft = "\u2514"; // └
    const char* bottomRight = "\u2518"; // ┘
    const char* horizontal = "\u2500"; // ─
    const char* vertical = "\u2502"; // │

    // Calculate the width for the border based on the text length
    int width = text.length() + 2; // Adding space for padding

    // Print top border
    std::cout << topLeft;
    for (int i = 0; i < width; i++) std::cout << horizontal;
    std::cout << topRight << std::endl;

    // Print text with side borders
    std::cout << vertical << " " << text << " " << vertical << std::endl;

    // Print bottom border
    std::cout << bottomLeft;
    for (int i = 0; i < width; i++) std::cout << horizontal;
    std::cout << bottomRight << std::endl;
}
