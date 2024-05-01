#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll mod = 1e9 + 7;
const int N = 3e5 + 7;
const long long INF = 1e18 + 7;

void solve() {
    ll n, k;
    cin >> n >> k;
    vector <ll> v(n+1);
    for(int i = 1; i <= n; i++){
        cin >> v[i]; // 1 based index for given array
    }
    ll dp[n+1][k+1];
    ll ans = INF;
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= k; j++){
            dp[i][j] = i == 0 ? 0 : INF; // i == 0 means no number is taken, It works as base condition to build dp
        }
    }
    for(int pos = 1; pos <= n; pos++){
        for(int c = 0; c <= k; c++){
            // dp[pos][c] = current position pos (1 based) & c operations done
            ll mn = INF;
            for(int prev = pos; pos - prev <= c && prev > 0; prev--){
                // going back as much as I can go
                mn = min(mn, v[prev]); // taking minimum one in that window

                // If all from prev to pos made equal to mn then
                ll x = (pos - prev + 1) * mn; // sum of that window

                // This will take (pos - prev) operations so add dp for [c - (pos-prev)]

                x += dp[prev - 1][c - (pos-prev)]; // new calculated dp value for dp[pos][c]
                // [prev-1] because, this gives minimum dp result up to our new taken window
                // [c - (pos-prev)] because, taking this window we lose some operations that needs to be updated in dp

                // Finally our dp should store the minimum of previously calculated and newly calculated for dp[pos][c]
                // dp is developing from no operations to k operations
                // If dp[pos][c] is here for first time, it has INF, so it will simply take x = v[pos] and update as minimum as no operation
                // Gradually it will use some operations and update the dp value minimum possible using that number of operations upto that position
                // So we will find our ans in pos = n, where we have checked all possible operation for the full array
                // Then we will take the minimum one between operations 0 to k as final answer

                dp[pos][c] = min(dp[pos][c], x);
            }
        }
    }
    
    // Checking for pos = n, because, in here we have checked all possibilities for full array
    // for(int c = 0; c <= k; c++){
    //     ans = min(dp[n][c], ans); // Maximum k operations, we can do any and searching for minimum one, But not necessary
    // }

    // dp will always run for c = k, and it will do as much operations as I can and update for k
    // Increasing operations we always update the best result than less operations
    // So [k] will always give the best result for dp[pos]
    // So it is not needed to check for all, The best result is simply in dp[n][k]

    cout << dp[n][k] << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
