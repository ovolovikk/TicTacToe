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

    // Draw "Play again" button
    SDL_Texture* playAgainTex = assetManager.getTexture("assets/play_again_texture.png");
    if (playAgainTex)
    {
        int texW, texH;
        SDL_QueryTexture(playAgainTex, nullptr, nullptr, &texW, &texH);
        // add a scale factor less than 1
        float buttonScale = 0.7f;
        int scaledW = static_cast<int>(texW * buttonScale);
        int scaledH = static_cast<int>(texH * buttonScale);

        // Center the scaled texture
        SDL_Rect playRect;
        playRect.w = scaledW;
        playRect.h = scaledH;
        playRect.x = (winWidth - scaledW) / 2;
        playRect.y = (winHeight - scaledH) / 2;
        SDL_RenderCopy(renderer, playAgainTex, nullptr, &playRect);
    }
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