#ifndef GAME
#define GAME

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "menu.h"
#include "player.h"
#include "missiles.h"
#include "asteroids.h"
#include "collision.h"

class Game {
public:
    Game();
    bool getRunning();
    void input();
    void keyDown(SDL_Event* event);
    void keyUp(SDL_Event* event);
    void logic();
    void update();
    void render();
    void clean();
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    bool running;
    SDL_Surface* surface;
    SDL_Texture* texture;
    Menu* menu;
    Player* player;
    Missiles* missiles;
    Asteroids* asteroids;
    Collision* collision;
};

#endif