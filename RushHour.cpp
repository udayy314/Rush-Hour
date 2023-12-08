// Name:       Golam Mostafa Uday
// Student ID: 1155183982
// Email:      1155183982@link.cuhk.edu.hk

#include <iostream>
#include <string>
#include "RushHour.h"
using namespace std;

RushHour::RushHour(const string g[]) {
    totalSteps = 0;
    grid[0] = "########";
    grid[7] = "########";
    for (int i=1;i<=6;i++)
        grid[i] = g[i-1];
}
//finds location of car (row,col) if it exists in grid, returns false otherwise.
bool RushHour::locateCar(int car, int &row, int &col) {
    for (int i=1;i<=6;i++) {
        for (int j=1;j<=6;j++) {
            if (grid[i].at(j) == to_string(car)[0]) {
                row = i;
                col = j;
                return true;
            }
        }
    }
    return false;

}

//checks move validity (returns 1,2 for two different types of errors),
//updates grid by moving car according to valid move,
//updates totalSteps,
//returns 0 after valid move.
int RushHour::moveCar(int car, int step) {
    int row,col,moveError = 0;

    if (step == 0 || locateCar(car,row,col) == false) //row and col already updated here
        moveError = 1;
    else {
        //Time to check move validity oh so fun i love csci1540!!!
        int length;
        if (grid[row].at(col) == grid[row].at(col + 1)) { //then horizontal car
            if (grid[row].at(col) == grid[row].at(col + 2))
                length = 3;
            else length = 2;

            if (step > 0) {
                for (int i = 0; i <= step - 1; i++)
                    if ((col+length+i > 7) || (grid[row].at(col+length+i) != '.')) { //ie a tile is within bounds and non-empty//
                        moveError = 2;
                        break;
                    }
                if (moveError != 2) {
                    for (int i=0;i<=step-1;i++)
                        grid[row].at(col+i) = '.';
                    for (int i=0;i<=length-1;i++)
                        grid[row].at(col+step+i) = to_string(car)[0];
                    totalSteps += step; //since positive//
                }
            }
            if (step < 0) {
                for (int i = 1; i <= -step; i++)
                    if ((col-i<0) || (grid[row].at(col-i) != '.'))
                        moveError = 2;
                if (moveError != 2) {
                    for (int i=1;i<=-step;i++)
                        grid[row].at(col+length-i) = '.';
                    for (int i=0;i<=length-1;i++)
                        grid[row].at(col+step+i) = to_string(car)[0];
                    totalSteps += (-step); //since negative//
                }
            }
        }

        else { //then vertical car//
            if (grid[row].at(col) == grid[row + 2].at(col))
                length = 3;
            else length = 2;

            if (step > 0) {
                for (int i = 0; i <= step - 1; i++)
                    if ((row+length+i > 7) || (grid[row+length+i].at(col) != '.'))
                        moveError = 2;
                if (moveError != 2) {
                    for (int i=0;i<=step-1;i++)
                        grid[row+i].at(col) = '.';
                    for (int i=0;i<=length-1;i++)
                        grid[row+step+i].at(col) = to_string(car)[0];
                    totalSteps += step;
                }
            }
            if (step < 0) {
                for (int i = 1; i <= -step; i++)
                    if ((row-i<0) || (grid[row-i].at(col) != '.'))
                        moveError = 2;
                if (moveError != 2) {
                    for (int i=1;i<=-step;i++)
                        grid[row+length-i].at(col) = '.';
                    for (int i=0;i<=length-1;i++)
                        grid[row+step+i].at(col) = to_string(car)[0];
                    totalSteps += (-step);
                }
            }
        }
    }
return moveError;
}

//checks if game complete.
bool RushHour::isSolved() {
    bool solved;
    if (grid[3].at(7) == '0')
        solved = true;
    else solved = false;
    return solved;
}

//invoke this to access total steps outside of class instead of totalSteps, since thats private.
int RushHour::getTotalSteps() {
    return totalSteps;
}

//prints grid.
void RushHour::print() {
    for (int i=0;i<=7;i++)
        cout << grid[i] << endl;
    cout << "Steps: " << totalSteps << endl; //uhh//
}
