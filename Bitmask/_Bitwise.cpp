#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define SetBit(x, k) (x |= (1ll << k))
#define ClearBit(x, k) (x &= ~(1ll << k))
#define CheckBit(x, k) ((x >> k) & 1ll)
#define PowerOf2(v) (v && !(v & (v - 1)))
#define to_Binary(n) bitset<sizeof(n) * 8>(n).to_string()
long long int const MOD = 1e9 + 7;
int const N = 5005;


void solve()
{
    ll n, m;
    cin >> n >> m;
    ll l = max(0ll, n - m), r = n + m;
    ll ans = l | r;
    // cout << to_Binary(n) << "\n";
    for(int i = 0; i <= 31; i++){
        if ((l >> (i + 1)) != (r >> (i + 1))) {
            SetBit(ans, i);
        }
    }
    cout << ans << "\n";
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
