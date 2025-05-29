#include <iostream>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

int min_value=INT_MAX;

int find_RLE(string s) {
    
    string result;
    int count = 1;

    for (int i = 1; i <= s.length(); i++) {
        if (i < s.length() && s[i] == s[i - 1]) {
            count++;
        } else {
            result.push_back(s[i - 1]);
            result.push_back(count + '0');
            count = 1;
        }
    }

    return (int)result.size();
}

int main() {
    string A;
    cin >> A;
    
    for(int i=0; i<A.size(); i++){
        rotate(A.begin(), A.end()-1, A.end());
        min_value = min(min_value,find_RLE(A));
    }

    cout << min_value;

    return 0;
}