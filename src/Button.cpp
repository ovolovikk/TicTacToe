#include "Button.h"

Button::Button(int x, int y, int w, int h, const Color &bgColor, const Color &borderColor)
    : backgroundColor(bgColor), borderColor(borderColor)
{
    rect.x = x;
    rect.y = y;
    rect.w = w;
    rect.h = h;
}

bool Button::isMouseInside(int mouseX, int mouseY) const
{
    return (mouseX >= rect.x && mouseX <= rect.x + rect.w &&
            mouseY >= rect.y && mouseY <= rect.y + rect.h);
}

bool Button::handleEvent(const SDL_Event &e) const
{
    if(e.type == SDL_MOUSEBUTTONDOWN)
    {
        int mouseX = e.button.x;
        int mouseY = e.button.y;
        return isMouseInside(mouseX, mouseY);
    }
    return false;
}

void Button::draw(SDL_Renderer* renderer) const
{
    SDL_SetRenderDrawColor(renderer, backgroundColor.r, backgroundColor.g, backgroundColor.b, backgroundColor.a);
    SDL_RenderFillRect(renderer, &rect);
    
    SDL_SetRenderDrawColor(renderer, borderColor.r, borderColor.g, borderColor.b, borderColor.a);
    SDL_RenderDrawRect(renderer, &rect);
}