//
// Created by Erutan on 14/08/2017.
//

#ifndef REDUCTIONSUDOKU_H
#define REDUCTIONSUDOKU_H

#include <fstream>
#include <iostream>
#include <vector>
#include <array>

using namespace std;

class ReductionSudoku
{
public:
    static int getId(int nbCase, int value);
    static void onlyOneValue(ofstream &file, int nbCase);
    static void forceValueInCase(ofstream &file,int nbCase, int value);
    static void differentValuePerCase(ofstream &file, array<int,9> listCase);
};


#endif //JEUFOURMI_REDUCTIONSUDOKU_H
