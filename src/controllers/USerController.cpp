#include "UserController.h"
#include "GameEngine.h"

UserController::UserController(
    GameEngine* game,
    Paddle* player) : game(game), player(player) {}

UserController::~UserController () {
    this->game = NULL;
    this->player = NULL;
}

void UserController::tick() {
    if (gb.buttons.repeat(BUTTON_UP, 0)) {
        this->player->up();
    } else if (gb.buttons.repeat(BUTTON_DOWN, 0)) {
        this->player->down();
    } else if (
        gb.buttons.released(BUTTON_UP) ||
        gb.buttons.released(BUTTON_DOWN)
    ) {
        this->player->stop();
    }

    if (gb.buttons.pressed(BUTTON_A)){
        this->game->start();  
    }
}