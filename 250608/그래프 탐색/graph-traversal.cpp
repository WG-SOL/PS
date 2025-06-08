#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<vector<int>> G;
vector<bool> seen;
int counter;

void dfs(int node){
    seen[node] = true;

    for(auto next : G[node]){
        if(!seen[next]){
            dfs(next);
            counter++;
        }
    }
}

int main() {
    cin >> n >> m; //vertex, edge
    G.resize(n+1);
    seen.resize(n+1,false);

    for (int i = 0; i < m; i++) {
        int s,e;
        cin >> s >> e;
        G[s].push_back(e);
        G[e].push_back(s);
    }

    dfs(1);
    

    cout << counter;

    // Please write your code here.

    return 0;
}
