#ifndef MAXPONG_GAME_ENGINE
#define MAXPONG_GAME_ENGINE

#include "../models/Paddle.h"
#include "UserController.h"

class GameEngine
{
    private
        Paddle* player;
        UserController* controller;

        void HandleScreenBounds();
        void Draw();

    public
        GameEngine();
        ~GameEngine();

        void tick();
};

#endif