#include "GameEngine.h"
#include "../global/Constants.h"

//Initialisition du moteur de jeu

GameEngine::GameEngine() {
    this->player = new Paddle(
        PADDLE_WIDTH,
        PADDLE_HEIGHT,
        PADDLE_X_OFFSET,
        (SCREEN_HEIGHT - PADDLE_HEIGHT) >> 1
    );

    this->controller = new UserController(player);
}

//Destructeur moteur de jeu

GameEngine::~GameEngine() {
    delete this->controller;
    delete this->player;
}

//Empêche la raquette de sortir de l'écran
void GameEngine::handleScreenBounds(){
    uint8_t h = this->player->getH();
    int8_t y = this->player->getY();
    if (y < 0) this->player->setY(0);
    else if (y + h > SCREEN_HEIGHT) this->player->setY(SCREEN_HEIGHT - h);
}

void GameEngine::tick() {
    this->controller->tick();
    this->player->tick();
    this->HandleScreenBounds();
    this->draw();
}

void GameEngine::draw() {
    gb.display.clear();
    this->player->draw();
}