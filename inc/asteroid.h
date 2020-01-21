#ifndef ASTEROID
#define ASTEROID

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "missiles.h"

class Asteroid {
public:
    Asteroid(SDL_Renderer* renderer, int y);
    bool getBroken();
    void setBroken(bool b);
    SDL_Rect getRect();
    void update();
    void render();
private:
    SDL_Renderer* renderer;
    SDL_Rect asteroidRect;
    bool broken;
    SDL_Surface* surface;
    SDL_Texture* texture;
};

#endif