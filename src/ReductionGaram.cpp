//
// Created by Erutan on 04/07/2017.
//

#include "ReductionGaram.h"



void ReductionGaram::onlyOneValue(ofstream &file, int nbCase) {
    for (int i = 0; i <10 ; ++i)
    {
        file << getId(nbCase,i) << " ";
    }
    file <<" 0\n";

    for (int j = 0; j < 10; ++j)
    {
        for (int i = j+1; i < 10; ++i)
        {
            file << "-" <<getId(nbCase,j) << " -" << getId(nbCase,i) << " 0\n";;
        }
    }

}

void ReductionGaram::forceValueInCase(ofstream &file, int nbCase, int value) {
    if (value==100)
        return;

    file << getId(nbCase,value) << " ";
    file << " 0\n";
}

int ReductionGaram::getId(int nbCase, int value) {
    if (value ==0)
        return (nbCase+1)*10;
    return nbCase*10+value;
}

void ReductionGaram::operationPlusMinus10(ofstream &file, int nbCase1, int nbCase2, int intermediateValue) {
    if(intermediateValue==100)
    {
        for (int i = 1; i < 10; ++i) {
            for (int j = i - 1; j >= 0; --j)
                file << "-" << getId(nbCase1, i) << " -" << getId(nbCase2, j) << " 0\n";
        }
    }
    else
    {
        for (int i = 0; i < 10; ++i) {
            if(i + intermediateValue <10)
                file << "-" << getId(nbCase1, i) << " " << getId(nbCase2, i+intermediateValue) << " 0\n";
            else file << "-" << getId(nbCase1, i) << " 0\n";
        }
    }


}

void ReductionGaram::operationMinus(ofstream &file, int nbCase1, int nbCase2, int intermediateValue) {

    if(intermediateValue==100)
    {
        for (int i = 0; i < 9; ++i) {
            for (int j = i+1 ; j < 10; ++j)
                file << "-" << getId(nbCase1, i) << " -" << getId(nbCase2, j) << " 0\n";
        }
    }
    else
    {
        for (int i = 0; i < 10; ++i) {
            if(i - intermediateValue >=0)
                file << "-" << getId(nbCase1, i) << " " << getId(nbCase2, i-intermediateValue) << " 0\n";
            else file << "-" << getId(nbCase1, i) << " 0\n";
        }
    }


}

void ReductionGaram::operationPlusPlus10(ofstream &file, int nbCase1, int nbCase2, int intermediateValue) {
    if(intermediateValue==100) {
        file << "-" <<getId(nbCase1,0) <<" 0\n";
        for (int i = 1; i < 10; ++i)
        {
            file << "-" <<getId(nbCase1,i) << " ";
            for (int j = i -1; j >= 0 ; --j)
                file <<getId(nbCase2,j) << " ";
            file << " 0\n";
        }
    }
    else
    {
        for (int i = 10-intermediateValue; i <10 ; ++i)
            file <<getId(nbCase1,i) <<" ";
        file <<" 0\n";

        for (int i = 10-intermediateValue; i <10 ; ++i) {
            file << "-" <<getId(nbCase1, i) << " ";
            file << getId(nbCase2, i+ intermediateValue-10) <<" ";
            file << " 0\n";
        }

    }


}

void ReductionGaram::operationPlusTwoCases(ofstream &file, int nbCase1, int nbCase2, int nbCase3) {
    file << "-" << getId(nbCase1,0) <<" 0\n";
    file << "-" << getId(nbCase2,0) <<" 0\n";

    for (int i = 1; i < 10; ++i)
    {
        for (int j = 10-i; j < 10; ++j)
        {
            file << "-" << getId(nbCase1,i) << " -" << getId(nbCase2,j) <<" "<< getId(nbCase3,i+j-10) << " 0\n";
        }
    }
    for (int i = 1; i < 10; ++i)
    {
        file << "-" << getId(nbCase1,i) << " ";
        for (int j = 10-i; j < 10; ++j)
        {
            file << getId(nbCase2,j) <<" ";
        }
        file << " 0\n";
    }
    for (int i = 1; i < 10; ++i)
    {
        file << "-" << getId(nbCase2,i) << " ";
        for (int j = 10-i; j < 10; ++j)
        {
            file << getId(nbCase1,j) <<" ";
        }
        file << " 0\n";
    }
}

void ReductionGaram::operationTimeMinus10(ofstream &file, int nbCase1, int nbCase2, int intermediateValue) {
    if(intermediateValue==100)
    {
        for (int i = 0; i < 10; ++i)
        {
            file << "-" << getId(nbCase1,i) << " ";
            for (int j = 0; j < 10; ++j)
            {
                if(i*j <10)
                    file << getId(nbCase2,i*j) <<" ";
            }
            file << " 0\n";

        }

    }
    else
    {
        for (int i = 0; i < 10; ++i)
        {
            if (i*intermediateValue > 10)
                file << "-" << getId(nbCase1,i) <<" 0\n";
            file << "-" << getId(nbCase1,i) << " " << getId(nbCase2,i*intermediateValue) <<" 0\n";
        }
    }
}

void ReductionGaram::operationPlusMinus10TwoCases(ofstream &file, int nbCase1, int nbCase2, int nbCase3) {

    for (int i = 0; i < 10; ++i)
    {
        for (int j = 9-i; j >= 0; --j)
        {
            file << "-" << getId(nbCase1,i) << " -" << getId(nbCase2,j) <<" "<< getId(nbCase3,i+j) << " 0\n";
        }
    }
    for (int i = 1; i < 10; ++i)
    {
        file << "-" << getId(nbCase1,i) << " ";
        for (int j = 9-i; j >= 0; --j)
        {
            file << getId(nbCase2,j) <<" ";
        }
        file << " 0\n";
    }
    for (int i = 1; i < 10; ++i)
    {
        file << "-" << getId(nbCase2,i) << " ";
        for (int j = 9-i; j >= 0; --j)
        {
            file << getId(nbCase1,j) <<" ";
        }
        file << " 0\n";
    }
}

void ReductionGaram::operationTimeMinus10TwoCases(ofstream &file, int nbCase1, int nbCase2, int nbCase3) {

    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            if(i*j <10)
                file << "-" << getId(nbCase1,i) << " -" << getId(nbCase2,j) <<" "<< getId(nbCase3,i*j) << " 0\n";
        }
    }
    for (int i = 2; i < 10; ++i)
    {
        file << "-" << getId(nbCase1,i) << " ";
        for (int j = 0; j < 10; ++j)
        {
            if(i*j < 10)
                file << getId(nbCase2,j) <<" ";
        }
        file << " 0\n";
    }
    for (int i = 2; i < 10; ++i)
    {
        file << "-" << getId(nbCase2,i) << " ";
        for (int j = 0; j < 10; ++j)
        {
            if(i*j < 10)
                file << getId(nbCase1,j) <<" ";
        }
        file << " 0\n";
    }
}

void ReductionGaram::operationTimePlus10(ofstream &file, int nbCase1, int nbCase2,
                                    int intermediateValue1, int intermediateValue2) {
    if(intermediateValue1==100) {
        file << "-" << getId(nbCase1,0)<< " 0\n"; ;
        file << "-" << getId(nbCase1,1)<< " 0\n"; ;
        for (int i = 2; i < 10; ++i)
        {
            file << "-" <<getId(nbCase1,i) << " ";
            for (int j = 2; j < 10 ; ++j) {
                if((intermediateValue2 ==100 && i*j >=10)
                   || (i*j >= intermediateValue2*10 && i*j < (intermediateValue2+1)*10))
                    file << getId(nbCase2, (i*j)%10) << " ";
            }
            file << " 0\n";
        }
    }
    else if(intermediateValue2 != 100)
    {
        for (int i = intermediateValue2+1; i <10 ; ++i)
            if(i*intermediateValue1 >= intermediateValue2*10
                    && i*intermediateValue1 < (intermediateValue2+1)*10)
            file << getId(nbCase1,i) << " ";
        file << " 0\n";


        for (int i = intermediateValue2+1; i <10 ; ++i) {
            file << "-" <<getId(nbCase1, i) << " ";
            file << getId(nbCase2, (i*intermediateValue1)%10) <<" ";
            file << " 0\n";
        }

    }
    else
    {
        for (int i = 2; i <10 ; ++i)
            if(i*intermediateValue1 >= 10)
                file << getId(nbCase1,i) << " ";
        file << " 0\n";


        for (int i = 2; i <10 ; ++i) {
            if(i*intermediateValue1 >= 10)
            {
                file << "-" << getId(nbCase1, i) << " ";
                file << getId(nbCase2, (i * intermediateValue1) % 10) << " ";
                file << " 0\n";
            }
        }
    }



}

void
ReductionGaram::operationTimePlus10TwoCases(ofstream &file, int nbCase1, int nbCase2, int nbCase3, int intermediateValue) {


    if(intermediateValue != 100)
    {
        for (int i = intermediateValue+1; i <10 ; ++i)
        {
            file <<"-"<< getId(nbCase1,i) << " ";
            for (int j = intermediateValue+1; j <10 ; ++j)
            {
                if(i*j >= intermediateValue*10
                   && i*j < (intermediateValue+1)*10)
                    file << getId(nbCase2,j) << " ";
            }
            file << " 0\n";
        }

        for (int i = intermediateValue+1; i <10 ; ++i)
        {
            file <<"-"<< getId(nbCase2,i) << " ";
            for (int j = intermediateValue+1; j <10 ; ++j)
            {
                if(i*j >= intermediateValue*10
                   && i*j < (intermediateValue+1)*10)
                    file << getId(nbCase1,j) << " ";
            }
            file << " 0\n";
        }
        for (int i = intermediateValue+1; i <10 ; ++i)
        {
            file << getId(nbCase1,i) << " ";
        }
        file << " 0\n";
        for (int i = intermediateValue+1; i <10 ; ++i)
        {
            file << getId(nbCase2,i) << " ";
        }
        file << " 0\n";

        for (int i = intermediateValue+1; i <10 ; ++i)
        {
            for (int j = intermediateValue+1; j <10 ; ++j)
            {
                if(i*j >= intermediateValue*10
                   && i*j < (intermediateValue+1)*10)
                    file <<"-"<< getId(nbCase1,i)<<" -"<< getId(nbCase2,j) << " " << getId(nbCase3,(j*i)%10)<< " 0\n";
            }
        }

    }
    else
    {
        for (int i = 2; i <10 ; ++i)
        {
            file <<"-"<< getId(nbCase1,i) << " ";
            for (int j = 2; j <10 ; ++j)
            {
                if(i*j >= 10)
                    file << getId(nbCase2,j) << " ";

            }
            file << " 0\n";
        }

        for (int i = 2; i <10 ; ++i)
        {
            file <<"-"<< getId(nbCase2,i) << " ";
            for (int j = 2; j <10 ; ++j)
            {
                if(i*j >= 10)
                    file << getId(nbCase1,j) << " ";
            }
            file << " 0\n";
        }

        file << "-"<< getId(nbCase1,1) << " 0\n";
        file << "-"<< getId(nbCase2,1) << " 0\n";

        for (int i = 2; i <10 ; ++i)
        {
            for (int j = 2; j <10 ; ++j)
            {
                if(i*j >= 10)
                    file <<"-"<< getId(nbCase1,i)<<" -"<< getId(nbCase2,j) << " " << getId(nbCase3,(j*i)%10)<< " 0\n";
            }
        }
    }



}

void ReductionGaram::operationMinusTwoCases(ofstream &file, int nbCase1, int nbCase2, int nbCase3) {

    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j <= i; ++j)
        {
            file << "-" << getId(nbCase1,i) << " -" << getId(nbCase2,j) <<" "<< getId(nbCase3,i-j) << " 0\n";
        }
    }
    for (int i = 0; i < 9; ++i)
    {
        file << "-" << getId(nbCase1,i) << " ";
        for (int j = 0; j <= i; ++j)
        {
            file << getId(nbCase2,j) <<" ";
        }
        file << " 0\n";
    }
    for (int i = 0; i < 9; ++i)
    {
        file << "-" << getId(nbCase2,i) << " ";
        for (int j = i; j < 10; ++j)
        {
            file << getId(nbCase1,j) <<" ";
        }
        file << " 0\n";
    }
}



