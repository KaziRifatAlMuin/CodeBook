#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int const N = 200;

void solve()
{
    ll start, end, n, d;
    cin >> start >> end >> n >> d;
    ll dp[n][1000];
    ll const inf = 1e17;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 1000; j++){
            dp[i][j] = -inf;
        }
    }

    dp[0][start] = 0;

    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < 1000; j++){
            for(int k = -d; k <= d; k++){
                if(j + k >= 0 && j + k < 1000){
                    dp[i+1][j+k] = max(dp[i+1][j+k], dp[i][j] + j);
                }
            }
        }
    }
    cout << dp[n-1][end] + end << "\n";
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
// https://codeforces.com/gym/302977/problem/G