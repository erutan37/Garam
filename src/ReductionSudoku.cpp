//
// Created by Erutan on 14/08/2017.
//

#include "ReductionSudoku.h"

int ReductionSudoku::getId(int nbCase, int value) {
    return nbCase*9+value;
}


void ReductionSudoku::onlyOneValue(ofstream &file, int nbCase) {
    for (int i = 1; i <=9 ; ++i)
    {
        file << getId(nbCase,i) << " ";
    }
    file <<" 0\n";

    for (int j = 1; j <= 9; ++j)
    {
        for (int i = j+1; i <= 9; ++i)
        {
            file << "-" <<getId(nbCase,j) << " -" << getId(nbCase,i) << " 0\n";;
        }
    }

}

void ReductionSudoku::forceValueInCase(ofstream &file, int nbCase, int value) {
    if (value==100)
        return;

    file << getId(nbCase,value) << " ";
    file << " 0\n";
}

void
ReductionSudoku::differentValuePerCase(ofstream &file, array<int, 9> listCase)
{
    for (int i : listCase)
    {
        for (int value = 1; value <= 9 ; ++value)
        {
            for (int j : listCase)
            {
                if(i==j) continue;
                file << "-" << getId(i,value) << " -" << getId(j,value) <<" 0\n";
            }

        }

    }

}
