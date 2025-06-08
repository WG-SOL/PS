#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int arr[100000];
int query[100000];

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> query[i];
        auto it = lower_bound(arr,arr+n,query[i]);
        if(it != arr+n && *it == query[i]){
            cout << (it-arr+1) << "\n";
        }
        else{
            cout << -1 << "\n";
        }
    }

    // Please write your code here.

    return 0;
}
