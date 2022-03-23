#include <iostream>
#include <vector>

// Define functions
void greet() {
    std::cout << "==========================================================\n"
              << "                      UFO : The Game                      \n"
              << "==========================================================\n"
              << "\n"
              << "Instructions: Save your friend from alien abduction.......\n"
              << "................. by guessing the letters in the codeword.\n"
              << "\n"
              << "==========================================================\n"
              << std::endl;
}

void display_status(std::vector <char> incorrect, std::string answer, int misses) {

    std::cout << "=================== Status ===================\n\n";
    std::cout << "Misses: " << misses << std::endl;
    
    std::cout << "Incorrect Guesses: ";
    for (auto c : incorrect) std::cout << c << " ";
    std::cout << std::endl;

    std::cout << "Codeword: ";
    for (auto c : answer) std::cout << c << " ";
    std::cout << "\n" << std::endl;

    std::cout << "==============================================\n"
              << std::endl;
}

void guess_status() {

}




void ufo() {
    std::cout << "                 .                            \n";
    std::cout << "                 |                            \n";
    std::cout << "              .-\"^\"-.                       \n";
    std::cout << "             /_....._\\                       \n";
    std::cout << "         .-\"`         `\"-.                  \n";
    std::cout << "        (  ooo  ooo  ooo  )                   \n";
    std::cout << "         '-.,_________,.-'    ,-----------.   \n";
}
void land() {
    std::cout << "______________________________________________\n";
    std::cout << "//////////////////////////////////////////////\n";
}
void display_misses(int misses) {

    if (misses == 0) {

        ufo();
        std::cout << "              /     \\        (  Send help! ) \n";
        std::cout << "             /       \\      / `-----------'  \n";
        std::cout << "            /    0    \\    /                 \n";
        std::cout << "           /   --|--   \\                     \n";
        std::cout << "          /      |      \\                    \n";
        std::cout << "         /      / \\      \\                  \n";
        land();

    }
    else if (misses == 1) {

        ufo();   
        std::cout << "              /     \\        (  Send help! ) \n";
        std::cout << "             /   0   \\      / `-----------'  \n";
        std::cout << "            /  --|--  \\    /                 \n";
        std::cout << "           /     |     \\                     \n";
        std::cout << "          /     / \\     \\                   \n";
        std::cout << "         /               \\                   \n";
        land();

    }
    else if (misses == 2) {

        ufo();
        std::cout << "              /  0  \\        (  Send help! ) \n";
        std::cout << "             / --|-- \\      / `-----------'  \n";
        std::cout << "            /    |    \\    /                 \n";
        std::cout << "           /    / \\    \\                    \n";
        std::cout << "          /             \\                    \n";
        std::cout << "         /               \\                   \n";
        land();

    }
    else if (misses == 3) {

        ufo();
        std::cout << "              /--|--\\        (  Send help! ) \n";
        std::cout << "             /   |   \\      / `-----------'  \n";
        std::cout << "            /   / \\   \\    /                \n";
        std::cout << "           /           \\                     \n";
        std::cout << "          /             \\                    \n";
        std::cout << "         /               \\                   \n";
        land();

    }
    else if (misses == 4) {

        ufo();
        std::cout << "              /  |  \\        (  Send help! ) \n";
        std::cout << "             /  / \\  \\      / `-----------' \n";
        std::cout << "            /         \\    /                 \n";
        std::cout << "           /           \\                     \n";
        std::cout << "          /             \\                    \n";
        std::cout << "         /               \\                   \n";
        land();

    }
    else if (misses == 5) {

        ufo();
        std::cout << "              / / \\ \\        (  Send help! )\n";
        std::cout << "             /       \\      / `-----------'  \n";
        std::cout << "            /         \\    /                 \n";
        std::cout << "           /           \\                     \n";
        std::cout << "          /             \\                    \n";
        std::cout << "         /               \\   LAST CHANCE !!! \n";
        std::cout << "______________________________________________\n";;
        std::cout << "//////////////////////////////////////////////\n";

  }

    std::cout << std::endl;
}

void end_game(bool flag_won) {
    if (flag_won) {
        std::cout << "                       ,-----------.          \n";
        std::cout << "                      (  Thank you! )         \n";
        std::cout << "                     / `-----------'          \n";
        std::cout << "                0   /                         \n";
        std::cout << "              --|--                           \n";
        std::cout << "                |                             \n";
        std::cout << "               / \\                           \n";
        land();

        std::cout << "\n\n"
                  << "=========================================================\n"
                  << "Horray! You saved the person and earned a medal of honor!\n"
                  << "=========================================================\n"
                  << "=================== CONGRATULATION !! ===================\n"
                  << std::endl;
    }
    else { 
        ufo();
        std::cout << "              /     \\        (  Send help! ) \n";
        std::cout << "             /       \\      / `-----------'  \n";
        std::cout << "            /         \\    /                 \n";
        std::cout << "           /           \\                     \n";
        std::cout << "          /             \\     GAME OVER      \n";
        std::cout << "         /               \\       !!!         \n";
        land();

        std::cout << "\n\n"
                  << "==================================================\n"
                  << "Oh no! The UFO just flew away with another person!\n" 
                  << "==================================================\n"
                  << "================== GAME OVER !! ==================\n"
                  << std::endl;
    }
}