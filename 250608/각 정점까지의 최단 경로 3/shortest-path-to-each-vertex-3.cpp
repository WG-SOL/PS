#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;
typedef pair<int,int> edge;

int n, m;
vector<vector<edge>> G;
vector<bool> seen;
vector<int> dist;
priority_queue<edge, vector<edge>, greater<edge>> pq;

int main() {
    cin >> n >> m; //vertex, edge
    G.resize(n+1);
    dist.resize(n+1, INT_MAX);
    seen.resize(n+1,false);

    for(int i=0; i<m; i++){
        int s,e,w;
        cin >> s >> e >> w;
        G[s].push_back(make_pair(e,w));
    }

    pq.push(make_pair(0,1)); // dist, vertex
    dist[1] = 0;

    while(!pq.empty()){
        edge now = pq.top(); // dist(first), seen(second)
        pq.pop();
        if(seen[now.second]) continue;
        seen[now.second] = true;

        for(int i=0; i<G[now.second].size(); i++){
            edge temp = G[now.second][i];
            int next = temp.first; //e
            int value = temp.second; //w

            if(dist[next] > dist[now.second] + value){
                dist[next] = dist[now.second] + value;
                pq.push(make_pair(dist[next],next));
            }
        }
    }

    for(int i=2; i<=n; i++){
        if(seen[i]) cout << dist[i] << "\n";
        else cout << -1 << "\n";
    }
    

    // Please write your code here.

    return 0;
}
