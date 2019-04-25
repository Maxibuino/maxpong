#include "GameEngine.h"
#include "../global/Constants.h"

//Initialisition du moteur de jeu

const uint8_t GameEngine::MODE_START = 0;
const uint8_t GameEngine::MODE_PLAY = 1;

GameEngine::GameEngine() {
    this->mode = MODE_START;

    this->player = new Paddle(
        PADDLE_WIDTH,
        PADDLE_HEIGHT,
        PADDLE_X_OFFSET,
        (SCREEN_HEIGHT - PADDLE_HEIGHT) >> 1
    );

    this->ball = new Ball(
        BALL_SIZE,
        BALL_SIZE,
        this->player->getX() + this->player->getW(),
        this->player->getY() + ((this->player->getH() - BALL_SIZE) >> 1)
    );

    this->controller = new UserController(this, player);
}

//Destructeur moteur de jeu

GameEngine::~GameEngine() {
    delete this->controller;
    delete this->ball;
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