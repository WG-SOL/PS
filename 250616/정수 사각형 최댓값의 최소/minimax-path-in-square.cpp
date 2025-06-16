#include <iostream>

using namespace std;

int n;
int grid[101][101];
int DP[101][101];

int main() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> grid[i][j];
        }
    }

    DP[1][1] = grid[1][1];
    for(int i=2; i<=n; i++){
        DP[1][i] = max(DP[1][i-1], grid[1][i]);
        DP[i][1] = max(DP[i-1][1], grid[1][i]); 
    }

    
    for (int i = 2; i <= n; i++) {
        for (int j = 2; j <= n; j++) {
            DP[i][j] = max(min(DP[i][j-1],DP[i-1][j]), grid[i][j]);
        }
    }
 
    cout << DP[n][n];
    

    return 0;
}
