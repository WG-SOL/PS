#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int grid[200][200];
int max_value = 0;

void neon(int x, int y) {
    // 중심 기준 3칸의 L자(ㄱ, ㄴ, 반대 ㄱ, 반대 ㄴ)
    // ㄱ자: (x, y), (x, y-1), (x+1, y)
    if (y - 1 >= 0 && x + 1 < n)
        max_value = max(max_value, grid[x][y] + grid[x][y - 1] + grid[x + 1][y]);

    // ㄴ자: (x, y), (x-1, y), (x, y+1)
    if (x - 1 >= 0 && y + 1 < m)
        max_value = max(max_value, grid[x][y] + grid[x - 1][y] + grid[x][y + 1]);

    // 반대 ㄱ: (x, y), (x, y+1), (x+1, y)
    if (y + 1 < m && x + 1 < n)
        max_value = max(max_value, grid[x][y] + grid[x][y + 1] + grid[x + 1][y]);

    // 반대 ㄴ: (x, y), (x-1, y), (x, y-1)
    if (x - 1 >= 0 && y - 1 >= 0)
        max_value = max(max_value, grid[x][y] + grid[x - 1][y] + grid[x][y - 1]);
}

void space_bar(int x, int y) {
    // 중심 기준 3칸의 일자형 (ㅡ, ㅣ)
    // 가로 (ㅡ): (x, y-1), (x, y), (x, y+1)
    if (y - 1 >= 0 && y + 1 < m)
        max_value = max(max_value, grid[x][y - 1] + grid[x][y] + grid[x][y + 1]);

    // 세로 (ㅣ): (x-1, y), (x, y), (x+1, y)
    if (x - 1 >= 0 && x + 1 < n)
        max_value = max(max_value, grid[x - 1][y] + grid[x][y] + grid[x + 1][y]);
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            neon(i, j);
            space_bar(i, j);
        }

    cout << max_value;
    return 0;
}