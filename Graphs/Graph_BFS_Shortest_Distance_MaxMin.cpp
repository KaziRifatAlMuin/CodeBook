#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
long long int const MOD = 1e9 + 7;
int const N = 10005;

vector <int> G[N];
int dist[N];
map <int, vector <int>> MaxDist;


int BFS(int start, bool visited[], int n){
    int ans = 0;
    queue <int> Q;
    visited[start] = true;
    dist[start] = 0;
    Q.push(start);
    while(!Q.empty()){
        int parent = Q.front();
        Q.pop();
        for(auto child : G[parent]){
            if(!visited[child]){
                Q.push(child);
                visited[child] = true;
                dist[child] = dist[parent] + 1;
                ans = max(ans, dist[child]);
            }
        }
    }
    return ans;
}

void solve()
{
    int n, m, s, d;
    cin >> n;
    for(int i = 2; i <= n; i++){
        int u;
        cin >> u;
        G[u].push_back(i);
        G[i].push_back(u);
    }

    bool visited[N];
    int MaximumDist = BFS(s, visited, n);

    for(int w = 1; w <= n; w++){
        memset(visited, 0, sizeof(visited));
        memset(dist, 0, sizeof(dist));
        int MaximumDist = BFS(w, visited, n);
        MaxDist[MaximumDist].push_back(w);
    }
    auto it = MaxDist.begin();
    for(auto computer : it->second){
        cout << computer << " ";
    }
    cout << "\n";
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