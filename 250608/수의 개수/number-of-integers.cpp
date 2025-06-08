#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int arr[100000];

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        auto it_s = lower_bound(arr,arr+n,x);
        auto it_e = upper_bound(arr,arr+n,x);
        if(*it_s == x && it_s != arr+n){
            cout << it_e - it_s << "\n";
        }
        else if(it_e == it_s){ //같으면 없음
            cout << 0 << "\n";
        }

    }

    // Please write your code here.

    return 0;
}
