#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int n;

long long grid[501][501];
long long DP[501][501];

int dx[]={-1,1,0,0};
int dy[] = {0,0,1,-1};


long long dfs(long long x, long long y){
    if(DP[x][y] != -1) return DP[x][y];
    long long max_len=1;

    for(int i=0; i<4; i++){
        int nx = x+dx[i];
        int ny = y+dy[i];

        if(nx<1 || ny < 1 || nx>n || ny >n) continue;
        if(grid[nx][ny] > grid[x][y]){
            max_len = max(max_len,dfs(nx,ny)+1);
        }
   }

    DP[x][y] = max_len;
    return max_len;
}
    

int main() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> grid[i][j];
        }
    }

    memset(DP, -1, sizeof(DP));

    long long result=0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
                result = max(result,dfs(i,j));
        }
    }

    cout << result;

    return 0;
}