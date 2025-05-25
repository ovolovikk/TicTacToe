#include "GameController.h"
#include <SDL2_gfxPrimitives.h>
#include <iostream>

// Constructor initializes the game state with window dimensions.
GameController::GameController(int winWidth, int winHeight)
    : gameState(winWidth, winHeight)
{}

// run() is the main game loop. It processes input, updates state, and renders frames.
void GameController::run(SDL_Renderer* renderer) {
    int winWidth, winHeight;
    SDL_GetRendererOutputSize(renderer, &winWidth, &winHeight);
    SDL_Event event;

    while(gameState.isRunning)
    {
        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT)
                gameState.isRunning = false;
            else
                InputHandler::processEvent(event, gameState, gameState.isRunning);
        }

        // Clear and draw the game board
        SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
        SDL_RenderClear(renderer);

        boardRenderer.draw(renderer, winWidth, winHeight, gameState.board);

        // if the game has ended drawing winningLine, overlay and button "PlayAgain"
        if(gameState.gameOver)
        {
            int cellW = gameState.cellWidth, cellH = gameState.cellHeight;
            int x1=0, y1=0, x2=0, y2=0;
            switch(gameState.winInfo.winCase)
            {
                case 0: // horizontal win
                    y1 = y2 = gameState.winInfo.index * cellH + cellH/2;
                    x1 = 0; x2 = winWidth;
                    break;
                case 1: // vertical win
                    x1 = x2 = gameState.winInfo.index * cellW + cellW/2;
                    y1 = 0; y2 = winHeight;
                    break;
                case 2: // main diagonal win
                    x1 = 0; y1 = 0; x2 = winWidth; y2 = winHeight;
                    break;
                case 3: // additional diagonal win
                    x1 = winWidth; y1 = 0; x2 = 0; y2 = winHeight;
                    break;
            }
            // drawing Winning line(green)
            thickLineRGBA(renderer, x1, y1, x2, y2, 8, 0, 170, 0, 255);

            // drawing semi-transparent overlay
            SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 128);
            SDL_Rect overlay = {0, 0, winWidth, winHeight};
            SDL_RenderFillRect(renderer, &overlay);
            SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_NONE);

            // drawing PlayAgainButton
            gameState.playAgainButton.draw(renderer);
        }

        SDL_RenderPresent(renderer);
        SDL_Delay(16);
    }
}