#include <iostream>
#include <vector>
using namespace std;

typedef long long int ll;

vector <int> graph[1005];
bool visited[1005];

class DSU{
    int parent[1005];
public:
    DSU(){}
    void make_set(int v){
        parent[v] = v;
    }

    int find_set(int v){
        if(parent[v] == v) return v;
        parent[v] = find_set(parent[v]);
        return parent[v];
    }

    void union_set(int a, int b){
        int root_a = find_set(a);
        int root_b = find_set(b);
        parent[root_b] = root_a;
    }

    bool is_Same_set(int a, int b){
        return find_set(a) == find_set(b);
    }
};

void DFS(int node){
    visited[node] = true;
    for(auto child : graph[node]){
        if(!visited[child]){
            DFS(child);
        }
    }
}

void solve()
{
    DSU dsu;
    ll n, m, prev = 0, d, a;
    vector <pair<int,int>> edge;
    vector <pair <int, int>> roads;
    vector <pair <int, int>> del;

    cin >> n >> d >> a;
    char s[n][n];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> s[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        dsu.make_set(i+1);
        for(int j = 0; j < i; j++){
            if(s[i][j] == '1'){
                edge.push_back({i+1,j+1});
            }
        }
    }
    for(int i = 0; i < edge.size(); i++){
        int u, v;
        u = edge[i].first;
        v = edge[i].second;
        graph[u].push_back(v);
        graph[v].push_back(u);

        if(dsu.is_Same_set(u,v)){
            del.push_back({u,v});
        }
        else{
            dsu.union_set(u,v);
        }
    }

    bool flag = false;

    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            if(flag) roads.push_back({prev, i});
            else flag = true;
            prev = i;
            DFS(i);
        }
    }
    
    vector<vector<char>> ans(n, vector<char>(n, '0')); // Dynamic allocation for ans array

    ll cancel = del.size(), add = roads.size();
    cout << d * cancel + a * add << "\n";

    for(auto x : roads){
        ans[x.first - 1][x.second - 1] = 'a';
        ans[x.second - 1][x.first - 1] = 'a';
    }
    for(auto x : del){
        ans[x.first - 1][x.second - 1] = 'd';
        ans[x.second - 1][x.first - 1] = 'd';
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
           cout << ans[i][j];
        }
        cout << "\n";
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
