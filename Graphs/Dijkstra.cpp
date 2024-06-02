#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
long long int const MOD = 1e9 + 7;
int const N = 1e5 + 7;
long long const INF = 1e18 + 7;

vector <pair <ll, ll>> G[N+2];
vector <ll> dist(N+2), pre(N+2);

struct info{
    ll city, cost;
    bool operator < (const info &p) const{
        return cost > p.cost;
    }
};

void Dijkstra(ll source){
    for(ll i = 0; i < N; i++) dist[i] = INF;
    priority_queue <info> q;
    info cur, next;
    cur.city = source, cur.cost = 0;
    pre[cur.city] = 0;
    q.push(cur);
    dist[source] = 0;
    while(!q.empty()){
        cur = q.top();
        q.pop();
        ll cur_cost = dist[cur.city];
        for(auto x : G[cur.city]){
            next.city = x.first;
            next.cost = x.second + cur_cost;
            if(next.cost < dist[next.city]){
                dist[next.city] = next.cost;
                pre[next.city] = cur.city;
                q.push(next);
            }
        }
    }
}

void solve()
{
    ll n, m;
    cin >> n >> m;
    for(ll i = 1; i <= m; i++){
        ll u, v, w;
        cin >> u >> v >> w;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }
    Dijkstra(1);
    vector <ll> path;
    path.push_back(n);
    ll cur = n;
    if(dist[n] == INF){
        cout << -1 << "\n";
        return;
    }
    while(cur != 1){
        path.push_back(pre[cur]);
        cur = pre[cur];
    }
    reverse(path.begin(), path.end());
    for(auto x : path) cout << x << " ";
    cout << "\n" << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}