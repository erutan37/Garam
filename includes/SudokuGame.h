//
// Created by Erutan on 11/08/2017.
//

#ifndef JEUFOURMI_SUDOKUGAME_H
#define JEUFOURMI_SUDOKUGAME_H


#include "Game.h"

class SudokuGame : public Game
{
public:
    SudokuGame();

    void reduction() override;

    void result() override;

};


#endif //JEUFOURMI_SUDOKUGAME_H
