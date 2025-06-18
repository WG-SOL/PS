#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Job {
    long long s, e;
    int p;
};

bool cmp(const Job &a, const Job &b) {
    return a.e < b.e; 
}

int main() {
    int N;
    cin >> N;
    vector<Job> table(N);

    for (int i = 0; i < N; i++) {
        cin >> table[i].s >> table[i].e >> table[i].p;
    }

    sort(table.begin(), table.end(), cmp); 

    vector<long long> DP(N);
    long long ans = 0;

    for (int i = 0; i < N; i++) {
        DP[i] = table[i].p;

        for (int j = 0; j < i; j++) {
            if (table[j].e < table[i].s) {
                DP[i] = max(DP[i], DP[j] + table[i].p);
            }
        }

        ans = max(ans, DP[i]);
    }

    cout << ans;
    return 0;
}