#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_N = 1000;

int N;
int M[MAX_N];
int DP[MAX_N];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> M[i];
        DP[i] = 1;
    }

    for(int i=1; i<N; i++){
        for(int j=0; j<i; j++){
            if(M[j] > M[i]){
                DP[i] = max(DP[j]+1, DP[i]);
            }
        }
    }

    cout << *max_element(DP,DP+N);

    // Please write your code here.

    return 0;
}
