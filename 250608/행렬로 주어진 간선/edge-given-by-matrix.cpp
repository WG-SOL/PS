#include <iostream>

using namespace std;

int n;
int graph[101][101];

int main() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> graph[i][j];
            if(i==j) graph[i][j] = 1;
        }
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
             for (int j = 1; j <= n; j++) {
                 if (graph[i][k] == 1 && graph[k][j] == 1) {
                      graph[i][j] = 1;
                    }
                }       
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << graph[i][j] << " ";
        }
        cout << "\n";
    }

    // Please write your code here.

    return 0;
}
