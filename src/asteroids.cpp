#include "asteroids.h"

Asteroids::Asteroids(SDL_Renderer* renderer)
{
    this->renderer = renderer;
}

void Asteroids::reset()
{
    asteroids.clear();
}

void Asteroids::generate()
{
    int number = rand() % 100;
    if (number == 0) {
        bool collision = false;
        int asteroidY = rand() % 430;
        Asteroid asteroidTemp(renderer, asteroidY);
        for (Asteroid &asteroid : asteroids) {
            SDL_Rect asteroidRect = asteroid.getRect();
            SDL_Rect secondRect = asteroidTemp.getRect();
            if (SDL_HasIntersection(
                &asteroidRect, 
                &secondRect)) {
                collision = true;
                break;
            }
        }
        if (collision == false) {
            asteroids.push_back(asteroidTemp);
        }      
    }
}

void Asteroids::update()
{
    for (Asteroid &asteroid : asteroids) {
        asteroid.update();
    }
}

void Asteroids::render()
{
    for (Asteroid &asteroid : asteroids) {
        asteroid.render();
    }
}