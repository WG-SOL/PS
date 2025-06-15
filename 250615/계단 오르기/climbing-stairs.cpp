#include <iostream>

using namespace std;

int n;
int DP[1001]; // 몇층 

int main() {
    cin >> n;

    //DP INIT
    DP[0] = 1;
    DP[2] = 1;
    DP[3]= 1;

    for(int i=4; i<=n; i++){
        DP[i] = DP[i-2] + DP[i-3];
    }
    
    cout << DP[n];

    // Please write your code here.

    return 0;
}