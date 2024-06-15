#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
long long int const MOD = 1e9 + 7;
int const N = 1e7 + 7;
long long const INF = 1e18 + 7;

ll dist[N];

struct info{
    ll num, cost;
    bool operator < (const info &p) const{
        return cost > p.cost;
    }
};

void Dijkstra(ll n, ll x, ll y){
    for(ll i = 0; i < N; i++) dist[i] = INF;
    priority_queue <info> q;
    dist[0] = 0;
    q.push({0,0});
    info node;

    while(!q.empty()){
        node = q.top();
        q.pop();
        ll cur = node.num, cost = node.cost;

        // cout << "["  << dist[cur] << " ";
        // cout << dist[cur + 1] << "]\n";

        if(cur == n){
            // cout << "Tata\n";
            break;
        }
        // if(dist[cur] < cost) continue;

        if(dist[cur + 1] > dist[cur] + x){
            // cout << "+\n";
            dist[cur + 1] = dist[cur] + x;
            q.push({cur + 1, dist[cur + 1]});
        }

        if(cur > 0 && cur * 2 <= (n + 1) && dist[cur * 2] > dist[cur] + y){
            // cout << "*\n";
            dist[cur * 2] = dist[cur] + y;
            q.push({cur * 2, dist[cur * 2]});
        }

        if(cur - 1 > 0 && dist[cur - 1] > dist[cur] + x){
            // cout << "-\n";
            dist[cur - 1] = dist[cur] + x;
            q.push({cur - 1, dist[cur - 1]});
        }
    }
}

void solve()
{
    ll n, x, y;
    cin >> n >> x >> y;
    Dijkstra(n, x, y);
    cout << dist[n] << "\n";
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