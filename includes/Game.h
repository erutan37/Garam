//
// Created by Erutan on 14/07/2017.
//

#ifndef GAME_H
#define GAME_H


#include <memory>
#include "Grid.h"


class Game {

protected:
    std::unique_ptr<Grid> grid;

public:
    Game(Grid * g);

    Grid & getGrid() const;

    void changeSelectedCase(DIRECTION d);

    virtual void changeContentSelectedCase(int content)=0;

    virtual void reduction()=0;

    virtual void result()=0;

    void reset();



};


#endif //JEUFOURMI_GAME_H
