//
// Created by Erutan on 17/04/2016.
//

#ifndef CONTROLER_H
#define CONTROLER_H


#include "View.h"

using namespace std;

class Controler {
    std::unique_ptr<View> view;
    unique_ptr<Game> game;


public:
    Controler();


    void loop();
};


#endif //JEUFOURMI_CONTROLER_H
