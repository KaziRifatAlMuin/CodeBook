#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int N = 30007;
const ll INF = 1e18 + 7;

bool vis[N+2];
vector <pair <ll, ll>> G[N+2];
ll dist[N+2];

void DFS(int v, int par = -1){
    for(auto child : G[v]){
        if(child.first == par) continue;
        dist[child.first] = dist[v] + child.second;
        // cout << v << " --- " << child.first << " : " << child.second << " -> ";
        // cout << dist[child.first] << "\n";
        DFS(child.first, v);
    }
}

void BFS(int start){
    queue <pair <ll, ll>> q;
    pair <ll, ll> cur;

    cur.first = start, cur.second = 0;
    q.push(cur);
    dist[cur.first] = 0;

    while(!q.empty()){
        cur = q.front();
        vis[cur.first] = true;
        q.pop();
        for(auto child : G[cur.first]){
            if(!vis[child.first]){
                q.push(child);
                dist[child.first] = dist[cur.first] + child.second;
                vis[child.first] = true;
                // cout << cur.first << " --- " << child.first << " : " << child.second << " -> ";
                // cout << dist[child.first] << "\n";
            }
        }
    }
}

void solve() {
    ll n;
    cin >> n;
    memset(G, 0, sizeof(G));
    memset(dist, 0, sizeof(dist));
    memset(vis, 0, sizeof(vis));

    for (ll i = 0; i < n - 1; i++){
        ll u, v, w;
        cin >> u >> v >> w;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }

    DFS(0);

    ll max_depth = 0, max_node = -1;
    for(int i = 0; i < n; i++){
        if(dist[i] > max_depth){
            max_depth = dist[i];
            max_node = i;
        }
        dist[i] = 0;
    }

    // cout << "Max Node : " << max_node << "\n";

    memset(vis, 0, sizeof(vis));
    memset(dist, 0, sizeof(dist));

    DFS(max_node);
    for(int i = 0; i < n; i++){
        if (dist[i] > max_depth){
            max_depth = dist[i];
            max_node = i;
        }
    }

    cout << max_depth << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1, cs = 1;
    cin >> t;
    while (t--) {
        cout << "Case " << cs++ << ": ";
        solve();
    }
    return 0;
}
