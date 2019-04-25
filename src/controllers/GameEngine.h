#ifndef MAXPONG_GAME_ENGINE
#define MAXPONG_GAME_ENGINE

#include "../models/Paddle.h"
#include "../models/Ball.h"
#include "UserController.h"

class GameEngine
{
    private:
    
        //prédéfinir les modes de jeu
        static const uint8_t MODE_START;
        static const uint8_t MODE_PLAY;
        
        uint8_t mode;
        
        Paddle* player;
        Ball* ball;
        UserController* controller;

        void attachBallTopPlayer();
        void throwBall();
        void HandleScreenBounds();
        void keepBallWithinScreen();
        void keepPlayerWithinScreen();
        void Draw();

    public:
    
        GameEngine();
        ~GameEngine();

        void start();
        void tick();
};

#endif