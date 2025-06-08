#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int arr[100000];

int main() {
    cin >> n >> m; //원소, query

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        auto it = lower_bound(arr, arr + n, x);
        if (it != arr + n && *it == x) {
             cout << (it - arr + 1) << "\n";  
        } 
        else {
            cout << -1 << "\n";
        }
    }

    // Please write your code here.

    return 0;
}
