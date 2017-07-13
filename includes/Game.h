//
// Created by Erutan on 17/04/2016.
//

#ifndef JEUFOURMI_GAME_H
#define JEUFOURMI_GAME_H


#include <vector>
#include "Grid.h"

class Game
{
    Grid grid;
    array<int,24> strategicCases;

    void completeGap();



public:
    Game();

    void changeSelectedCase(DIRECTION d);
    void changeContentSelectedCase(int content);

    void reduction();

    void result();

    void reset();

    const Grid & getGrid() const;
};


#endif //JEUFOURMI_GAME_H
