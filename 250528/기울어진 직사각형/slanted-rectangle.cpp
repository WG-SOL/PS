#include <iostream>
#include <algorithm>

using namespace std;

int n;
int grid[20][20];
int max_value = 0;

void find(int x, int y, int a, int b) {
    int sum = 0;
    int cx = x;
    int cy = y;

    // 1. ↘ 방향 a칸
    for (int i = 0; i < a; i++) {
        cx += 1;
        cy += 1;
        if (cx < 0 || cy < 0 || cx >= n || cy >= n) return;
        sum += grid[cx][cy];
    }

    // 2. ↙ 방향 b칸
    for (int i = 0; i < b; i++) {
        cx += 1;
        cy -= 1;
        if (cx < 0 || cy < 0 || cx >= n || cy >= n) return;
        sum += grid[cx][cy];
    }

    // 3. ↖ 방향 a칸
    for (int i = 0; i < a; i++) {
        cx -= 1;
        cy -= 1;
        if (cx < 0 || cy < 0 || cx >= n || cy >= n) return;
        sum += grid[cx][cy];
    }

    // 4. ↗ 방향 b칸
    for (int i = 0; i < b; i++) {
        cx -= 1;
        cy += 1;
        if (cx < 0 || cy < 0 || cx >= n || cy >= n) return;
        sum += grid[cx][cy];
    }

    max_value = max(max_value, sum);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++) 
            cin >> grid[i][j];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int a = 1; a < n; a++) {
                for (int b = 1; b < n; b++) {
                    find(i, j, a, b);
                }
            }
        }
    }

    cout << max_value;
    return 0;
}