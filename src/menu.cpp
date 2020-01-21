#include "menu.h"

Menu::Menu(SDL_Renderer* renderer)
{
    this->renderer = renderer;
    menu = 1;
    menuStatus = true;
    surface = IMG_Load("res/menu1.png");
    menuOneTex = SDL_CreateTextureFromSurface(renderer, surface);
    surface = IMG_Load("res/menu2.png");
    menuTwoTex = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
}

bool Menu::getMenuStatus()
{
    return menuStatus;
}

void Menu::setMenuStatus(bool b)
{
    menuStatus = b;
}

int Menu::getMenu()
{
    return menu;
}

void Menu::setMenu(int x)
{
    menu = x;
}

void Menu::render()
{
    if (menu == 1) {
        SDL_RenderCopy(renderer, menuOneTex, NULL, NULL);
    }
    else if (menu == 2) {
        SDL_RenderCopy(renderer, menuTwoTex, NULL, NULL);
    }
}