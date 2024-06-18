#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
long long int const MOD = 1e9 + 7;
int const N = 10007;
long long const INF = 1e18 + 7;
int timer = 0;


vector <int> G[N];
bool visited[N];
int disc[N], low[N];
vector <pair <int, int>> bridges;

void DFS(int v, int par = -1){
    visited[v] = true;
    disc[v] = low[v] = timer;
    timer++;
    for(auto child : G[v]){
        if(!visited[child]){
            DFS(child, v);
            low[v] = min(low[child], low[v]);
            if(disc[v] < low[child]){
                bridges.push_back({min(v,child), max(v, child)});
            }
        }
        else{
            if(child == par) continue;
            low[v] = min(low[child], low[v]);
        }
    }
}


void solve()
{
    int n;
    cin >> n;
    memset(G, 0, sizeof(G));
    memset(disc, 0, sizeof(disc));
    memset(low, 0, sizeof(low));
    memset(visited, 0, sizeof(visited));
    bridges.clear();

    for(int i = 0; i < n; i++){
        int u, v_size;
        vector <int> v;
        char c1, c2;
        cin >> u >> c1 >> v_size >> c2;
        for(int i = 0; i < v_size; i++){
            int a; cin >> a;
            v.push_back(a);
        }
        G[u] = v;
    }

    for(int i = 0; i < n; i++){
        if(!visited[i]){
            timer = 0;
            DFS(i);
        }
    }
    cout << bridges.size() << " critical links\n";
    sort(bridges.begin(), bridges.end());
    for(auto x : bridges){
        cout << x.first << " - " << x.second << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t = 1, cs = 1;
    cin >> t;
    while(t--){
        cout << "Case " << cs++ << ":\n";
        solve();
    }
    return 0;
}