#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

int n;
string words[1000];

int main() {
    cin >> n;

    unordered_map<string,int> freq;
    for (int i = 0; i < n; i++) {
        cin >> words[i];
        sort(words[i].begin(),words[i].end());
        freq[words[i]]++;
    }

    int max_value=0;
    for(int i=0; i<n; i++){
        max_value = max(freq[words[i]],max_value);
    }
    // Please write your code here.

    cout << max_value;
    
    return 0;
}
