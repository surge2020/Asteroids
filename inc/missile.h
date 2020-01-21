#ifndef MISSILE
#define MISSILE

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Missile {
public:
    void initialize(SDL_Renderer* renderer, SDL_Rect playerRect);
    bool getBroken();
    void setBroken(bool b);
    SDL_Rect getRect();
    void update();
    void render();
private:
    SDL_Renderer* renderer;
    SDL_Rect playerRect;
    SDL_Rect missileRect;
    bool broken;
    SDL_Surface* surface;
    SDL_Texture* texture;
};

#endif