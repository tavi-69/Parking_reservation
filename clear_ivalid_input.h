#include <iostream>
#include <limits>

void clear_invalid_input () {
    std::cin.clear(); // clear fail state
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
}