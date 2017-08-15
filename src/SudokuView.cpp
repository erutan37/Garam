//
// Created by Erutan on 11/08/2017.
//
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics.hpp>
#include "SudokuView.h"

void SudokuView::display()
{
    window.clear(sf::Color(176, 242, 182));


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


    sf::Text textOperator;
    textOperator.setFont(font);
    textOperator.setCharacterSize(50);
    textOperator.setFillColor(sf::Color::Black);

    for(int y=0;y<game->getGrid().getRows();y++)
    {
        numberCase.setPosition(250, numberCase.getPosition().y + MENU_CASE_LENGTH);

        for (int x = 0; x < game->getGrid().getColumns(); ++x)
        {

            numberCase.setPosition(numberCase.getPosition().x + MENU_CASE_LENGTH, numberCase.getPosition().y);
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
    sf::RectangleShape horizontalLine(sf::Vector2f(9*MENU_CASE_LENGTH,6));
    sf::RectangleShape verticalLine(sf::Vector2f(6,9*MENU_CASE_LENGTH));
    horizontalLine.setPosition(250+MENU_CASE_LENGTH,20+MENU_CASE_LENGTH-3);
    verticalLine.setPosition(250+MENU_CASE_LENGTH-3,20+MENU_CASE_LENGTH);
    horizontalLine.setFillColor(sf::Color::Black);
    verticalLine.setFillColor(sf::Color::Black);

    for (int i = 0; i < 4; ++i)
    {
        window.draw(horizontalLine);
        window.draw(verticalLine);
        horizontalLine.setPosition(horizontalLine.getPosition().x,
                                   horizontalLine.getPosition().y+3*MENU_CASE_LENGTH);
        verticalLine.setPosition(verticalLine.getPosition().x+3*MENU_CASE_LENGTH,
                                 verticalLine.getPosition().y);

    }



    window.display();

}

SudokuView::SudokuView() : View::View()
{}
