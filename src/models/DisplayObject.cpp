#include "DisplayObject.h"

const Color DisplayObject::DEFAULT_COLOR = WHITE;

//Initialisation de l'Objet

DisplayObject::DisplayObject(
    uint8_t w,
    uint8_t h,
    int8_t x,
    int8_t y,
    int8_t vx,
    int8_t vy,
    Color c) : w(w), h(h), y(y), vx(vx), vy(vy), color(c) {}


// Destructeur

DisplayObject::~DisplayObject() = default;

//Acccesseurs
//Hauteur

// width
uint8_t DisplayObject::getW() {
    return this->w;
}

// height
uint8_t DisplayObject::getH() {
    return this->h;
}

// horizontal position
int8_t DisplayObject::getX() {
    return this->x;
}

// vertical position
int8_t DisplayObject::getY() {
    return this->y;
}

// horizontal velocity
int8_t DisplayObject::getVx() {
    return this->vx;
}

// vertical velocity
int8_t DisplayObject::getVy() {
    return this->vy;
}

// ---------------------------------------------------------
// Mutators
// ---------------------------------------------------------

// horizontal position
void DisplayObject::setX(int8_t x) {
    this->x = x;
}

// vertical position
void DisplayObject::setY(int8_t y) {
    this->y = y;
}

// horizontal velocity
void DisplayObject::setVx(int8_t vx) {
    this->vx = vx;
}

// vertical velocity
void DisplayObject::setVy(int8_t vy) {
    this->vy = vy;
}

// ---------------------------------------------------------
// Motion handling
// ---------------------------------------------------------

void DisplayObject::move() {
    this->x += this->vx;
    this->y += this->vy;
}

// ---------------------------------------------------------
// Graphic rendering
// ---------------------------------------------------------

void DisplayObject::draw() {
    gb.display.setColor(this->color);
    gb.display.fillRect(this->x, this->y, this->w, this->h);
}