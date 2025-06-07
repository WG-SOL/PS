#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<pair<int, int>> bombs; 
bool used[10001]; 

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int s, t;
        cin >> s >> t;
        bombs.push_back({s, t});
    }

    sort(bombs.begin(), bombs.end(), [](auto a, auto b) {
        return a.first > b.first;
    });

    int answer = 0;
    for (auto temp : bombs) {
        for (int t = temp.second; t >= 1; t--) { //time
            if (!used[t]) {
                used[t] = true;
                answer += temp.first; // score
                break;
            }
        }
    }

    cout << answer << endl;
    return 0;
}
