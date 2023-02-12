#pragma once

#include <iostream>
#include <limits>

namespace rps {

template <typename T>
T getUserInputIngeterToEnum() {
    int userInput;
    int min = static_cast<int>(T::BEGIN);
    int max = static_cast<int>(T::COUNT);
    while (true) {
        std::cin >> userInput;
        if (std::cin.fail() || userInput < min || userInput >= max) {
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
