//
// Created by Erutan on 17/04/2016.
//

#ifndef JEUFOURMI_VIEW_H
#define JEUFOURMI_VIEW_H


#include <SFML/Window/VideoMode.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Font.hpp>
#include "Game.h"


#define RESOURCES_PATH "../Resources/"

class View {

private:
    const Game *game;
    sf::RenderWindow window;
    sf::Font font;


    void displayMenu();

    void displayGrid();


public:
    View(Game *g);


    sf::RenderWindow * getWindow();

    void display() ;






};



#endif //JEUFOURMI_VIEW_H

