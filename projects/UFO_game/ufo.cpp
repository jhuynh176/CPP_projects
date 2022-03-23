#include <iostream>
#include "ufo_functions.hpp"

int main() {
    greet();

    std::string codeword = "humaan";
    std::string answer = "______";

    std::vector <char> incorrect;

    char letter;

    int misses = 0;
    bool flag_won = false;

    while (answer != codeword && misses < 6) {

        //default variable for every iteration
        bool guess = false;

        display_misses(misses);
        display_status(incorrect, answer, misses);

        //player input function
        std::cout << "Please enter your guess: ";
        std::cin >> letter;

        for(int i = 0; i < codeword.size(); i++) {
            if(letter == codeword[i]) {
                answer[i] = letter;
                guess = true;
            }
        }
        if (guess) 
            std::cout << "\n--> Correct!" << std::endl;
        else {
            std::cout << "\n--> Incorrect! The tractor beam pulls the person in further." << std::endl;
            incorrect.push_back(letter);
            misses++;
        }
    }

    end_game(flag_won);

    
}
