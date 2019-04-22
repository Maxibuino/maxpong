#ifndef MAXPONG_PADDLE
#define MAXPONG_PADDLE

#include "DisplayObject.h"

class Paddle : public DisplayObject
{
    public :

    //Constructeur
    Paddle(
        uint_t w,
        uint_t h,
        uint_t x,
        uint_t y,
        uint_t vx = 0,
        uint_t vy = 0,
    );

    //Destructeur
    ~Paddle();

    //Commande de mouvement
    void up();
    void down();
    void stop();
};

#endif