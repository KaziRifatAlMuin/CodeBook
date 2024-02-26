#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
long long int const MOD = 1e9 + 7;
int const N = 2e5 + 7;

ll dp[N];

ll f(ll n){
    if(n == 2) return 2;
    if(n & 1) return 0;
    if(dp[n] != -1) return dp[n];
    return dp[n] = 2 * f(n - 2);
}

void solve()
{
    ll n;
    cin >> n;
    memset(dp, -1, sizeof(dp));
    cout << f(n) << "\n";
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