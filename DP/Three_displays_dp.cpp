#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int const N = 200;

void solve()
{
    int n;
    cin >> n;
    vector <ll> a(n), c(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> c[i];

    ll dp[n][3]; // dp[position][length] = minimum cost possible

    ll const inf = 1e17;
    ll ans = inf;

    for(int i = 0; i < n; i++){
        for(int k = 0; k < 3; k++){
            dp[i][k] = inf;
        }
    }

    for(int i = 0; i < n; i++){
        dp[i][0] = c[i];
        for(int j = 0; j < i; j++){
            for(int k = 1; k < 3; k++){
                if(a[j] < a[i]){
                    dp[i][k] = min(dp[i][k], dp[j][k-1] + c[i]);
                }
            }
        }
        ans = min(ans, dp[i][2]);
        // cout << ans << " ";
    }
    if(ans == inf) ans = -1;
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
// https://codeforces.com/gym/302977/problem/H