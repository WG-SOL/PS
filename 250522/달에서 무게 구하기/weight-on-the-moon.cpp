#include <iostream>
using namespace std;

int main() {
    int weight = 13;
    double gravity = 0.165;

    cout << fixed;
    cout.precision(6);

    cout << weight << " * " << gravity << " = " << weight*gravity;
    return 0;
}