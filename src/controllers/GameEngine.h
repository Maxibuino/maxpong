#ifndef POONG_GAME_ENGINE
#define POONG_GAME_ENGINE

#include "../models/Paddle.h"
#include "../models/Ball.h"
#include "UserController.h"

class GameEngine
{
    private:

        // predefined game modes
        static const uint8_t MODE_START;
        static const uint8_t MODE_PLAY;

        uint8_t mode;               // game mode

        Paddle* player;             // the player
        Ball* ball;                 // the ball
        UserController* controller; // player controller

        void attachBallToPlayer();     // makes the ball follow the player
        void throwBall();              // throws the ball
        void handleScreenBounds();     // keeps the ball and the player within the screen
        void keepBallWithinScreen();   // keeps the ball within the screen
        void keepPlayerWithinScreen(); // keeps the player within the screen
        void draw();                   // graphic rendering

    public:

        GameEngine();  // constructor
        ~GameEngine(); // destructor

        void start(); // start the game
        void tick();  // runtime control hook
};

#endif