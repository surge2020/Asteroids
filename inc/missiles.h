#ifndef MISSILES
#define MISSILES

#include <vector>
#include <SDL2/SDL.h>
#include <player.h>
#include "missile.h"

class Missiles {
public:
    Missiles(SDL_Renderer* renderer, Player* player);
    std::vector<Missile> missiles;
    void reset();
    void shoot();
    void update();
    void render();
private:
    SDL_Renderer* renderer;
    Player* player;   
};

#endif