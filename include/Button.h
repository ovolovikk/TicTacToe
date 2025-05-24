#pragma once

#include <SDL2/SDL.h>
#include "Colors.h"

class Button
{
public:
    Button(int x, int y, int w, int h, const Color &bgColor, const Color &borderColor);
    bool isMouseInside(int mouseX, int mouseY) const;
    bool handleEvent(const SDL_Event &e) const;
    void draw(SDL_Renderer * renderer) const;
private:
    SDL_Rect rect;
    Color backgroundColor;
    Color borderColor;
};