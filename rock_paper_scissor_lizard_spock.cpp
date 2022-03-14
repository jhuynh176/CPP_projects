#include <iostream>
#include <stdlib.h>

/* Description:
    - 1 Rock    beats   3 Scissor,  4 Lizard
    - 2 Paper   beats   5 Spock,    1 Rock
    - 3 Scissor beats   4 Lizard,   2 Paper
    - 4 Lizard  beats   2 Paper,    5 Spock
    - 5 Spock   beats   3 Scissor,  1 Rock 
*/

struct Game {
    
    const std::string choice[5] = {"Rock", "Paper", "Scissor", "Lizard", "Spock"};
    int round; //number of rounds play want to play
    int win = 0,
        lose = 0,
        tie = 0;
    int player_choice;
    int computer_choice;
    int round_result;
    
    void game_intro();
    void game_choice();
    void game_comparison();
    void game_progress();
    void game_ending();
        
        
};

void Game::game_intro() {
    std::cout   << "*******************************************\n"
                << "* Rock | Paper | Scissor | Lizard | Spock *\n"
                << "*******************************************\n";
    
    std::cout   << "How many rounds would you like to play?" << std::endl;
    std::cin    >> round;
}

void Game::game_choice() {
    std::cout   << "\t[1] - Rock\n"
                << "\t[2] - Paper\n"
                << "\t[3] - Scissor\n"
                << "\t[4] - Lizard\n"
                << "\t[5] - Spock\n"
                << std::endl;
    std::cout   << "Enter your choice number: ";
    std::cin    >> player_choice;    

    //Make choice for computer
}

void Game::game_comparison() {
//Tie
    if (player_choice == computer_choice) round_result = 0;
//Win
    //Rock
    else if (player_choice == 1 && (computer_choice == 3 || computer_choice == 4)) round_result = 1;
    //Paper
    else if (player_choice == 2 && (computer_choice == 5 || computer_choice == 1)) round_result = 1;
    //Scissor
    else if (player_choice == 3 && (computer_choice == 4 || computer_choice == 2)) round_result = 1;
    //Lizard
    else if (player_choice == 4 && (computer_choice == 2 || computer_choice == 5)) round_result = 1;
    //Spock
    else if (player_choice == 5 && (computer_choice == 3 || computer_choice == 1)) round_result = 1;
//Lose
    else round_result = 2;    

    switch(round_result) {
        case 0:
            std::cout << "\t(Player) " << choice[player_choice] 
                      << " vs. (Computer) " << choice[player_choice]
                      << " ===> You Win!" << std::endl;
            win++;
            break;
        case 1:
            std::cout << "\t(Player) " << choice[player_choice] 
                      << " vs. (Computer) " << choice[player_choice]
                      << " ===> You Lose!" << std::endl;
            lose++;
            break;            
        case 2:
            std::cout << "\t(Player) " << choice[player_choice] 
                      << " vs. (Computer) " << choice[player_choice]
                      << " ===> Tie!" << std::endl;
            tie++;
            break;        
    }
}

void Game::game_progress() {
    std::cout   << "\tWin = " << win << " | "
                << "Lose = " << lose << " | "
                << "Tie = " << tie 
                << std::endl;    
}

void Game::game_ending() {
    if (win > lose) 
        std::cout << "\nResult: (Player) won!" << std::endl;
    else if (lose > win) 
        std::cout << "\nResult: (Player) lost!" << std::endl;
    else 
        std::cout << "\nResult: It's a tie!" << std::endl;

    std::cout << "\nGame completed . . ." << std::endl;
    std::cout << "Thank you for playing." << std::endl;
}

int main() {
    srand(time(NULL));

    //Object player
    Game player;
    player.game_intro();

    //Counting number of played rounds
    int count = 1;

    for(int i = 0; i < player.round; i++) {
        std::cout   << "\nRound " << count++ << ": " << std::endl;
        player.game_choice();
        player.computer_choice = rand() % 5 + 1;
        player.game_comparison();
        player.game_progress();
    }
    
    player.game_ending();

    system("pause");
    
    return 0;
}