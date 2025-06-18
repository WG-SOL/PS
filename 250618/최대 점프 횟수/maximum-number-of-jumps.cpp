#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[1000];
int DP[1000];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        //도달불가 초기화
        DP[i] = -1;  
    }

    //제자리 안됨
    DP[0] = 0;  

    for (int i = 0; i < n; i++) {
        if (DP[i] == -1 || arr[i] == 0) {
            continue;
        } 
        for (int j = 1; j <= arr[i]; j++) {
            if (i + j < n) {
                DP[i + j] = max(DP[i + j], DP[i] + 1);
            }
        }
    }

    int result = *max_element(DP, DP + n);
    cout << result << endl;

    return 0;
}
