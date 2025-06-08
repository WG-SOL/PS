#include <iostream>
#include <climits>

using namespace std;

int n, m;
int dist[101][101];

int main() {
    cin >> n >> m; //vertex,edge

    for (int i = 1; i <= n; i++) {
        for(int j=1; j<=n; j++){
            if(i==j) dist[i][j] = 0;
            else dist[i][j] = 1000001;
        }
    }

    for(int i=0; i<m; i++){
        int s,e,w;
        cin >> s >> e >> w;
        if(dist[s][e] > w){
            dist[s][e] = w;
        }
    }

    for(int k=1; k<=n; k++){
        for(int s=1; s<=n; s++){
            for(int e=1; e<=n; e++){
                if(dist[s][e] > dist[s][k] + dist[k][e]){
                    dist[s][e] = dist[s][k] + dist[k][e];
                }
            }
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(dist[i][j] == 100001) cout << -1 << " ";
            else cout << dist[i][j] << " ";
        }
        cout << "\n";
    }

    // Please write your code here.

    return 0;
}
