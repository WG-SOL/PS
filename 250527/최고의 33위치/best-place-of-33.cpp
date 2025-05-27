#include <iostream>
#include <algorithm>

using namespace std;

int N;
int grid[20][20];
int m_value;


void find(int n, int m){
    int counter=0;
    for(int i=n; i<=n+2; i++){
        for(int j=m; j<=m+2; j++){
            if(grid[i][j]) counter++;
        }
    }
    m_value = max(m_value,counter);
}

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }

    // Please write your code here.

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if(i<0 || j<0 || i>=(N-2) || j>=(N-2)) continue;
            find(i,j);
        }
    }

    cout << m_value;
    return 0;
}
