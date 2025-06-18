#include <iostream>
#include <cstring>
#include <climits>
using namespace std;

int N, M;
int coin[101];
int DP[10001];

int main() {
    cin >> N >> M; //동전수, PAY 액수

    for (int i = 1; i <= N; i++) {
        cin >> coin[i];
    }

    for (int i = 1; i <= M; i++) {
        DP[i] = INT_MAX;
    }
    DP[0] = 0;

    for(int i=1; i<=M; i++){
        for(int j=1; j<=N; j++){
            if(i >= coin[j]){
                DP[i] = min(DP[i], DP[i-coin[j]]+1);
            }
        }
    }

    if(DP[M] == INT_MAX){
        cout << -1;
    }
    else{
        cout << DP[M];
    }

    // Please write your code here.

    return 0;
}
