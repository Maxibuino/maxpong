#ifndef MAXPONG_USER_CONTROLLER
#define MAXPONG_USER_CONTROLLER

#include "../models/Paddle.h"

class MAXPONG_USER_CONTROLLER
{
    private
        Paddle* player;

    public
        UserController(Paddle* player);
        ~UserController();

        void tick();
};

#endif