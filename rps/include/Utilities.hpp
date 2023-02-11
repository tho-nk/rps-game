#pragma once


#include <limits>
#include <iostream>

namespace rps {

template <typename T>
T getUserInputIngeter(int min, int max) {
    int userInput;
    while (true) {
        std::cin >> userInput;
        if (std::cin.fail() || userInput < min || userInput > max) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please try again." << std::endl;
        } else {
            break;
        }
    }
    return static_cast<T>(userInput);
}
}  // namespace rps
