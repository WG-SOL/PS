#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int grid[101][101];
int r, c, m1, m2, m3, m4, dir;
vector<int> v;
vector<pair<int,int>> table;

//m1 : (-1, +1) ↗
//m2 : (-1,-1) ↖
//m3 : (+1,-1) ↙
//m4 : (+1,+1) ↘

void ccw(int r, int c, int m1, int m2, int m3, int m4){
    v.push_back(grid[r][c]);
    table.push_back(make_pair(r,c));

    //m1 : (-1, +1) ↗
    for(int i=1; i<=m1; i++){
        v.push_back(grid[r-i][c+i]);
        table.push_back(make_pair(r-i,c+i));
    }

    r-=m1;
    c+=m1;

    //m2 : (-1,-1) ↖
    for(int i=1; i<=m2; i++){
        v.push_back(grid[r-i][c-i]);
        table.push_back(make_pair(r-i,c-i));
    }

    r-=m2;
    c-=m2;

    //m3 : (+1,-1) ↙
    for(int i=1; i<=m3; i++){
        v.push_back(grid[r+i][c-i]);
        table.push_back(make_pair(r+i,c-i));
    }
    r+=m3;
    c-=m3;

    //m4 : (+1,+1) ↘
    for(int i=1; i<m4; i++){
        v.push_back(grid[r+i][c+i]);
        table.push_back(make_pair(r+i,c+i));
    }
    r+=m4;
    c+=m4;
  
    rotate(v.begin(), v.end()-1,v.end());
    
    for(int i=0; i<table.size(); i++){
        grid[table[i].first][table[i].second] = v[i];
    }

}



void cw(int r, int c, int m1, int m2, int m3, int m4){
    v.push_back(grid[r][c]);
    table.push_back(make_pair(r,c));

    //m1 : (-1, +1) ↗
    for(int i=1; i<=m1; i++){
        v.push_back(grid[r-i][c+i]);
        table.push_back(make_pair(r-i,c+i));
    }

    r-=m1;
    c+=m1;

    //m2 : (-1,-1) ↖
    for(int i=1; i<=m2; i++){
        v.push_back(grid[r-i][c-i]);
        table.push_back(make_pair(r-i,c-i));
    }

    r-=m2;
    c-=m2;

    //m3 : (+1,-1) ↙
    for(int i=1; i<=m3; i++){
        v.push_back(grid[r+i][c-i]);
        table.push_back(make_pair(r+i,c-i));
    }
    r+=m3;
    c-=m3;

    //m4 : (+1,+1) ↘
    for(int i=1; i<m4; i++){
        v.push_back(grid[r+i][c+i]);
        table.push_back(make_pair(r+i,c+i));
    }
    r+=m4;
    c+=m4;
  
    rotate(v.begin(), v.begin()+1,v.end());
    
    for(int i=0; i<table.size(); i++){
        grid[table[i].first][table[i].second] = v[i];
    }

}



int main() {
    cin >> n;

    for (int i = 1; i <= n; i++) //Input
        for (int j = 1; j <= n; j++) {
            cin >> grid[i][j];
        }

    cin >> r >> c >> m1 >> m2 >> m3 >> m4 >> dir; 
    // dir(0)-> ccw 1칸 , dir(1) -> cw 1칸
    // (r,c)시작 -> 1번(↗), 2번(↖), 3번(↙), 4(↘)번으로 / 
    //              m1(↗),m2(↖),m3(↙),m4(↘)만큼 "순서대로" 이동
    // 기울어진 직사각형은 given 보장
    // m1,m2,m3,m4로 폐경로 만들고 ccw / cw로 1칸 이동 후 출력

    if(dir==0){
        ccw(r,c,m1,m2,m3,m4);
    }
    else{
        cw(r,c,m1,m2,m3,m4);
    }

     for (int i = 1; i <= n; i++) {// output
        for (int j = 1; j <= n; j++) {
            cout << grid[i][j] <<" ";
        }
        cout << "\n";
     }

    // Please write your code here.

    return 0;
} 