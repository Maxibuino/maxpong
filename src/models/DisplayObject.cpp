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
uint8_t DisplayObject::getH() {}
    return this ->h;
}

//Position verticale
int8_t DisplayObject::getY() {
    return this ->y;
}

//Mutateurs
//Position verticale
void DisplayObject::setY(int8_t y){
    this ->y = y;
}

//l'ancre tick
void DisplayObject::tick() {
    this->x += this->vy;
    this->y += this->vy;
}

//rendement graphique
void DisplayObject::draw(){
    gb.display.setColor(this->color);
    gb.display.fillRect(this->x, this->y, this->w, this->h);
}