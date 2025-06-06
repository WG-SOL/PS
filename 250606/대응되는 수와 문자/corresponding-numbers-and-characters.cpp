#include <iostream>
#include <string>
#include <unordered_map>
#include <cctype>

using namespace std;

int n, m;
string words[100001]; 
string queries[100000];

bool is_number(const string& s) {
    for (char c : s) {
        if (!isdigit(c)) return false;
    }
    return true;
}

int main() {
    cin >> n >> m;

    unordered_map<string, int> name_to_num;

    for (int i = 1; i <= n; i++) {
        cin >> words[i];
        name_to_num[words[i]] = i;
    }

    for (int i = 0; i < m; i++) {
        cin >> queries[i];
        if (is_number(queries[i])) {
            int idx = stoi(queries[i]);
            cout << words[idx] << "\n";
        } else {
            cout << name_to_num[queries[i]] << "\n";
        }
    }

    return 0;
}
