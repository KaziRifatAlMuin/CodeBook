#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int const N = 2e7 + 7;

// 1 + a + a^2 + ... + a^n-1

ll GeoSum(ll a, ll n, ll mod) {
    if(n == 0 || n == 1) return 1 % mod;
    if(n & 1) return ((a * GeoSum(a, n - 1, mod) % mod) + 1) % mod;
    ll x = GeoSum((a * a) % mod, n / 2, mod) % mod;
    return (x + (a * x) % mod) % mod;
}

void solve() {
    ll a, x, m;
    cin >> a >> x >> m;
    cout << GeoSum(a, x, m) << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1, st = clock();
    // cin >> t;
    while(t--){
        solve();
    }
    cerr << "[Time : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}
// https://vjudge.net/problem/AtCoder-abc293_e