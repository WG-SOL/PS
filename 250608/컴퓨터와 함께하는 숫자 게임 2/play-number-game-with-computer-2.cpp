#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

long long m;
long long a, b;

int main() {
    cin >> m; // [1,m] 정답
    cin >> a >> b; // a,...,b시 count 최대 최소 

    int min_value = INT_MAX;
    int max_value = 0;

    for (int target = a; target <= b; target++) {
        int L = 1, R = m;
        int count = 0;

        while (L <= R) {
            int mid = (L + R) / 2;
            count++;

            if (mid == target) {
                break;
            }
            else if (mid < target) {
                L = mid + 1;
            }
            else {
                R = mid - 1;
            }
        }

        min_value = min(min_value, count);
        max_value = max(max_value, count);
    }

    cout << min_value << " " << max_value << "\n";
    return 0;
}