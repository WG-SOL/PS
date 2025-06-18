#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int x1[1000];
int x2[1000];
vector<pair<int,int>> v;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x1[i] >> x2[i]; //s,e
        v.push_back({x2[i],x1[i]}); //e,s
    }

    int counter=0;
    int end_point=-1;
    sort(v.begin(),v.end());

    for(int i=0; i<v.size(); i++){
        if(v[i].second > end_point){//e > s
            end_point = v[i].first;
            counter++; 
        }
    }

    cout << counter;


    // Please write your code here.

    return 0;
}
