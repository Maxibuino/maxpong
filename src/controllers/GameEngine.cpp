#include "GameEngine.h"
#include "../global/Constants.h"

// ---------------------------------------------------------
// Initialisation du moteur de jeu
// ---------------------------------------------------------

// les modes de jeu
const uint8_t GameEngine::MODE_START = 0;
const uint8_t GameEngine::MODE_PLAY  = 1;

// constructeur
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

// ---------------------------------------------------------
// Destructeur du mode de jeu
// ---------------------------------------------------------

GameEngine::~GameEngine() {
    delete this->controller;
    delete this->ball;
    delete this->player;
}

// ---------------------------------------------------------
// Game rules management
// ---------------------------------------------------------

void GameEngine::attachBallToPlayer() {
    uint8_t ph = this->player->getH();
    int8_t  py = this->player->getY();
    uint8_t bh = this->ball->getH();
    this->ball->setY(py + ((ph - bh) >> 1));
}

void GameEngine::throwBall() {
    int8_t vx = 1 + random(BALL_H_SPEED);
    int8_t vy = (random(2) ? -1 : 1) * (1 + random(BALL_V_SPEED));
    this->ball->toss(vx, vy);
}

void GameEngine::handleScreenBounds() {
    this->keepPlayerWithinScreen();
    if (this->mode == MODE_PLAY) {
        this->keepBallWithinScreen();
    }
}

void GameEngine::keepBallWithinScreen() {
    uint8_t w  = this->ball->getW();
    uint8_t h  = this->ball->getH();
    int8_t  x  = this->ball->getX();
    int8_t  y  = this->ball->getY();
    int8_t  vx = this->ball->getVx();
    int8_t  vy = this->ball->getVy();

    if (x < 0 || x + w > SCREEN_WIDTH) {
        this->ball->setX(x - vx);
        this->ball->setVx(-vx);
    }

    if (y < 0 || y + h > SCREEN_HEIGHT) {
        this->ball->setY(y - vy);
        this->ball->setVy(-vy);
    }
}

void GameEngine::keepPlayerWithinScreen() {
    uint8_t h = this->player->getH();
    int8_t  y = this->player->getY();

    if (y < 0) {
        this->player->setY(0);
        this->attachBallToPlayer();
    } else if (y + h > SCREEN_HEIGHT) {
        this->player->setY(SCREEN_HEIGHT - h);
        this->attachBallToPlayer();
    }
}

// ---------------------------------------------------------
// Commencer et stopper la partie
// ---------------------------------------------------------

void GameEngine::start() {
    this->throwBall();
    this->mode = MODE_PLAY;
}

// ---------------------------------------------------------
// Runtime control hook
// ---------------------------------------------------------

void GameEngine::tick() {
    this->controller->tick();
    this->player->move();

    switch (this->mode) {
        case MODE_START:
            this->attachBallToPlayer();
            break;
        case MODE_PLAY:
            this->ball->move();
            break;
    }

    this->handleScreenBounds();
    this->draw();
}

// ---------------------------------------------------------
// Rendu graphique
// ---------------------------------------------------------

void GameEngine::draw() {
    gb.display.clear();
    this->player->draw();
    this->ball->draw();
}