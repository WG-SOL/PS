#include <iostream>
#include <unordered_map>

using namespace std;

int n;
int x[100000], y[100000];

int main() {
    unordered_map<int,int> point;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];

        if(point.count(x[i])){
            if(point[x[i]] > y[i]){
                point[x[i]] = y[i];
            }
        }
        else{
            point[x[i]] = y[i];
        }
    }

    int sum=0;
    for(auto temp: point){
        sum+= temp.second;
    }

    cout << sum;
    // Please write your code here.

    return 0;
}