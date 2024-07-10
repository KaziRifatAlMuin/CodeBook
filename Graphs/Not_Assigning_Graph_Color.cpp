#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int const N = 1e5 + 7;

vector<int> G[N];
bool visited[N];
map<pair <int,int>, int> color;

void dfs(int u, int par = -1, int col = 2){
    visited[u] = true;
    for(auto &v : G[u]){
        if(!visited[v]){
            color[{min(u,v), max(u,v)}] = col;
            dfs(v, u, col == 2 ? 3 : 2);
        }
    }
}

void solve() {
    memset(visited, false, sizeof(visited));
    for(int i = 0; i < N; ++i) G[i].clear();
    color.clear();
    int n;
    cin >> n;
    map<int, int> deg;
    vector <pair<int, int>> edges;

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        deg[u]++, deg[v]++;
        G[u].push_back(v);
        G[v].push_back(u);
        edges.push_back({min(u,v), max(u,v)});
    }

    for(auto x : deg){
        if(x.second > 2){
            cout << -1 << "\n";
            return;
        }
    }

    for(int i = 1; i <= n; i++){
        if(deg[i] == 1){
            dfs(i);
            break;
        }
    }

    for(auto x : edges){
        cout << color[{x.first, x.second}] << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
// https://codeforces.com/problemset/problem/1627/C