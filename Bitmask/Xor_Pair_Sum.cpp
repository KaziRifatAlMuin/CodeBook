#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int const N = 1e5 + 7;
int const mod = 1e9 + 7;
#define CheckBit(x, k) ((x >> k) & 1ll)

void solve()
{
    ll n;
    cin >> n;
    vector <ll> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    ll sum = 0;
    for(int bit = 0; bit <= 60; bit++){
        ll cnt = 0;
        for(int i = 0; i < n; i++){
            if(CheckBit(v[i], bit)) cnt++;
        }
        ll add = (((cnt * (n - cnt)) % mod) * ((1ll << bit) % mod)) % mod;
        sum = (sum + add) % mod;
    }
    cout << sum << "\n";
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
// https://vjudge.net/contest/640475#problem/C