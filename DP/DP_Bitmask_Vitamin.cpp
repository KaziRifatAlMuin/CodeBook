#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
long long int const MOD = 1e9 + 7;
int const N = 2e5 + 7;

void solve() {
    int n;
    cin >> n;
    ll dp[n+1][8];
    const ll inf = 1e18;
    for(int i = 0; i <= n; i++){
        for(int j = 0; j < 8; j++){
            dp[i][j] = inf;
        }
    }
    dp[0][0] = 0;
    for(int i = 0; i < n; i++){
        int taka; cin >> taka;
        string s; cin >> s;
        int str_mask = 0;
        for(int pos = 0; pos < 3; pos++){
            char c = 'C' - pos;
            bool have = 0;
            for(auto d : s){
                if(d == c){
                    have = 1;
                }
            }
            if(have){
                str_mask += (1 << pos); // 2 ^ pos
            }
        }
        for(int mask = 0; mask < 8; mask++){
            dp[i+1][mask] = min(dp[i][mask], dp[i+1][mask]);
            dp[i+1][mask | str_mask] = min(dp[i+1][mask | str_mask], dp[i][mask] + taka);
        }
    }
    ll ans = dp[n][7] == inf ? -1 : dp[n][7];
    cout << ans << "\n";
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