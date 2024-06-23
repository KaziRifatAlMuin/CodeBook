#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
long long int const MOD = 1e9 + 7;
int const N = 107;

vector <pair<ll, ll>> G[N];
vector <ll> dist(N);

struct info{
    ll city;
    ll cost;
    bool operator < (const info &p) const{
        return cost > p.cost;
    }
};

void Dijkstra(ll source){
    for(int i = 0; i < N; i++) dist[i] = 1e18;
    priority_queue <info> q;

    info cur, next;
    cur.city = source, cur.cost = 0;
    q.push(cur);
    dist[source] = cur.cost;

    while(!q.empty()){
        cur = q.top();
        q.pop();
        ll cur_cost = dist[cur.city];
        for(auto x : G[cur.city]){
            next.city = x.first;
            next.cost = x.second + cur_cost;
            if(next.cost < dist[next.city]){
                dist[next.city] = next.cost;
                q.push(next);
            }
        }
    }
}

void solve()
{
    ll n;
    cin >> n;
    for(int i = 2; i <= n; i++){
        for(int j = 1; j < i; j++){
            string s;
            ll w; cin >> s;
            if(s == "x") continue;
            else w = stoll(s);
            G[i].push_back({j, w});
            G[j].push_back({i, w});
            // cout << i << " " << j << " " <<  w  << "\n";
        }
    }
    Dijkstra(1);
    ll ans = 0;
    for(int i = 1; i <= n; i++) ans = max(ans, dist[i]);
    cout << ans << "\n";
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