#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;


int n;
int a[100001];

int main() {

    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];

    int ans = INT_MIN;
    int sum = 0;

    for(int i = 1; i <= n; i++) {
        if(sum < 0){
            sum = a[i];
        }
        else{
            sum += a[i];
        }

        ans = max(ans, sum);
    }
    
    cout << ans;
}
