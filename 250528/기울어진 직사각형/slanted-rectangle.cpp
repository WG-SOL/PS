#include <iostream>

using namespace std;

int n;
int grid[20][20];
int max_value;
int check;

void find(int x, int y)
{
    int value=0;
    
    while(x>=0 && y>=0 && x<n && y<n){
        value += grid[x][y];

        if((x-1)>=0 && (y-1)>=0){
            value += grid[x-1][y-1];
            check++;
        }
        else{
            value -= grid[x][y];    
        }
        
        x -= 1;
        y += 1;
        
    }

    if(check<2) value=0;
    max_value = max(value,max_value);

}



int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    // Please write your code here.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            find(i,j);
            check=0;
        }
    }

    cout << max_value;

    return 0;
}
