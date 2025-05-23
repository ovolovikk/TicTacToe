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