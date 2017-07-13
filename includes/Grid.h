//
// Created by Erutan on 16/04/2016.
//

#ifndef TESTSFML_GRILLE_H
#define TESTSFML_GRILLE_H

using namespace std;

#include <SFML/Graphics/Color.hpp>
#include <array>


#define PLUS  10
#define MINUS 11
#define TIME  12

enum DIRECTION
{
    UP, DOWN, LEFT, RIGHT
};

class Grid : public array<int,44>
{
public:
    Grid();

    void changeSelectedCase(DIRECTION d);
    void changeContentSelectedCase(int content);

    const array<int, 2> &getSelectedCase() const;

    const array<int, 20> &getOp() const;

    void reset();

private:
    array<int,20> op;
    array<int,2> selectedCase;
};


#endif //TESTSFML_GRILLE_H
