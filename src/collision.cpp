#include "collision.h"

Collision::Collision(Menu* menu, Player* player, Missiles* missiles, Asteroids* asteroids)
{
    this->menu = menu;
    this->player = player;
    this->missiles = missiles;
    this->asteroids = asteroids;
}

void Collision::update()
{
    playerRect = player->getRect();
}

void Collision::playerWindow()
{
    // Top window
    if (playerRect.y <= 0) {
        player->setUp(false);
    }
    // Bottom window
    else if (playerRect.y >= 430) {
        player->setDown(false);
    }
}

void Collision::missileAsteroid()
{
    for (Missile &missile : missiles->missiles) {
        for (Asteroid &asteroid : asteroids->asteroids) {
            if (!missile.getBroken() && !asteroid.getBroken()) {
                SDL_Rect missileRect = missile.getRect();
                SDL_Rect asteroidRect = asteroid.getRect();
                if (SDL_HasIntersection(&missileRect, &asteroidRect)) {
                missile.setBroken(true);
                asteroid.setBroken(true);
                }
            }            
        }
    }
}

void Collision::asteroidWindow()
{
    for (Asteroid &asteroid : asteroids->asteroids) {
        SDL_Rect asteroidRect = asteroid.getRect();
        if (!asteroid.getBroken() && asteroidRect.x <= 0) {
            player->reset();
            missiles->reset();
            asteroids->reset();
            menu->setMenuStatus(true);
            menu->setMenu(1);
        }
    }
}