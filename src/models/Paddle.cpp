#include "Paddle.h"
#include "../global/Constants.h"

//Initialisation de la raquette

Paddle::paddle(
    uint8_t w,
    uint8_t h,
    int8_t x,
    int8_t y,
    int8_t vx,
    int8_t vy) : DisplayObject(w, h, x, y, vx, vy, LIGHTBLUE) {}

//Destructeur raquette

Paddle::~Paddle() = default;

//Commands de déplacement

void Paddle::up(){
    this->vy = -PADDLE_SPEED;
}

void Paddle::down(){
    this->vy = PADDLE_SPEED;
}

void Paddle::stop(){
    this->vy = 0;
}