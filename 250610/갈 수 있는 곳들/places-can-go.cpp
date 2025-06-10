#include <iostream>

using namespace std;

int n, k;
int grid[100][100];
int r[10000], c[10000];

int counter;
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
bool seen[100][100] = {false};

void dfs(int x,int y){
    if(seen[x][y] == true) return;
    seen[x][y] = true;
    counter++;

    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx<1 || ny<1 || nx>n || ny>n) continue;
        if(grid[nx][ny]==0 && seen[nx][ny] == false){
            dfs(nx,ny);
        }
    }
}



int main() {
    cin >> n >> k;

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++) {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < k; i++) {
        cin >> r[i] >> c[i];
        dfs(r[i],c[i]);
    }

    cout << counter;
    // Please write your code here.

    return 0;
}
