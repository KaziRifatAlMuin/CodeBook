#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
long long int const MOD = 1e9 + 7;
int const N = 5005;

class DSU{
    int parent[N];
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

void solve()
{
    int n;
    cin >> n;
    vector <int> gang(n+1);
    vector <pair<int,int>> ans;
    DSU dsu;
    for(int i = 1; i <= n; i++){
        cin >> gang[i];
        dsu.make_set(i);
    }
    for(int i = 1; i < n; i++){
        for(int j = i + 1; j <= n; j++){
            if(dsu.is_Same_set(i,j) || gang[i] == gang[j]) continue;
            else{
                dsu.union_set(i,j);
                ans.push_back({i,j});
            }
        }
    }

    if(ans.size() != n - 1){
        cout << "NO\n";
    }
    else{
        cout << "YES\n";
        for(auto x : ans){
            cout << x.first << " " << x.second << "\n";
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
