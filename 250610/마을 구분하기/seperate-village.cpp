#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int grid[25][25];
int area; //영역 수(마을 수)
int num; //사람 수
bool seen[25][25]= {false};
vector<int> ans;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};


void dfs(int x, int y){
    seen[x][y] = true;
    num++;

    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx<0 || ny<0 || nx>=n || ny>=n) continue;
            
        if(grid[nx][ny] == 1 && seen[nx][ny] == false){
            dfs(nx,ny);
        }
        
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(seen[i][j] == false && grid[i][j] == 1){
                num =0;
                dfs(i,j);
                area++;
                ans.push_back(num);
                
            }
        }
    }

    sort(ans.begin(),ans.end());

    cout << area << "\n";
    for(int counter : ans){
        cout << counter << "\n";
    }


    // Please write your code here.

    return 0;
}
