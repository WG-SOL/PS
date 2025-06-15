#include <iostream>

using namespace std;
long long DP[1001];
const int MOD = 1e9 + 7;

int n;

int main() {
    cin >> n;
    // 2 BY N을 채우는데
    // 1 by 2 or 2 by 1에 1 by 1 사각형이 추가됨.
    DP[0] = 1;
    DP[1] = 2;
    DP[2] = 7;

    for (int i = 3; i <= n; ++i) {
    DP[i] = (DP[i - 1] * 2 % MOD + DP[i - 2] * 3 % MOD) % MOD;

    for (int j = 3; j <= i; ++j) {
        DP[i] = (DP[i] + DP[i - j] * 2 % MOD) % MOD;
    }
}

    cout << DP[n];



    // Please write your code here.

    return 0;
}
