#ifndef POONG_BALL
#define POONG_BALL

#include "DisplayObject.h"

class Ball : public DisplayObject
{
    public:

        // constructeurr
        Ball(
            uint8_t w,
            uint8_t h,
            int8_t  x,
            int8_t  y,
            int8_t  vx = 0,
            int8_t  vy = 0
        );

        // destructeurr
        ~Ball();

        // motion command
        void toss(int8_t vx, int8_t vy);
};

#endif