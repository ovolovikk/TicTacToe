#include "SDLWindow.h"
#include "GameController.h"
#include <SDL2_gfxPrimitives.h>
#include <iostream>

SDLWindow::SDLWindow() : window(nullptr), renderer(nullptr), boardTexture(nullptr), isRunning(false)
{
}

SDLWindow::~SDLWindow()
{
    cleanup();
}

bool SDLWindow::init(const char* title, int width, int height)
{
    if(SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        std::cerr << "SDL Init error: " << SDL_GetError() << std::endl;
        return false;
    }
    
    window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                              width, height, SDL_WINDOW_SHOWN);
    if(!window)
    {
        std::cerr << "SDL CreateWindow Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return false;
    }
    
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
    if(!renderer)
    {
        std::cerr << "SDL CreateRenderer Error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return false;
    }
    
    isRunning = true;
    return true;
}

void SDLWindow::run()
{
    int winWidth, winHeight;
    SDL_GetWindowSize(window, &winWidth, &winHeight);

    GameController gameController(winWidth, winHeight);
    gameController.run(renderer);
}

void SDLWindow::cleanup()
{
    if(boardTexture)
    {
        SDL_DestroyTexture(boardTexture);
        boardTexture = nullptr;
    }
    if(renderer)
    {
        SDL_DestroyRenderer(renderer);
        renderer = nullptr;
    }
    if(window)
    {
        SDL_DestroyWindow(window);
        window = nullptr;
    }
    IMG_Quit();
    SDL_Quit();
}