//
// Created by Erutan on 17/04/2016.
//

#ifndef JEUFOURMI_CONTROLER_H
#define JEUFOURMI_CONTROLER_H


#include "View.h"

class Controler {
    View view;
    Game game;


public:
    Controler();


    void loop();
};


#endif //JEUFOURMI_CONTROLER_H
