#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int used[10001]; // 시간 슬롯 사용 여부
vector<pair<int, int>> v;

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int score, time;
        cin >> score >> time;
        v.push_back({score, time});
    }

    // 당신이 쓴 정렬 방식 유지: 제한시간 오름차순, 같으면 점수 높은 순
    sort(v.begin(), v.end(), [](auto a, auto b) {
        if (a.second == b.second) return a.first > b.first;
        return a.second < b.second;
    });

    int answer = 0;
    for (auto& bomb : v) {
        int score = bomb.first;
        int time = bomb.second;

        // 가능한 가장 늦은 시간에 해체되도록 시도
        for (int t = time; t >= 1; t--) {
            if (!used[t]) {
                used[t] = 1;
                answer += score;
                break;
            }
        }
    }

    cout << answer << endl;
    return 0;
}