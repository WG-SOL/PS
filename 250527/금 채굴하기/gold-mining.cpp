#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int grid[20][20];

int GetArea(int k) {
    return k * k + (k + 1) * (k + 1);
}

// 마름모 범위로 금의 개수를 셈
int GetNumOfGold(int row, int col, int k) {
    int num_of_gold = 0;
    for (int d = 0; d <= k; d++) {
        for (int dx = -d; dx <= d; dx++) {
            int dy = d - abs(dx);

            // (row+dx, col+dy)
            int nx1 = row + dx;
            int ny1 = col + dy;
            if (nx1 >= 0 && nx1 < n && ny1 >= 0 && ny1 < n)
                num_of_gold += grid[nx1][ny1];

            // (row+dx, col-dy) (dy != 0일 때만 중복 방지)
            if (dy != 0) {
                int ny2 = col - dy;
                if (nx1 >= 0 && nx1 < n && ny2 >= 0 && ny2 < n)
                    num_of_gold += grid[nx1][ny2];
            }
        }
    }
    return num_of_gold;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];

    int max_gold = 0;
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            for (int k = 0; k <= 2 * (n - 1); k++) {
                int num_of_gold = GetNumOfGold(row, col, k);
                if (num_of_gold * m >= GetArea(k))
                    max_gold = max(max_gold, num_of_gold);
            }
        }
    }

    cout << max_gold;
}