#include "Board.h"
#include "Player.h"
#include "SDLWindow.h"

int main() {
    /*
    Board board;
    Player player1('X');
    Player player2('0');

    while (true) {
        board.printBoard();
        player1.makeMove(board);
        if (board.hasSomeoneWin() != '\0')
            break;

        board.printBoard();
        player2.makeMove(board);
        if (board.hasSomeoneWin() != '\0')
            break;
    }

    board.printBoard();
    char winner = board.hasSomeoneWin();
    if (winner != '\0')
        std::cout << "Winner is: " << winner << std::endl;
    else
        std::cout << "Game Over!" << std::endl;
    */
    SDLWindow window;
    if (window.init("Tic Tac Toe", 800, 600))
    {
        window.run();
    }
    return 0;
}