#ifndef PLAYER
#define PLAYER

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Player {
public:
    Player(SDL_Renderer* renderer);
    void reset();
    void setUp(bool b);
    void setDown(bool b);
    SDL_Rect getRect();
    void update();
    void render();
private:
    SDL_Renderer* renderer;
    SDL_Rect playerRect;
    bool up;
    bool down;
    SDL_Surface* surface;
    SDL_Texture* texture;
};

#endif