//
// Created by Erutan on 11/08/2017.
//

#include "SudokuGame.h"
#include "ReductionSudoku.h"

SudokuGame::SudokuGame() : Game(new Grid(9,9,SUDOKU))
{}

void SudokuGame::reduction()
{

    ofstream file("reduction", ios::out | ios::trunc);
    if(file)
    {
        file <<"c  reduction\n";
        file <<"c\n";
        file << "p cnf 200 500\n";
        for (int y = 0; y < 9; ++y)
            for (int x = 0; x < 9; ++x)
            {
                ReductionSudoku::onlyOneValue(file, y * 9 + x);
                ReductionSudoku::forceValueInCase(file, y * 9 + x, grid->getContentCase(x, y));
            }
       for (int i = 0; i < 9; ++i)
        {
            std::array<int,9> line;
            std::array<int,9> column;
            for(int j = 0; j < 9; ++j)
            {
                line[j]=i*9+j;
                column[j]=j*9+i;
            }
            ReductionSudoku::differentValuePerCase(file,line);
            ReductionSudoku::differentValuePerCase(file,column);
        }
        for (int xBlock = 0; xBlock < 3; ++xBlock)
            for (int yBlock = 0; yBlock < 3; ++yBlock)
            {
                std::array<int,9> block;
                for (int x = 0; x < 3; ++x)
                    for (int y = 0; y < 3; ++y)
                        block[x*3+y]=xBlock*3+yBlock*3*9+y*9+x;

                ReductionSudoku::differentValuePerCase(file,block);
            }


        file.close();
        system("./glucose reduction result");
        result();
    }
    else  // sinon
        cerr << "Erreur à l'ouverture !" << endl;

}

void SudokuGame::result()
{

    ifstream fichier("result", ios::in);

    if(fichier)
    {
        for (int y = 0; y < 9; ++y)
        for (int x = 0; x < 9; ++x)
        {
            for (int j = 1; j <=9 ; ++j)
            {
                int value;
                fichier >> value;
                if(value>0)
                    grid->setContentCase(x,y,j);
            }
        }
        fichier.close();
    }
    else  // sinon
        cerr << "Impossible d'ouvrir le fichier !" << endl;

}
