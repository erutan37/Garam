//
// Created by Erutan on 14/07/2017.
//

#include "Game.h"

Game::Game(Grid *g) : grid(g) {

}

Grid &Game::getGrid() const {
    return *grid;
}

void Game::changeSelectedCase(DIRECTION d) {
    grid->changeSelectedCase(d);
}

void Game::reset() {
    grid->reset();
}


