#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    unordered_map<string, int> group;
    for (int i = 0; i < n; i++) {
        string word;
        cin >> word;

        for (char& c : word) {
            c = tolower(c);
        }

        vector<int> freq(26, 0);
        for (char c : word) {
            freq[c - 'a']++;
        }

        string key;
        for (int count : freq) {
            key += to_string(count);  
        }

        group[key]++;
    }

    // 가장 큰 그룹 크기 찾기
    int max_value = 0;
    for (auto p : group) {
        max_value = max(max_value, p.second);
    }

    cout << max_value << endl;

    return 0;
}