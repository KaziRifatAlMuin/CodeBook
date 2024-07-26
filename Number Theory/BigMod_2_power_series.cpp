#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int const N = 2e7 + 7;
int const mod = 1e9 + 7;

// a + ar + ar^2 + ar^3 + ... + ar^n-1 = a(r^(n) - 1) / (r - 1)
// 1 + a + a^2 + a^3 + a^4 + .... + a^(n-1) = (a^n - 1) / (a - 1)

// 1 + a + a^2 + a^3 + a^4 + a^5 = 1 + a^2 + (a^2)^2 + a(1 + a^2 + (a^2)^2) 
// bigsum(a, 6) = bigsum(a^2, 3) + a * bigsum(a^2, 3)
// 1 + a + a^2 + a^3 + a^4 = 1 + a(1 + a + a^2 + a^3)
// bigsum(a, 5) = 1 + a * bigsum(a, 4)

ll bigsum(ll a, ll n) {
    if(n == 0 || n == 1) return n;
    if(n & 1) return ((a % mod) * bigsum(a % mod, n - 1) + 1) % mod;
    ll x = bigsum((a * a) % mod, n / 2);
    return (x + (a * x) % mod) % mod;
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

inline ll modInverse(ll a) { return power(a, mod - 2); }

ll formula(ll a, ll n){
    if(a == 1) return n;
    return ((power(a, n) - 1) * (modInverse(a - 1))) % mod; // if mod is prime
}

void solve(ll a, ll n) {
    ll loop = 1e5;
    ll ans = 0;
    while(loop--){
        ans = bigsum(a, n);
    }
    cout << bigsum(a, n) << " " << formula(a, n) << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1, st = clock();
    cin >> t;
    while(t--){
        ll a, n;
        cin >> a >> n;
        solve(a, n);
    }
    cerr << "[Time : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}