#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

typedef pair<int,int> edge; // {weight, vertex}

int n, m;
vector<vector<edge>> G;
vector<int> dist;
vector<int> prev_v;  // 경로 추적용

int A, B;

int main() {
    cin >> n >> m;

    G.resize(n + 1);
    dist.resize(n + 1, INT_MAX);
    prev_v.resize(n + 1, -1);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        G[u].push_back({w, v});
        G[v].push_back({w, u});  
    }

    cin >> A >> B;

    priority_queue<edge, vector<edge>, greater<edge>> pq;
    dist[B] = 0;
    pq.push({0, B});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;

        for (auto [w, v] : G[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                prev_v[v] = u;
                pq.push({dist[v], v});
            } else if (dist[v] == dist[u] + w && u < prev_v[v]) {
                prev_v[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    
    cout << dist[A] << '\n';

    vector<int> route;
    for (int x = A; x != -1; x = prev_v[x])
        route.push_back(x);

    for (auto it = route.begin(); it != route.end(); ++it){
        cout << *it << " ";
    }

    return 0;
}