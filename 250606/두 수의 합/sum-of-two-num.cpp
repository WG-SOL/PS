#include <iostream>
#include <unordered_map>
using namespace std;

int n, k;
int arr[100000];

int main() {
    cin >> n >> k;

    unordered_map<int, int> freq;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        freq[arr[i]]++;
    }

    int result = 0;

    for (pair<int,int> temp : freq) {
        int y = k - temp.first;
        if (freq.count(y)) {
            if (temp.first == y) {
                
                result += temp.second * (temp.second - 1) / 2;
            } else if (temp.first < y) {
                
                result += temp.second * freq[y];
            }
        }
    }

    cout << result << "\n";

    return 0;
}