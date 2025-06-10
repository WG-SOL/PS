#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int grid[50][50];
bool seen[50][50];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};

int max_value = 0;
int ans = 0;

void dfs(int x, int y, int rain) {
    seen[x][y] = true;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
        if (!seen[nx][ny] && grid[nx][ny] > rain) {
            dfs(nx, ny, rain);
        }
    }
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++){
            cin >> grid[i][j];
        }

    for (int rain = 1; rain <= 100; rain++) {
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                seen[i][j] = false;

        int area = 0;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (grid[i][j] > rain && !seen[i][j]) {
                    dfs(i, j, rain);
                    area++;
                }
            }
        }

        if (area > max_value) {
            max_value = area;
            ans = rain;
        }
    }

    cout << ans << " " << max_value;
    return 0;
}