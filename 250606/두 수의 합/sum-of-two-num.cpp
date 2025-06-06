#include <iostream>
#include <algorithm>
using namespace std;

int n, k;
int arr[100000];

int main() {
    cin >> n >> k;

    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);

    int left = 0, right = n - 1;
    int result = 0;

    while (left < right) {
        int sum = arr[left] + arr[right];

        if (sum == k) {
            int l_cnt = 1, r_cnt = 1;
            
            while (left + 1 < right && arr[left] == arr[left + 1]) {
                l_cnt++; 
                left++;
            }
            while (right - 1 > left && arr[right] == arr[right - 1]) {
                r_cnt++; 
                right--;
            }

            if (arr[left] == arr[right]) {
                int count = l_cnt + r_cnt;
                result += count * (count - 1) / 2;
                break;
            }

            result += l_cnt * r_cnt;
            left++; right--;
        }
        else if (sum < k) {
            left++;
        }
        else {
            right--;
        }
    }

    cout << result << "\n";
}