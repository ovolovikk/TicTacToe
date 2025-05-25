#pragma once

class Board;

class Player {
private:
    char symbol;
    int score; // curr score(unused rn)
public:
    Player(char s);
    char getSymbol() const { return symbol; }

    // places symbol into the cell
    bool makeMove(Board &board, int row, int col);
};
