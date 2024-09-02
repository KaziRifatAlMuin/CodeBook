#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int const N = 2e5 + 7;

vector <int> G[N];
int parent[N];
int black[N];

int find_set(int v){
    if(parent[v] == v) return v;
    parent[v] = find_set(parent[v]);
    return parent[v];
}

void union_set(int a, int b){
    int root_a = find_set(a);
    int root_b = find_set(b);
    parent[root_a] = root_b;
}

void solve() {
    int n;
    cin >> n;
    vector <int> v(n+1);
    memset(black, 0, sizeof(black));
    memset(parent, 0, sizeof(parent));
    for(int i = 0; i <= n; i++) parent[i] = i;
    for(int i = 1; i <= n; i++){
        cin >> v[i];
        union_set(i, v[i]);
    }
    string s;
    cin >> s;
    for(int i = 1; i <= n; i++){
        if(s[i-1] == '0') black[find_set(v[i])]++;
    }
    for(int i = 1; i <= n; i++){
        cout << black[find_set(i)] << " ";
    }
    cout << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1, st = clock();
    cin >> t;
    while(t--){
        solve();
    }
    cerr << "[Time : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}
// https://codeforces.com/contest/2008/problem/D