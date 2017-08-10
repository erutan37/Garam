//
// Created by Erutan on 14/07/2017.
//

#ifndef VIEW_H
#define VIEW_H


#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Font.hpp>
#include "Game.h"


#define DEFAULT_HEIGHT 1200
#define DEFAULT_LENGTH 1500

#define MENU_LENGTH DEFAULT_LENGTH*0.5*0.75

#define MENU_CASE_LENGTH MENU_LENGTH*0.2
#define CASE_OPERATOR MENU_CASE_LENGTH/3


#define RESOURCES_PATH "../Resources/"

class View {

protected:
    const Game *game;
    sf::RenderWindow window;
    sf::Font font;

public:
    View();

    virtual void display()=0;

    sf::RenderWindow * getWindow();

    void setGame(const Game *game);
};


#endif //JEUFOURMI_VIEW_H
