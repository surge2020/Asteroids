#ifndef COLLISION
#define COLLISION

#include <SDL2/SDL.h>
#include "menu.h"
#include "player.h"
#include "missile.h"
#include "missiles.h"
#include "asteroid.h"
#include "asteroids.h"

class Collision {
public:
    Collision(Menu* menu, Player* player, Missiles* missiles, Asteroids* asteroids);
    void update();
    void playerWindow();
    void missileAsteroid();
    void asteroidWindow();
private:
    Menu* menu;
    Player* player;
    Missiles* missiles;
    SDL_Rect playerRect;
    Asteroids* asteroids;
};

#endif