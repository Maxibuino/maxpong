#include "UserController.h"

UserController::UserController(Paddle* player) : player(player) {}

UserController::~UserController () {
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
}