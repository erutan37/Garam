//
// Created by Erutan on 17/04/2016.
//

#include <SFML/Window/Event.hpp>
#include "Controler.h"

Controler::Controler() : game() , view(&game) {

}


void Controler::loop() {
    sf::Clock clock;
    clock.restart();
    view.display();
    while(view.getWindow()->isOpen())
    {
        sf::Event event;
        while(view.getWindow()->pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                view.getWindow()->close();
            if(event.type == sf::Event::KeyPressed)
            {
                switch (event.key.code)
                {
                    case sf::Keyboard::Up:
                        game.changeSelectedCase(UP);
                        break;
                    case sf::Keyboard::Down:
                        game.changeSelectedCase(DOWN);
                        break;
                    case sf::Keyboard::Left:
                        game.changeSelectedCase(LEFT);
                        break;
                    case sf::Keyboard::Right:
                        game.changeSelectedCase(RIGHT);
                        break;
                    case sf::Keyboard::Num1:
                        game.changeContentSelectedCase(1);
                        break;
                    case sf::Keyboard::Num2:
                        game.changeContentSelectedCase(2);
                        break;
                    case sf::Keyboard::Num3:
                        game.changeContentSelectedCase(3);
                        break;
                    case sf::Keyboard::Num4:
                        game.changeContentSelectedCase(4);
                        break;
                    case sf::Keyboard::Num5:
                        game.changeContentSelectedCase(5);
                        break;
                    case sf::Keyboard::Num6:
                        game.changeContentSelectedCase(6);
                        break;
                    case sf::Keyboard::Num7:
                        game.changeContentSelectedCase(7);
                        break;
                    case sf::Keyboard::Num8:
                        game.changeContentSelectedCase(8);
                        break;
                    case sf::Keyboard::Num9:
                        game.changeContentSelectedCase(9);
                        break;
                    case sf::Keyboard::Num0:
                        game.changeContentSelectedCase(0);
                        break;
                        game.changeContentSelectedCase(100);
                        break;
                    case sf::Keyboard::P :
                        game.changeContentSelectedCase(PLUS);
                        break;
                    case sf::Keyboard::M :
                        game.changeContentSelectedCase(MINUS);
                        break;
                    case sf::Keyboard::O :
                        game.changeContentSelectedCase(TIME);
                        break;
                    case sf::Keyboard::BackSpace :
                        game.changeContentSelectedCase(100);
                        break;
                    case sf::Keyboard::Return :
                        game.reduction();
                        break;
                    case sf::Keyboard::A :
                        game.result();
                        break;
                    case sf::Keyboard::Space:
                        game.reset();
                        break;
                    default:

                        break;
                }
            }
            view.display();
        }


    }
}

