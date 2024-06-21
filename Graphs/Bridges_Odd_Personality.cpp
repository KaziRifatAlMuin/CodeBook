#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
long long int const MOD = 1e9 + 7;
int const N = 10007;
long long const INF = 1e18 + 7;

vector <int> G[N];
int disc[N], low[N], mark[N], timer, cnt, odd;
set <pair <int, int>> bridges;

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
    for(auto v : G[u]){
        if(bridges.count({min(u,v), max(u,v)}) > 0) continue;
        if(mark[v] && mark[u] == mark[v]) odd = 1;
        else if(!mark[v]) mark[v] = 0 - mark[u], DFS2(v);
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
    bridges.clear();

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    for(int i = 0; i < n; i++){
        if(!disc[i]){
            timer = 0, DFS(i);
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        if(!mark[i]){
            mark[i] = 1, odd = cnt = 0, DFS2(i);
            if(odd) ans += cnt;
        }
    }
    cout << ans << "\n";
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