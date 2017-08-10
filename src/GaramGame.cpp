//
// Created by Erutan on 17/04/2016.
//

#include "GaramGame.h"
#include "Reduction.h"
#include <fstream>
#include <iostream>


#define Case Grid::Case
using namespace std;




GaramGame::GaramGame() : Game::Game(new Grid(10,12,GARAM)),
                         strategicCases{{Case(0,0),Case(3,0),Case(6,0),Case(9,0),
                                         Case(3,2),Case(6,2),
                                         Case(0,4),Case(2,4),Case(3,4),Case(6,4),Case(8,4),Case(9,4),
                                         Case(0,7),Case(2,7),Case(3,7),Case(6,7),Case(8,7),Case(9,7),
                                         Case(3,9),Case(6,9),
                                         Case(0,11),Case(3,11),Case(6,11),Case(9,11)
                                        }}

{
    threeCasesOperations.push_back({{Case(0,0,0),Case(1,0),Case(2,0),Case(3,0,1)}});
    threeCasesOperations.push_back({{Case(6,0,2),Case(7,0),Case(8,0),Case(9,0,3)}});
    threeCasesOperations.push_back({{Case(3,2,4),Case(4,2),Case(5,2),Case(6,2,5)}});
    threeCasesOperations.push_back({{Case(0,4,6),Case(1,4),Case(2,4,7),Case(3,4,8)}});
    threeCasesOperations.push_back({{Case(6,4,9),Case(7,4),Case(8,4,10),Case(9,4,11)}});
    threeCasesOperations.push_back({{Case(0,7,12),Case(1,7),Case(2,7,13),Case(3,7,14)}});
    threeCasesOperations.push_back({{Case(6,7,15),Case(7,7),Case(8,7,16),Case(9,7,17)}});
    threeCasesOperations.push_back({{Case(0,11,20),Case(1,11),Case(2,11),Case(3,11,21)}});
    threeCasesOperations.push_back({{Case(6,11,22),Case(7,11),Case(8,11),Case(9,11,23)}});
    threeCasesOperations.push_back({{Case(3,9,18),Case(4,9),Case(5,9),Case(6,9,19)}});
    threeCasesOperations.push_back({{Case(2,4,7),Case(2,5),Case(2,6),Case(2,7,13)}});
    threeCasesOperations.push_back({{Case(8,4,10),Case(8,5),Case(8,6),Case(8,7,16)}});

    fourCasesOperations.push_back({{Case(0,0,0),Case(0,1),Case(0,2),Case(0,3),Case(0,4,6)}});
    fourCasesOperations.push_back({{Case(3,0,1),Case(3,1),Case(3,2,4),Case(3,3),Case(3,4,8)}});
    fourCasesOperations.push_back({{Case(6,0,2),Case(6,1),Case(6,2,5),Case(6,3),Case(6,4,9)}});
    fourCasesOperations.push_back({{Case(9,0,3),Case(9,1),Case(9,2),Case(9,3),Case(9,4,11)}});
    fourCasesOperations.push_back({{Case(0,7,12),Case(0,8),Case(0,9),Case(0,10),Case(0,11,20)}});
    fourCasesOperations.push_back({{Case(3,7,14),Case(3,8),Case(3,9,18),Case(3,10),Case(3,11,21)}});
    fourCasesOperations.push_back({{Case(6,7,15),Case(6,8),Case(6,9,19),Case(6,10),Case(6,11,22)}});
    fourCasesOperations.push_back({{Case(9,7,17),Case(9,8),Case(9,9),Case(9,10),Case(9,11,23)}});

}



void GaramGame::changeContentSelectedCase(int content) {
    int c = grid->getContentSelectedCase();
    if(content==PLUS || content==MINUS || content==TIME) {
        if (c==PLUS || c==MINUS || c==TIME)
            grid->changeContentSelectedCase(content);
    }
    else if(c!=PLUS && c!=MINUS && c!=TIME)
        grid->changeContentSelectedCase(content);
}

void GaramGame::reduction() {


    ofstream file("reduction", ios::out | ios::trunc);
    if(file)
    {
        file <<"c  reduction\n";
        file <<"c\n";
        file << "p cnf 200 500\n";
        for (int i = 0; i < 24; ++i) {
            Reduction::onlyOneValue(file, i);
            Reduction::forceValueInCase(file,i,grid->getContentCase(strategicCases[i]));
        }


        for(auto &a : threeCasesOperations)
        {
            switch (grid->getContentCase(a[1]))
            {
                case PLUS :
                    if(a[2].id==-1)
                        Reduction::operationPlusMinus10(file,a[0].id,a[3].id,grid->getContentCase(a[2]));
                    else Reduction::operationPlusMinus10TwoCases(file,a[0].id,a[2].id,a[3].id);
                    break;
                case MINUS:
                    if(a[2].id==-1)
                        Reduction::operationMinus(file,a[0].id,a[3].id,grid->getContentCase(a[2]));
                    else Reduction::operationMinusTwoCases(file,a[0].id,a[2].id,a[3].id);
                    break;
                case TIME:
                    if(a[2].id==-1)
                        Reduction::operationTimeMinus10(file,a[0].id,a[3].id,grid->getContentCase(a[2]));
                    else Reduction::operationTimeMinus10TwoCases(file,a[0].id,a[2].id,a[3].id);
                    break;
            }
        }

       for(auto &a : fourCasesOperations)
       {
           switch (grid->getContentCase(a[1]))
           {
               case PLUS :
                   if(a[2].id==-1)
                       Reduction::operationPlusPlus10(file,a[0].id,a[4].id,grid->getContentCase(a[2]));
                   else Reduction::operationPlusTwoCases(file,a[0].id,a[2].id,a[4].id);
                   break;
               case MINUS:
                   break;
               case TIME:
                   if(a[2].id==-1)
                       Reduction::operationTimePlus10(file,a[0].id,a[4].id,grid->getContentCase(a[2]),
                                                      grid->getContentCase(a[3]));
                   else Reduction::operationTimePlus10TwoCases(file,a[0].id,a[2].id,a[4].id,grid->getContentCase(a[3]));
                   break;
           }
       }




        file.close();
        system("./glucose reduction result");
        result();
    }
    else  // sinon
        cerr << "Erreur à l'ouverture !" << endl;
}

void GaramGame::result() {

    ifstream fichier("result", ios::in);

    if(fichier)
    {
        for (Case &c : strategicCases)
        {
            for (int j = 1; j <=10 ; ++j)
            {
                int value;
                fichier >> value;
                if(value>0)
                    grid->setContentCase(c,j%10);
            }
        }
        fichier.close();
        fillGaps();
    }
    else  // sinon
        cerr << "Impossible d'ouvrir le fichier !" << endl;

}

void GaramGame::fillGaps() {

    for(auto &a : threeCasesOperations)
    {
        switch (grid->getContentCase(a[1]))
        {
            case PLUS :
                if(a[2].id==-1)
                    grid->setContentCase(a[2],grid->getContentCase(a[3])-grid->getContentCase(a[0]));
                break;
            case MINUS:
                if(a[2].id==-1)
                    grid->setContentCase(a[2],grid->getContentCase(a[0])-grid->getContentCase(a[3]));
                break;
            case TIME:
                if(a[2].id==-1)
                    grid->setContentCase(a[2],grid->getContentCase(a[3])/grid->getContentCase(a[0]));
                break;
        }
    }

    for(auto &a : fourCasesOperations)
    {
        switch (grid->getContentCase(a[1]))
        {
            case PLUS :
                grid->setContentCase(a[3],1);
                if(a[2].id==-1)
                    grid->setContentCase(a[2],10+grid->getContentCase(a[4])-grid->getContentCase(a[0]));
                break;
            case MINUS:
                break;
            case TIME:
                if(a[2].id==-1)
                {
                    if(grid->getContentCase(a[3])==EMPTY)
                        for (int i = 2; i < 10; ++i)
                        {
                            if (i * grid->getContentCase(a[0]) >= 10 &&
                                (i * grid->getContentCase(a[0])) % 10 == grid->getContentCase(a[4]))
                            {
                                grid->setContentCase(a[2], i);
                                grid->setContentCase(a[3],
                                                     (i * grid->getContentCase(a[0]) - grid->getContentCase(a[4])) /
                                                     10);
                            }
                        }
                    else
                        for (int i = 2; i < 10; ++i)
                        {
                            if (i * grid->getContentCase(a[0]) >= 10 &&
                                (i * grid->getContentCase(a[0])) == grid->getContentCase(a[3])*10+
                                                                            grid->getContentCase(a[4]))
                                grid->setContentCase(a[2], i);
                        }
                }
                else
                {
                    grid->setContentCase(a[3],
                                         (grid->getContentCase(a[0]) *
                                          grid->getContentCase(a[2]) -
                                          grid->getContentCase(a[4])) /
                                         10);
                }
                break;
        }
    }


}


