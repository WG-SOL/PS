#include <iostream>

using namespace std;

int n, m;
int A[100];
int DP[10001];

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    //DP INIT
    DP[0]=0;
    for(int i=1; i<=m; i++){
        DP[i] = 101;
    }

    for(int i=0; i<n; i++){
        for(int j=m; j>=0; j--){
            if(j >= A[i]){
                DP[j] = min(DP[j], DP[j-A[i]]+1);
            }
        }
    }

    int min_len = DP[m];

    if(min_len == 101){
        cout << -1;
        return 0;
    }
    else{
        cout << min_len;
    }

    // Please write your code here.

    return 0;
}
