#ifndef TICTACTOE_H
#define TICTACTOE_H
#include <iostream>
#include <stdlib.h>
using namespace std;

//Array for the board

char layout[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};

int choice;
int row;
int column;
char turn = 'X';
bool draw = false;

void disp_board();
void player_turn();
bool gameover();

#endif