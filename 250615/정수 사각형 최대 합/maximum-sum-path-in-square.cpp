#include <iostream>
#include <algorithm>

using namespace std;

int n;
long long grid[101][101];

int main() {
    cin >> n;
   
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> grid[i][j];
        }
    }

 
    for(int i = 2; i <= n; i++){
        grid[1][i] += grid[1][i-1];
        grid[i][1] += grid[i-1][1];
    }


    for (int i = 2; i <= n; i++) {
        for (int j = 2; j <= n; j++) {
            grid[i][j] += max(grid[i-1][j], grid[i][j-1]);
        }
    }

    cout << grid[n][n];

    return 0;
}
