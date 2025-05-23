#pragma once

#include "Board.h"
#include <iostream>

class Player {
private:
    char symbol;
    int score;
public:
    Player(char s);
    char getSymbol() const { return symbol; }
    bool makeMove(Board &board, int row, int col);
};
