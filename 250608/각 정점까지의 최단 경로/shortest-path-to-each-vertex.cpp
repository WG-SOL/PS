#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int,int> edge;

vector<vector<edge>> G;
vector<bool> seen;
vector<int> dist;
priority_queue<edge, vector<edge>, greater<edge>> pq;

int n, m, k;

int main() {
    cin >> n >> m; //vertex, edge
    cin >> k; // start vertex

    G.resize(n+1);
    seen.resize(n+1,false);
    dist.resize(n+1,INT_MAX);
    
    for (int i = 0; i < m; i++) {
        int s,e,w;
        cin >> s >> e >> w;
        G[s].push_back({e,w});
        G[e].push_back({s,w});
    }

    pq.push({0,k}); // dist, vertex
    dist[k] = 0;

    while(!pq.empty()){
        edge now = pq.top();
        pq.pop();
        int now_vertex = now.second;
        if(seen[now_vertex]) continue;
        seen[now_vertex] = true;

        for(int i=0; i<G[now_vertex].size(); i++){
            edge temp = G[now_vertex][i];
            int next = temp.first; //vertex
            int value = temp.second; //weight

            if(dist[next] > dist[now_vertex] + value){
                dist[next] = dist[now_vertex] + value;
                pq.push({dist[next],next});
            }
        }
    }

    for(int i=1; i<=n; i++){
        if(seen[i]) cout << dist[i] << "\n";
        else cout << -1 << "\n";
    }

    // Please write your code here.

    return 0;
}
