#include <bits/stdc++.h>
using namespace std;
#define YN(result) (result)? cout<<"YES\n" : cout<<"NO\n";
typedef long long int ll;
long long int const MOD = 1e9 + 7;
int const N = 2e5 + 7;

ll BigMod(ll a, ll p, ll mod){
    if(p == 0) return 1;
    ll ans = BigMod(a, p / 2, mod);
    ans = (ans * ans) % mod;
    if(p & 1) ans = (ans * a) % mod;
    return ans;
}

void solve()
{
    ll a, p, mod;
    while(cin >> a >> p >> mod){
        cout << BigMod(a, p, mod) << "\n";
    }
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