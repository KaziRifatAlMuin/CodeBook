#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
long long int const mod = 1e8 + 7;
int const N = 1e6 + 7;
ll const MAX = 1e10 + 5;\

vector <ll> pp;

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

void perfectPower(){
    for(ll i = 2; i < N; i++){;
        ll num = i * i;
        while(num < MAX){
            pp.push_back(num);
            num = num * i;
        }
    }
    sort(pp.begin(), pp.end());
    pp.erase(unique(pp.begin(), pp.end()), pp.end());
}

ll PowerCount(ll n){
    ll x = upper_bound(pp.begin(), pp.end(), n) - pp.begin() - 1;
    return x;
}

void solve(){
    ll a, b;
    cin >> a >> b;
    // cout << PowerCount(b) << " " << PowerCount(a-1) << " ";
    ll n = PowerCount(b) - PowerCount(a-1);
    // cout << n << " ";
    if(n == 0){
        cout << 0 << "\n";
        return;
    }
    ll ans = (nCr(2*n, n) % mod - nCr(2*n, n+1) % mod + mod) % mod; // catalan
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1, cs = 1;
    cin >> t;
    pre();
    perfectPower();
    while (t--) {
        cout << "Case " << cs++ << ": ";
        solve();
    }
    return 0;
}
