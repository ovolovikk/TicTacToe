#pragma once

#include <SDL.h>
#include <SDL_image.h>

class SDLWindow
{
public:
    SDLWindow();
    ~SDLWindow();
    bool init(const char* title, int width, int height);
    void run();
    void cleanup();
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Texture* boardTexture;
    bool isRunning;
};
