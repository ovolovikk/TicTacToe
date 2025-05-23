#include "SDLWindow.h"
#include "Board.h"
#include "BoardRenderer.h"
#include "Player.h"
#include "InputHandler.h"
#include <SDL2_gfxPrimitives.h>
#include <iostream>
#include <cmath>

SDLWindow::SDLWindow() : window(nullptr), renderer(nullptr), isRunning(false)
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
        std::cerr << "SDL Init error" << SDL_GetError() << std::endl;
        return false;
    }
    
    window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
                              width, height, SDL_WINDOW_SHOWN);
    if(!window)
    {
        std::cerr << "SDL CreateWindow Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
    }
    
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED
    |                             SDL_RENDERER_PRESENTVSYNC);
    if(!renderer)
    {
        std::cerr << "SDL CreateRenderer Error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return false;
    }

    //getting texture from assets
    boardTexture = IMG_LoadTexture(renderer, "assets/board.png");
    if(!boardTexture)
    {
        std::cerr << "IMG_LoadTexture Error: " << IMG_GetError() << std::endl;
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        IMG_Quit();
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

    Board board;
    BoardRenderer boardRenderer;
    
    Player playerX('X');
    Player playerO('0');

    Player* currentPlayer = &playerX;

    int cellWidth = winWidth / 3;
    int cellHeight = winHeight / 3;


    SDL_Event event;
    while (isRunning)
    {
        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT)
                isRunning = false;
            else
            {
                InputHandler::processEvent(event, cellWidth, cellHeight, board, 
                                           currentPlayer, playerX, playerO);
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
        SDL_RenderClear(renderer);

        boardRenderer.draw(renderer, winWidth, winHeight, board);

        SDL_RenderPresent(renderer);
        SDL_Delay(16);
    }
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
