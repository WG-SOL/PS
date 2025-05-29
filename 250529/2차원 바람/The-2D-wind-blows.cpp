#include <iostream>

using namespace std;

int n, m, q;
int a[101][101]; // 회전용 - 답
int sub[101][101]; // 회전 후 동시 평균용

// (r1,c1)~(r1,c2) + (r1,c2)~(r2,c2)까진 우회전으로 밀고
// (r2,c2)~(r2,c1) + (r2,c1)~(r1,c1) 까진 좌회전으로 밀어내기
void rotation(int r1, int c1, int r2, int c2){
    int top_left     = a[r1][c1];
    int top_right    = a[r1][c2];
    int bottom_right = a[r2][c2];
    int bottom_left  = a[r2][c1];

    // 위쪽 행 → 오른쪽으로 이동
    for (int i = c2; i > c1; i--)
        a[r1][i] = a[r1][i - 1];
    a[r1][c1 + 1] = top_left;

    // 오른쪽 열 ↓ 아래로 이동
    for (int i = r2; i > r1; i--)
        a[i][c2] = a[i - 1][c2];
    a[r1 + 1][c2] = top_right;

    // 아래쪽 행 ← 왼쪽으로 이동
    for (int i = c1; i < c2; i++)
        a[r2][i] = a[r2][i + 1];
    a[r2][c2 - 1] = bottom_right;

    // 왼쪽 열 ↑ 위로 이동
    for (int i = r1; i < r2; i++)
        a[i][c1] = a[i + 1][c1];
    a[r2 - 1][c1] = bottom_left;
}

void change(int r1, int c1, int r2, int c2){
    for(int i=r1; i<=r2; i++){
        for(int j=c1; j<=c2; j++){
            int counter=0;

            if(i-1 <1) counter++;
            if(j-1 <1) counter++;
            if(i+1 > n) counter++;
            if(j+1 > m) counter++;

            a[i][j] = (sub[i][j] + sub[i-1][j] + sub[i][j-1] + sub[i+1][j] + sub[i][j+1])/(5-counter);

        }
    }
}



int main() {
    cin >> n >> m >> q; // n by m, 바람수 

    for (int i = 1; i <= n; i++) // Input
        for (int j = 1; j <= m; j++) cin >> a[i][j];

    for (int i = 0; i < q; i++) { //(r1,c1)이 바람 맞는곳- 좌측상단 
        int r1, c1, r2, c2; 
        cin >> r1 >> c1 >> r2 >> c2; //(r2,c2)도 바람 맞는 곳 우측 하단 
        rotation(r1,c1,r2,c2);

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                sub[i][j] = a[i][j];
            }
        }

        change(r1,c1,r2,c2);
    }

    // Please write your code here.







    //Output
   for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }





    return 0;
}
