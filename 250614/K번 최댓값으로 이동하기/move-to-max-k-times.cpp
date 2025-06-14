#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

#define NOT_EXISTS make_pair(-1, -1)

int n, k;
int grid[100][100];
bool visited[100][100];
pair<int, int> curr_cell;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};


bool bfs() {
    queue<pair<int, int> > q;
    pair<int, int> best = NOT_EXISTS;

    int sx = curr_cell.first;
    int sy = curr_cell.second;
    int curr_val = grid[sx][sy];

    // visited 초기화
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            visited[i][j] = false;

    visited[sx][sy] = true;
    q.push(make_pair(sx, sy));

    while (!q.empty()) {
        pair<int, int> now = q.front(); q.pop();
        int x = now.first;
        int y = now.second;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            
            if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if (visited[nx][ny] || grid[nx][ny] >= curr_val) continue;

            visited[nx][ny] = true;
            q.push(make_pair(nx, ny));

            pair<int, int> next = make_pair(nx, ny);
            if (best == NOT_EXISTS ||
                make_tuple(grid[nx][ny], -nx, -ny) > make_tuple(grid[best.first][best.second], -best.first, -best.second))
                best = next;
        }
    }

    if (best == NOT_EXISTS)
        return false;

    curr_cell = best;
    return true;
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];

    int r, c;
    cin >> r >> c;
    curr_cell = make_pair(r - 1, c - 1);

    while (k--) {
        if (!bfs())
            break;
    }

    cout << curr_cell.first + 1 << " " << curr_cell.second + 1 << '\n';
    return 0;
}