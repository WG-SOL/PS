#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int grid[50][50];
int max_value; // 최댓값
bool seen[50][50]={false}; //방문배열
int area;
int ans;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,-1,1};


void dfs(int x, int y, int rain){
    seen[x][y] = true;

    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx<0 || ny<0 || nx>=N || ny>=M) continue;
        if(seen[nx][ny] == false && grid[nx][ny] > rain ){
            dfs(nx,ny,rain);
        }
    }

}



int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> grid[i][j];
        }
    }
    
    for(int rain=1; rain<=100; rain++){
        area=0;
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                seen[i][j] = false;
            }
        }

        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(grid[i][j] > rain && seen[i][j] == false){
                    dfs(i,j,rain);
                    area++;
                }
            }
        }
        if(area > max_value){
            ans = rain;
            max_value = max(area,max_value);
        }
    }

    if(max_value==0) {
        cout << 1 << " " << max_value; 
    }
    else{
        cout << ans << " " << max_value;
    }
    // Please write your code here.
    return 0;
}

