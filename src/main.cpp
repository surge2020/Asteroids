#include "game.h"

int main()
{
    Game game;
    while (game.getRunning()) {
        game.input();
        game.logic();
        game.update();
        game.render();
        SDL_Delay(1000/60);
    }
    game.clean();
    return 0;
}