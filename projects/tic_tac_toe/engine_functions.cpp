//header declaration
#include "engine_functions.hpp"

//library declaration
#include <iostream>


void intro() {
    std::cout << "===============================================================\n"
              << "======================= Tic - Tac - Toe =======================\n"
              << "===============================================================\n"
              << std::endl;
    std::cout << "Instruction: \n"
              << "- Player 1 is X\n"
              << "- Player 2 is O\n";
    std::cout << "- The first player who succeeds in placing three of their marks in a\n"
              << "\t- horizontal row\n"
              << "\t- vertical column\n"
              << "\t- diagonal rown\n"
              << "\t\t- will win the game.\n\n";
    std::cout << "=============================================================\n\n";
    sample_grid();
    system("pause");
    system("cls");
}

void menu(char &option) {
    system("cls");
    std::cout << "\nMain Menu: \n";
    std::cout << "[1]. New Game\n";
    std::cout << "[2]. Quit\n";
    std::cout << std::endl;
    std::cout << "Enter your option: ";
    std::cin >> option;
}

void draw_grid(std::vector <char> grid) {
    std::cout << "\t===============\n";
    for(int i = 0; i < 9; i += 3) {
        std::cout << "\t| " << grid[i] << " || " << grid[i+1] << " || " << grid[i+2] << " |\n";
        std::cout << "\t===============\n";
    }
    std::cout << "\n";
}

std::vector <char> reset() {
    std::vector <char> grid = {'_','_','_','_','_','_','_','_','_'};
    return grid;
}

void sample_grid() {
    std::vector <char> sample_grid = {'1','2','3','4','5','6','7','8','9'};
    std::cout << "Sample Grid: \n\n";
    draw_grid(sample_grid);
}

std::vector <char> user_input(int turn, std::vector <char> grid, char player) {
    int input_location;

    std::cout << "Player '" << player << "' turn.\n";

    input_error:
    std::cout << "\nPlease enter a valid number between 1 and 9: ";
    std::cin >> input_location;
    //Check available
    if(input_location < 1 || input_location > 9 || grid[input_location - 1] != '_')
        {
        std::cout << "\nERROR: Invalid Input. Please try again.\n";
        goto input_error;
        }
        grid[input_location-1] = player;
        return grid;
}

bool check_grid(std::vector <char> grid) {
    bool winner = false;

    //checking row wise
    if ((grid[0] == grid[1]) && (grid[1] == grid[2]) && grid[0] != '_') winner = true;
    else if ((grid[3] == grid[4]) && (grid[3] == grid[5]) && grid[3] != '_') winner = true;
    else if ((grid[6] == grid[7]) && (grid[6] == grid[8]) && grid[6] != '_') winner = true;
    

    //checking column wise
    else if ((grid[0] == grid[3]) && (grid[0] == grid[6]) && grid[0] != '_') winner = true;
    else if ((grid[1] == grid[4]) && (grid[1] == grid[7]) && grid[1] != '_') winner = true;
    else if ((grid[2] == grid[5]) && (grid[2] == grid[8]) && grid[2] != '_') winner = true;
    
    // checking diagonal wise
    else if ((grid[0] == grid[4]) && (grid[0] == grid[8]) && grid[0] != '_') winner = true;
    else if ((grid[2] == grid[4]) && (grid[2] == grid[6]) && grid[2] != '_') winner = true;

    return winner;
}

char change_player(int turn) {
    char player;
    if(turn % 2 == 0) {
        //even turn
        player = 'X';
    }
    else {
        //odd turn
        player = 'O';
    }
    return player;
}

bool winner_found(bool winner, char player) {
    bool game_on = true;
    if(winner) {
        std::cout << "\n\nPlayer '" << player << "' is the winner!.\n\n";
        game_on = false;
        system("pause");
    }
    return game_on;
}

void game_initiate(int &turn, bool &game_run) {
    turn = 0;
    game_run = true;
    system ("cls");
    sample_grid();
    system("pause");
}