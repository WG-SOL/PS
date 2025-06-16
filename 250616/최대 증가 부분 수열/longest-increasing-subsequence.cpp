#include <iostream>
#include <algorithm>

using namespace std;

int N;
int M[1000];
int DP[1000];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> M[i];
        DP[i] = 1;
    }

    for(int i=1; i<N; i++){
        for(int j=0; j<i; j++){
            if(M[j] < M[i]){
                DP[i] = max(DP[j]+1, DP[i]);
            }
        }
    }

    cout << *max_element(DP, DP+N);

    // Please write your code here.

    return 0;
}
