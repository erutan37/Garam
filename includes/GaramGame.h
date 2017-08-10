//
// Created by Erutan on 17/04/2016.
//

#ifndef GARAM_GAME_H
#define GARAM_GAME_H


#include <array>
#include "Game.h"

using namespace std;

class GaramGame : public Game
{
    array<Grid::Case,24> strategicCases;
    vector<array<Grid::Case,4>> threeCasesOperations;
    vector<array<Grid::Case,5>> fourCasesOperations;

    void fillGaps();


public:
    GaramGame();

    virtual void changeContentSelectedCase(int content);

    virtual void reduction();

    virtual void result();


};


#endif //JEUFOURMI_GAME_H
