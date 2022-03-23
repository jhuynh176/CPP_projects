//header declaration
#include "engine_functions.hpp"

//library declaration
#include <iostream>

int main() {
    bool menu_run = true;
    bool game_run = false;
    bool winner = false;
    char option = -1;
    std::vector <char> grid;
    int turn = 0;
    char player;

    intro();

    while (menu_run) {
        menu(option);
        switch (option) {
            case '1':
                system ("cls");
                grid = reset();
                turn = 0;
                game_run = true;
                sample_grid();
                system("pause");
                while (game_run) {
                    system("cls");
                    std::cout << "Current game grid: \n\n";
                    draw_grid(grid);

                    turn++;
                    player = change_player(turn);
                    grid = user_input(turn, grid, player);
                    winner = check_grid(grid);
                    game_run = winner_found(winner, player);
                }
                break;
            case '2':
                std::cout << "Exiting . . .\n\n";
                menu_run = false;
                break;
            default:
                std::cout << "ERROR: Invalid option. Please try again.\n\n";
        }
    }
}