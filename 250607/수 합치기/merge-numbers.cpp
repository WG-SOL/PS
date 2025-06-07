#include <iostream>
#include <queue>

using namespace std;

int n;
int arr[100000];
long long cost;
priority_queue<int, vector<int>,greater<int>> pq;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for(int i=0; i<n; i++){
        pq.push(arr[i]);
    }

    int ans=0;

    while(pq.size()>1){
        int temp1 = pq.top();
        pq.pop();
        int temp2 = pq.top();
        pq.pop();

        ans += temp1+temp2;
        pq.push(temp1+temp2);
    }

    cout << ans;
    // Please write your code here.

    return 0;
}
