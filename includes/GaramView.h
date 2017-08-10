//
// Created by Erutan on 17/04/2016.
//

#ifndef GARAM_VIEW_H
#define GARAM_VIEW_H


#include "View.h"




class GaramView : public View
{


public:
    GaramView();

    void display() override;

    void displayGrid();

    void displayMenu();
};



#endif //JEUFOURMI_VIEW_H

