#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int const N = 2000;
int const mod = 1e9 + 7;

void solve()
{
    ll n, k;
    cin >> n >> k;

    ll dp[k+1][n+1];  // dp[length][Last value] = number of good sequences
    memset(dp, 0, sizeof(dp));

    dp[0][1] = 1; // Base case

    for(ll i = 0; i < k; i++){
        for(ll j = 1; j <= n; j++){
            for(ll v = j; v <= n; v += j){
                dp[i+1][v] = (dp[i+1][v] + dp[i][j]) % mod;
            }
        }
    }

    ll ans = 0;
    for(ll i = 1; i <= n; i++){
        ans = (ans + dp[k][i]) % mod;
    }
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t = 1, cs = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}