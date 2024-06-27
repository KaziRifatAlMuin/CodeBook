#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
long long int const MOD = 1e9 + 7;
int const N = 10007;
long long const INF = 1e18 + 7;

vector <int> G[N];
int disc[N], low[N], mark[N], timer, cnt, component[N], deg[N], color, counter[N];
set <pair <int, int>> bridges;
ll ans, n, m;

void DFS(int u, int par = -1){
    disc[u] = low[u] = ++timer;
    for(auto v : G[u]){
        if(!disc[v]){
            DFS(v, u);
            low[u] = min(low[v], low[u]);
            if(low[v] > disc[u]){
                bridges.insert({min(u,v), max(u, v)});
            }
        }
        else{
            if(v == par) continue;
            low[u] = min(low[v], low[u]);
        }
    }
}

void DFS2(int u){
    ++cnt;
    component[u] = color;
    for(auto v : G[u]){
        if(bridges.count({min(u,v), max(u,v)}) > 0) continue;
        else if(!mark[v]) mark[v] = 1, DFS2(v);
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    memset(G, 0, sizeof(G));
    memset(disc, 0, sizeof(disc));
    memset(low, 0, sizeof(low));
    memset(mark, 0, sizeof(mark));
    memset(component, 0, sizeof(component));
    memset(deg, 0, sizeof(deg));
    memset(counter, 0, sizeof(counter));
    bridges.clear();

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    vector <int> leaf;
    ans = n * (n - 1) / 2;
    color = timer = 0, DFS(1);

    for(int i = 1; i <= n; i++){
        if(!mark[i]){
            mark[i] = 1, cnt = 0, DFS2(i);
            counter[color] = cnt;
            color++;
        }
    }
    for(int u = 1; u <= n; u++){
        for(auto v : G[u]){
            // Component Alada mane tara notun graph er ekta edge
            if(component[u] != component[v]){
                deg[component[v]]++;
            }
        }
    }

    for(int i = 1; i <= n; i++){
        // cout << i << " " << component[i] << " " << counter[component[i]] << "\n";
    }

    for(int i = 0; i < color; i++){
        // cout << i << " " << deg[i] << "\n";
        if(deg[i] == 1){
            // cout << counter[counter[i]] << "\n";
            leaf.push_back(counter[i]);
        }
    }
    for(auto x : leaf){
        ll a = x, b = n - x;
        ans = min(ans, a * (a - 1) / 2 + b * (b - 1) / 2);
        // cout << a << " " << b << " " << ans << "\n";
    }
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t = 1, cs = 1;
    cin >> t;
    while(t--){
        // cout << "Case " << cs++ << ": ";
        solve();
    }
    return 0;
}