#include "GameController.h"
#include "UIManager.h"
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
    AssetManager assetManager(renderer);
    UIManager uiManager(renderer, winWidth, winHeight);

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

        boardRenderer.draw(renderer, winWidth, winHeight, gameState.board, assetManager);

        // if the game has ended drawing winningLine, overlay and button "PlayAgain"
        if(gameState.gameOver)
        {
            uiManager.drawEndGameOverlay(gameState);
        }

        SDL_RenderPresent(renderer);
        SDL_Delay(16);
    }
}