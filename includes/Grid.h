//
// Created by Erutan on 14/07/2017.
//

#ifndef GRID_H
#define GRID_H

#include <vector>
#include <array>

#define EMPTY 100
#define BLOCK 101
#define PLUS  10
#define MINUS 11
#define TIME  12

enum DIRECTION
{
    UP, DOWN, LEFT, RIGHT
};

enum TYPE
{
    GARAM,SUDOKU
};



class Grid
{

public:

    struct Case
    {
        Case(int x, int y);

        Case(int x, int y, int id);

        int x,y;
        int id;

        bool operator==(const Case &rhs) const;

        bool operator!=(const Case &rhs) const;
    };

    Grid(size_t columns, size_t rows, TYPE t);

    void changeSelectedCase(DIRECTION d);

    void changeContentSelectedCase(int content);

    void reset();

    int getContentSelectedCase() const;

    int getContentCase(const Case &c) const;

    int getContentCase(int x,int y) const;

    void setContentCase(const Case &c, int content);

    void setContentCase(int x, int y, int content);

    bool isThisCaseSelected(int x,int y) const;

    size_t getRows() const;

    size_t getColumns() const;

    void display() const;

protected:
    TYPE type;
    size_t rows,columns;
    Case selectedCase;
    std::unique_ptr<int[]> grid;

};


#endif
