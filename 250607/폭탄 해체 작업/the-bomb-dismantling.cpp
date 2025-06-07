#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int score[10000];
int time_limit[10000];
vector<pair<int,int>> v;

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> score[i] >> time_limit[i];
        v.push_back({score[i],time_limit[i]});
    }

    sort(v.begin(),v.end(),[](auto a, auto b){
        if(a.second==b.second) return a.first>b.first;
        else return a.second<b.second;
    });

    int answer=0;
    for(int i=0; i<N; i++){
        if(v[i].second == 0){
            for(int j=0; j<N; j++){
                v[j].second--;
            }
            continue;
        }

        answer += v[i].first;

        for(int j=0; j<N; j++){
            v[j].second--;
        }
    }

    cout << answer;
    // Please write your code here.

    return 0;
}
