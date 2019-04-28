#include "Paddle.h"
#include "../global/Constants.h"

// ---------------------------------------------------------
// Paddle initialization
// ---------------------------------------------------------

Paddle::Paddle(
    uint8_t w,
    uint8_t h,
    int8_t  x,
    int8_t  y,
    int8_t  vx,
    int8_t  vy) : DisplayObject(w, h, x, y, vx, vy, LIGHTBLUE) {}

// ---------------------------------------------------------
// Paddle destruction
// ---------------------------------------------------------

Paddle::~Paddle() = default;

// ---------------------------------------------------------
// Motion commands
// ---------------------------------------------------------

void Paddle::up() {
    this->vy = -PADDLE_SPEED;
}

void Paddle::down() {
    this->vy = PADDLE_SPEED;
}

void Paddle::stop() {
    this->vy = 0;
}