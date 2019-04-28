#include "Ball.h"
#include "../global/Constants.h"

// ---------------------------------------------------------
// Ball initialization
// ---------------------------------------------------------

Ball::Ball(uint8_t w,
    uint8_t h,
    int8_t  x,
    int8_t  y,
    int8_t  vx,
    int8_t  vy) : DisplayObject(w, h, x, y, vx, vy) {}

// ---------------------------------------------------------
// Ball destruction
// ---------------------------------------------------------

Ball::~Ball() = default;

// ---------------------------------------------------------
// Motion commands
// ---------------------------------------------------------

void Ball::toss(int8_t vx, int8_t vy) {
    this->vx = vx;
    this->vy = vy;
}