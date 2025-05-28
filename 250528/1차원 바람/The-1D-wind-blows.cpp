#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, q;
int a[100][100];
vector<bool> seen(100,false); // recursive 방지

void right_wind(int row);
void left_wind(int row);


void left_wind(int row){
    if(seen[row]) return;
    seen[row] = true;

    int left_temp = a[row][m-1];

    for(int i=m-1; i>=1; i--){
        a[row][i] = a[row][i-1];
    }
    a[row][0] = left_temp;

    //위쪽으로 역전파
    if(row>0){
        for(int i=0; i<m; i++){
            if(a[row-1][i] == a[row][i]){
                right_wind(row-1);
                break;
            }
        }
    }

    //아래쪽으로 역전파
    if(row<n-1){
        for(int i=0; i<m; i++){
            if(a[row+1][i] == a[row][i]){
                right_wind(row+1);
                break;
            }
        }
    }

}

void right_wind(int row){
    if(seen[row]) return;
    seen[row] = true;

    int right_temp = a[row][0];

    for(int i=1; i<m; i++){
        a[row][i-1] = a[row][i];
    }
    a[row][m-1] = right_temp;


    //위로 역전파
    if(row>0){
        for(int i=0; i<m; i++){
            if(a[row-1][i] == a[row][i]){
                left_wind(row-1);
                break;
            }
        }
    }

    //아래로 역전파
    if(row<n-1){
        for(int i=0; i<m; i++){
            if(a[row+1][i] == a[row][i]){
                left_wind(row+1);
                break;
            }
        }
    }
}



int main() {
    cin >> n >> m >> q; //n by m , 바람수

    for (int i = 0; i < n; i++) { //INPUT
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < q; i++) { //타겟 행, 방향(L/R)
        int r;
        char d;
        cin >> r >> d;
        
        fill(seen.begin(),seen.end(),false);

        if(d == 'L') {
            left_wind(r-1);
        }
        else if(d == 'R'){
            right_wind(r-1);
        }

    }

    // Please write your code here.
    

    for (int i = 0; i < n; i++) { // output
        for (int j = 0; j < m; j++) {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }

    //Q개 바람 이후 건물 상태 출력 
    return 0;
}
