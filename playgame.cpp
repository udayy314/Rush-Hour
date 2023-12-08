// Name:       Golam Mostafa Uday
// Student ID: 1155183982
// Email:      1155183982@link.cuhk.edu.hk

#include <iostream>
#include <string>
#include "RushHour.h"
using namespace std;

int main() {
    string g0,g1,g2,g3,g4,g5;
    cout <<"Enter initial grid: ";
    cin >> g0>> g1 >> g2 >> g3 >> g4 >> g5;
    const string g[] = {g0,g1,g2,g3,g4,g5};
    RushHour Game(g);
    Game.print();

    int car,step;
    cout << "Move a car: "; //initialize game//
    cin >> car >> step;
    int movestate = Game.moveCar(car,step);
    while (Game.isSolved() == false) { //before next prompt to move, checks if game is over
        if (movestate == 1) { //error type 1
            cout << "Invalid car or step! Try again." << endl;
            cout << "Move a car: ";
            cin >> car >> step;
            movestate = Game.moveCar(car,step);
        }
        else if (movestate == 2) { //error type 2
            cout << "Hit! Try again." << endl;
            cout << "Move a car: ";
            cin >> car >> step;
            movestate = Game.moveCar(car,step);
        }
        else if (movestate == 0) { //no error
            Game.print();
            cout << "Move a car: ";
            cin >> car >> step;
            movestate = Game.moveCar(car, step);
            if (Game.getTotalSteps() >= 100) { //out of moves
                Game.print();
                cout << "Oops! You could not solve in 100 steps.";
                return 0;
            }
        }
    }
    Game.print();
    cout << "Congrats! You finished in " << Game.getTotalSteps() << " steps.";
    return 0;
}
