#include <iostream>

using namespace std;

int n;
int sequence[1000];
int LIS[1000];
int LDS[1000];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> sequence[i];
    }

    for(int i=0; i<n; i++){
        LIS[i]=1;
        LDS[i]=1;
    }


    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            if(sequence[j] < sequence[i]){ //증가
                LIS[i] = max(LIS[i],LIS[j]+1);
            }
        }
    }

    for(int i=n-1; i>=0; i--){
        for(int j=n-1; j>i; j--){
            if(sequence[j] < sequence[i]){ //감소(거꾸로)
                LDS[i] = max(LDS[i], LDS[j]+1);
            }
        }
    }

    int res=0;
    for(int i=0; i<n; i++){
        res = max(res, LIS[i]+LDS[i]-1);
    }

    cout << res;

    // Please write your code here.

    return 0;
}
