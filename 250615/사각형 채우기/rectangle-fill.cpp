#include <iostream>

using namespace std;

int n;
int DP[1001];

int main() {
    cin >> n;

    // 2 by N을 1 by 2 or 2 by 1 크기로 채우기.

    DP[1] = 1; // 2 by 1
    DP[2] = 2; // 2 by 1 2개 , 1 by 2 2개

    for(int i=3; i<=n; i++){
        DP[i] = ((DP[i-1]%10007) + (DP[i-2]%10007)) % 10007;
    }

    cout << DP[n];

    // Please write your code here.

    return 0;
}
