#include <iostream>

using namespace std;

int n;
long long DP[1001];
const int MOD = 1e9 + 7;

int main() {
    cin >> n;

    DP[0] = 1;
    DP[1] = 1;

    for(int i=2; i<=n; i++){
        DP[i] = (DP[i-1] + DP[i-2] *2) % MOD;
    }

    cout << DP[n];

    // Please write your code here.

    return 0;
}
