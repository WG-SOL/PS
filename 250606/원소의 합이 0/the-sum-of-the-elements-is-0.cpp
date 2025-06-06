#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int n;
int A[5000], B[5000], C[5000], D[5000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 0; i < n; i++) cin >> A[i];
    for (int i = 0; i < n; i++) cin >> B[i];
    for (int i = 0; i < n; i++) cin >> C[i];
    for (int i = 0; i < n; i++) cin >> D[i];

    unordered_map<int, int> sumAB;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            sumAB[A[i] + B[j]]++;
        }
    }

    long long count = 0;

    for (int k = 0; k < n; k++) {
        for (int l = 0; l < n; l++) {
            int target = -(C[k] + D[l]);
            if (sumAB.find(target) != sumAB.end()) {
                count += sumAB[target];
            }
        }
    }

    cout << count << "\n";
    
    return 0;
}