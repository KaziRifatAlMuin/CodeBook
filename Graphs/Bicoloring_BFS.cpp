#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int const N = 1e5 + 7;


bool BFS(int start, bool vis[], vector <int> graph[N+5], string color){
    queue <int> q;
    q.push(start);
    // level[start] = 0;
    color[start] = 'B';
    while(!q.empty()){
        int cur_v = q.front();
        vis[cur_v] = true;
        q.pop();
        for(auto child : graph[cur_v]){
            if(!vis[child]){
                q.push(child);
                if(color[cur_v] == color[child]) return 0;
                else{
                    if(color[cur_v] == 'B') color[child] = 'W';
                    else color[child] = 'B';
                }
                // level[child] = level[cur_v] + 1;
            }
        }
    }
    return 1;
}

void solve()
{
    while(1){
        int n, m;
        cin >> n;
        if(n == 0) break;
        cin >> m;
        bool vis[n+1] = {0};
        vector <int> graph[n+1];
        string color;
        for(int i = 0; i <= n; i++) color += '*';
        for(int i = 0; i < m; i++){
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        if(BFS(0, vis, graph, color)) cout << "BICOLORABLE.\n";
        else cout << "NOT BICOLORABLE.\n";
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