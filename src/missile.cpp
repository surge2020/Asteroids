#include "missile.h"

void Missile::initialize(SDL_Renderer* renderer, SDL_Rect playerRect)
{
    this->renderer = renderer;
    this->playerRect = playerRect;
    missileRect = {50, playerRect.y + 15, 20, 20};
    broken = false;
    surface = IMG_Load("res/missile.png");
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
}

bool Missile::getBroken()
{
    return broken;
}

void Missile::setBroken(bool b)
{
    broken = b;
}

SDL_Rect Missile::getRect()
{
    return missileRect;
}

void Missile::update()
{  
    missileRect.x += 3;
}

void Missile::render()
{
    if (broken == false) {
        SDL_RenderCopy(renderer, texture, NULL, &missileRect);
    }  
}