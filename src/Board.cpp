#include "Board.h"
#include <SDL2_gfxPrimitives.h>

Board::Board() {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j) 
            cells[i][j] = ' ';
}

bool Board::setCell(int row, int col, char symbol) {
    if (row >= 0 && row < 3 && col >= 0 && col < 3 && cells[row][col] == ' ') {
        cells[row][col] = symbol;
        return true;
    }
    return false;
}

char Board::getCell(int row, int col) const
{
    if (row >= 0 && row < 3 && col >= 0 && col < 3)
        return cells[row][col];
    return ' ';
}

bool Board::hasSomeoneWin(Player* player, int &winCase, int &index)
{   
    char ch = player->getSymbol();
    // check if any horizontal
    for(int i = 0; i < 3; ++i) {
        if(cells[i][0] == ch && cells[i][1] == ch && cells[i][2] == ch) {
            winCase = 0; index = i;
            return true;
        }
    }
    // check if any vertical
    for(int j = 0; j < 3; ++j) {
        if(cells[0][j] == ch && cells[1][j] == ch && cells[2][j] == ch) {
            winCase = 1; index = j;
            return true;
        }
    }
    // main diagonal
    if(cells[0][0] == ch && cells[1][1] == ch && cells[2][2] == ch) {
        winCase = 2; index = -1;
        return true;
    }
    // additional diagonal
    if(cells[0][2] == ch && cells[1][1] == ch && cells[2][0] == ch) {
        winCase = 3; index = -1;
        return true;
    }
    return false;
}