//
// Created by Erutan on 17/04/2016.
//

#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics.hpp>
#include "GaramView.h"





GaramView::GaramView() : View::View()
{
}

void GaramView::displayMenu()  {
    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(100); // exprimée en pixels, pas en points !

// choix de la couleur du texte
    text.setFillColor(sf::Color::Black);


    sf::RectangleShape hLine(sf::Vector2f(3,DEFAULT_HEIGHT));
    hLine.setPosition(DEFAULT_LENGTH,0);
    hLine.setFillColor(sf::Color::Black);
    window.draw(hLine);

    sf::RectangleShape numberCase(sf::Vector2f((float) (MENU_CASE_LENGTH - 3), MENU_CASE_LENGTH - 3));
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


void GaramView::displayGrid() {

    sf::RectangleShape numberCase(sf::Vector2f(MENU_CASE_LENGTH-3,MENU_CASE_LENGTH-3));
    numberCase.setFillColor(sf::Color::White);
    numberCase.setOutlineThickness(3);
    numberCase.setOutlineColor(sf::Color::Black);

    numberCase.setPosition(250,
                           20);
    sf::Text textNumber;
    textNumber.setFont(font);
    textNumber.setCharacterSize(100);
    textNumber.setFillColor(sf::Color::Black);



    sf::RectangleShape operatorCase(sf::Vector2f(CASE_OPERATOR-3,CASE_OPERATOR-3));
    operatorCase.setFillColor(sf::Color(250, 150, 100));
    operatorCase.setOutlineThickness(3);
    operatorCase.setOutlineColor(sf::Color::Black);

    sf::Text textOperator;
    textOperator.setFont(font);
    textOperator.setCharacterSize(50);
    textOperator.setFillColor(sf::Color::Black);

    for(int y=0;y<game->getGrid().getRows();y++)
    {
        if(y==1 || y==5 ||y==8) continue;

        numberCase.setPosition(250, numberCase.getPosition().y + MENU_CASE_LENGTH);

        for (int x = 0; x < game->getGrid().getColumns(); ++x)
        {
            if(x==1 || x==4 || x==7) continue;

            if(game->getGrid().getContentCase(x,y)==PLUS
               || game->getGrid().getContentCase(x,y)==MINUS
               || game->getGrid().getContentCase(x,y)==TIME)
                continue;

            numberCase.setPosition(numberCase.getPosition().x + MENU_CASE_LENGTH, numberCase.getPosition().y);
            if(game->getGrid().getContentCase(x,y)==BLOCK) continue;

            window.draw(numberCase);
            if (game->getGrid().isThisCaseSelected(x, y))
            {
                numberCase.setFillColor(sf::Color::Blue);
                window.draw(numberCase);
                numberCase.setFillColor(sf::Color::White);
            }
            if (game->getGrid().getContentCase(x, y) != EMPTY)
            {
                textNumber.setString(std::to_string(game->getGrid().getContentCase(x, y)));
                textNumber.setPosition(numberCase.getPosition().x + MENU_CASE_LENGTH * 0.25,
                                     numberCase.getPosition().y - MENU_CASE_LENGTH * 0.1);
                window.draw(textNumber);
            }

        }


    }
    numberCase.setPosition(MENU_CASE_LENGTH-3,MENU_CASE_LENGTH-3);


    for(int y=0;y<game->getGrid().getRows();y++)
    {
        if(y!=1 && y!=5 &&y!=8)
            numberCase.setPosition(250, numberCase.getPosition().y + MENU_CASE_LENGTH);
        else numberCase.setPosition(250,numberCase.getPosition().y);

        for (int x = 0; x < game->getGrid().getColumns(); ++x)
        {
            if(game->getGrid().getContentCase(x,y)==PLUS
               || game->getGrid().getContentCase(x,y)==MINUS
               || game->getGrid().getContentCase(x,y)==TIME )
            {

                if(x==1 || x==4 || x==7)
                    operatorCase.setPosition(numberCase.getPosition().x + 0.8*MENU_CASE_LENGTH,
                                         numberCase.getPosition().y-0.5*MENU_CASE_LENGTH);
                else {
                    operatorCase.setPosition(numberCase.getPosition().x + 1.3 * MENU_CASE_LENGTH,
                                             numberCase.getPosition().y + 0.1* MENU_CASE_LENGTH);
                    if(x==2 && y==5)
                        numberCase.setPosition(numberCase.getPosition().x+MENU_CASE_LENGTH,numberCase.getPosition().y);
                }
                window.draw(operatorCase);
                if (game->getGrid().isThisCaseSelected(x, y)) {
                    operatorCase.setFillColor(sf::Color::Blue);
                    window.draw(operatorCase);
                    operatorCase.setFillColor(sf::Color(250, 150, 100));
                }
                switch (game->getGrid().getContentCase(x,y))
                {
                    case PLUS: textOperator.setString("+"); break;
                    case MINUS: textOperator.setString("-"); break;
                    case TIME: textOperator.setString("x"); break;
                }
                textOperator.setPosition(operatorCase.getPosition().x + CASE_OPERATOR*0.1,
                                         operatorCase.getPosition().y-CASE_OPERATOR*0.35);
                window.draw(textOperator);


            }
            else if((x==1 || x==4 || x==7) && !(y==1 ||y==8)) continue;
            else
                numberCase.setPosition(numberCase.getPosition().x + MENU_CASE_LENGTH, numberCase.getPosition().y);
        }


    }


}

void GaramView::display() {

    window.clear(sf::Color(176, 242, 182));
    displayMenu();
    displayGrid();


    window.display();

}

