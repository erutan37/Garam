//
// Created by Erutan on 16/04/2016.
//

#include "Grid.h"



Grid::Grid()
{
    selectedCase[0] =0;
    selectedCase[1]=1;
    for (int &i : *this)
        i=100;
    for (int &i : op)
        i=PLUS;


}

void Grid::changeContentSelectedCase(int content) {
    if(selectedCase[0] ==0)
    {
        if(content==PLUS || content ==MINUS || content == TIME)
            return;
        (*this).at(selectedCase[1]-1)=content;
        return;
    }
    if(content!=PLUS && content !=MINUS && content != TIME && content != 100)
        return;
    op[selectedCase[1]-1]=content;
    return;
}

void Grid::changeSelectedCase(DIRECTION d) {
    if(selectedCase[0]== 0)
    {
        switch (d) {
            case UP:
                switch (selectedCase[1]) {
                    case 1:
                        selectedCase[1]=39;
                        break;
                    case 2:
                        selectedCase[1]=40;
                        break;
                    case 3:
                        selectedCase[1]=41;
                        break;
                    case 4:
                        selectedCase[1]=42;
                        break;
                    case 5:
                        selectedCase[1]=43;
                        break;
                    case 6:
                        selectedCase[1]=44;
                        break;
                    case 7:
                        selectedCase[0]=1;
                        selectedCase[1]=1;
                        break;
                    case 8:
                        selectedCase[0]=1;
                        selectedCase[1]=3;
                        break;
                    case 9:
                        selectedCase[1]=32;
                        break;
                    case 10:
                        selectedCase[0]=1;
                        selectedCase[1]=6;
                        break;
                    case 11:
                        selectedCase[0]=1;
                        selectedCase[1]=8;
                        break;
                    case 12:
                        selectedCase[1]=7;
                        break;
                    case 13:
                        selectedCase[1]=8;
                        break;
                    case 14:
                        selectedCase[1]=10;
                        break;
                    case 15:
                        selectedCase[1]=11;
                        break;
                    case 16:
                        selectedCase[1]=12;
                        break;
                    case 17:
                        selectedCase[1]=2;
                        break;
                    case 18:
                        selectedCase[1]=13;
                        break;
                    case 19:
                        selectedCase[1]=14;
                        break;
                    case 20:
                        selectedCase[1]=5;
                        break;
                    case 21:
                        selectedCase[1]=15;
                        break;
                    case 22:
                        selectedCase[0]=1;
                        selectedCase[1]=10;
                        break;
                    case 23:
                        selectedCase[0]=1;
                        selectedCase[1]=11;
                        break;
                    case 24:
                        selectedCase[1]=16;
                        break;
                    case 25:
                        selectedCase[1]=22;
                        break;
                    case 26:
                        selectedCase[1]=18;
                        break;
                    case 27:
                        selectedCase[1]=19;
                        break;
                    case 28:
                        selectedCase[1]=23;
                        break;
                    case 29:
                        selectedCase[1]=21;
                        break;
                    case 30:
                        selectedCase[0]=1;
                        selectedCase[1]=12;
                        break;
                    case 31:
                        selectedCase[0]=1;
                        selectedCase[1]=14;
                        break;
                    case 32:
                        selectedCase[1]=9;
                        break;
                    case 33:
                        selectedCase[0]=1;
                        selectedCase[1]=17;
                        break;
                    case 34:
                        selectedCase[1]=29;
                        break;
                    case 35:
                        selectedCase[1]=30;
                        break;
                    case 36:
                        selectedCase[1]=31;
                        break;
                    case 37:
                        selectedCase[1]=33;
                        break;
                    case 38:
                        selectedCase[1]=34;
                        break;
                    case 39:
                        selectedCase[1]=35;
                        break;
                    case 40:
                        selectedCase[1]=25;
                        break;
                    case 41:
                        selectedCase[1]=36;
                        break;
                    case 42:
                        selectedCase[1]=37;
                        break;
                    case 43:
                        selectedCase[1]=28;
                        break;
                    case 44:
                        selectedCase[1]=38;
                        break;
                }break;
            case DOWN:
                switch (selectedCase[1]) {
                    case 1:
                        selectedCase[0]=1;
                        selectedCase[1]=1;
                        break;
                    case 2:
                        selectedCase[1]=17;
                        break;
                    case 3:
                        selectedCase[0]=1;
                        selectedCase[1]=3;
                        break;
                    case 4:
                        selectedCase[0]=1;
                        selectedCase[1]=6;
                        break;
                    case 5:
                        selectedCase[1]=20;
                        break;
                    case 6:
                        selectedCase[0]=1;
                        selectedCase[1]=8;
                        break;
                    case 7:
                        selectedCase[1]=12;
                        break;
                    case 8:
                        selectedCase[1]=13;
                        break;
                    case 9:
                        selectedCase[1]=32;
                        break;
                    case 10:
                        selectedCase[1]=14;
                        break;
                    case 11:
                        selectedCase[1]=15;
                        break;
                    case 12:
                        selectedCase[1]=16;
                        break;
                    case 13:
                        selectedCase[1]=18;
                        break;
                    case 14:
                        selectedCase[1]=19;
                        break;
                    case 15:
                        selectedCase[1]=21;
                        break;
                    case 16:
                        selectedCase[1]=24;
                        break;
                    case 17:
                        selectedCase[0]=1;
                        selectedCase[1]=10;
                        break;
                    case 18:
                        selectedCase[1]=26;
                        break;
                    case 19:
                        selectedCase[1]=27;
                        break;
                    case 20:
                        selectedCase[0]=1;
                        selectedCase[1]=11;
                        break;
                    case 21:
                        selectedCase[1]=29;
                        break;
                    case 22:
                        selectedCase[1]=25;
                        break;
                    case 23:
                        selectedCase[1]=28;
                        break;
                    case 24:
                        selectedCase[0]=1;
                        selectedCase[1]=12;
                        break;
                    case 25:
                        selectedCase[1]=40;
                        break;
                    case 26:
                        selectedCase[0]=1;
                        selectedCase[1]=14;
                        break;
                    case 27:
                        selectedCase[0]=1;
                        selectedCase[1]=17;
                        break;
                    case 28:
                        selectedCase[1]=43;
                        break;
                    case 29:
                        selectedCase[0]=1;
                        selectedCase[1]=19;
                        break;
                    case 30:
                        selectedCase[1]=35;
                        break;
                    case 31:
                        selectedCase[1]=36;
                        break;
                    case 32:
                        selectedCase[1]=9;
                        break;
                    case 33:
                        selectedCase[1]=37;
                        break;
                    case 34:
                        selectedCase[1]=38;
                        break;
                    case 35:
                        selectedCase[1]=39;
                        break;
                    case 36:
                        selectedCase[1]=41;
                        break;
                    case 37:
                        selectedCase[1]=42;
                        break;
                    case 38:
                        selectedCase[1]=44;
                        break;
                    case 39:
                        selectedCase[1]=1;
                        break;
                    case 40:
                        selectedCase[1]=2;
                        break;
                    case 41:
                        selectedCase[1]=3;
                        break;
                    case 42:
                        selectedCase[1]=4;
                        break;
                    case 43:
                        selectedCase[1]=5;
                        break;
                    case 44:
                        selectedCase[1]=6;
                        break;
                }break;
            case LEFT:
                switch (selectedCase[1]) {
                    case 1:
                        selectedCase[1]=6;
                        break;
                    case 2:
                        selectedCase[0]=1;
                        selectedCase[1]=2;
                        break;
                    case 3:
                        selectedCase[1]=2;
                        break;
                    case 4:
                        selectedCase[1]=3;
                        break;
                    case 5:
                        selectedCase[0]=1;
                        selectedCase[1]=7;
                        break;
                    case 6:
                        selectedCase[1]=5;
                        break;
                    case 7:
                        selectedCase[1]=11;
                        break;
                    case 8:
                        selectedCase[1]=7;
                        break;
                    case 9:
                        selectedCase[0]=1;
                        selectedCase[1]=5;
                        break;
                    case 10:
                        selectedCase[1]=9;
                        break;
                    case 11:
                        selectedCase[1]=10;
                        break;
                    case 12:
                        selectedCase[1]=15;
                        break;
                    case 13:
                        selectedCase[1]=12;
                        break;
                    case 14:
                        selectedCase[1]=13;
                        break;
                    case 15:
                        selectedCase[1]=14;
                        break;
                    case 16:
                        selectedCase[1]=21;
                        break;
                    case 17:
                        selectedCase[0]=1;
                        selectedCase[1]=4;
                        break;
                    case 18:
                        selectedCase[1]=17;
                        break;
                    case 19:
                        selectedCase[1]=18;
                        break;
                    case 20:
                        selectedCase[0]=1;
                        selectedCase[1]=9;
                        break;
                    case 21:
                        selectedCase[1]=20;
                        break;
                    case 22:
                        selectedCase[1]=23;
                        break;
                    case 23:
                        selectedCase[1]=22;
                        break;
                    case 24:
                        selectedCase[1]=29;
                        break;
                    case 25:
                        selectedCase[0]=1;
                        selectedCase[1]=13;
                        break;
                    case 26:
                        selectedCase[1]=25;
                        break;
                    case 27:
                        selectedCase[1]=26;
                        break;
                    case 28:
                        selectedCase[0]=1;
                        selectedCase[1]=18;
                        break;
                    case 29:
                        selectedCase[1]=28;
                        break;
                    case 30:
                        selectedCase[1]=34;
                        break;
                    case 31:
                        selectedCase[1]=30;
                        break;
                    case 32:
                        selectedCase[0]=1;
                        selectedCase[1]=16;
                        break;
                    case 33:
                        selectedCase[1]=32;
                        break;
                    case 34:
                        selectedCase[1]=33;
                        break;
                    case 35:
                        selectedCase[1]=38;
                        break;
                    case 36:
                        selectedCase[1]=35;
                        break;
                    case 37:
                        selectedCase[1]=36;
                        break;
                    case 38:
                        selectedCase[1]=37;
                        break;
                    case 39:
                        selectedCase[1]=44;
                        break;
                    case 40:
                        selectedCase[0]=1;
                        selectedCase[1]=15;
                        break;
                    case 41:
                        selectedCase[1]=40;
                        break;
                    case 42:
                        selectedCase[1]=41;
                        break;
                    case 43:
                        selectedCase[0]=1;
                        selectedCase[1]=20;
                        break;
                    case 44:
                        selectedCase[1]=43;
                        break;
                }break;
            case RIGHT:
                switch (selectedCase[1]) {
                    case 1:
                        selectedCase[0]=1;
                        selectedCase[1]=2;
                        break;
                    case 2:
                        selectedCase[1]=3;
                        break;
                    case 3:
                        selectedCase[1]=4;
                        break;
                    case 4:
                        selectedCase[0]=1;
                        selectedCase[1]=7;
                        break;
                    case 5:
                        selectedCase[1]=6;
                        break;
                    case 6:
                        selectedCase[1]=1;
                        break;
                    case 7:
                        selectedCase[1]=8;
                        break;
                    case 8:
                        selectedCase[0]=1;
                        selectedCase[1]=5;
                        break;
                    case 9:
                        selectedCase[1]=10;
                        break;
                    case 10:
                        selectedCase[1]=11;
                        break;
                    case 11:
                        selectedCase[1]=7;
                        break;
                    case 12:
                        selectedCase[1]=13;
                        break;
                    case 13:
                        selectedCase[1]=14;
                        break;
                    case 14:
                        selectedCase[1]=15;
                        break;
                    case 15:
                        selectedCase[1]=12;
                        break;
                    case 16:
                        selectedCase[0]=1;
                        selectedCase[1]=4;
                        break;
                    case 17:
                        selectedCase[1]=18;
                        break;
                    case 18:
                        selectedCase[1]=19;
                        break;
                    case 19:
                        selectedCase[0]=1;
                        selectedCase[1]=9;
                        break;
                    case 20:
                        selectedCase[1]=21;
                        break;
                    case 21:
                        selectedCase[1]=16;
                        break;
                    case 22:
                        selectedCase[1]=23;
                        break;
                    case 23:
                        selectedCase[1]=22;
                        break;
                    case 24:
                        selectedCase[0]=1;
                        selectedCase[1]=13;
                        break;
                    case 25:
                        selectedCase[1]=26;
                        break;
                    case 26:
                        selectedCase[1]=27;
                        break;
                    case 27:
                        selectedCase[0]=1;
                        selectedCase[1]=18;
                        break;
                    case 28:
                        selectedCase[1]=29;
                        break;
                    case 29:
                        selectedCase[1]=24;
                        break;
                    case 30:
                        selectedCase[1]=31;
                        break;
                    case 31:
                        selectedCase[0]=1;
                        selectedCase[1]=16;
                        break;
                    case 32:
                        selectedCase[1]=33;
                        break;
                    case 33:
                        selectedCase[1]=34;
                        break;
                    case 34:
                        selectedCase[1]=30;
                        break;
                    case 35:
                        selectedCase[1]=36;
                        break;
                    case 36:
                        selectedCase[1]=37;
                        break;
                    case 37:
                        selectedCase[1]=38;
                        break;
                    case 38:
                        selectedCase[1]=35;
                        break;
                    case 39:
                        selectedCase[0]=1;
                        selectedCase[1]=15;
                        break;
                    case 40:
                        selectedCase[1]=41;
                        break;
                    case 41:
                        selectedCase[1]=42;
                        break;
                    case 42:
                        selectedCase[0]=1;
                        selectedCase[1]=20;
                        break;
                    case 43:
                        selectedCase[1]=44;
                        break;
                    case 44:
                        selectedCase[1]=39;
                        break;
                }break;
        }

    }
    else
    {
        switch (d) {
            case UP:
                switch (selectedCase[1]) {
                    case 1:
                        selectedCase[0]=0;
                        selectedCase[1]=1;
                        break;
                    case 2:
                        break;
                    case 3:
                        selectedCase[0]=0;
                        selectedCase[1]=3;
                        break;
                    case 4:
                        break;
                    case 5:
                        break;
                    case 6:
                        selectedCase[0]=0;
                        selectedCase[1]=4;
                        break;
                    case 7:
                        break;
                    case 8:
                        selectedCase[0]=0;
                        selectedCase[1]=6;
                        break;
                    case 9:
                        break;
                    case 10:
                        selectedCase[0]=0;
                        selectedCase[1]=17;
                        break;
                    case 11:
                        selectedCase[0]=0;
                        selectedCase[1]=20;
                        break;
                    case 12:
                        selectedCase[0]=0;
                        selectedCase[1]=24;
                        break;
                    case 13:
                        break;
                    case 14:
                        selectedCase[0]=0;
                        selectedCase[1]=26;
                        break;
                    case 15:
                        break;
                    case 16:
                        break;
                    case 17:
                        selectedCase[0]=0;
                        selectedCase[1]=27;
                        break;
                    case 18:
                        break;
                    case 19:
                        selectedCase[0]=0;
                        selectedCase[1]=29;
                        break;
                    case 20:
                        break;
                }break;
            case DOWN:
                switch (selectedCase[1]) {
                    case 1:
                        selectedCase[0]=0;
                        selectedCase[1]=7;
                        break;
                    case 2:
                        break;
                    case 3:
                        selectedCase[0]=0;
                        selectedCase[1]=8;
                        break;
                    case 4:
                        break;
                    case 5:
                        break;
                    case 6:
                        selectedCase[0]=0;
                        selectedCase[1]=10;
                        break;
                    case 7:
                        break;
                    case 8:
                        selectedCase[0]=0;
                        selectedCase[1]=11;
                        break;
                    case 9:
                        break;
                    case 10:
                        selectedCase[0]=0;
                        selectedCase[1]=22;
                        break;
                    case 11:
                        selectedCase[0]=0;
                        selectedCase[1]=23;
                        break;
                    case 12:
                        selectedCase[0]=0;
                        selectedCase[1]=30;
                        break;
                    case 13:
                        break;
                    case 14:
                        selectedCase[0]=0;
                        selectedCase[1]=31;
                        break;
                    case 15:
                        break;
                    case 16:
                        break;
                    case 17:
                        selectedCase[0]=0;
                        selectedCase[1]=33;
                        break;
                    case 18:
                        break;
                    case 19:
                        selectedCase[0]=0;
                        selectedCase[1]=34;
                        break;
                    case 20:
                        break;
                }break;
            case LEFT:
                switch (selectedCase[1]) {
                    case 1:
                        break;
                    case 2:
                        selectedCase[0]=0;
                        selectedCase[1]=1;
                        break;
                    case 3:
                        break;
                    case 4:
                        selectedCase[0]=0;
                        selectedCase[1]=16;
                        break;
                    case 5:
                        selectedCase[0]=0;
                        selectedCase[1]=8;
                        break;
                    case 6:
                        break;
                    case 7:
                        selectedCase[0]=0;
                        selectedCase[1]=4;
                        break;
                    case 8:
                        break;
                    case 9:
                        selectedCase[0]=0;
                        selectedCase[1]=19;
                        break;
                    case 10:
                        break;
                    case 11:
                        break;
                    case 12:
                        break;
                    case 13:
                        selectedCase[0]=0;
                        selectedCase[1]=24;
                        break;
                    case 14:
                        break;
                    case 15:
                        selectedCase[0]=0;
                        selectedCase[1]=39;
                        break;
                    case 16:
                        selectedCase[0]=0;
                        selectedCase[1]=31;
                        break;
                    case 17:
                        break;
                    case 18:
                        selectedCase[0]=0;
                        selectedCase[1]=27;
                        break;
                    case 19:
                        break;
                    case 20:
                        selectedCase[0]=0;
                        selectedCase[1]=42;
                        break;
                }break;
            case RIGHT:
                switch (selectedCase[1]) {
                    case 1:
                        break;
                    case 2:
                        selectedCase[0]=0;
                        selectedCase[1]=2;
                        break;
                    case 3:
                        break;
                    case 4:
                        selectedCase[0]=0;
                        selectedCase[1]=17;
                        break;
                    case 5:
                        selectedCase[0]=0;
                        selectedCase[1]=9;
                        break;
                    case 6:
                        break;
                    case 7:
                        selectedCase[0]=0;
                        selectedCase[1]=5;
                        break;
                    case 8:
                        break;
                    case 9:
                        selectedCase[0]=0;
                        selectedCase[1]=20;
                        break;
                    case 10:
                        break;
                    case 11:
                        break;
                    case 12:
                        break;
                    case 13:
                        selectedCase[0]=0;
                        selectedCase[1]=25;
                        break;
                    case 14:
                        break;
                    case 15:
                        selectedCase[0]=0;
                        selectedCase[1]=40;
                        break;
                    case 16:
                        selectedCase[0]=0;
                        selectedCase[1]=32;
                        break;
                    case 17:
                        break;
                    case 18:
                        selectedCase[0]=0;
                        selectedCase[1]=28;
                        break;
                    case 19:
                        break;
                    case 20:
                        selectedCase[0]=0;
                        selectedCase[1]=43;
                        break;
                }break;

        }

    }

}

const array<int, 2> &Grid::getSelectedCase() const {
    return selectedCase;
}

const array<int, 20> &Grid::getOp() const {
    return op;
}

void Grid::reset() {
    for (int &i : *this)
        i=100;
    for (int &i : op)
        i=PLUS;

}

