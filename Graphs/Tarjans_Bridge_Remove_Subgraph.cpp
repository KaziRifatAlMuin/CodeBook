#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
long long int const MOD = 1e9 + 7;
int const N = 1e5 + 7;
long long const INF = 1e18 + 7;

vector <int> G[N];
int disc[N], low[N], compSize[N], timer;
ll ans, n, m;

void DFS(int u, int par = -1){
    compSize[u] = 1;
    disc[u] = low[u] = ++timer;
    for(auto v : G[u]){
        if(!disc[v]){
            DFS(v, u);
            low[u] = min(low[v], low[u]);
            compSize[u] += compSize[v];
            if(low[v] > disc[u]){
                // if u-v is removed, then the component sizes of the two resulting subgraphs
                ll a = compSize[v], b = n - compSize[v];
                ans = min(ans, a * (a - 1) / 2 + b * (b - 1) / 2);
            }
        }
        else{
            if(v == par) continue;
            low[u] = min(low[v], low[u]);
        }
    }
}

void Find_Bridges(){
    memset(disc, 0, sizeof(disc));
    memset(low, 0, sizeof(low));
    memset(compSize, 0, sizeof(compSize));
    timer = 0;
    for(int i = 1; i <= n; i++){
        if(!disc[i]){
            DFS(i);
        }
    }
}

void solve()
{
    cin >> n >> m;
    for(int i = 0; i <= n; i++) G[i].clear();
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    ans = n * (n - 1) / 2;
    Find_Bridges();
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
// https://codeforces.com/contest/1986/problem/F