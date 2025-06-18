#include <iostream>
using namespace std;

int N;
long long s[1001], e[1001];
int p[1001];
long long DP[1001];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> s[i] >> e[i] >> p[i];
    }

    long long ans = 0;
    for (int i = 0; i < N; i++) {
        DP[i] = p[i]; 

        for (int j = 0; j < i; j++) {
            if (e[j] < s[i]) { 
                DP[i] = max(DP[i], DP[j] + p[i]);
            }
        }

        if (i > 0)
            DP[i] = max(DP[i], DP[i - 1]);

        ans = max(ans, DP[i]);
    }

    cout << ans;
    return 0;
}