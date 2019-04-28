#ifndef MAXPONG_USER_CONTROLLER
#define MAXPONG_USER_CONTROLLER


#include "../models/Paddle.h"

class GameEngine;

class UserController
{
    private:
        GameEngine* game;
        Paddle* player;

    public:
        UserController(GameEngine* game,Paddle* player);
        ~UserController();

        void tick();
};

#endif