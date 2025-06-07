#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int s[100000];
int e[100000];
vector<pair<int,int>> table;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i] >> e[i];
        table.push_back({e[i],s[i]});
    }

    int counter=0;
    int end=-1;
    sort(table.begin(), table.end(), [](auto &a, auto &b) {
        if (a.first == b.first)
           return a.second < b.second;
        return a.first < b.first;
    });

    for(int i=0; i<n; i++){
        if(table[i].second >= end){ //겹치는대로 
            end = table[i].first;
            counter++;
        }
    }

    cout << counter;

    // Please write your code here.

    return 0;
}
