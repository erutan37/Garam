//
// Created by Erutan on 17/04/2016.
//

#include "Game.h"
#include "Reduction.h"
#include <fstream>
#include <iostream>

using namespace std;



Game::Game() : grid(), strategicCases{{0,2,15,16,17,7,3,5,9,18,19,20,23,24,25,30,38,40,26,27,28,32,41,43}} {
}






const Grid &Game::getGrid() const {
    return grid;
}

void Game::changeSelectedCase(DIRECTION d) {
    grid.changeSelectedCase(d);
}

void Game::changeContentSelectedCase(int content) {
    grid.changeContentSelectedCase(content);

}

void Game::reduction() {

    for(int i : grid.getOp())
        if(i ==100)
            return;;


    ofstream file("reduction", ios::out | ios::trunc);
    if(file)
    {
        file <<"c  reduction\n";
        file <<"c\n";
        file << "p cnf 200 500\n";
        for (int i = 0; i < 24; ++i) {
            Reduction::onlyOneValue(file, i);
            Reduction::forceValueInCase(file,i,grid[strategicCases[i]]);
        }

        switch (grid.getOp()[0])
        {
            case PLUS:
                Reduction::operationPlusPlus10(file,0,2,grid[6]);
                break;
            case MINUS:
                cerr << "Erreur mauvais signe" <<endl;
                break;
            case TIME:
            Reduction::operationTimePlus10(file,0,2,grid[6],grid[11]);
                break;
        }

        switch (grid.getOp()[1])
        {
            case PLUS:
                Reduction::operationPlusMinus10(file,0,1,grid[1]);
                break;
            case MINUS:
                Reduction::operationMinus(file,0,1,grid[1]);
                break;
            case TIME:
                Reduction::operationTimeMinus10(file,0,1,grid[1]);
                break;
        }

        switch (grid.getOp()[2])
        {
            case PLUS:
                Reduction::operationPlusTwoCases(file,1,5,4);
                break;
            case MINUS:
                cerr << "Erreur mauvais signe" <<endl;
                break;
            case TIME:
                Reduction::operationTimePlus10TwoCases(file,1,5,4,grid[12]);
                break;
        }

        switch (grid.getOp()[3])
        {
            case PLUS:
                Reduction::operationPlusMinus10TwoCases(file, 2, 3, 4);
                break;
            case MINUS:
                Reduction::operationMinusTwoCases(file,2,3,4);
                break;
            case TIME:
                Reduction::operationTimeMinus10TwoCases(file,2,3,4);
                break;
        }

        switch (grid.getOp()[4])
        {
            case PLUS:
                Reduction::operationPlusMinus10(file,5,8,grid[8]);
                break;
            case MINUS:
                Reduction::operationMinus(file,5,8,grid[8]);
                break;
            case TIME:
                Reduction::operationTimeMinus10(file,5,8,grid[8]);
                break;
        }

        switch (grid.getOp()[5])
        {
            case PLUS:
                Reduction::operationPlusTwoCases(file,6,8,9);
                break;
            case MINUS:
                cerr << "Erreur mauvais signe" <<endl;
                break;
            case TIME:
                Reduction::operationTimePlus10TwoCases(file,6,8,9,grid[13]);
                break;
        }

        switch (grid.getOp()[6])
        {
            case PLUS:
                Reduction::operationPlusMinus10(file,6,7,grid[4]);
                break;
            case MINUS:
                Reduction::operationMinus(file,6,7,grid[4]);
                break;
            case TIME:
                Reduction::operationTimeMinus10(file,6,7,grid[4]);
                break;
        }

        switch (grid.getOp()[7])
        {
            case PLUS:
                Reduction::operationPlusPlus10(file,7,11,grid[10]);
                break;
            case MINUS:
                cerr << "Erreur mauvais signe" <<endl;
                break;
            case TIME:
                Reduction::operationTimePlus10(file,7,11,grid[10],grid[14]);
                break;
        }

        switch (grid.getOp()[8])
        {
            case PLUS:
                Reduction::operationPlusMinus10TwoCases(file, 9, 10, 11);
                break;
            case MINUS:
                Reduction::operationMinusTwoCases(file,9,10,11);
                break;
            case TIME:
                Reduction::operationTimeMinus10TwoCases(file,9,10,11);
                break;
        }

        switch (grid.getOp()[9])
        {
            case PLUS:
                Reduction::operationPlusMinus10(file,3,13,grid[21]);
                break;
            case MINUS:
                Reduction::operationMinus(file,3,13,grid[21]);
                break;
            case TIME:
                Reduction::operationTimeMinus10(file,3,13,grid[21]);
                break;
        }

        switch (grid.getOp()[10])
        {
            case PLUS:
                Reduction::operationPlusMinus10(file,10,19,grid[22]);
                break;
            case MINUS:
                Reduction::operationMinus(file,10,19,grid[22]);
                break;
            case TIME:
                Reduction::operationTimeMinus10(file,10,19,grid[22]);
                break;
        }

        switch (grid.getOp()[11])
        {
            case PLUS:
                Reduction::operationPlusPlus10(file,12,16,grid[29]);
                break;
            case MINUS:
                cerr << "Erreur mauvais signe" <<endl;
                break;
            case TIME:
                Reduction::operationTimePlus10(file,12,16,grid[29],grid[34]);
                break;
        }

        switch (grid.getOp()[12])
        {
            case PLUS:
                Reduction::operationPlusMinus10TwoCases(file, 12, 13, 14);
                break;
            case MINUS:
                Reduction::operationMinusTwoCases(file,12,13,14);
                break;
            case TIME:
                Reduction::operationTimeMinus10TwoCases(file,12,13,14);
                break;
        }

        switch (grid.getOp()[13])
        {
            case PLUS:
                Reduction::operationPlusTwoCases(file,14,15,17);
                break;
            case MINUS:
                cerr << "Erreur mauvais signe" <<endl;
                break;
            case TIME:
                Reduction::operationTimePlus10TwoCases(file,14,15,17,grid[35]);
                break;
        }

        switch (grid.getOp()[14])
        {
            case PLUS:
                Reduction::operationPlusMinus10(file,16,17,grid[39]);
                break;
            case MINUS:
                Reduction::operationMinus(file,16,17,grid[39]);
                break;
            case TIME:
                Reduction::operationTimeMinus10(file,16,17,grid[39]);
                break;
        }

        switch (grid.getOp()[15])
        {
            case PLUS:
                Reduction::operationPlusMinus10(file,15,21,grid[31]);
                break;
            case MINUS:
                Reduction::operationMinus(file,15,21,grid[31]);
                break;
            case TIME:
                Reduction::operationTimeMinus10(file,15,21,grid[31]);
                break;
        }

        switch (grid.getOp()[16])
        {
            case PLUS:
                Reduction::operationPlusTwoCases(file,18,21,22);
                break;
            case MINUS:
                cerr << "Erreur mauvais signe" <<endl;
                break;
            case TIME:
                Reduction::operationTimePlus10TwoCases(file,18,21,22,grid[36]);
                break;
        }
        switch (grid.getOp()[17])
        {
            case PLUS:
                Reduction::operationPlusMinus10TwoCases(file, 18, 19, 20);
                break;
            case MINUS:
                Reduction::operationMinusTwoCases(file,18,19,20);
                break;
            case TIME:
                Reduction::operationTimeMinus10TwoCases(file,18,19,20);
                break;
        }

        switch (grid.getOp()[18])
        {
            case PLUS:
                Reduction::operationPlusPlus10(file,20,23,grid[33]);
                break;
            case MINUS:
                cerr << "Erreur mauvais signe" <<endl;
                break;
            case TIME:
                Reduction::operationTimePlus10(file,20,23,grid[33],grid[37]);
                break;
        }

        switch (grid.getOp()[19])
        {
            case PLUS:
                Reduction::operationPlusMinus10(file,22,23,grid[42]);
                break;
            case MINUS:
                Reduction::operationMinus(file,22,23,grid[42]);
                break;
            case TIME:
                Reduction::operationTimeMinus10(file,22,23,grid[42]);
                break;
        }







        file.close();
        system("./glucose reduction result");
        result();
    }
    else  // sinon
        cerr << "Erreur à l'ouverture !" << endl;
}

void Game::result() {

    ifstream fichier("result", ios::in);

    if(fichier)
    {
        for (int i : strategicCases)
        {
            for (int j = 1; j <=10 ; ++j)
            {
                int value;
                fichier >> value;
                if(value>0)
                    grid[i]=(j%10);
            }
        }
        fichier.close();

        completeGap();

    }
    else  // sinon
        cerr << "Impossible d'ouvrir le fichier !" << endl;

}

void Game::completeGap() {
    switch (grid.getOp()[0])
    {
        case PLUS:
            grid[6] = 10 + grid[strategicCases[2]]-grid[strategicCases[0]];
            grid[11]=1;
            break;
        case TIME:
            if(grid[11] != 100)
            {
                grid[6]= (grid[11]*10+grid[strategicCases[2]])/grid[strategicCases[0]];
            }
            else
            {
                for (int i = 2 ; i <10 ; ++i)
                {
                    if(grid[strategicCases[0]]*i>=10
                       && (grid[strategicCases[0]]*i)%10==grid[strategicCases[2]])
                    {
                        grid[6]=i;
                    }
                }

            }
            if(grid[11]==100)
                grid[11]=(grid[strategicCases[0]]*grid[6]-grid[strategicCases[2]])/10;
            break;
    }

    switch (grid.getOp()[1])
    {
        case PLUS:
            grid[1] = grid[strategicCases[1]]-grid[strategicCases[0]];
            break;
        case MINUS:
            grid[1] = grid[strategicCases[0]]-grid[strategicCases[1]];
            break;
        case TIME:
            grid[1]=grid[strategicCases[1]]/grid[strategicCases[0]];
            break;
    }

    switch (grid.getOp()[2])
    {
        case PLUS:
            grid[12]=1;
            break;
        case MINUS:
            cerr << "Erreur mauvais signe" <<endl;
            break;
        case TIME:
            if(grid[12]==100)
                grid[12]=(grid[strategicCases[1]]*grid[strategicCases[5]]-grid[strategicCases[4]])/10;
            break;
    }


    switch (grid.getOp()[4])
    {
        case PLUS:
            grid[8] = grid[strategicCases[8]]-grid[strategicCases[5]];
            break;
        case MINUS:
            grid[8] = grid[strategicCases[5]]-grid[strategicCases[8]];
            break;
        case TIME:
            grid[8]=grid[strategicCases[8]]/grid[strategicCases[5]];
            break;
    }

    switch (grid.getOp()[5])
    {
        case PLUS:
            grid[13] = 1;
            break;
        case MINUS:
            cerr << "Erreur mauvais signe" <<endl;
            break;
        case TIME:
            if(grid[13]==100)
                grid[13]=(grid[strategicCases[6]]*grid[strategicCases[8]]-grid[strategicCases[9]])/10;
            break;
    }

    switch (grid.getOp()[6])
    {
        case PLUS:
            grid[4] = grid[strategicCases[7]]-grid[strategicCases[6]];
            break;
        case MINUS:
            grid[4] = grid[strategicCases[6]]-grid[strategicCases[7]];
            break;
        case TIME:
            grid[4]=grid[strategicCases[7]]/grid[strategicCases[6]];
            break;
    }

    switch (grid.getOp()[7])
    {
        case PLUS:
            grid[10] = 10 + grid[strategicCases[11]]-grid[strategicCases[7]];
            grid[14] = 1;
            break;
        case MINUS:
            cerr << "Erreur mauvais signe" <<endl;
            break;
        case TIME:
            if(grid[14] != 100)
            {
                grid[10]= (grid[14]*10+grid[strategicCases[11]])/grid[strategicCases[7]];
            }
            else
            {
                for (int i = 2 ; i <10 ; ++i)
                {
                    if(grid[strategicCases[7]]*i>=10
                       && (grid[strategicCases[7]]*i)%10==grid[strategicCases[11]])
                    {
                        grid[10]=i;
                    }
                }

            }
            if(grid[14]==100)
                grid[14]=(grid[strategicCases[7]]*grid[10]-grid[strategicCases[11]])/10;
            break;
    }


    switch (grid.getOp()[9])
    {
        case PLUS:
            grid[21] = grid[strategicCases[13]]-grid[strategicCases[3]];
            break;
        case MINUS:
            grid[21] = grid[strategicCases[3]]-grid[strategicCases[13]];
            break;
        case TIME:
            grid[21]=grid[strategicCases[13]]/grid[strategicCases[3]];
            break;
    }

    switch (grid.getOp()[10])
    {
        case PLUS:
            grid[22] = grid[strategicCases[19]]-grid[strategicCases[10]];
            break;
        case MINUS:
            grid[22] = grid[strategicCases[10]]-grid[strategicCases[19]];
            break;
        case TIME:
            grid[22]=grid[strategicCases[19]]/grid[strategicCases[10]];
            break;
    }

    switch (grid.getOp()[11])
    {
        case PLUS:
            grid[29] = 10 + grid[strategicCases[16]]-grid[strategicCases[12]];
            grid[34] = 1;
            break;
        case MINUS:
            cerr << "Erreur mauvais signe" <<endl;
            break;
        case TIME:
            if(grid[34] != 100)
            {
                grid[29]= (grid[34]*10+grid[strategicCases[16]])/grid[strategicCases[12]];
            }
            else
            {
                for (int i = 2 ; i <10 ; ++i)
                {
                    if(grid[strategicCases[12]]*i>=10
                       && (grid[strategicCases[12]]*i)%10==grid[strategicCases[16]])
                    {
                        grid[29]=i;
                    }
                }

            }
            if(grid[34]==100)
                grid[34]=(grid[strategicCases[12]]*grid[29]-grid[strategicCases[16]])/10;
            break;
    }


    switch (grid.getOp()[13])
    {
        case PLUS:
            grid[35] = 1;
            break;
        case MINUS:
            cerr << "Erreur mauvais signe" <<endl;
            break;
        case TIME:
            if(grid[35]==100)
                grid[35]=(grid[strategicCases[14]]*grid[strategicCases[15]]-grid[strategicCases[17]])/10;
            break;
    }

    switch (grid.getOp()[14])
    {
        case PLUS:
            grid[39] = grid[strategicCases[17]]-grid[strategicCases[16]];
            break;
        case MINUS:
            grid[39] = grid[strategicCases[16]]-grid[strategicCases[17]];
            break;
        case TIME:
            grid[39] = grid[strategicCases[17]]/grid[strategicCases[16]];
            break;
    }

    switch (grid.getOp()[15])
    {
        case PLUS:
            grid[31] = grid[strategicCases[21]]-grid[strategicCases[15]];
            break;
        case MINUS:
            grid[31] = grid[strategicCases[15]]-grid[strategicCases[21]];
            break;
        case TIME:
            grid[31] = grid[strategicCases[21]]/grid[strategicCases[15]];
            break;
    }

    switch (grid.getOp()[16])
    {
        case PLUS:
            grid[36] = 1;
            break;
        case MINUS:
            cerr << "Erreur mauvais signe" <<endl;
            break;
        case TIME:
            if(grid[36]==100)
                grid[36]=(grid[strategicCases[18]]*grid[strategicCases[21]]-grid[strategicCases[22]])/10;
            break;
    }


    switch (grid.getOp()[18])
    {
        case PLUS:
            grid[33] = 10 + grid[strategicCases[23]]-grid[strategicCases[20]];
            grid[37] = 1;
            break;
        case MINUS:
            cerr << "Erreur mauvais signe" <<endl;
            break;
        case TIME:
            if(grid[37] != 100)
            {
                grid[33]= (grid[37]*10+grid[strategicCases[23]])/grid[strategicCases[20]];
            }
            else
            {
                for (int i = 2 ; i <10 ; ++i)
                {
                    if(grid[strategicCases[20]]*i>=10
                       && (grid[strategicCases[20]]*i)%10==grid[strategicCases[23]])
                    {
                        grid[33]=i;
                    }
                }

            }
            if(grid[37]==100)
                grid[37]=(grid[strategicCases[20]]*grid[33]-grid[strategicCases[23]])/10;
            break;
    }

    switch (grid.getOp()[19])
    {
        case PLUS:
            grid[42] =grid[strategicCases[23]]-grid[strategicCases[22]];
            break;
        case MINUS:
            grid[42] =grid[strategicCases[22]]-grid[strategicCases[23]];
            break;
        case TIME:
            grid[42] =grid[strategicCases[23]]/grid[strategicCases[22]];
            break;
    }


}

void Game::reset() {
    grid.reset();
}


