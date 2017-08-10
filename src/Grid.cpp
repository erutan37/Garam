//
// Created by Erutan on 14/07/2017.
//

#include <ostream>
#include <iostream>
#include "Grid.h"


Grid::Grid(size_t columns, size_t rows, TYPE t) : rows(rows), columns(columns), selectedCase(0,0),
                                          grid(new int[rows*columns]), type(t){
    reset();

}

void Grid::changeContentSelectedCase(int content) {
    setContentCase(selectedCase,content);
}

void Grid::changeSelectedCase(DIRECTION d) {
    switch (d)
    {

        case UP: selectedCase.y--; break;
        case DOWN: selectedCase.y++; break;
        case LEFT: selectedCase.x--; break;
        case RIGHT:selectedCase.x++; break;
    }
    selectedCase.y%=rows;
    selectedCase.x%=columns;
    
    if(getContentSelectedCase()==BLOCK)
        changeSelectedCase(d);
}

void Grid::reset() {
    switch (type)
    {

        case GARAM:
            for (int y = 0; y <rows ; ++y)
                for (int x = 0; x < columns; ++x)
                    setContentCase(x,y,EMPTY);


            for (int x = 0; x < columns; ++x)
            {
                if(x!=2 && x!=8)
                {
                    setContentCase(x,5,BLOCK);
                    setContentCase(x,6,BLOCK);
                }
            }

            for (int y = 0; y < rows; ++y)
            {
                if(y!=2 && y!=9)
                {
                    setContentCase(4,y,BLOCK);
                    setContentCase(5,y,BLOCK);
                }
            }

            for (int y = 0; y < rows; ++y)
                for (int x = 0; x < columns; ++x)
                    if(x==1 ||x==2||x==7||x==8)
                        if((y>=1 && y<=3) ||(y>=8 && y<=10))
                            setContentCase(x,y,BLOCK);




            for(int x=0; x<columns; ++x)
            {
                if(x==1 || x==7)
                {
                    setContentCase(x,0,PLUS);
                    setContentCase(x,4,PLUS);
                    setContentCase(x,7,PLUS);
                    setContentCase(x,11,PLUS);
                }
                if(x==0 || x == 3 || x == 6 || x ==9)
                {
                    setContentCase(x,1,PLUS);
                    setContentCase(x,8,PLUS);
                }
                if(x==4)
                {
                    setContentCase(x,2,PLUS);
                    setContentCase(x,9,PLUS);
                }
            }
            setContentCase(2,5,PLUS);
            setContentCase(8,5,PLUS);


            break;
        case SUDOKU:


            break;
    }

}

int Grid::getContentSelectedCase() const {
    return getContentCase(selectedCase);
}

int Grid::getContentCase(const Grid::Case &c) const {
    return grid[rows*c.x+c.y];
}

void Grid::setContentCase(const Grid::Case &c, int content) {
    setContentCase(c.x,c.y,content);
}

int Grid::getContentCase(int x, int y) const {
    return getContentCase(Case(x,y));
}

bool Grid::isThisCaseSelected(int x, int y) const {
    return (x==selectedCase.x && y==selectedCase.y);
}

void Grid::setContentCase(int x, int y, int content) {
    if(grid[rows*x+y]==BLOCK)
    {

    }
    grid[rows*x+y]=content;
}

size_t Grid::getRows() const {
    return rows;
}

size_t Grid::getColumns() const {
    return columns;
}

void Grid::display() const {
    std::cout << std::endl;
    for (int y = 0; y < rows; ++y) {
        std::cout << std::endl;
        for (int x = 0; x < columns; ++x)
        {
            switch(getContentCase(x,y))
            {
                case EMPTY: std::cout << "X";
                    break;
                case BLOCK: std::cout <<" ";
                    break;
                case PLUS: std::cout<<"+";
                    break;
                case MINUS: std::cout<<"-";
                    break;
                case TIME: std::cout<<"*";
                    break;
                default:std::cout<<getContentCase(x,y);
            }
        }
    }
}


Grid::Case::Case(int x, int y) : x(x), y(y), id(-1) {}

bool Grid::Case::operator==(const Grid::Case &rhs) const {
    return x == rhs.x &&
           y == rhs.y;
}

bool Grid::Case::operator!=(const Grid::Case &rhs) const {
    return !(rhs == *this);
}

Grid::Case::Case(int x, int y, int id) : x(x), y(y), id(id) {}
