#include "asteroid.h"

Asteroid::Asteroid(SDL_Renderer* renderer, int y)
{
    this-> renderer = renderer;
    asteroidRect = {640, y, 50, 50};
    broken = false;
    surface = IMG_Load("res/asteroid.png");
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
}

bool Asteroid::getBroken()
{
    return broken;
}

void Asteroid::setBroken(bool b)
{
    broken = b;
}

SDL_Rect Asteroid::getRect()
{
    return asteroidRect;
}

void Asteroid::update()
{
    asteroidRect.x -= 1;
}

void Asteroid::render()
{
    if (broken == false) {
        SDL_RenderCopy(renderer, texture, NULL, &asteroidRect);
    }  
}