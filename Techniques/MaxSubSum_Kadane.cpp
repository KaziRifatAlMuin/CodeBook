#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll mod = 1e9 + 7;

ll maxSubArraySum(ll a[], ll size) {
    ll ans = INT_MIN, sum = 0;
    for (ll i = 0; i < size; i++) {
        sum += a[i];
        ans = max(ans, sum);
        if (sum < 0)
            sum = 0;
    }
    if(ans < 0) ans = 0;
    return ans;
}

void solve() {
    ll n, k;
    cin >> n >> k;
    ll v[n];
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        sum = ((sum + v[i]) % mod + mod) % mod;
    }
    ll ans = maxSubArraySum(v, n);
    //sum = ((sum - ans) % mod + mod) % mod;
    ll add = 0, times = k * (k + 1) / 2;
    for(int i = 0; i < k; i++){
        add = (add + ans) % mod;
        ans = (ans * 2) % mod;
    }
    sum = (((sum + add) % mod) +  mod) % mod;
    cout << sum << "\n";
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
