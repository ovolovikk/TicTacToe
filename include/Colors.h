#pragma once
#include <SDL.h>

struct Color {
    Uint8 r, g, b, a;
    Color(Uint8 red, Uint8 green, Uint8 blue, Uint8 alpha = 255)
        : r(red), g(green), b(blue), a(alpha) {}
};