#include "player.h"

Player::Player(SDL_Renderer* renderer)
{
    this->renderer = renderer;
    playerRect = {0, 215, 50, 50};
    up = false;
    down = false;
    surface = IMG_Load("res/player.png");
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
}

void Player::reset()
{
    playerRect = {0, 215, 50, 50};
    up = false;
    down = false;
}

void Player::setUp(bool b)
{
    up = b;
}

void Player::setDown(bool b)
{
    down = b;
}

SDL_Rect Player::getRect()
{
    return playerRect;
}

void Player::update()
{
    if (up) {
        playerRect.y -= 2;
    }
    if (down) {
        playerRect.y += 2;
    }
}

void Player::render()
{
    SDL_RenderCopy(renderer, texture, NULL, &playerRect);
}