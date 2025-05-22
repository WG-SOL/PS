#include <iostream>

using namespace std;

int N;

int sum(int n){
    int temp=0;
    
    for(int i=0; i<n/2; i++){
        temp += (i + (n-i));
    }
    temp += n/2;

    return temp/10;
}


int main() {
    cin >> N;

    cout << sum(N);
    // Please write your code here.

    return 0;
}