#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int const N = 2e7 + 7;
int const mod = 1e9 + 7;

ll bigmod(ll a, ll b) {
    if(b == 0) return 1;
    ll x = bigmod(a, b/2) % mod; // divide
    x = (x * x) % mod; // conquer
    if(b & 1) return (x * (a % mod)) % mod;
    return x; // recursion slow
}

ll power(ll a, ll b) {
    ll result = 1;
    a = a % mod;
    while (b > 0){
        if (b & 1) result = (result * a) % mod;
        a = (a * a) % mod;
        b >>= 1ll;
    }
    return result;
}

void solve(ll a, ll b) {
    ll loop = 1e5;
    ll ans = 0;
    while(loop--){
        ans = power(a, b);
    }
    cout << power(a,b) << " " << bigmod(a,b) << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1, st = clock();
    cin >> t;
    while(t--){
        ll a, b;
        cin >> a >> b;
        solve(a, b);
    }
    cerr << "[Time : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}