#include <iostream>

using namespace std;

int n, m;
int grid[100][100];
bool seen[100][100];

int dx[] = {1,0};
int dy[] = {0,1}; //우 하 
bool flag = false;

void dfs(int x, int y){
    seen[x][y] = true;
    if(x == n-1 && y == m-1) flag = true;
    for(int i=0; i<2; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx<0 || ny<0 || nx>=n || ny>=m) continue;
        if(seen[nx][ny]) continue;
        if(grid[nx][ny] ==1){
            dfs(nx,ny);
        }
    }

}


int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    dfs(0,0);
    if(flag) cout << 1;
    else cout << 0;

    // Please write your code here.

    return 0;
}
