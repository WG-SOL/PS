#include <iostream>
#include <algorithm>

using namespace std;

int n;
pair<int,int> lines[1000];
int DP[1000];

int main() {
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> lines[i].first >> lines[i].second;  // s,e;
    }

    sort(lines, lines + n); // s기준

    for(int i = 0; i < n; i++) {
        DP[i] = 1;  // 본인

        for(int j = 0; j < i; j++) {
            // i번째 선분을 골라놓고 앞에서부터 체크해 만들 수 있는 최대개수 
            if(lines[j].second < lines[i].first) {
                DP[i] = max(DP[i], DP[j] + 1);
            }
        }
    }

    cout << *max_element(DP,DP+n);

    return 0;
}