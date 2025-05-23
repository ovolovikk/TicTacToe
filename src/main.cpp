#include "Board.h"
#include "Player.h"
#include "SDLWindow.h"

int main() {
    SDLWindow window;
    if (window.init("Tic Tac Toe", 800, 600))
    {
        window.run();
    }
    return 0;
}