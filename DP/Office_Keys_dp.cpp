#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
long long int const MOD = 1e9 + 7;
int const N = 2e3 + 7;
long long const INF = 1e18 + 7;

void solve()
{
    int n, k, p;
    cin >> n >> k >> p;
    vector <ll> a(n), b(k);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < k; i++) cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    // Optimal answer = minimum time needed among all i.e. maximum cost among all n people should be minimum
    ll dp[k+1][n+1]; // dp[Position of key][number of person used till position] = optimal answer
    
    for(int i = 0; i <= k; i++){
        for(int j = 0; j <= n; j++){
            dp[i][j] = INF;
        }
    }

    dp[0][0] = 0; // Base Case

    for(int i = 0; i < k; i++){
        for(int j = 0; j <= n; j++){
            dp[i+1][j] = min(dp[i+1][j], dp[i][j]); // Do not Take
            if(j < n) dp[i+1][j+1] = min(dp[i+1][j+1], max(dp[i][j], abs(a[j] - b[i]) + abs(b[i] - p))); // Take
        }
    }
    cout << dp[k][n] << "\n";
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
// https://codeforces.com/gym/302977/problem/E