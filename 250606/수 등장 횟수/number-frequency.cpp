#include <iostream>
#include <unordered_map>

using namespace std;

const int MAX_N = 100000;

int n, m;
int arr[MAX_N];
int nums[MAX_N];

int main() {
    cin >> n >> m; //원소수, query수 (5,2)

    unordered_map<int,int> my_m;

    for (int i = 0; i < n; i++) {
        cin >> arr[i]; // (1,1,3,2,3) : 원소
        my_m[arr[i]]++;
    }

    for (int i = 0; i < m; i++) {
        cin >> nums[i]; // query, 없다면 0
        cout << my_m[nums[i]] <<  " ";
    }


    //out : 몇개 존재하는가
    

    // Please write your code here.

    return 0;
}
