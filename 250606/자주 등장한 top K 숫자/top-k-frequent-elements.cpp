#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>

using namespace std;

int n, k;
int arr[100000];
unordered_map<int,int> freq;

bool cmp(pair<int,int> a, pair<int,int> b){
	if (a.second == b.second) return a.first > b.first;
	return a.second > b.second;
}

int main() {
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        freq[arr[i]]++; //개수 check
    }

    vector<pair<int,int>> v(freq.begin(),freq.end());
    sort(v.begin(),v.end(),cmp);
    auto it = v.begin();

    for(int i=0; i<k; i++){                                                                                                                                                                                                                                                                                 
        cout << v[i].first << " ";
    }

    // Please write your code here.

    return 0;
}
