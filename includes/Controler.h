//
// Created by Erutan on 17/04/2016.
//

#ifndef CONTROLER_H
#define CONTROLER_H


#include "GaramView.h"

using namespace std;

class Controler {
    GaramView view;
    unique_ptr<Game> game;


public:
    Controler();


    void loop();
};


#endif //JEUFOURMI_CONTROLER_H
