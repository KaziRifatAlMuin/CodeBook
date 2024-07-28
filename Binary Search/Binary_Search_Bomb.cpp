#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int const N = 2e5 + 7;

ll n, k;
vector <ll> a(N), b(N);

inline pair <ll, ll> get(ll x) {
    ll tot_sum = 0, tot_ops = 0;
    for(int i = 0; i < n; i++){
        ll diff = max(0ll, a[i] - x);
        ll ops = diff / b[i] + (a[i] >= x);
        ll sum = a[i] * ops - (ops * (ops - 1) * b[i] / 2);
        tot_ops += ops;
        tot_sum += sum;
    }
    if(tot_ops > k) tot_sum -= ((tot_ops - k) * x);
    pair <ll, ll> ans ={tot_ops, tot_sum};
    return ans;
}

void solve() {
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    // TTTTTTTFFFFFF
    ll ans = 0, low = 0, high = 1e9 + 20;
    while(high - low > 1){
        ll mid = (low + high) / 2;
        if(get(mid).first >= k){
            low = mid;
            ans = mid;
        }
        else{
            high = mid;
        }
        // cout << mid << " ";
    }
    cout << get(ans).second << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1, st = clock();
    cin >> t;
    while(t--){
        solve();
    }
    cerr << "[Time : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}
// https://codeforces.com/contest/1996/problem/F