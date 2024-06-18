#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
long long int const MOD = 1e9 + 7;
int const N = 107;
long long const INF = 1e18 + 7;


vector <int> G[N];
bool visited[N];
int disc[N], low[N];
bool mark[N];
int timer;

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
    while(1){
        int n;
        cin >> n;
        if(n == 0) break;
        cin.ignore();

        memset(G, 0, sizeof(G));
        memset(disc, 0, sizeof(disc));
        memset(low, 0, sizeof(low));
        memset(visited, 0, sizeof(visited));
        memset(mark, 0, sizeof(mark));

        while(1){
            string line;
            getline(cin, line);
            stringstream ss(line);
            vector<int> v;
            int number, u;
            while (ss >> number) {
                v.push_back(number);
            }
            u = v[0];
            if(u == 0) break;
            for (int i = 1; i < v.size(); ++i) {
                G[u].push_back(v[i]);
                G[v[i]].push_back(u);
            }
        }

        for(int i = 1; i <= n; i++){
            if(!visited[i]){
                timer = 0;
                DFS(i);
            }
        }
        int AP = 0;
        for(int i = 1; i <= n; i++){
            if(mark[i]) AP++;
        }
        cout << AP << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t = 1, cs = 1;
    // cin >> t;
    while(t--){
        // cout << "Case " << cs++ << ":\n";
        solve();
    }
    return 0;
}