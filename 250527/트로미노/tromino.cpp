#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int grid[200][200];
int max_value = 0;

// 6가지 트로미노 형태만 검사
void check(int x, int y) {
    // 블록 좌표 상대 위치
    // ㄱ, ㄴ, 반ㄱ, 반ㄴ, ㅡ, ㅣ
    int dx[6][2] = {
        {0, 1}, { -1, 0 }, { 1, 0 }, { 0, -1 }, {0, 1}, {-1, 1}
    };
    int dy[6][2] = {
        {-1, 0}, {0, 1}, {0, 1}, { -1, 0 }, {-1, 1}, {0, 0}
    };

    // 각각의 형태 적용
    for (int k = 0; k < 6; k++) {
        int sum = grid[x][y];
        bool valid = true;

        for (int i = 0; i < 2; i++) {
            int nx = x + dx[k][i];
            int ny = y + dy[k][i];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m) {
                valid = false;
                break;
            }
            sum += grid[nx][ny];
        }

        if (valid)
            max_value = max(max_value, sum);
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            check(i, j);

    cout << max_value;
    return 0;
}