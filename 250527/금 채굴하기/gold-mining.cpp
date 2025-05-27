#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int n, m;
int grid[20][20];

int cost(int k) {
    return k * k + (k + 1) * (k + 1);
}

int gold_count(int x, int y, int k) {
    int num_of_gold = 0;
    for (int d = 0; d <= k; d++) {
        for (int dx = -d; dx <= d; dx++) {
            int dy = d - abs(dx);

            
            int nx1 = x + dx; // 위쪽, 오른쪽
            int ny1 = y + dy;
            if (nx1 >= 0 && nx1 < n && ny1 >= 0 && ny1 < n)
                num_of_gold += grid[nx1][ny1];

            
            if (dy != 0) { // 왼쪽, 오른쪽
                int ny2 = y - dy;
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
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            for (int k = 0; k <= 2 * (n - 1); k++) {
                int num_of_gold = gold_count(x, y, k);
                if (num_of_gold * m >= cost(k))
                    max_gold = max(max_gold, num_of_gold);
            }
        }
    }

    cout << max_gold;
}