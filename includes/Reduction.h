//
// Created by Erutan on 04/07/2017.
//

#ifndef JEUFOURMI_REDUCTION_H
#define JEUFOURMI_REDUCTION_H

#include <fstream>
#include <iostream>
#include "Grid.h"

using namespace std;


class Reduction {
public:
    static int getId(int nbCase, int value);
    static void onlyOneValue(ofstream &file, int nbCase);
    static void forceValueInCase(ofstream &file,int nbCase, int value);
    static void operationPlusMinus10(ofstream &file,int nbCase1, int nbCase2, int intermediateValue);
    static void operationPlusMinus10TwoCases(ofstream &file, int nbCase1, int nbCase2, int Case3);
    static void operationMinus(ofstream &file,int nbCase1, int nbCase2, int intermediateValue);
    static void operationMinusTwoCases(ofstream &file,int nbCase1, int nbCase2, int intermediateValue);
    static void operationPlusPlus10(ofstream &file,int nbCase1, int nbCase2, int intermediateValue);
    static void operationPlusTwoCases(ofstream &file, int nbCase1, int nbCase2, int nbCase3);
    static void operationTimeMinus10(ofstream &file,int nbCase1, int nbCase2, int intermediateValue);
    static void operationTimeMinus10TwoCases(ofstream &file,int nbCase1, int nbCase2, int nbCase3);
    static void operationTimePlus10(ofstream &file,int nbCase1, int nbCase2,
                                    int intermediateValue, int intermediateValue2);
    static void operationTimePlus10TwoCases(ofstream &file,int nbCase1, int nbCase2,
                                    int nbCase3, int intermediateValue2);


};


#endif //JEUFOURMI_REDUCTION_H
