#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int grid[51][51];
int DP[51][51];

int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= m; j++) 
            cin >> grid[i][j];

    
    DP[1][1] = 1;

    // 전체 탐색
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {

            for (int x = i + 1; x <= n; x++) {
                for (int y = j + 1; y <= m; y++) {
                    if (grid[x][y] > grid[i][j]) {
                        DP[x][y] = max(DP[x][y], DP[i][j] + 1);
                    }
                }
            }
        }
    }

    
    int ans = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            ans = max(ans, DP[i][j]);
        }
    }
    cout << ans;
    return 0;
}