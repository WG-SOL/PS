#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

#define NOT_EXISTS make_pair(-1, -1)

int n, k;
int grid[101][101];
bool visited[101][101];

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};


pair<int, int> bfs(int x, int y) {
    queue<pair<int, int> > q;
    pair<int, int> best = NOT_EXISTS;

    
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            visited[i][j] = false;
        }
    }

    visited[x][y] = true;
    q.push(make_pair(x, y));
    int curr_val = grid[x][y];

    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if (visited[nx][ny] || grid[nx][ny] >= curr_val) continue;

            visited[nx][ny] = true;
            q.push(make_pair(nx, ny));

            // best 업데이트
            if (best == NOT_EXISTS ||
                make_tuple(grid[nx][ny], -nx, -ny) >
                make_tuple(grid[best.first][best.second], -best.first, -best.second)) {
                best = make_pair(nx, ny);
            }
        }
    }

    if (best == NOT_EXISTS) return make_pair(x, y); //(-1,-1)

    return best;
}

int main() {
    cin >> n >> k;

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> grid[i][j];
        }
    }

    int r, c;
    cin >> r >> c;

    for (int i = 0; i < k; i++) {
        pair<int, int> next = bfs(r, c);
        if (next.first == r && next.second == c)
            break; 
        r = next.first;
        c = next.second;
    }

    cout << r << " " << c;
    return 0;
}
