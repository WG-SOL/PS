#include <iostream>

using namespace std;

int n, t;
int u[200];
int d[200];

int main() {
    cin >> n >> t;

    for (int i = 0; i < n; i++) cin >> u[i];
    for (int i = 0; i < n; i++) cin >> d[i];

    // Please write your code here.
    while(t--){
        int temp = u[n-1];

        for(int i=n-1; i>=1; i--) u[i] = u[i-1];
        u[0] = d[n-1];

        for(int i=n-1; i>=1; i--) d[i] = d[i-1];
        d[0] = temp;
    }

    for (int i = 0; i < n; i++) cout << u[i] << " ";
    cout << "\n";
    for (int i = 0; i < n; i++) cout << d[i] << " ";


    return 0;
}
