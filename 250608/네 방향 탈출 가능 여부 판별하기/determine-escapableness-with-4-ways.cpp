#include <iostream>
#include <queue>

using namespace std;

int n, m;
int a[100][100];
bool seen[100][100]={false};

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

bool bfs(int x, int y){
    queue<pair<int,int>> q;
    q.push({x,y});
    seen[x][y] = true;

    while(!q.empty()){
        auto now = q.front();
        q.pop();
        int now_x = now.first;
        int now_y = now.second;

        if(now_x == n-1 && now_y == m-1) return true;

        for(int i=0; i<4; i++){
            int nx = now_x + dx[i];
            int ny = now_y + dy[i];

            if(nx<0 || ny <0 || nx>=n || ny>=m) continue;
            if(seen[nx][ny]) continue;
            if(a[nx][ny] == 1){
                seen[nx][ny] = true;
                q.push({nx,ny});
            }
        }
    }

    return false;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    if(bfs(0,0)) cout << 1;
    else cout << 0;
    
    // Please write your code here.

    return 0;
}
