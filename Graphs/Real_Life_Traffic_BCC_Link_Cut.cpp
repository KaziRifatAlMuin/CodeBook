#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
long long int const MOD = 1e9 + 7;
int const N = 10007;
long long const INF = 1e18 + 7;

vector <int> G[N];
bool visited[N], mark[N];
int disc[N], low[N], timer, comp, component[N], deg[N];
stack <int> s;

void DFS(int u, int par = -1){
    visited[u] = true;
    disc[u] = low[u] = ++timer;
    int children = 0;
    s.push(u);

    // Entering in a Component
    for(auto v : G[u]){
        if(v == par) continue;
        if(!visited[v]){
            children++;
            DFS(v, u);
            low[u] = min(low[u], low[v]);
            if(par != -1 && low[v] >= disc[u]) mark[u] = true;
        }
        else{
            low[u] = min(low[u], disc[v]);
        }
    }
    // Ekta node theke sobai k visit kora sesh
    // Amar low < disc mane amar backedge ache
    // Amar low = disc mane ami eka / amr theke component shuru
    if(par == -1 && children > 1) mark[u] = true;
    if(low[u] == disc[u]){
        ++comp;
        while(!s.empty()){
            int node = s.top();
            s.pop();
            component[node] = comp;
            if(u == node) break; // Amar kache fire asha mane amr component sesh
            // stack er baki gula amr ager karo 
        }
    }
}


void solve()
{
    int n, m;
    cin >> n >> m;
    memset(G, 0, sizeof(G));
    memset(disc, 0, sizeof(disc));
    memset(low, 0, sizeof(low));
    memset(visited, 0, sizeof(visited));
    memset(mark, 0, sizeof(mark));
    memset(deg, 0, sizeof(deg));
    memset(component, 0, sizeof(component));
    while(!s.empty()) s.pop();
    comp = timer = 0;

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            DFS(i);
        }
    }
    int AP = 0;
    for(int i = 1; i <= n; i++){
        if(mark[i]) AP++;
    }
    // cout << AP << "\n";
    ll ans = 0;
    for(int u = 0; u < n; u++){
        for(auto v : G[u]){
            // Component Alada mane tara notun graph er ekta edge
            if(component[u] != component[v]){
                deg[component[v]]++;
            }
        }
    }
    for(int i = 0; i <= comp; i++){
        // cout << i << " " << deg[i] << "\n";
        if(deg[i] == 1) ans++;
    }
    cout << (ans + 1) / 2 << "\n";

}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t = 1, cs = 1;
    cin >> t;
    while(t--){
        cout << "Case " << cs++ << ": ";
        solve();
    }
    return 0;
}