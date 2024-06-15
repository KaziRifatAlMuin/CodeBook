#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int N = 30007;
const ll INF = 1e18 + 7;

vector <int> G[N];
int depth[N], height[N];

void DFS(int v, int par = -1){
    // After Entering Vertex, Before Entering Child [Downwards]
    for(auto child : G[v]){
        // Before Entering Child Node [Downwards]
        if(child == par) continue;
        depth[child] = depth[v] + 1;
        DFS(child, v);
        height[v] = max(height[v], height[child] + 1); 
        // After Exiting The Child [Upwards]
    }
    // Before Exiting The Vertex [Upwards]
}

void solve() {
    ll n;
    cin >> n;
    memset(G, 0, sizeof(G));
    for (ll i = 0; i < n - 1; i++){
        ll u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    DFS(1);

    for(int i = 1; i <= n; i++){
        cout << depth[i] << " ";
    }
    cout << "\n";

    for(int i = 1; i <= n; i++){
        cout << height[i] << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

/*

Input :

13
1 2
1 3
1 13
2 5
3 4
5 6
5 7
5 8
8 12
4 9
4 10
10 11

Output : 
0 1 1 2 2 3 3 3 3 3 4 4 1 
4 3 3 2 2 0 0 1 0 1 0 0 0 

*/