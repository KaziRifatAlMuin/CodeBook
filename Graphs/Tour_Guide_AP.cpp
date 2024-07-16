#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
long long int const MOD = 1e9 + 7;
int const N = 10007;
long long const INF = 1e18 + 7;

vector <int> G[N];
bool visited[N];
int disc[N], low[N];
bool mark[N];
int timer;
map <string, int> mp;

void DFS(int v, int par = -1){
    visited[v] = true;
    disc[v] = low[v] = timer;
    timer++;
    int children = 0;
    for(auto child : G[v]){
        if(child == par) continue;
        if(!visited[child]){
            DFS(child, v);
            low[v] = min(low[child], low[v]);
            if(par != -1 && low[child] >= disc[v]) mark[v] = true;
            children++;
        }
        else{
            
            low[v] = min(low[v], disc[child]);
        }
    }
    if(par == -1 && children > 1) mark[v] = true; 
}


void solve()
{
    int n, m, no = 1;
    while(1){
        cin >> n;
        if(n == 0) break;
        memset(G, 0, sizeof(G));
        memset(disc, 0, sizeof(disc));
        memset(low, 0, sizeof(low));
        memset(visited, 0, sizeof(visited));
        memset(mark, 0, sizeof(mark));
        mp.clear();

        string s[n];
        for(int i = 0; i < n; i++){
            cin >> s[i];
            mp[s[i]] = i + 1;
        }
        cin >> m;
        for(int i = 0; i < m; i++){
            string su, sv;
            cin >> su >> sv;
            G[mp[su]].push_back(mp[sv]);
            G[mp[sv]].push_back(mp[su]);
        }

        for(int i = 1; i <= n; i++){
            if(!visited[i]){
                timer = 0;
                DFS(i);
            }
        }
        vector <string> ans;
        for(int i = 1; i <= n; i++){
            if(mark[i]) ans.push_back(s[i-1]);
        }
        sort(ans.begin(), ans.end());
        if (no > 1) cout << "\n";
        cout << "City map #" << no++ << ": " << ans.size() << " camera(s) found\n";
        for( auto x : ans){
            cout << x << "\n";
        };
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t = 1, cs = 1;
    // cin >> t;
    while(t--){
        // cout << "Case " << cs++ << ": ";
        solve();
    }
    return 0;
}