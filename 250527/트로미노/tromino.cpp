#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int grid[200][200];
int max_value;

void neon(int x, int y){
    int sumation=0;

    if(x>0 && y>0 && x<n && y<m){  // 기본 x,y

        if(x>0&&(y-1)>0 && x<n && (y-1)<m){ // ㄱ
            if((x+1)>0 && y>0 && (x+1)<n && y<m){
                if(x != (n-2) && y != 1)
                sumation = max(sumation, grid[x][y] + grid[x][y-1] + grid[x+1][y]);
            }
        }                

        if((x-1)>0 && y>0 && (x-1)<n && y<m){ // ㄴ
            if(x>0 && (y+1)>0 && x<n && (y+1)<m){
                if(x != 1 && y!=(m-2))
                sumation = max(sumation, grid[x][y]+grid[x-1][y]+grid[x][y+1]);
            }
        }

        if(x>0 && (y+1)>0 && x<n && (y+1)<m){ // 반대 ㄱ
            if((x+1)>0 && y>0 && (x+1)<n && y<m){
                if(x != (n-2) && y!= (m-2)){
                    sumation = max(sumation, grid[x][y]+grid[x][y+1]+grid[x+1][y]);
                }
            }
        }               
                        
        if((x-1)>0 && y>0 && (x-1)<n && y<m){ //반대 ㄴ
            if(x>0 && (y-1)>0 && x<n && (y-1)<m){
                if(x != 1 && y!= 1){
                    sumation = max(sumation, grid[x][y]+grid[x-1][y]+grid[x][y-1]);
                }
            }
        }                
    }
    max_value = max(sumation,max_value);
}

void space_bar(int x, int y){
    int sumation=0;
    if(x>0 && y>0 && x<n && y<m){ // 기본 x,y

        if(x>0 && (y-1)>0 && x<n && (y-1)<m){ //가로 스페이스
            if(x>0 && (y+1)>0 && x<n && (y+1)<m){
                sumation = max(sumation, grid[x][y]+grid[x][y-1]+grid[x][y+1]);
            }
        }

        if((x-1)>0 && y>0 && (x-1)<n && y<m){ //세로 스페이스
            if((x+1)>0 && y>0 && (x+1)<n && y<m){
                sumation = max(sumation, grid[x][y]+grid[x-1][y]+grid[x+1][y]);
            }
        }
     }
    max_value = max(sumation,max_value);
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
            neon(i,j);
            space_bar(i,j);
        }
    }

    cout << max_value;

    return 0;
}
