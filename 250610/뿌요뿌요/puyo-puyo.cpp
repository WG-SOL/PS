#include <iostream>
#include <algorithm>

using namespace std;

int n;
int grid[100][100];
bool seen[100][100];

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};


int dfs(int x, int y, int target){
    seen[x][y] = true;
    int count=1;

    for(int i=0; i<4; i++){
        int nx = x+dx[i];
        int ny = y+dy[i];

        if(nx<0 || ny<0 || nx>=n || ny>=n) continue;
        if(seen[nx][ny] == false && grid[nx][ny] == target){
            count += dfs(nx,ny,target);
        }
    }
    return count;
}


int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    int exploded = 0;
    int max_size = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(seen[i][j] == false){
                int b_size = dfs(i,j,grid[i][j]);
                max_size = max(max_size,b_size);
                if(b_size>=4){
                    exploded++;
                }
            }
        }
    }

    cout << exploded << " " << max_size;
    // Please write your code here.

    return 0;
}
