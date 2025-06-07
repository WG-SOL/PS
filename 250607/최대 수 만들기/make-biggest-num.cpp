#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int n;

bool cmp(const string a, const string b){
    return a+b > b+a;
}


int main() {
    cin >> n;
    vector<string> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(),arr.end(),cmp);


    for(string temp : arr){
        cout <<temp;
    }
    

    // Please write your code here.

    return 0;
}
