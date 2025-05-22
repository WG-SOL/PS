#include <iostream>

using namespace std;

int N;

void print(int n){
    int num=1;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << num << " ";
            num++;
            if(num >9) num =1;
        }
        cout << "\n";
    }
}


int main() {
    cin >> N;

    print(N);
    // Please write your code here.

    return 0;
}