#include <iostream>

using namespace std;

int n, m;
int grid[20][20];
int max_value=-1;

bool validation(int x, int y, int x2, int y2){
    for(int i=x; i<=x2; i++){
        for(int j=y; j<=y2; j++){
            if(grid[i][j]<0) return false;
        }
    }
    return true;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    


    // Please write your code here.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for(int l=i; l<n; l++){
                for(int k=j; k<m; k++){
                    if(validation(i,j,l,k)){
                        int area = (l-i+1) * (k-j+1);
                        max_value = max(area, max_value);
                    }
                }
            }
        }
    }


    cout << max_value;
    return 0;
}
