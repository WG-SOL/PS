#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int points[100000];
int start[100000], end_p[100000];

int main() {
    cin >> n >> m; //점 선분수  

    for (int i = 0; i < n; i++) {
        cin >> points[i]; // 10 30 50
    }

    for (int i = 0; i < m; i++) {
        cin >> start[i] >> end_p[i];
        int counter=0;
        //(1,5) -> 0
        //(5,21) => 1 (10)
        //(22,59) -> 2(30,50)
        //(210,293) -> 0
        long long diff = end_p[i] - start[i];
        vector<int> v(diff,0);
        for(auto it= v.begin(); it != v.end(); it++){
            *it = start[i]++;
        }
        
        for(int i=0; i<n; i++){
            auto it_s = lower_bound(v.begin(),v.end(),points[i]);
            auto it_e = upper_bound(v.begin(),v.end(),points[i]);
            if(it_s < it_e && *it_s == points[i]){
                counter++;
            }
        }

        cout << counter << "\n";
    }


    //out : 각 선분 위 몇개의 점이 존재하는가
    // Please write your code here.

    return 0;
}
