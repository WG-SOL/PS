#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int points[100000];
int start[100000], end_p[100000];

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> points[i];
    }

    sort(points,points+n);

    for (int i = 0; i < m; i++) {
        cin >> start[i] >> end_p[i];

        auto lower = lower_bound(points, points + n, start[i]);
        auto upper = upper_bound(points, points + n, end_p[i]);
        int count = upper - lower;
        cout << count << "\n";
    }

    return 0;
}
