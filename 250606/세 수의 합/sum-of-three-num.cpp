#include <iostream>
#include <unordered_map>

using namespace std;

#define MAX_N 1000

// 변수 선언
int n, k;
int arr[MAX_N];
unordered_map<int, int> freq;

int main() {
    cin >> n >> k;

    int ans = 0;

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        freq[arr[i]]++;
    }

    /
    for(int i = 0; i < n; i++) {
        
        freq[arr[i]]--; // 중복 제거

        for(int j = 0; j < i; j++) { // 한개 더 선택
            if(freq.count(k - arr[i] - arr[j]))
                ans += freq[k - arr[i] - arr[j]];
        }
    }

    cout << ans;

    return 0;
}