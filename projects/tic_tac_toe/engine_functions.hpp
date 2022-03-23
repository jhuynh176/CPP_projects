//library declaration
#include <iostream>
#include <vector>


void intro();
void draw_grid(std::vector <char>);
void sample_grid();
void menu(char &);

std::vector <char> reset();
std::vector <char> user_input(int, std::vector <char>, char);
bool check_grid(std::vector <char>);
char change_player(int);
bool winner_found(bool, char);

void game_initiate(int &, bool &);