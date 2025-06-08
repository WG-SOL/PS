#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

typedef pair<int,int> edge;

int n, m;

vector<vector<edge>> G;
vector<int> dist;
vector<int> path;
vector<bool> seen;
priority_queue<edge, vector<edge>, greater<edge>> pq;

int A, B; 

int main() {
    cin >> n >> m; // vertex, edge

    G.resize(n+1);
    dist.resize(n+1,INT_MAX);
    seen.resize(n+1,false);
    path.resize(n+1,0);

    for (int i = 0; i < m; i++) {
        int s,e,w;
        cin >> s >> e >> w;
        G[s].push_back({e,w});
        G[e].push_back({s,w});
    }

    cin >> A >> B; //start, end

    pq.push({0,A});
    dist[A] =0;

    while(!pq.empty()){
        edge now = pq.top();
        pq.pop();
        int now_vertex = now.second;
        if(seen[now_vertex]) continue;
        seen[now_vertex] = true;

        for(int i=0; i<G[now_vertex].size(); i++){
            edge temp = G[now_vertex][i];
            int next = temp.first;
            int value = temp.second;

            if(dist[next] > dist[now_vertex] + value){
                dist[next] = dist[now_vertex] + value;
                path[next] = now_vertex; // 이전 루트
                pq.push({dist[next],next});
            }
        }
    }

    cout << dist[B] << "\n";

    vector<int> route;

    for (int v = B; v != 0; v = path[v]) {
        route.push_back(v);
        if (v == A) break;
    }

    reverse(route.begin(), route.end());

    for (int v : route) {
        cout << v << " ";
    }
    
    // Please write your code here.

    return 0;
}
