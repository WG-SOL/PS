#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int n;
string words[100000];

int main() {
    cin >> n;

    unordered_map<string,int> m;

    for (int i = 0; i < n; i++) {
        cin >> words[i]; // string 중복 허용
        m[words[i]]++; // key별 횟수
    }

    int max_value=0;
    for(int i=0; i<n; i++){
        max_value = max(max_value, m[words[i]]);
    }


    cout << max_value;
    // Please write your code here.

    return 0;
}
