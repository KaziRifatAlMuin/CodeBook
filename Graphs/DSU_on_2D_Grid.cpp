#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
long long int const MOD = 1e9 + 7;
int const N = 1e6 + 7;

int par[N], cnt[N];

int find_par(int node) {
    if(par[node] == node) return node;
    return par[node] = find_par(par[node]);
}
int merge(int a, int b) {
    a = find_par(a);
    b = find_par(b);
    if(a == b) return a;
    par[a] = b;
    cnt[b] += cnt[a];
    return b;
}

int ax[] = {0, 1, -1};
int bx[] = {-1, 0, 0};

int f(vector<vector<int>>v) 
{
    int n = v.size();
    int m = v[0].size();
    vector<int>pre(m + 1), suff(m + 1);
    int tot = n * m;
    for(int i = 0; i <= tot; i++) {
        par[i] = i;
        cnt[i] = 1;
    }
    auto valid = [&](int x, int y) {
        if(min(x, y) < 0 || x >= n || y >= m || !v[x][y])
        return false;
        return true;
    };
    auto f1 = [&](int i, int j) {
        return i * m + j;
    };
    bx[0] = -1;
    for(int i = 0; i < m; i++) {
        set<int>st;
        for(int j = 0; j < n; j++) {
            if(!valid(j, i)) continue;
            // cout << j << " " << i << "\n";
            for(int k = 0; k < 3; k++) {
                int i1 = j + ax[k];
                int j1 = i + bx[k];
                if(!valid(i1, j1)) continue;
                merge(f1( j, i), f1(i1, j1));
            }
        }
        for(int j = 0; j < n; j++) {
            if(!valid(j, i)) continue;
            st.insert(find_par(f1(j, i)));
        }
        for(auto &u:st) pre[i] += cnt[u];
        // cout << pre[i] << "\n";
    }
    for(int i = 0; i <= tot; i++) {
        par[i] = i;
        cnt[i] = 1;
    }
    bx[0] = 1;
    for(int i = m - 1; i >= 0; i--) {
        set<int>st;
        for(int j = 0; j < n; j++) {
            if(!valid(j, i)) continue;
            for(int k = 0; k < 3; k++) {
                int i1 = j + ax[k];
                int j1 = i + bx[k];
                if(!valid(i1, j1)) continue;
                merge(f1(j, i), f1(i1, j1));
            }
        }
        for(int j = 0; j < n; j++) {
            if(!valid( j, i)) continue;
            st.insert(find_par(f1(j, i)));
        }
        for(auto &u:st) suff[i] += cnt[u];
    }
    int ans = 0;
    for(int i = 0; i < m; i++) {
        ans = max(ans, n + suff[i + 1] + (i?pre[i - 1]:0));
    }
    return ans;
}

void solve() 
{
    int n, m; cin >> n >> m;
    vector<vector<int>>v(n, vector<int>(m)), v1(m, vector<int>(n));
    for(int i = 0; i < n; i++) {
        string  c; cin >> c;
        for(int j = 0; j < m; j++) {
            v[i][j] = c[j] == '#';
            v1[j][i] = v[i][j];
        }
    }
    // f(v);
    cout << max(f(v), f(v1)) << "\n";
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
// https://codeforces.com/contest/1985/problem/H1