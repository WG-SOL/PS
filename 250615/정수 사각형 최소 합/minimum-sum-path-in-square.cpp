#include <iostream>
#include <algorithm>

using namespace std;

int n;
int grid[101][101];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> grid[i][j];
        }
    }

    //(1,N) 시작해 왼쪽 or 밑으로만 이동해 (N,1)이동시 최소합

    for(int i=n-1; i>=1; i--){
        grid[1][i] += grid[1][i+1];
    }
    for(int i=2; i<=n; i++){
        grid[i][n] += grid[i-1][n];
    }

    for(int i=2; i<=n; i++){
        for(int j=n-1; j>=1; j--){
            grid[i][j] += min(grid[i][j+1], grid[i-1][j]);
        }
    }

    cout << grid[n][1];

    // Please write your code here.

    return 0;
}
