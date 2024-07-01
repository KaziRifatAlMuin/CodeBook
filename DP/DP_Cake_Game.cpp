#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int N = 5e3 + 7;

void solve()
{
    int n;
    cin >> n;
    vector <ll> v(n);
    map <int, int> mp;
    vector <int> frq;
    int ans = -1;
    for(int i = 0; i < n; i++) cin >> v[i], mp[v[i]]++;
    for(auto x : mp) frq.push_back(x.second);
    int sz = frq.size();
    int dp[sz][sz+1]; // dp[i][x] : Remaining moves for bob at ith index after alice using x cakes
    memset(dp, -1, sizeof(dp));
    dp[0][1] = 1;
    for(int i = 1; i < sz; i++){
        for(int x = 1; x <= sz; x++){
            if(dp[i-1][x-1]!= -1) dp[i][x] = dp[i-1][x-1] + 1; // Picked ith one
            if(dp[i-1][x] >= frq[i]) dp[i][x] = max(dp[i][x], dp[i-1][x] - frq[i]); // Not picked ith one
        }
    }
    for(int x = 1; x <= sz; x++){
        if(ans == -1 && dp[sz-1][x] != -1) ans = x; // Minimum x where bob is not failed to stop
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