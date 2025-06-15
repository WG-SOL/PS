#include <iostream>

using namespace std;
long long DP[1001];

int n;

int main() {
    cin >> n;
    // 2 BY N을 채우는데
    // 1 by 2 or 2 by 1에 1 by 1 사각형이 추가됨.
    DP[0] = 1;
    DP[1] = 2;
    DP[2] = 7;

    for (int i = 3; i <= n; i++) {
        DP[i] = ((DP[i - 1]%1000000007) * 2 + (DP[i - 2]%1000000007) * 3) % 1000000007;

        for (int j = 3; j <= i; j++) {
            DP[i] = ((DP[i] % 1000000007) + (DP[i - j] % 1000000007))%1000000007 * 2;
        }
    }

    cout << DP[n];



    // Please write your code here.

    return 0;
}
