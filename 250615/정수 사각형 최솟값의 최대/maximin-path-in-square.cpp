#include <iostream>
#include <algorithm>

using namespace std;

int n;
int grid[101][101];
int DP[101][101];


int main() {
    cin >> n;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> grid[i][j];
        }
    }
    
    //DP INIT
    DP[1][1] = grid[1][1];

    for(int i = 2; i <= n; i++){
        DP[i][1] = min(DP[i-1][1], grid[i][1]);
        DP[1][i] = min(DP[1][i-1], grid[1][i]);
    }

    for(int i = 2; i <= n; i++){
        for(int j = 2; j <= n; j++){
            DP[i][j] = min(max(DP[i-1][j], DP[i][j-1]), grid[i][j]);
        }
    }

    cout << DP[n][n];

    return 0;
}