#include <iostream>

using namespace std;

int n, t;
int l[200];
int r[200];
int f[200];

int main() {
    cin >> n >> t;

    for (int i = 0; i < n; i++) cin >> l[i];
    for (int i = 0; i < n; i++) cin >> r[i];
    for (int i = 0; i < n; i++) cin >> f[i];

    // Please write your code here.

    while(t--){
        int left_temp = l[n-1];
        int right_temp = r[n-1];
        int front_temp = f[n-1];

        for(int i=n-1; i>=1; i--) l[i] = l[i-1];

        for(int i=n-1; i>=1; i--) r[i] = r[i-1];
        r[0] = left_temp;

        for(int i=n-1; i>=1; i--) f[i] = f[i-1];
        l[0] = front_temp;

        f[0] = right_temp;

    }

    for (int i = 0; i < n; i++) cout << l[i] << " ";
    cout << "\n";
    for (int i = 0; i < n; i++) cout << r[i] << " ";
    cout << "\n";
    for (int i = 0; i < n; i++) cout << f[i] << " ";




    return 0;
}
