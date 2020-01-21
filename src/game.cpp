#include "game.h"

Game::Game()
{
    window = SDL_CreateWindow(
        "Asteroids",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        640, 480, 0);
    renderer = SDL_CreateRenderer(window, -1, 0);
    running = true;

    surface = IMG_Load("res/background.png");
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    menu = new Menu(renderer);
    player = new Player(renderer);
    missiles = new Missiles(renderer, player);
    asteroids = new Asteroids(renderer);
    collision = new Collision(menu, player, missiles, asteroids);
}

bool Game::getRunning()
{
    return running;
}

void Game::input()
{
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_QUIT:
            running = false;
            break;
        case SDL_KEYDOWN:
            keyDown(&event);
            break;
        case SDL_KEYUP:
            keyUp(&event);
            break;
        default:
            break;
        }
    }
}

void Game::keyDown(SDL_Event* event)
{
    switch (event->key.keysym.sym) {
    case SDLK_UP:
        if (menu->getMenuStatus() && menu->getMenu() == 2) {
            menu->setMenu(1);
        }
        if (menu->getMenuStatus() == false) {
            player->setUp(true);
        }      
        break;
    case SDLK_DOWN:
        if (menu->getMenuStatus() && menu->getMenu() == 1) {
            menu->setMenu(2);
        }
        if (menu->getMenuStatus() == false) {
            player->setDown(true);
        }    
        break;
    case SDLK_RETURN:
        if (menu->getMenuStatus() && menu->getMenu() == 1) {
            menu->setMenuStatus(false);
        }
        if (menu->getMenuStatus() && menu->getMenu() == 2) {
            running = false;
        }
    default:
        break;
    }
}

void Game::keyUp(SDL_Event* event)
{
    switch (event->key.keysym.sym) {
    case SDLK_UP:
        player->setUp(false);
        break;
    case SDLK_DOWN:
        player->setDown(false);
        break;
    case SDLK_SPACE:
        missiles->shoot();
        break;
    default:
        break;
    }
}

void Game::logic()
{
    if (!menu->getMenuStatus()) {
        collision->playerWindow();
        collision->missileAsteroid();
        collision->asteroidWindow();
        asteroids->generate();
    }  
}

void Game::update()
{
    if (!menu->getMenuStatus()) {
        player->update();
        asteroids->update();
        missiles->update();
        collision->update();
    }
    
}

void Game::render()
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    if (menu->getMenuStatus()) {
        menu->render();
    }
    else {
        player->render();
        missiles->render();
        asteroids->render();
    } 
    SDL_RenderPresent(renderer);
}

void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
}