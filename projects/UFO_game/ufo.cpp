#include <iostream>
#include "ufo_functions.hpp"

int main() {
    greet();

    std::string codeword = "human";
    std::string answer = "_ _ _ _ _";

    int misses = 0;
    bool won = false;

    while (answer != codeword && misses < 7) {


        misses++;
    }

    
}
