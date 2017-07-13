//
// Created by Erutan on 17/04/2016.
//

#include <SFML/Graphics/Text.hpp>
#include "View.h"

#define DEFAULT_HEIGHT 1200
#define DEFAULT_LENGTH 1500
#define MENU_LENGTH DEFAULT_LENGTH*0.5*0.75

#define MENU_CASE_LENGTH MENU_LENGTH*0.2
#define CASE_OPERATOR MENU_CASE_LENGTH/3


View::View(Game *g) : game(g), window(sf::VideoMode(DEFAULT_LENGTH+MENU_LENGTH,DEFAULT_HEIGHT), "Garam")
{
    if (!font.loadFromFile(RESOURCES_PATH "Herculanum.ttf"))
        exit(EXIT_FAILURE);

}

void View::display() {

    window.clear(sf::Color(176, 242, 182));
    displayMenu();
    displayGrid();


    window.display();
}

void View::displayMenu()  {
    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(100); // exprimée en pixels, pas en points !

// choix de la couleur du texte
    text.setFillColor(sf::Color::Black);


    sf::RectangleShape hLine(sf::Vector2f(3,DEFAULT_HEIGHT));
    hLine.setPosition(DEFAULT_LENGTH,0);
    hLine.setFillColor(sf::Color::Black);
    window.draw(hLine);

    sf::RectangleShape numberCase(sf::Vector2f(MENU_CASE_LENGTH-3,MENU_CASE_LENGTH-3));
    numberCase.setFillColor(sf::Color::White);
    numberCase.setOutlineThickness(3);
    numberCase.setOutlineColor(sf::Color::Black);

    numberCase.setPosition(MENU_CASE_LENGTH,DEFAULT_HEIGHT*0.05);
    int nb =1;
    for (int i = 0; i < 3; ++i){
        numberCase.setPosition(DEFAULT_LENGTH,numberCase.getPosition().y + MENU_CASE_LENGTH);
        for (int j = 0; j < 3; ++j)
        {
            numberCase.setPosition(numberCase.getPosition().x + MENU_CASE_LENGTH,
                                   numberCase.getPosition().y);
            window.draw(numberCase);
            text.setString(std::to_string(nb));
            text.setPosition(numberCase.getPosition().x + MENU_CASE_LENGTH*0.25,
                             numberCase.getPosition().y-MENU_CASE_LENGTH*0.1);
            window.draw(text);
            nb++;
        }

    }
    numberCase.setPosition(DEFAULT_LENGTH+2*MENU_CASE_LENGTH,numberCase.getPosition().y + MENU_CASE_LENGTH);
    window.draw(numberCase);
    text.setString("0");
    text.setPosition(numberCase.getPosition().x + MENU_CASE_LENGTH*0.25,
                     numberCase.getPosition().y-MENU_CASE_LENGTH*0.1);
    window.draw(text);

    numberCase.setFillColor(sf::Color(250, 150, 100));
    numberCase.setPosition(DEFAULT_LENGTH,numberCase.getPosition().y + 1.5*MENU_CASE_LENGTH);
    for (int j = 0; j < 3; ++j)
    {
        numberCase.setPosition(numberCase.getPosition().x + MENU_CASE_LENGTH,
                               numberCase.getPosition().y);
        window.draw(numberCase);
        if(j==0) text.setString("+");
        if(j==1) text.setString("-");
        if(j==2) text.setString("x");
        text.setPosition(numberCase.getPosition().x + MENU_CASE_LENGTH*0.25,
                         numberCase.getPosition().y-MENU_CASE_LENGTH*0.1);
        window.draw(text);
    }


}



sf::RenderWindow *View::getWindow() {
    return &window;
}

void View::displayGrid() {

    sf::RectangleShape numberCase(sf::Vector2f(MENU_CASE_LENGTH-3,MENU_CASE_LENGTH-3));
    numberCase.setFillColor(sf::Color::White);
    numberCase.setOutlineThickness(3);
    numberCase.setOutlineColor(sf::Color::Black);

    numberCase.setPosition(250,
                           20);
    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(100); // exprimée en pixels, pas en points !

// choix de la couleur du texte
    text.setFillColor(sf::Color::Black);
    int nbCase=0;
    for (int i = 0; i < 9; ++i)
    {
        numberCase.setPosition(250, numberCase.getPosition().y + MENU_CASE_LENGTH);
        for (int j = 0; j < 7; ++j) {
            numberCase.setPosition(numberCase.getPosition().x + MENU_CASE_LENGTH,
                                   numberCase.getPosition().y);
            if (j == 3 && (i != 1 && i != 6)) continue;
            if ((j==1 || j== 5) && (i==1 || i==2 || i== 6 || i==7)) continue;
            if(i == 4 &&  (j != 1 && j != 5)) continue;

            window.draw(numberCase);
            nbCase++;

            if(game->getGrid().getSelectedCase()[0] == 0 && game->getGrid().getSelectedCase()[1] == nbCase)
            {
                numberCase.setFillColor(sf::Color::Blue);
                window.draw(numberCase);
                numberCase.setFillColor(sf::Color::White);
            }


            if(game->getGrid()[(nbCase-1)] != 100)
            {
                text.setString(std::to_string(game->getGrid()[(nbCase-1)]));
                text.setPosition(numberCase.getPosition().x + MENU_CASE_LENGTH*0.25,
                                 numberCase.getPosition().y-MENU_CASE_LENGTH*0.1);
                window.draw(text);
            }
        }
    }

    sf::RectangleShape operatorCase(sf::Vector2f(CASE_OPERATOR-3,CASE_OPERATOR-3));
    operatorCase.setFillColor(sf::Color(250, 150, 100));
    operatorCase.setOutlineThickness(3);
    operatorCase.setOutlineColor(sf::Color::Black);


    text.setCharacterSize(50);


    // CASE 1
    operatorCase.setPosition(250 + 1.5*MENU_CASE_LENGTH - (CASE_OPERATOR/2),
                             20 +1.5*MENU_CASE_LENGTH+  CASE_OPERATOR);
    if(game->getGrid().getSelectedCase()[0] == 1 && game->getGrid().getSelectedCase()[1] == 1)
    {
        operatorCase.setFillColor(sf::Color::Blue);
        window.draw(operatorCase);
        operatorCase.setFillColor(sf::Color(250, 150, 100));
    }
    else window.draw(operatorCase);
    if(game->getGrid().getOp().at(0) != 100)
    {
        switch (game->getGrid().getOp().at(0))
        {
            case PLUS: text.setString("+"); break;
            case MINUS: text.setString("-"); break;
            case TIME: text.setString("x"); break;
        }
        text.setPosition(operatorCase.getPosition().x + CASE_OPERATOR*0.1,
                         operatorCase.getPosition().y-CASE_OPERATOR*0.35);
        window.draw(text);
    }


    //CASE 2
    operatorCase.setPosition(250 + 2*MENU_CASE_LENGTH - (CASE_OPERATOR/2),
                           20 +MENU_CASE_LENGTH+  CASE_OPERATOR);
    if(game->getGrid().getSelectedCase()[0] == 1 && game->getGrid().getSelectedCase()[1] == 2)
    {
        operatorCase.setFillColor(sf::Color::Blue);
        window.draw(operatorCase);
        operatorCase.setFillColor(sf::Color(250, 150, 100));
    }
    else window.draw(operatorCase);
    if(game->getGrid().getOp().at(1) != 100)
    {
        switch (game->getGrid().getOp().at(1))
        {
            case PLUS: text.setString("+"); break;
            case MINUS: text.setString("-"); break;
            case TIME: text.setString("x"); break;
        }
        text.setPosition(operatorCase.getPosition().x + CASE_OPERATOR*0.1,
                         operatorCase.getPosition().y-CASE_OPERATOR*0.35);
        window.draw(text);
    }

    //CASE 3
    operatorCase.setPosition(250 + 3.5*MENU_CASE_LENGTH - (CASE_OPERATOR/2),
                             20 +1.5*MENU_CASE_LENGTH+  CASE_OPERATOR);
    if(game->getGrid().getSelectedCase()[0] == 1 && game->getGrid().getSelectedCase()[1] == 3)
    {
        operatorCase.setFillColor(sf::Color::Blue);
        window.draw(operatorCase);
        operatorCase.setFillColor(sf::Color(250, 150, 100));
    }
    else window.draw(operatorCase);
    if(game->getGrid().getOp().at(2) != 100)
    {
        switch (game->getGrid().getOp().at(2))
        {
            case PLUS: text.setString("+"); break;
            case MINUS: text.setString("-"); break;
            case TIME: text.setString("x"); break;
        }
        text.setPosition(operatorCase.getPosition().x + CASE_OPERATOR*0.1,
                         operatorCase.getPosition().y-CASE_OPERATOR*0.35);
        window.draw(text);
    }

    //CASE 4
    operatorCase.setPosition(250 + 2*MENU_CASE_LENGTH - (CASE_OPERATOR/2),
                             20 +4*MENU_CASE_LENGTH+  CASE_OPERATOR);
    if(game->getGrid().getSelectedCase()[0] == 1 && game->getGrid().getSelectedCase()[1] == 4)
    {
        operatorCase.setFillColor(sf::Color::Blue);
        window.draw(operatorCase);
        operatorCase.setFillColor(sf::Color(250, 150, 100));
    }
    else window.draw(operatorCase);
    if(game->getGrid().getOp().at(3) != 100)
    {
        switch (game->getGrid().getOp().at(3))
        {
            case PLUS: text.setString("+"); break;
            case MINUS: text.setString("-"); break;
            case TIME: text.setString("x"); break;
        }
        text.setPosition(operatorCase.getPosition().x + CASE_OPERATOR*0.1,
                         operatorCase.getPosition().y-CASE_OPERATOR*0.35);
        window.draw(text);
    }

    // CASE 5
    operatorCase.setPosition(250 + 4*MENU_CASE_LENGTH - (CASE_OPERATOR/2),
                             20 +2*MENU_CASE_LENGTH+  CASE_OPERATOR);
    if(game->getGrid().getSelectedCase()[0] == 1 && game->getGrid().getSelectedCase()[1] == 5)
    {
        operatorCase.setFillColor(sf::Color::Blue);
        window.draw(operatorCase);
        operatorCase.setFillColor(sf::Color(250, 150, 100));
    }
    else window.draw(operatorCase);
    if(game->getGrid().getOp().at(4) != 100)
    {
        switch (game->getGrid().getOp().at(4))
        {
            case PLUS: text.setString("+"); break;
            case MINUS: text.setString("-"); break;
            case TIME: text.setString("x"); break;
        }
        text.setPosition(operatorCase.getPosition().x + CASE_OPERATOR*0.1,
                         operatorCase.getPosition().y-CASE_OPERATOR*0.35);
        window.draw(text);
    }

    // CASE 6
    operatorCase.setPosition(250 + 5.5*MENU_CASE_LENGTH - (CASE_OPERATOR/2),
                             20 +1.5*MENU_CASE_LENGTH+  CASE_OPERATOR);
    if(game->getGrid().getSelectedCase()[0] == 1 && game->getGrid().getSelectedCase()[1] == 6)
    {
        operatorCase.setFillColor(sf::Color::Blue);
        window.draw(operatorCase);
        operatorCase.setFillColor(sf::Color(250, 150, 100));
    }
    else window.draw(operatorCase);
    if(game->getGrid().getOp().at(5) != 100)
    {
        switch (game->getGrid().getOp().at(5))
        {
            case PLUS: text.setString("+"); break;
            case MINUS: text.setString("-"); break;
            case TIME: text.setString("x"); break;
        }
        text.setPosition(operatorCase.getPosition().x + CASE_OPERATOR*0.1,
                         operatorCase.getPosition().y-CASE_OPERATOR*0.35);
        window.draw(text);
    }

    //CASE 7
    operatorCase.setPosition(250 + 6*MENU_CASE_LENGTH - (CASE_OPERATOR/2),
                             20 +MENU_CASE_LENGTH+  CASE_OPERATOR);
    if(game->getGrid().getSelectedCase()[0] == 1 && game->getGrid().getSelectedCase()[1] == 7)
    {
        operatorCase.setFillColor(sf::Color::Blue);
        window.draw(operatorCase);
        operatorCase.setFillColor(sf::Color(250, 150, 100));
    }
    else window.draw(operatorCase);
    if(game->getGrid().getOp().at(6) != 100)
    {
        switch (game->getGrid().getOp().at(6))
        {
            case PLUS: text.setString("+"); break;
            case MINUS: text.setString("-"); break;
            case TIME: text.setString("x"); break;
        }
        text.setPosition(operatorCase.getPosition().x + CASE_OPERATOR*0.1,
                         operatorCase.getPosition().y-CASE_OPERATOR*0.35);
        window.draw(text);
    }
    //CASE 8
    operatorCase.setPosition(250 + 7.5*MENU_CASE_LENGTH - (CASE_OPERATOR/2),
                             20 +1.5*MENU_CASE_LENGTH+  CASE_OPERATOR);
    if(game->getGrid().getSelectedCase()[0] == 1 && game->getGrid().getSelectedCase()[1] == 8)
    {
        operatorCase.setFillColor(sf::Color::Blue);
        window.draw(operatorCase);
        operatorCase.setFillColor(sf::Color(250, 150, 100));
    }
    else window.draw(operatorCase);
    if(game->getGrid().getOp().at(7) != 100)
    {
        switch (game->getGrid().getOp().at(7))
        {
            case PLUS: text.setString("+"); break;
            case MINUS: text.setString("-"); break;
            case TIME: text.setString("x"); break;
        }
        text.setPosition(operatorCase.getPosition().x + CASE_OPERATOR*0.1,
                         operatorCase.getPosition().y-CASE_OPERATOR*0.35);
        window.draw(text);
    }

    //CASE 9
    operatorCase.setPosition(250 + 6*MENU_CASE_LENGTH - (CASE_OPERATOR/2),
                             20 +4*MENU_CASE_LENGTH+  CASE_OPERATOR);
    if(game->getGrid().getSelectedCase()[0] == 1 && game->getGrid().getSelectedCase()[1] == 9)
    {
        operatorCase.setFillColor(sf::Color::Blue);
        window.draw(operatorCase);
        operatorCase.setFillColor(sf::Color(250, 150, 100));
    }
    else window.draw(operatorCase);
    if(game->getGrid().getOp().at(8) != 100)
    {
        switch (game->getGrid().getOp().at(8))
        {
            case PLUS: text.setString("+"); break;
            case MINUS: text.setString("-"); break;
            case TIME: text.setString("x"); break;
        }
        text.setPosition(operatorCase.getPosition().x + CASE_OPERATOR*0.1,
                         operatorCase.getPosition().y-CASE_OPERATOR*0.35);
        window.draw(text);
    }

    //CASE 10
    operatorCase.setPosition(250 + 2.5*MENU_CASE_LENGTH - (CASE_OPERATOR/2),
                             20 +4.5*MENU_CASE_LENGTH+  CASE_OPERATOR);
    if(game->getGrid().getSelectedCase()[0] == 1 && game->getGrid().getSelectedCase()[1] == 10)
    {
        operatorCase.setFillColor(sf::Color::Blue);
        window.draw(operatorCase);
        operatorCase.setFillColor(sf::Color(250, 150, 100));
    }
    else window.draw(operatorCase);
    if(game->getGrid().getOp().at(9) != 100)
    {
        switch (game->getGrid().getOp().at(9))
        {
            case PLUS: text.setString("+"); break;
            case MINUS: text.setString("-"); break;
            case TIME: text.setString("x"); break;
        }
        text.setPosition(operatorCase.getPosition().x + CASE_OPERATOR*0.1,
                         operatorCase.getPosition().y-CASE_OPERATOR*0.35);
        window.draw(text);
    }

    //CASE 11
    operatorCase.setPosition(250 + 6.5*MENU_CASE_LENGTH - (CASE_OPERATOR/2),
                             20 +4.5*MENU_CASE_LENGTH+  CASE_OPERATOR);
    if(game->getGrid().getSelectedCase()[0] == 1 && game->getGrid().getSelectedCase()[1] == 11)
    {
        operatorCase.setFillColor(sf::Color::Blue);
        window.draw(operatorCase);
        operatorCase.setFillColor(sf::Color(250, 150, 100));
    }
    else window.draw(operatorCase);
    if(game->getGrid().getOp().at(10) != 100)
    {
        switch (game->getGrid().getOp().at(10))
        {
            case PLUS: text.setString("+"); break;
            case MINUS: text.setString("-"); break;
            case TIME: text.setString("x"); break;
        }
        text.setPosition(operatorCase.getPosition().x + CASE_OPERATOR*0.1,
                         operatorCase.getPosition().y-CASE_OPERATOR*0.35);
        window.draw(text);
    }


    // CASE 12
    operatorCase.setPosition(250 + 1.5*MENU_CASE_LENGTH - (CASE_OPERATOR/2),
                             20 +6.5*MENU_CASE_LENGTH+  CASE_OPERATOR);
    if(game->getGrid().getSelectedCase()[0] == 1 && game->getGrid().getSelectedCase()[1] == 12)
    {
        operatorCase.setFillColor(sf::Color::Blue);
        window.draw(operatorCase);
        operatorCase.setFillColor(sf::Color(250, 150, 100));
    }
    else window.draw(operatorCase);
    if(game->getGrid().getOp().at(11) != 100)
    {
        switch (game->getGrid().getOp().at(11))
        {
            case PLUS: text.setString("+"); break;
            case MINUS: text.setString("-"); break;
            case TIME: text.setString("x"); break;
        }
        text.setPosition(operatorCase.getPosition().x + CASE_OPERATOR*0.1,
                         operatorCase.getPosition().y-CASE_OPERATOR*0.35);
        window.draw(text);
    }

    //CASE 13
    operatorCase.setPosition(250 + 2*MENU_CASE_LENGTH - (CASE_OPERATOR/2),
                             20 +6*MENU_CASE_LENGTH+  CASE_OPERATOR);
    if(game->getGrid().getSelectedCase()[0] == 1 && game->getGrid().getSelectedCase()[1] == 13)
    {
        operatorCase.setFillColor(sf::Color::Blue);
        window.draw(operatorCase);
        operatorCase.setFillColor(sf::Color(250, 150, 100));
    }
    else window.draw(operatorCase);
    if(game->getGrid().getOp().at(12) != 100)
    {
        switch (game->getGrid().getOp().at(12))
        {
            case PLUS: text.setString("+"); break;
            case MINUS: text.setString("-"); break;
            case TIME: text.setString("x"); break;
        }
        text.setPosition(operatorCase.getPosition().x + CASE_OPERATOR*0.1,
                         operatorCase.getPosition().y-CASE_OPERATOR*0.35);
        window.draw(text);
    }

    //CASE 14
    operatorCase.setPosition(250 + 3.5*MENU_CASE_LENGTH - (CASE_OPERATOR/2),
                             20 +6.5*MENU_CASE_LENGTH+  CASE_OPERATOR);
    if(game->getGrid().getSelectedCase()[0] == 1 && game->getGrid().getSelectedCase()[1] == 14)
    {
        operatorCase.setFillColor(sf::Color::Blue);
        window.draw(operatorCase);
        operatorCase.setFillColor(sf::Color(250, 150, 100));
    }
    else window.draw(operatorCase);
    if(game->getGrid().getOp().at(13) != 100)
    {
        switch (game->getGrid().getOp().at(13))
        {
            case PLUS: text.setString("+"); break;
            case MINUS: text.setString("-"); break;
            case TIME: text.setString("x"); break;
        }
        text.setPosition(operatorCase.getPosition().x + CASE_OPERATOR*0.1,
                         operatorCase.getPosition().y-CASE_OPERATOR*0.35);
        window.draw(text);
    }

    //CASE 15
    operatorCase.setPosition(250 + 2*MENU_CASE_LENGTH - (CASE_OPERATOR/2),
                             20 +9*MENU_CASE_LENGTH+  CASE_OPERATOR);
    if(game->getGrid().getSelectedCase()[0] == 1 && game->getGrid().getSelectedCase()[1] == 15)
    {
        operatorCase.setFillColor(sf::Color::Blue);
        window.draw(operatorCase);
        operatorCase.setFillColor(sf::Color(250, 150, 100));
    }
    else window.draw(operatorCase);
    if(game->getGrid().getOp().at(14) != 100)
    {
        switch (game->getGrid().getOp().at(14))
        {
            case PLUS: text.setString("+"); break;
            case MINUS: text.setString("-"); break;
            case TIME: text.setString("x"); break;
        }
        text.setPosition(operatorCase.getPosition().x + CASE_OPERATOR*0.1,
                         operatorCase.getPosition().y-CASE_OPERATOR*0.35);
        window.draw(text);
    }

    // CASE 16
    operatorCase.setPosition(250 + 4*MENU_CASE_LENGTH - (CASE_OPERATOR/2),
                             20 +7*MENU_CASE_LENGTH+  CASE_OPERATOR);
    if(game->getGrid().getSelectedCase()[0] == 1 && game->getGrid().getSelectedCase()[1] == 16)
    {
        operatorCase.setFillColor(sf::Color::Blue);
        window.draw(operatorCase);
        operatorCase.setFillColor(sf::Color(250, 150, 100));
    }
    else window.draw(operatorCase);
    if(game->getGrid().getOp().at(15) != 100)
    {
        switch (game->getGrid().getOp().at(15))
        {
            case PLUS: text.setString("+"); break;
            case MINUS: text.setString("-"); break;
            case TIME: text.setString("x"); break;
        }
        text.setPosition(operatorCase.getPosition().x + CASE_OPERATOR*0.1,
                         operatorCase.getPosition().y-CASE_OPERATOR*0.35);
        window.draw(text);
    }

    // CASE 17
    operatorCase.setPosition(250 + 5.5*MENU_CASE_LENGTH - (CASE_OPERATOR/2),
                             20 +6.5*MENU_CASE_LENGTH+  CASE_OPERATOR);
    if(game->getGrid().getSelectedCase()[0] == 1 && game->getGrid().getSelectedCase()[1] == 17)
    {
        operatorCase.setFillColor(sf::Color::Blue);
        window.draw(operatorCase);
        operatorCase.setFillColor(sf::Color(250, 150, 100));
    }
    else window.draw(operatorCase);
    if(game->getGrid().getOp().at(16) != 100)
    {
        switch (game->getGrid().getOp().at(16))
        {
            case PLUS: text.setString("+"); break;
            case MINUS: text.setString("-"); break;
            case TIME: text.setString("x"); break;
        }
        text.setPosition(operatorCase.getPosition().x + CASE_OPERATOR*0.1,
                         operatorCase.getPosition().y-CASE_OPERATOR*0.35);
        window.draw(text);
    }

    //CASE 18
    operatorCase.setPosition(250 + 6*MENU_CASE_LENGTH - (CASE_OPERATOR/2),
                             20 +6*MENU_CASE_LENGTH+  CASE_OPERATOR);
    if(game->getGrid().getSelectedCase()[0] == 1 && game->getGrid().getSelectedCase()[1] == 18)
    {
        operatorCase.setFillColor(sf::Color::Blue);
        window.draw(operatorCase);
        operatorCase.setFillColor(sf::Color(250, 150, 100));
    }
    else window.draw(operatorCase);
    if(game->getGrid().getOp().at(17) != 100)
    {
        switch (game->getGrid().getOp().at(17))
        {
            case PLUS: text.setString("+"); break;
            case MINUS: text.setString("-"); break;
            case TIME: text.setString("x"); break;
        }
        text.setPosition(operatorCase.getPosition().x + CASE_OPERATOR*0.1,
                         operatorCase.getPosition().y-CASE_OPERATOR*0.35);
        window.draw(text);
    }

    //CASE 19
    operatorCase.setPosition(250 + 7.5*MENU_CASE_LENGTH - (CASE_OPERATOR/2),
                             20 +6.5*MENU_CASE_LENGTH+  CASE_OPERATOR);
    if(game->getGrid().getSelectedCase()[0] == 1 && game->getGrid().getSelectedCase()[1] == 19)
    {
        operatorCase.setFillColor(sf::Color::Blue);
        window.draw(operatorCase);
        operatorCase.setFillColor(sf::Color(250, 150, 100));
    }
    else window.draw(operatorCase);
    if(game->getGrid().getOp().at(18) != 100)
    {
        switch (game->getGrid().getOp().at(18))
        {
            case PLUS: text.setString("+"); break;
            case MINUS: text.setString("-"); break;
            case TIME: text.setString("x"); break;
        }
        text.setPosition(operatorCase.getPosition().x + CASE_OPERATOR*0.1,
                         operatorCase.getPosition().y-CASE_OPERATOR*0.35);
        window.draw(text);
    }

    //CASE 20
    operatorCase.setPosition(250 + 6*MENU_CASE_LENGTH - (CASE_OPERATOR/2),
                             20 +9*MENU_CASE_LENGTH+  CASE_OPERATOR);

    if(game->getGrid().getSelectedCase()[0] == 1 && game->getGrid().getSelectedCase()[1] == 20)
    {
        operatorCase.setFillColor(sf::Color::Blue);
        window.draw(operatorCase);
        operatorCase.setFillColor(sf::Color(250, 150, 100));
    }
    else window.draw(operatorCase);
    if(game->getGrid().getOp().at(19) != 100)
    {
        switch (game->getGrid().getOp().at(19))
        {
            case PLUS: text.setString("+"); break;
            case MINUS: text.setString("-"); break;
            case TIME: text.setString("x"); break;
        }
        text.setPosition(operatorCase.getPosition().x + CASE_OPERATOR*0.1,
                         operatorCase.getPosition().y-CASE_OPERATOR*0.35);
        window.draw(text);
    }

}

