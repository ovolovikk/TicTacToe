#pragma once

class Board;

class Player {
private:
    char symbol;
    int score;
public:
    Player(char s);
    char getSymbol() const { return symbol; }
    bool makeMove(Board &board, int row, int col);
};
