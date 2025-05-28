#include <iostream>

using namespace std;

int N;
long long DP[46];

int main() {
    cin >> N;
    DP[1]=1;
    DP[2]=1;

    for(int i=3; i<46; i++){
        DP[i] = DP[i-1]+DP[i-2];
    }

    cout << DP[N];
    // Please write your code here.
    return 0;
}
