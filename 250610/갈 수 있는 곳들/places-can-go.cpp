#include <iostream>
#include <queue>
using namespace std;

int n, k;
int grid[100][100];
int r[10000], c[10000];
bool seen[100][100];

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
int counter;

void bfs(int x, int y){
    queue<pair<int,int>> q;
    q.push({x,y});
    if(seen[x][y] == true) return;
    seen[x][y] = true;
    counter++;


    while(!q.empty()){
        pair<int,int> now = q.front();
        q.pop();
        int now_x = now.first;
        int now_y = now.second;

        for(int i=0; i<4; i++){
            int nx = now_x + dx[i];
            int ny = now_y + dy[i];

            if(nx<1 || ny<1 || nx>n || ny>n) continue;
            if(grid[nx][ny] == 0 && seen[nx][ny] == false){
                q.push({nx,ny});
                seen[nx][ny] = true;
                counter++;
            }
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
        bfs(r[i],c[i]);
    }

    cout << counter;
    // Please write your code here.

    return 0;
}
