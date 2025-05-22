#include <iostream>
#include <algorithm>

using namespace std;

int a, b, c;

int find_min(int a, int b, int c){
    int temp=0;
    temp = min(temp,a);
    temp = min(temp,b);
    temp = min(temp,c);

    return temp;
}



int main() {
    cin >> a >> b >> c;

    cout << find_min(a,b,c);
    // Please write your code here.

    return 0;
}