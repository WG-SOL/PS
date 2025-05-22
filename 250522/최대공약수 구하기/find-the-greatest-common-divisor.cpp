#include <iostream>

using namespace std;

int n, m;

int gcd(int a, int b){
    if(b==0) return a;

    else return gcd(b,a%b);
}



int main() {
    cin >> n >> m;

    int gcd_num = gcd(n,m);
  

    cout << gcd_num;

    // Please write your code here.

    return 0;
}