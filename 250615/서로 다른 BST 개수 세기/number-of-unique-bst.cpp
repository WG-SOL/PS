#include <iostream>

using namespace std;

int n;
long long DP[20];

int main() {
    cin >> n;

    DP[0] = 1;
    DP[1] = 1;
    DP[2] = 2;

    for(int i=3; i<=n; i++){
        for(int j=0; j<i; j++){
            DP[i] += DP[j] * DP[i-j-1];
        }
    }

    cout << DP[n];

    // Please write your code here.

    return 0;
}
