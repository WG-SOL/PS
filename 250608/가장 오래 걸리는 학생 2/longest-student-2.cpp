#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int,int> edge;

vector<vector<edge>> G;
vector<bool> seen;
vector<int> dist;
priority_queue<edge, vector<edge>, greater<edge>> pq;

int N, M;


int main() {
    cin >> N >> M;

    G.resize(N+1);
    seen.resize(N+1,false);
    dist.resize(N+1, INT_MAX);

    for (int k = 0; k < M; k++) {
        int s,e,w;
        cin >> s >> e >> w;
        G[e].push_back({s,w}); //reverse
    }

    pq.push({0,N});
    dist[N] = 0;

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

            if(dist[next] > dist[now_vertex]+value){
                dist[next] = dist[now_vertex] + value;
                pq.push({dist[next],next});
            }
        }
    }

    int max_value = -1;

    for(int i=1; i<=N-1; i++){
        max_value = max(dist[i],max_value);
    }

    cout << max_value;

    // Please write your code here.

    return 0;
}
