#include "InputHandler.h"

bool InputHandler::processEvent(const SDL_Event &event, int cellWidth, int cellHeight, Board &board,
                                 Player *&currentPlayer, Player &playerX, Player &playerO)
{
    if(event.type == SDL_MOUSEBUTTONDOWN)
    {
        int mouseX = event.button.x;
        int mouseY = event.button.y;
        int col = mouseX / cellWidth;
        int row = mouseY / cellHeight;
        if(row >= 0 && row < 3 && col >= 0 && col < 3)
        {
            if(currentPlayer->makeMove(board, row, col))
            {
                if(board.hasSomeoneWin(currentPlayer))
                {
                    return true;
                };
                currentPlayer = (currentPlayer->getSymbol() == 'X') ? &playerO : &playerX;
            }
        }
    }
    return false;
}