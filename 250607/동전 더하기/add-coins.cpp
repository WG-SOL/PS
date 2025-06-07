#include <iostream>

using namespace std;

int n, k;
int coins[10];

int main() {
    cin >> n >> k; //동전수, 가격
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    int counter=0;
    for(int i=n-1; i>=0; i--){
        if(k==0) break;
        counter += k/coins[i];
        k = k%coins[i];
    }

    cout << counter;

    // Please write your code here.

    return 0;
}
