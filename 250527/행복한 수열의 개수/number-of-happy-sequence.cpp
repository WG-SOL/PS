#include <iostream>
#include <vector>
using namespace std;


int n, m;
int grid[100][100];
int counter;

bool row_find(int row, int num){
    int temp=0;
    bool flag = false;

        for(int j=0; j<n-1; j++){
            if(grid[row][j] == grid[row][j+1]){
                temp++; 
                flag=true;
                if(temp == num) return flag;
            }
            else{
                flag = false;
            }
        }
    
    return flag;
}

bool col_find(int col, int num){
    int temp=0;
    bool flag = false;
    
        for(int i=0; i<n-1; i++){
            if(grid[i][col] == grid[i+1][col]){
                temp++; 
                flag=true;
                if(temp == num) return flag;
            }
            else{
                flag = false;
            }
        }

    return flag;
}



int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    if(m==1) cout << 2*n;
    else{
        for(int i=0; i<n; i++){
            if(row_find(i,m)) counter++;
            if(col_find(i,m)) counter++;
        }
        cout << counter;
    }

    
    
    // Please write your code here.

    return 0;
}
