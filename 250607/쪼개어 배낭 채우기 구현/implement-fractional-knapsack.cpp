#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
int w[100000]; 
int v[100000]; 
vector<pair<double, int>> frac; // (무게당 가치, 인덱스)

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> w[i] >> v[i];
        frac.push_back({(double)v[i] / w[i], i});
    }

    sort(frac.begin(), frac.end(), [](const pair<double, int>& a, const pair<double, int>& b) {
        return a.first > b.first;
    });

    double ans = 0.0;

    for (int i = 0; i < N && M > 0; i++) {
        int idx = frac[i].second;

        if (w[idx] <= M) {
            ans += v[idx];
            M -= w[idx];
        } else {
            ans += v[idx] * ((double)M / w[idx]);
            M = 0;
        }
    }

    cout.precision(3);
    cout << fixed;
    cout << ans << endl;

    return 0;
}