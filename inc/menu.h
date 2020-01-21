#ifndef MENU
#define MENU

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Menu {
public:
    Menu(SDL_Renderer* renderer);
    bool getMenuStatus();
    void setMenuStatus(bool b);
    int getMenu();
    void setMenu(int x);
    void render();
private:
    SDL_Renderer* renderer;
    int menu;
    bool menuStatus;
    SDL_Surface* surface;
    SDL_Texture* menuOneTex;
    SDL_Texture* menuTwoTex;
};

#endif