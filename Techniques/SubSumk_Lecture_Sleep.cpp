#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int const N = 2e5 + 7;
const int MOD = 998244353;

ll maxSubArraySum(vector<ll> a, ll size, ll k) {
    ll ans = INT_MIN, sum = 0;
    for (ll i = 0; i < size; i++) {
        if (i < k) {
            sum += a[i];
            ans = sum;
        } else {
            sum += a[i] - a[i - k];
            ans = max(ans, sum);
        }
    }
    return ans;
}

void solve() {
    ll n, k;
    cin >> n >> k;
    vector <ll> v(n), wake(n), a(n, 0);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    for(int i = 0; i < n; i++){
        cin >> wake[i];
    }
    ll ans = 0;
    for(int i = 0; i < n; i++){
        if(wake[i]){
            ans += v[i];
        }
        else{
            a[i] = v[i];
        }
    }
    cout << ans + maxSubArraySum(a, n, k) << "\n";
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