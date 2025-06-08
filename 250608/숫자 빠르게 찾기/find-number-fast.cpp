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

    bool find = true;

    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        int start = 0, end=n-1;
        while(start<=end){
            int mid_idx = (start+end)/2;
            int mid_value = arr[mid_idx];

            if(mid_value == x){
                cout << (mid_idx+1) << "\n";
                find = true;
                break;
            }
            else if(mid_value >x){
                end = mid_idx-1;
            }
            else{
                start = mid_idx+1;
            }
            find = false;   
        }
        if(!find){
                cout << -1 << "\n";
            }

    }

    

    // Please write your code here.

    return 0;
}
