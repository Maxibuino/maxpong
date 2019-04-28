#ifndef POONG_PADDLE
#define POONG_PADDLE

#include "DisplayObject.h"

class Paddle : public DisplayObject
{
    public:

        // contructeur
        Paddle(
            uint8_t w,
            uint8_t h,
            int8_t  x,
            int8_t  y,
            int8_t  vx = 0,
            int8_t  vy = 0
        );

        // destructeur
        ~Paddle();

        // motion commands
        void up();
        void down();
        void stop();
};

#endif