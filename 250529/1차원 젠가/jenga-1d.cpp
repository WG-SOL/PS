#include <iostream>

using namespace std;

int n;
int blocks[101];
int s1, e1;
int s2, e2;
int temp[101];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> blocks[i];
    }
    cin >> s1 >> e1;
    cin >> s2 >> e2;

    int idx = 0;

    // 첫 번째 제거
    for (int i = 1; i <= n; i++) {
        if (i < s1 || i > e1) {
            temp[++idx] = blocks[i];
        }
    }

    // temp -> blocks로 복사
    for (int i = 1; i <= idx; i++) {
        blocks[i] = temp[i];
    }
    n = idx;

    // 두 번째 제거
    idx = 0;
    for (int i = 1; i <= n; i++) {
        if (i < s2 || i > e2) {
            temp[++idx] = blocks[i];
        }
    }

    // 출력
    cout << idx << "\n";
    for (int i = 1; i <= idx; i++) {
        cout << temp[i] << "\n";
    }

    return 0;
}