#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> blocks(101);
int s1, e1;
int s2, e2;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> blocks[i];
    }
    cin >> s1 >> e1;
    cin >> s2 >> e2;

    // 첫 번째 제거
    for (int i = s1; i <= e1; i++) {
        blocks[i] = 0;
    }

    // 첫 번째 제거 후 필터링
    vector<int> temp;
    for (int i = 1; i <= n; i++) {
        if (blocks[i] != 0) temp.push_back(blocks[i]);
    }

    // temp -> blocks (1-indexed 유지 위해 앞에 0 삽입)
    blocks = {0}; // 0번은 사용 안함
    for (int val : temp) {
        blocks.push_back(val);
    }

    // 두 번째 제거
    for (int i = s2; i <= e2 && i < blocks.size(); i++) {
        blocks[i] = 0;
    }

    // 다시 필터링
    temp.clear();
    for (int i = 1; i < blocks.size(); i++) {
        if (blocks[i] != 0) temp.push_back(blocks[i]);
    }

    // 출력
    cout << temp.size() << "\n";
    for (int val : temp) {
        cout << val << "\n";
    }

    return 0;
}