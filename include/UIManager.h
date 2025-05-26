#pragma once
#include <SDL2/SDL.h>
#include "GameState.h"
#include "AssetManager.h"

class UIManager
{
public:

    UIManager(SDL_Renderer* renderer, int winWidth, int winHeight);
    ~UIManager();

    // processes the overlay for win or draw
    void drawEndGameOverlay(const GameState &gameState);

    bool handleUIEvent(const SDL_Event& event, GameState &gameState);

    // Exposes the AssetManager to load textures if needed.
    AssetManager& getAssetManager() { return assetManager; }

private:
    SDL_Renderer* renderer;
    AssetManager assetManager;
};