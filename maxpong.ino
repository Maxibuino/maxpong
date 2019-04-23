
#include <Gamebuino-Meta.h>
#include "src/controllers/GameEngine.h"

// ---------------------------------------------------------
// Game engine initialization
// ---------------------------------------------------------

GameEngine game;

// ---------------------------------------------------------
// META initialization
// ---------------------------------------------------------

void setup() {
    gb.begin();
    gb.setFrameRate(50);
}

// ---------------------------------------------------------
// Main control loop
// ---------------------------------------------------------

void loop() {
    gb.waitForUpdate();
    game.tick();
}