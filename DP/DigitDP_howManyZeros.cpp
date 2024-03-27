#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
long long int const MOD = 1e9 + 7;
int const N = 1e5 + 7;

ll dp[20][20][2];

ll digitDP(const string &num, ll pos = 0, ll cnt = 0, bool tight = 1, bool isStart = 1){
    if(pos == num.size()) return isStart ? 1 : cnt;
    else if(dp[pos][cnt][tight] != -1) return dp[pos][cnt][tight];
    ll ans = 0, lim = tight ? num[pos] - '0' : 9;
    for(int digit = 0; digit <= lim; digit++){
        ans += digitDP(num, pos + 1, cnt + (!isStart && digit == 0), tight && digit == lim, isStart && digit == 0);
    }
    return isStart ? ans : dp[pos][cnt][tight] = ans;
}

void solve() {
    ll l, r;
    cin >> l >> r;
    memset(dp, -1, sizeof(dp)); 
    ll ans1 = digitDP(to_string(r));
    memset(dp, -1, sizeof(dp));
    ll ans2 = digitDP(to_string(l - 1));
    cout << ans1 - ans2 << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1, cs = 1;
    cin >> t;
    while (t--) {
        cout << "Case " << cs++ << ": ";
        solve();
    }
    return 0;
}
