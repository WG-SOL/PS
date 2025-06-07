#include <iostream>
#include <algorithm>
using namespace std;

int n;
int a[100000];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int max_sum = a[0];  
    int current_sum = a[0];  // 부분합

    for (int i = 1; i < n; i++) {
        current_sum = max(a[i], current_sum + a[i]); 
        max_sum = max(max_sum, current_sum);         
    }

    cout << max_sum;

    return 0;
}