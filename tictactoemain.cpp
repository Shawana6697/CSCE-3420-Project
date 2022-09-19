//Main
#include <iostream>
#include <stdlib.h>
#include "tictactoe.h"
#include "tictactoe.cpp"
using namespace std;
int main()
{
     while(gameover()){
        disp_board();
        player_turn();
        gameover();
    cout<<"TIMMY AND SHAWANA'S TIC TAC TOE \n";
    cout<<"2 PLAYERS\n";
    
    }
    if(turn == 'X' && draw == false){
        cout<<"Congratulations! Player 'O' has won the game";
    }
    else if(turn == 'O' && draw == false){
        cout<<"Congratulations! Player 'X' has won the game";
    }
    else
    cout<<"Game is a draw";
} 