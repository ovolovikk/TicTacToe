#include "UIManager.h"
#include "Button.h"
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>

UIManager::UIManager(SDL_Renderer* ren, int winWidth, int winHeight)
    : renderer(ren), assetManager(ren)
{
}

UIManager::~UIManager()
{
}

void UIManager::drawEndGameOverlay(const GameState& gameState)
{
    int winWidth = gameState.cellWidth * 3;
    int winHeight = gameState.cellHeight * 3;

    // Draw semi-transparent overlay
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 128);
    SDL_Rect overlay = {0, 0, winWidth, winHeight};
    SDL_RenderFillRect(renderer, &overlay);
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_NONE);

    // Draw "Play again" button with our Button class
    // Button already stored in GameState.playAgainButton,
    // possible to draw addititonal UI Elements.
    gameState.playAgainButton.draw(renderer);

}

bool UIManager::handleUIEvent(const SDL_Event &event, GameState &gameState)
{
    if(gameState.gameOver)
    {
        if(gameState.playAgainButton.handleEvent(event))
        {
            int winW = gameState.cellWidth * 3;
            int winH = gameState.cellHeight * 3;
            gameState.reset(winW, winH);
            return true;
        }
    }
    return false;
}