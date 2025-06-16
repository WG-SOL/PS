#include <iostream>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

int n;
int grid[101][101];
bool visited[101][101];
int dx[4] = {0, 1};
int dy[4] = {1, 0};


bool bfs(int min_val, int max_val) {
    if (grid[1][1] < min_val || grid[1][1] > max_val) return false;

    queue<pair<int, int>> q;
    q.push({1, 1});

    for (int i = 1; i <= n; ++i){
        fill(visited[i] + 1, visited[i] + n + 1, false);
    }

    visited[1][1] = true;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (x == n && y == n) return true;

        for (int i = 0; i < 2; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 1 || ny < 1 || nx > n || ny > n) continue;
            if (visited[nx][ny]) continue;

            int val = grid[nx][ny];
            if (val < min_val || val > max_val) continue;

            visited[nx][ny] = true;
            q.push({nx, ny});
        }
    }

    return false;
}

int main() {
    cin >> n;

    int max_num = 1;
    int min_num = INT_MAX;

    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
            cin >> grid[i][j];
            max_num = max(max_num, grid[i][j]);
            min_num = min(min_num, grid[i][j]);
        }
    }

    int result = INT_MAX;

    for (int min_val = min_num; min_val <= max_num; ++min_val) {
        int low = 0, high = max_num - min_val;

        while (low <= high) {
            int mid = (low + high) / 2;
            int max_val = min_val + mid;

            if (max_val > max_num) {
                high = mid - 1;
                continue;
            }

            if (bfs(min_val, max_val)) {
                result = min(result, mid);
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
    }

    cout << result;
    return 0;
}