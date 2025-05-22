#include <iostream>

using namespace std;

int N;

int sum(int n){
    int temp=0;
    
    for(int i=0; i<=n; i++){
        temp += i;
    }

    return temp/10;
}


int main() {
    cin >> N;

    cout << sum(N);
    // Please write your code here.

    return 0;
}