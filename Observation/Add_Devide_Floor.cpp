#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int const N = 2e7 + 7;

void solve()
{
    int n;
    cin >> n;
    ll low = 2e9, high = 0, add;
    vector <ll> v(n), ans, opt1, opt2;
    for(int i = 0; i < n; i++){
        ll a; cin >> a;
        low = min(low, a);
        high = max(high, a);
    }
    while(high != low){
        add = high + 1;
        ans.push_back(add);
        low = (low + add) / 2; // It will converge to high
        high = (high + add) / 2; // It will remain same
    }
    cout << ans.size() << "\n";
    if(ans.size() <= n && ans.size() > 0){
        for(auto x : ans){
            cout << x << " ";
        }
        cout << "\n";
    }
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
// https://codeforces.com/contest/1901/problem/C