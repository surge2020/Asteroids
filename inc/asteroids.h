#ifndef ASTEROIDS
#define ASTEROIDS

#include <vector>
#include <SDL2/SDL.h>
#include "asteroid.h"

class Asteroids {
public:
    Asteroids(SDL_Renderer* renderer);
    std::vector<Asteroid> asteroids;
    void reset();
    void generate();
    void update();
    void render();
private:
    SDL_Renderer* renderer;
};

#endif