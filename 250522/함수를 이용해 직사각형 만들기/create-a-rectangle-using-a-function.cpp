#include <iostream>

using namespace std;

int n, m;

void print(int n, int m){

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << 1;
        }
        cout <<"\n";
    }
}


int main() {
    cin >> n >> m;

    print(n,m);

    return 0;
}