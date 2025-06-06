#include <iostream>
#include <unordered_map>
using namespace std;

int n, k;
int arr[100000];

int main() {
    cin >> n >> k; //원소수, 합이될 값

    unordered_map<int,int> m;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        m[arr[i]]++;
    }

    int counter=0;
    for(int i=0; i<n; i++){
        if(m[arr[i]]){
            if(m[k-arr[i]]) counter += m[k-arr[i]];
        }
    }

    cout << counter/2;



    // Please write your code here.

    return 0;
}
