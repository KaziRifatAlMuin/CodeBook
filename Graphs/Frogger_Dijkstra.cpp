#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
long long int const MOD = 1e9 + 7;
int const N = 207;

vector <pair<int, double>> G[N];
vector <double> dist(N);

struct info{
    int city;
    double cost;
    bool operator < (const info &p) const{
        return cost > p.cost;
    }
};

void Dijkstra(int source){
    for(int i = 0; i < N; i++) dist[i] = 1e18;
    priority_queue <info> q;

    info cur, next;
    cur.city = source, cur.cost = 0;
    q.push(cur);
    dist[source] = cur.cost;

    while(!q.empty()){
        cur = q.top();
        q.pop();
        double cur_cost = dist[cur.city];
        for(auto x : G[cur.city]){
            next.city = x.first;
            next.cost = max(x.second, cur_cost);
            if(next.cost < dist[next.city]){
                dist[next.city] = next.cost;
                q.push(next);
            }
        }
    }
}

void solve()
{
    ll n, cs = 1;
    while(1){
        cin >> n;
        if(n == 0) break;
        memset(G, 0, sizeof(G));
        vector <pair<double, double>> xy;
        for(int i = 0; i < n; i++){
            double x, y;
            cin >> x >> y;
            xy.push_back({x,y});
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == j) continue;
                double w = sqrt((xy[i].first - xy[j].first) * (xy[i].first - xy[j].first) + (xy[i].second - xy[j].second) * (xy[i].second - xy[j].second));
                G[i].push_back({j, w});
                G[j].push_back({i, w});
            }
        }
        Dijkstra(0);
        // for(int i = 0; i < n; i++){
        //     cout << dist[i] << " ";
        // }
        // cout << "\n";
        cout << "Scenario #" << cs++ << "\n";
        cout << fixed << setprecision(3) << "Frog Distance = " << dist[1] << "\n\n";
    }
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