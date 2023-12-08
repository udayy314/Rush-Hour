// Name:       Golam Mostafa Uday
// Student ID: 1155183982
// Email:      1155183982@link.cuhk.edu.hk

#include <string>
using namespace std;

class RushHour {
public:
    RushHour(const string g[]);
    bool locateCar(int car, int &row, int &col);
    int moveCar(int car, int step);
    bool isSolved();
    int getTotalSteps();
    void print();
private:
    string grid[8];
    int totalSteps;
};
