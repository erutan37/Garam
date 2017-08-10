//
// Created by Erutan on 14/07/2017.
//

#include "View.h"




View::View() : window(sf::VideoMode(DEFAULT_LENGTH+MENU_LENGTH,DEFAULT_HEIGHT), "Garam")
{
    if (!font.loadFromFile(RESOURCES_PATH "Herculanum.ttf"))
        exit(EXIT_FAILURE);

}


sf::RenderWindow *View::getWindow() {
    return &window;
}

void View::setGame(const Game *game) {
    View::game = game;
}


