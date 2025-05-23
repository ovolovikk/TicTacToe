#include "Player.h"

Player::Player(char Symbol) : symbol(Symbol), score(0) 
{
}

bool Player::makeMove(Board &board, int row, int col)
{
    return board.setCell(row, col, symbol);
}