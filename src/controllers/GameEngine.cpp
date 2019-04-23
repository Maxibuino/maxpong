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

