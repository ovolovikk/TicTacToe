#include "InputHandler.h"
#include "GameLogic.h"
#include <iostream>

void InputHandler::processEvent(const SDL_Event &event, GameState &gameState, bool &isRunning)
{

    if(event.type == SDL_MOUSEBUTTONDOWN)
    {
        if(gameState.gameOver)
        {
            if(gameState.playAgainButton.handleEvent(event))
            {
                int winW = gameState.cellWidth * 3;
                int winH = gameState.cellHeight * 3;
                gameState.reset(winW, winH);
            }
            return;
        }
        // processing click on game board cells
        int mouseX = event.button.x;
        int mouseY = event.button.y;
        int col = mouseX / gameState.cellWidth;
        int row = mouseY / gameState.cellHeight;
        if(row >= 0 && row < 3 && col >= 0 && col < 3)
        {
            GameLogic logic;
            logic.processMove(gameState, row, col);
        }
    }
}