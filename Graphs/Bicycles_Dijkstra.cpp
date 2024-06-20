#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
long long int const MOD = 1e9 + 7;
int const N = 1007;
long long const INF = 1e18 + 7;

vector <pair <ll, ll>> G[N+2];
ll dist[N][N], s[N];

struct info{
    ll city, cost, slow;
    bool operator < (const info &p) const{
        if(cost == p.cost) return slow > p.slow;
        else return cost > p.cost;
    }
};

void Dijkstra(ll source){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            dist[i][j] = INF;
        }
    }
    priority_queue <info> q;
    q.push({source, 0, 1000});
    dist[source][1000] = 0;
    while(!q.empty()){
        auto[city, cost, slow] = q.top();
        q.pop();
        if(dist[city][slow] < cost) continue;
        int slowness = min(slow, s[city]);
        for(auto x : G[city]){
            if(dist[x.first][slowness] > dist[city][slow] + x.second * slowness){
                dist[x.first][slowness] = dist[city][slow] + x.second * slowness;
                q.push({x.first, dist[x.first][slowness], slowness});
            }
        }
    }
}

void solve()
{

    ll n, m;
    cin >> n >> m;
    memset(G, 0, sizeof(G));
    memset(s, 0, sizeof(s));

    for(ll i = 1; i <= m; i++){
        ll u, v, w;
        cin >> u >> v >> w;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }
    for(int i = 1; i <= n; i++){
        cin >> s[i];
    }
    Dijkstra(1);
    ll ans = INF;

    for(int i = 0; i <= 1000; i++){
        ans = min(ans, dist[n][i]);
    }
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}