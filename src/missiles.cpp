#include "missiles.h"

Missiles::Missiles(SDL_Renderer* renderer, Player* player)
{
    this->renderer = renderer;
    this->player = player;
}

void Missiles::reset()
{
    missiles.clear();
}

void Missiles::shoot()
{  
    Missile missile;
    missile.initialize(renderer, player->getRect());
    missiles.push_back(missile);
}

void Missiles::update()
{
   for (Missile &missile : missiles) {
       missile.update();
   }  
}

void Missiles::render()
{
    for (Missile &missile : missiles) {
        missile.render();
    }  
}