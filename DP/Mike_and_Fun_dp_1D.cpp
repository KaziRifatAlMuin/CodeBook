#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int const N = 2000;
int const mod = 1e9 + 7;

void solve()
{
    int n, m, q;
    cin >> n >> m >> q;
    bool state[n][m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> state[i][j];
        }
    }
    int maxi[n], dp[m];
    for(int i = 0; i < n; i++){
        int ans = 0;
        memset(dp, 0, sizeof(dp));
        ans = dp[0] = state[i][0]; // Base case
        for(int j = 1; j < m; j++){
            if(state[i][j] == 0) dp[j] = 0;
            else dp[j] = dp[j-1] + 1;
            ans = max(ans, dp[j]); // calculating maximum consecutive ones
        }
        maxi[i] = ans;
    }

    while(q--){
        int x, y;
        cin >> x >> y;
        state[x-1][y-1] ^= 1;
        memset(dp, 0, sizeof(dp));
        int ans = 0;
        ans = dp[0] = state[x-1][0];
        for(int j = 1; j < m; j++){
            if(state[x-1][j] == 0) dp[j] = 0;
            else dp[j] = dp[j-1] + 1;
            ans = max(ans, dp[j]);
        }
        maxi[x-1] = ans;
        for(int i = 0; i < n; i++) ans = max(ans, maxi[i]);
        cout << ans << "\n";
    }
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