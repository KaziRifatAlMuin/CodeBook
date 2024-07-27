#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int const N = 1e5 + 7;
int const mod = 1e9 + 7;

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    vector <ll> pre(n+1), sumx(n+n+2);
    pre[0] = n;
    for(int i = 0; i < n; i++){
        int a = s[i] == '0' ? -1 : 1;
        pre[i+1] = pre[i] + a;
    }
    ll ans = 0;
    for(ll y = 0; y <= n; y++){
        ans = (ans + (sumx[pre[y]] * (n - y + 1)) % mod) % mod;
        sumx[pre[y]] += (y + 1);
    }
    cout << ans << "\n";
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
// https://codeforces.com/contest/1996/problem/E