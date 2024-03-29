#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
long long int const mod = 1e9 + 7;
int const N = 1e6 + 7;

ll power(ll a, ll b) {
    ll ans = 1;
    bool flag = (a >= mod);
    while(b) {
        if(b & 1) {
            ans *= a;
            if(ans >= mod) {
                ans %= mod;
                flag = true;
            }
        }
        a *= a;
        if(a >= mod) {
            a %= mod;
            flag = true;
        }
        b >>= 1;
    }
    return (ans + (flag * mod)) % mod;
}

int f[N], invf[N];

void pre() {
    f[0] = 1;
    for (int i = 1; i < N; i++) {
        f[i] = 1LL * i * f[i - 1] % mod;
    }
    invf[N - 1] = power(f[N - 1], mod - 2);
    for (int i = N - 2; i >= 0; i--) {
        invf[i] = 1LL * invf[i + 1] * (i + 1) % mod;
    }
}

int nCr(int n, int r) {
    if (n < r or n < 0) return 0;
    return 1LL * f[n] * invf[r] % mod * invf[n - r] % mod;
}


void solve() {
    ll n, r;
    cin >> n >> r;
    cout << nCr(n,r) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1, cs = 1;
    cin >> t;
    pre();
    while (t--) {
        cout << "Case " << cs++ << ": ";
        solve();
    }
    return 0;
}
