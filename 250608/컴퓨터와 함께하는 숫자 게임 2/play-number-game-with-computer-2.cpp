#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

long long m;
long long a, b;

int main() {
    cin >> m; // [1,m] 정답
    cin >> a >> b; // a,...,b시 count 최대 최소 

    long long min_value = LLONG_MAX;
    long long max_value = 0;

    for (long long target = a; target <= b; target++) {
        long long L = 1, R = m;
        long long count = 0;

        while (L <= R) {
            long long mid = (L + R) / 2;
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